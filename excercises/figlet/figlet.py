import sys
from pyfiglet import Figlet


def main():
    figlet = Figlet()
    font = ""
    fonts = figlet.getFonts()
    is_args_ok = False

    if len(sys.argv) == 3:
        if sys.argv[1] == "-f" or sys.argv[1] == "--font":
            font = sys.argv[2]
            if font in fonts:
                is_args_ok = True
    elif len(sys.argv) == 1:
        font = random.choice(fonts)
        is_args_ok = True

    if is_args_ok:
        text = input("Entrada: ")
        figlet.setFont(font=font)
        print(f"Salida:\n{figlet.renderText(text)}")
    else:
        print(f"Uso: {sys.argv[0]}")
        print(f"Uso: {sys.argv[0]} -f 'fuente'")
        print(f"Uso: {sys.argv[0]} --font 'fuente'")
        exit(1)


if __name__ == "__main__":
    main()
