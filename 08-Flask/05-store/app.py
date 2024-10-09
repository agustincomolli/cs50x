from cs50 import SQL
from flask import Flask, redirect, render_template, request, session
from flask_session import Session


# Configurar la app.
app = Flask("__name__")

# Configurar la sesión.
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Conectar la base de datos.
db = SQL("sqlite:///books.db")

@app.route("/")
def index():
    # Devolver una lista de diccionarios con los datos de los libros.
    books = db.execute("SELECT * FROM books;")
    return render_template("index.html", books=books)


@app.route("/cart", methods=["GET", "POST"])
def cart():
    # Si no hay un carrito de compras en la sesión, crearlo.
    if "cart" not in session:
        session["cart"] = []

    # POST
    if request.method == "POST":
        book_id = request.form.get("id")
        if book_id:
            session["cart"].append(book_id)
        return redirect("/cart")

    # GET
    books = db.execute("SELECT * FROM books WHERE id IN (?)", session["cart"])
    return render_template("cart.html", books=books)


def main():
    app.run(debug=True)


if __name__ == "__main__":
    main()
