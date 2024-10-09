QUARTER = 25
DIME = 10
NICKEL = 5
PENNY = 1


def main():
    print("*** Calculador de cambio 🪙 ***\n")

    change = input_number("Cambio adeudado: ")
    change *= 100
    cents = 0

    # Cantidad de monedas de 25 centavos.
    cents += change // QUARTER
    change %= QUARTER

    # Cantidad de monedas de 10 centavos.
    cents += change // DIME
    change %= DIME

    # Cantidad de monedas de 5 centavos.
    cents += change // NICKEL
    change %= NICKEL

    # Cantidad de monedas de 1 centavo.
    cents += change // PENNY

    print("Devolver al cliente: ")
    print(cents)


def input_number(message: str) -> float:
    """
    Solicita al usuario que ingrese un número mayor o igual a 0.01

    Args:
        message (str): Mensaje que se mostrará al usuario.

    Returns:
        float: El número en formato decimal, ingresado por el usuario.
    """

    MINIMUM = 0.01
    while True:
        try:
            number = float(input(message))
            if number >= MINIMUM:
                break
        except ValueError:
            pass

    return number


if __name__ == "__main__":
    main()
