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


# Coincidir con el method del formulario HTML
@app.route("/greet", methods=["POST"])
def greet():
    """
    Función para manejar la ruta /greet cuando se recibe una solicitud POST.
    Obtiene el nombre del usuario del formulario y lo renderiza en una plantilla HTML.

    Returns:
        Una plantilla HTML renderizada con el nombre del usuario.
    """
    # Obtener el nombre del usuario del formulario
    name = request.form.get("name")

    # Renderizar la plantilla "greet.html" con el nombre del usuario
    return render_template("greet.html", name=name)


if __name__ == "__main__":
    # Ejecuta la aplicación Flask en modo de depuración.
    app.run(debug=True)
