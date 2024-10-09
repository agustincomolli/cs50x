def draw_wall(rows: int = 1, cols: int = 1):
    """
    Dibuja una pared de cuadrados rojos.

    Args:
        rows (int, opcional): El número de fijas en la pared. Por defecto es 1.
        cols (int, opcional): El número de columnas. Por defecto es 1.
    """
    for i in range(rows):
        print("🟥 " * cols)


def input_number(message: str) -> int:
    """
    Solicita al usuario que ingrese un número entero mayor a 0.

    Args:
        message (str): El mensaje que se mostrá al usuario al solicitar un número.

    Returns:
        int: El número ingresado por el usuario.
    """
    while True:
        try:
            number = int(input(message))
            if number > 0:
                break
        except ValueError:
            pass
    return number


def main():
    height = input_number("Altura: ")
    width = input_number("Ancho: ")

    draw_wall(height, width)


if __name__ == "__main__":
    main()
