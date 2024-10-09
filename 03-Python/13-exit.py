import sys

def main():
    if len(sys.argv) != 2:
        print("Faltan argumentos en la línea de comandos.")
        sys.exit(1)

    print(f"¡Hola {sys.argv[1]}!")
    exit(0)


if __name__ == "__main__":
    main()
