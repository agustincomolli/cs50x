"""
    This program implemented the functions of updating and deleting birthdays.
    To update birthdays I have created a separate file called update.html.
    Since I can't upload via submit50; I leave the code of said file in comments
    below the index.html file.

 """

import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    """
    Maneja la ruta principal de la aplicación, permitiendo tanto la visualización como la inserción de registros de cumpleaños.

    Si el método de la solicitud es POST, se recuperan los datos del formulario, se validan y se insertan en la base de datos.
    Si el método es GET, se recuperan todos los registros de la base de datos y se renderiza la página principal con estos datos.

    Returns:
        Response: Redirige a la página principal después de insertar un registro o renderiza la página principal con los registros de cumpleaños.
    """
    if request.method == "POST":
        # Recuperar los valores del formulario
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Alternativamente, recuperar en forma de diccionario:
        # data = request.form.to_dict()

        # Verificar si los datos del formulario son válidos
        if not is_valid_data(name, month, day):
            return redirect("/")

        # Para depuración, mostrar los datos del formulario en la consola.
        # print("\n\n", f"name: {name} - month: {month} - day: {day}", "\n\n")

        # Insertar los datos en la base de datos
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?);",
                   name, month, day)

        # Redirigir a la página principal después de la inserción
        return redirect("/")

    else:
        # Recuperar todos los registros de cumpleaños de la base de datos
        birthdays = db.execute("SELECT * FROM birthdays;")

        # print("\n\n", birthdays, "\n\n")

        # Renderizar la página principal con los registros de cumpleaños
        return render_template("index.html", birthdays=birthdays)


@app.route("/update", methods=["GET", "POST"])
def update():
    """
    Maneja la actualización de registros de cumpleaños en la base de datos.

    Si el método de la solicitud es GET, se obtiene el id del registro a actualizar y se renderiza el formulario
    con los datos actuales. Si el método es POST, se procesan los datos del formulario y se actualiza el registro
    en la base de datos.

    Returns:
        Response: Renderiza la plantilla de actualización o redirige a la página principal.
    """
    if request.method == "GET":
        # Obtener el id del registro a actualizar desde los parámetros de la URL
        id = request.args.get("id")
        if id:
            # Obtener los datos del registro de cumpleaños correspondiente
            birthday = db.execute("SELECT * FROM birthdays WHERE id = ?", id)
            # Renderizar la plantilla de actualización con los datos del cumpleaños
            return render_template("update.html", birthday=birthday[0])
        # Redirigir a la página principal si no se proporciona id
        return redirect("/")
    else:
        # Obtener los datos del formulario
        id = request.form.get("id")
        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        # Verificar si los datos del formulario son válidos
        if not is_valid_data(name, month, day):
            # Redirigir a la página principal si los datos no son válidos
            return redirect("/")

        # Actualizar el registro en la base de datos
        db.execute(
            "UPDATE birthdays SET name = ?, month = ?, day = ? WHERE id = ?",
            name, month, day, id
        )

        # Redirigir a la página principal después de actualizar el registro
        return redirect("/")


@app.route("/delete", methods=["POST"])
def delete():
    id = request.form.get("id")
    if id:
        db.execute("DELETE FROM birthdays WHERE id = ?", id)
    return redirect("/")


def main():
    app.run(debug=True)


def is_valid_data(name, month, day):
    """
    Verifica que los datos proporcionados sean válidos antes de agregarlos a la base de datos.

    Args:
        name (str): Nombre proporcionado por el usuario.
        month (str): Mes proporcionado por el usuario, esperado como cadena que se puede convertir a entero.
        day (str): Día proporcionado por el usuario, esperado como cadena que se puede convertir a entero.

    Returns:
        bool: True si los datos son válidos, False en caso contrario.

    """
    # Comprobar que haya datos en los campos del formulario.
    if not name or not month or not day:
        return False

    # Convertir los valores de los meses y día a números enteros.
    try:
        month = int(month)
        day = int(day)
    except ValueError:
        return False

    # Comprobar que los rangos de valores para los días y los meses sean correctos
    if not (month >= 1 and month <= 12) or not (day >= 1 and day <= 31):
        return False

    # Si todo está bien...
    return True


if __name__ == "__main__":
    main()
