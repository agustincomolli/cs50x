from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)
# Cookie de sesión: al cerrar el navegador se cierra la sesión.
app.config["SESSION_PERMANENT"] = False
# Almacenar los datos de sesión en el servidor.
app.config["SESSION_TYPE"] = "filesystem"
# Crear la sesión para la aplicación.
Session(app)


@app.route("/")
def index():
    return render_template("index.html", name=session.get("name"))


@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["name"] = request.form.get("user-name")
        return redirect("/")
    return render_template("login.html")


@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")


def main():
    app.run(debug=True)


if __name__ == "__main__":
    main()
