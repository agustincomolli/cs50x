from cs50 import SQL
from flask import Flask, redirect, render_template, request

if __name__ == "__main__":
    # Ejecuta la aplicación Flask en modo de depuración.
    app.run(debug=True)

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = ["Football",
          "Basketball",
          "Volleyball"]

# users = {}


@app.route("/")
def index():
    # Renderiza el template 'index.html' pasándole como parámetro la lista de deportes válida.
    return render_template("index.html", sports=SPORTS)


@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    # Si no hay ningún valor en el campo nombre...
    if not name:
        return render_template("failure.html", message="No escribiste tu nombre")

    sport = request.form.get("sport")
    # Si no hay un deporte válido seleccionado...
    if not sport in SPORTS:
        return render_template("failure.html", message="No hay un deporte válido seleccionado")

    # Guardar los datos del inscripto.
    # users[name] = sport
    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name, sport)
    # Mostrar la página con todos los inscriptos.
    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    users = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", users=users)


@app.route("/deregister", methods=["POST"])
def deregister():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM registrants WHERE id = ?", id)

    return redirect("/registrants")
