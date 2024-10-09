from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/")
def index():
    """
    Ruta principal de la aplicación que renderiza la página de inicio.

    Returns:
        str: El contenido HTML de la página de inicio.
    """
    # Renderiza el template 'index.html' sin pasarle ningún parámetro.
    return render_template("index.html")


@app.route("/greet")
def greet():
    """
    Ruta para saludar al usuario. Obtiene el nombre de los parámetros de la URL.

    Returns:
        str: El contenido HTML de la página de saludo con el nombre del usuario.
    """
    # Obtiene el parámetro 'name' de la URL, si no existe usa 'Flask' como valor por defecto.
    name = request.args.get("name", "Flask")
    # Renderiza el template 'greet.html' pasando el nombre como parámetro.
    return render_template("greet.html", name=name)


if __name__ == "__main__":
    # Ejecuta la aplicación Flask en modo de depuración.
    app.run(debug=True)
