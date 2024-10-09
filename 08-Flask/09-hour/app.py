from flask import Flask
from datetime import datetime
from pytz import timezone


app = Flask(__name__)


@app.route("/")
def index():
    now = datetime.now(timezone("America/Argentina/Buenos_Aires"))
    return f"La hora actual en Buenos Aires es: <strong>{now.strftime('%I:%M %p')}</strong>"


def main():
    app.run(debug=True)


if __name__ == "__main__":
    main()
