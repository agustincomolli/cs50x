from cs50 import SQL
from flask import Flask, redirect, render_template, request


# Configurar la aplicación.
app = Flask("__name__")

# Conectar la base de datos.
db = SQL("sqlite:///shows.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    query = request.args.get("q")
    if query:
        # Buscar títulos que contengan 'query' en cualquier posición.
        # %: Comodín SQL que representa cualquier número de caracteres (incluyendo ninguno).
        shows = db.execute("SELECT * FROM shows WHERE title LIKE ? ORDER BY year LIMIT 50", f"%{query}%")
    else:
        shows = []
    return render_template("search.html", shows=shows)


def main():
    app.run(debug=True)


if __name__ == "__main__":
    main()
