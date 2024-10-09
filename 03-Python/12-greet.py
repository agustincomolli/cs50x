from sys import argv

def main():
    if len(argv) == 2:
        print(f"¡Hola {argv[1]}!")
    else:
        print(f"Usar {argv[0]} <tu nombre>")


if __name__ == "__main__":
    main()
