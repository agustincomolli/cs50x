import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Error codes.
ERROR_MUST_PROVIDE_SYMBOL = "must provide symbol"
ERROR_MUST_PROVIDE_USERNAME = "must provide username"
ERROR_MUST_PROVIDE_PASSWORD = "must provide password"
ERROR_MUST_PROVIDE_SHARES = "must provide shares"
ERROR_MUST_REPEAT_PASSWORD = "must repeat password"
ERROR_MUST_PROVIDE_NUMBER = "you must provide an integer number"
ERROR_INVALID_LOGIN = "invalid username and/or password"
ERROR_INVALID_SYMBOL = "invalid symbol"
ERROR_NOT_ENOUGH_MONEY = "you don't have enough money"
ERROR_NOT_ENOUGH_SHARES = "you don't have enough shares"
ERROR_NOT_EQUAL_PASSWORD = "password and repeat password must equals"
ERROR_USER_EXIST = "the user already exist"
ERROR_SHARES_RANGE = "shares must be greater than 0"
ERROR_CASH_RANGE = "cash must be greater than 0"

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """
    Show portfolio of stocks.

    Retrieves user's stock portfolio and cash balance, calculates total values,
    and renders the index.html template with the portfolio data.

    Returns:
        flask.Response: Rendered HTML template displaying the user's portfolio and total values.
    """

    # Get the sum of shares by symbol
    shares = db.execute(
        "SELECT symbol, SUM(shares) AS shares FROM history WHERE user_id = ? GROUP BY symbol;",
        session["user_id"],
    )

    # Create a list of dictionary with data for portfolio.
    stocks = []
    subtotal = 0
    for share in shares:
        # Get the actual price of symbol.
        price = lookup(share["symbol"])["price"]
        stocks.append(
            {
                "symbol": share["symbol"],
                "shares": share["shares"],
                "price": price,
                "total": share["shares"] * price,
            }
        )
        # Add all totals to get a grand total.
        subtotal += share["shares"] * price

    # Get the amount of user cash.
    cash = get_user(session["user_id"])["cash"]

    total = subtotal + cash
    return render_template("index.html", stocks=stocks, cash=cash, total=total)


@app.route("/account", methods=["GET", "POST"])
@login_required
def account():
    """
    Display and update user account information.

    If accessed via POST method:
        - Validates and processes form data for updating additional cash and/or password.
        - Updates the user's account in the database accordingly.
        - Redirects to "/account" upon successful update or displays an apology if there's an error.

    If accessed via GET method:
        - Retrieves user information and renders the account.html template with user data.

    Returns:
        flask.Response: Rendered HTML template displaying user account information or
                        redirects to the account page after updating information.
    """
    user_id = session["user_id"]

    if request.method == "POST":
        form_data = request.form
        additional_cash = form_data["additional-cash"]
        password = form_data["password"]
        repeat_password = form_data["confirmation"]

        message, code = check_account_form(additional_cash, password, repeat_password)
        if message:
            return apology(message, code)

        if additional_cash:
            additional_cash = float(additional_cash)
        else:
            additional_cash = 0

        # Get current amount of cash.
        cash = get_user(user_id)["cash"] + additional_cash

        if password:
            # Save the password in hash format.
            hash_password = generate_password_hash(password)
            # Update user account in database.
            db.execute(
                "UPDATE users SET cash = ?, hash = ? WHERE id = ?;",
                cash,
                hash_password,
                user_id,
            )
        else:
            # Update user account in database, cash only.
            db.execute("UPDATE users SET cash = ? WHERE id = ?;", cash, user_id)

        return redirect("/account")

    else:
        user = get_user(user_id)
        return render_template("account.html", user=user)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """
    Buy shares of stock.

    If accessed via POST method:
        - Validates and processes form data for buying shares.
        - Checks if the user has enough cash to make the purchase.
        - Updates the user's transaction history and cash balance in the database.
        - Redirects to the home page upon successful purchase or displays an apology if there's an error.

    If accessed via GET method:
        - Renders the buy.html template for entering stock symbol and shares.

    Returns:
        flask.Response: Redirects to the home page after successful purchase or renders the buy.html template.
    """
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        message, error_code, price = check_buy_sell_form(symbol, shares)
        if not message == "price":
            return apology(message, error_code)

        shares = int(shares)

        # Check how much cash the user has.
        user = get_user(session["user_id"])
        if (price * shares) > user["cash"]:
            return apology(ERROR_NOT_ENOUGH_MONEY, 400)

        # Buy the shares.
        db.execute(
            "INSERT INTO history (user_id, symbol, shares, price, transacted) "
            + "VALUES (?, ?, ?, ?, datetime('now'));",
            user["id"],
            symbol,
            shares,
            price,
        )

        # Update the user cash.
        cash_remained = user["cash"] - (price * shares)
        db.execute("UPDATE users SET cash = ? WHERE id = ?;", cash_remained, user["id"])

        # Redirect user to home page.
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """
    Show history of transactions.

    Retrieves transaction history from the database for the logged-in user and renders it
    in the history.html template.

    Returns:
        flask.Response: Renders the history.html template with transaction history data.
    """
    transactions = db.execute(
        "SELECT * FROM history WHERE user_id = ?;", session["user_id"]
    )
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """
    Log user in.

    Clears any existing user session. Handles both GET and POST requests:
    - GET: Renders the login.html template.
    - POST: Processes login form submission, verifies username and password
      against the database, and logs the user in if credentials are correct.

    Returns:
        flask.Response: Redirects to the home page on successful login or
        renders the login.html template on GET request.
    """
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        user_name = request.form.get("username")
        password = request.form.get("password")
        if not user_name:
            return apology(ERROR_MUST_PROVIDE_USERNAME, 403)

        # Ensure password was submitted
        elif not password:
            return apology(ERROR_MUST_PROVIDE_PASSWORD, 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", user_name)

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], password):
            return apology(ERROR_INVALID_LOGIN, 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """
    Log user out.

    Clears any existing user session and redirects the user to the login form.

    Returns:
        flask.Response: Redirects to the login page ("/").
    """
    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """
    Get stock quote.

    Allows users to get a stock quote based on the symbol provided. Handles both GET and POST requests.

    Returns:
        flask.Response: Renders "quote.html" template for GET requests or "quoted.html" template with
        stock quote information for POST requests.
    """
    if request.method == "POST":
        symbol = request.form.get("symbol")

        # Ensure username was submitted
        if not symbol:
            return apology(ERROR_MUST_PROVIDE_SYMBOL, 400)

        quoted = lookup(symbol)

        # Ensure symbol is valid.
        if not quoted:
            return apology(ERROR_INVALID_SYMBOL, 400)

        return render_template("quoted.html", quoted=quoted)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """
    Register user.

    Handles user registration. If the request method is POST, it validates the form data
    (username, password, confirmation), hashes the password, and inserts the new user into
    the database. If the registration is successful, redirects the user to the login page.
    If the request method is GET, renders the "register.html" template for user registration.

    Returns:
        flask.Response: Redirects to "/login" if registration is successful, or renders
        "register.html" template for GET requests.
    """
    if request.method == "POST":
        form_data = request.form
        username = form_data["username"]
        password = form_data["password"]
        repeat_password = form_data["confirmation"]

        # Ensure username was submitted.
        if not username:
            return apology(ERROR_MUST_PROVIDE_USERNAME, 400)

        # Ensure password was submitted.
        if not password:
            return apology(ERROR_MUST_PROVIDE_PASSWORD, 400)

        # Ensure confirmation was submitted.
        elif not repeat_password:
            return apology(ERROR_MUST_REPEAT_PASSWORD, 400)

        # Ensure password and reapeat-password are equals.
        elif not password == repeat_password:
            return apology(ERROR_NOT_EQUAL_PASSWORD, 400)

        # Ensure user don't exist
        try:
            # Save the password in hash format.
            hash_password = generate_password_hash(password)
            db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?);",
                username,
                hash_password,
            )
        except ValueError:
            return apology(ERROR_USER_EXIST, 400)
    else:
        return render_template("register.html")

    return redirect("/login")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """
    Sell shares of stock.

    Handles selling of shares for the logged-in user. If the request method is POST,
    validates the form data (symbol, shares), checks if the user has enough shares
    to sell, calculates the new cash balance after selling, updates the database with
    the transaction details, and redirects to the home page ("/"). If the request method
    is GET, retrieves the symbols of stocks the user owns and renders the "sell.html"
    template with the list of symbols.

    Returns:
        flask.Response: Redirects to "/" after a successful sale transaction. Renders
        "sell.html" template for GET requests with symbols of stocks the user can sell.
    """
    user_id = session["user_id"]
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        message, error_code, price = check_buy_sell_form(symbol, shares)
        if not message == "price":
            return apology(message, error_code)

        # Get the sum of shares by symbol and return the first row ([0]) and the amount of shares.
        query = "SELECT symbol, SUM(shares) AS shares FROM history WHERE user_id = ? AND symbol = ? GROUP BY symbol;"
        amount_shares = db.execute(query, user_id, symbol)[0]["shares"]

        # Convert to integer
        shares = int(shares)
        if shares > amount_shares:
            return apology(ERROR_NOT_ENOUGH_SHARES, 400)

        # Sell the shares.
        db.execute(
            "INSERT INTO history (user_id, symbol, shares, price, transacted) "
            + "VALUES (?, ?, ?, ?, datetime('now'));",
            user_id,
            symbol,
            -shares,
            price,
        )

        # Update the user cash.
        cash = get_user(user_id)["cash"]
        cash += shares * price
        db.execute("UPDATE users SET cash = ? WHERE id = ?;", cash, user_id)

        # Redirect user to home page.
        return redirect("/")
    else:
        symbols = db.execute(
            "SELECT symbol FROM history WHERE user_id = ? GROUP BY symbol;", user_id
        )
        return render_template("sell.html", symbols=symbols)


def get_user(user_id):
    """
    Retrieve a user's information from the database.

    Args:
        user_id (int): The ID of the user whose information is to be retrieved.

    Returns:
        dict: A dictionary containing the user's information from the database.
              The keys are column names from the 'users' table and the values are
              the corresponding values for the specified user.
    """
    return db.execute("SELECT * FROM users WHERE id = ?;", user_id)[0]


def check_buy_sell_form(symbol, shares):
    """
    Validates the input for buying or selling a stock.

    Args:
        symbol (str): The stock symbol to lookup.
        shares (int): The number of shares to buy or sell.

    Returns:
        tuple: A tuple containing a message (str), a status code (int), and the stock price (float).

    Raises:
        ValueError: If shares is not a positive integer.

    Notes:
        - Returns a message and status code if the input is invalid.
        - Uses a helper function `lookup` to verify the stock symbol and get the current price.
    """
    # Ensure symbol was submitted.
    if not symbol:
        return (ERROR_MUST_PROVIDE_SYMBOL, 400, 0.0)

    # Ensure symbol is valid.
    quoted = lookup(symbol)
    if not quoted:
        return (ERROR_INVALID_SYMBOL, 400, 0.0)

    # Ensure shares was submitted and is greater than 0.
    if not shares:
        return (ERROR_MUST_PROVIDE_SHARES, 400, 0.0)

    try:
        shares = int(shares)
    except ValueError:
        return(ERROR_MUST_PROVIDE_NUMBER, 400, 0.0)

    if shares < 1:
        return(ERROR_SHARES_RANGE, 400, 0.0)

    return ("price", 0, quoted["price"])


def check_account_form(additional_cash, password, repeat_password):
    """
    Validates the input from an account form.

    Parameters:
    additional_cash (float or int): The additional cash amount to be added.
    password (str): The password provided by the user.
    repeat_password (str): The repeated password provided by the user.

    Returns:
    tuple: A tuple containing an error message and a status code, or (None, None) if the input is valid.
    """
    if additional_cash:
        # Make sure it is a number.
        try:
            additional_cash = int(additional_cash)
        except ValueError:
            return ERROR_MUST_PROVIDE_NUMBER, 403

        if additional_cash < 0:
            return ERROR_CASH_RANGE, 403

    if password:
        # Ensure confirmation was submitted.
        if not repeat_password:
            return ERROR_MUST_REPEAT_PASSWORD, 403
        # Ensure password and reapeat-password are equals.
        if password != repeat_password:
            return ERROR_NOT_EQUAL_PASSWORD, 403

    return None, None
