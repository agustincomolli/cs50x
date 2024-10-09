# Mastercard usa números de 16 dígitos y comienzan en 51, 52, 53, 54 o 55
MASTERCARD_MAX_DIGITS = 5599999999999999
MASTERCARD_MIN_DIGITS = 5100000000000000
# American Express usa números de 15 dígitos y comienzan en 34 o 37
AMEX_MAX_DIGITS = 379999999999999
AMEX_MIN_DIGITS = 340000000000000
# VISA: Visa usa números de 13 y 16 dígitos y comienzan en 4
VISA_MAX_13_DIGITS = 4999999999999
VISA_MIN_13_DIGITS = 4000000000000
VISA_MAX_16_DIGITS = 4999999999999999
VISA_MIN_16_DIGITS = 4000000000000000


def main():
    print("*** 💳 Validador de tarjetas de crédito 💳 ***\n")
    credit_card_number = input_number("Número: ")
    answer = validate_credit_card(credit_card_number)
    print(answer)


def input_number(message: str) -> int:
    """
    Solicita al usuario que ingrese un número entero.

    Args:
        message (str): Mensaje que se mostrará al usuario para solicitar un número.

    Returns:
        int: El número ingresado por el usuario.
    """

    while True:
        # Intentar convertir el ingreso a número entero.
        try:
            number = int(input(message))
            # Si el valor es correcto salir del bucle.
            break
        except ValueError:
            pass
    return number


def validate_credit_card(number: int) -> str:
    # Comprobar la suma de verificación del número.
    if not checksum_ok(number):
        return "INVALID"

    # Comprueba que el número esté en el rango correcto.
    if number >= MASTERCARD_MIN_DIGITS and number <= MASTERCARD_MAX_DIGITS:
        return "MASTERCARD"
    elif number >= AMEX_MIN_DIGITS and number <= AMEX_MAX_DIGITS:
        # Verifica que el número comience de forma correcta a la tarjeta.
        is_start_with_34 = (number // 10**13) == 34
        is_start_with_37 = (number // 10**13) == 37
        if is_start_with_34 or is_start_with_37:
            return "AMEX"
    elif (number >= VISA_MIN_13_DIGITS and number <= VISA_MAX_13_DIGITS) or \
            (number >= VISA_MIN_16_DIGITS and number <= VISA_MAX_16_DIGITS):
        if (number // 1000000000000000 == 4 and len(str(number)) == 16) or \
                (number // 1000000000000 == 4 and len(str(number)) == 13):
            return "VISA"

    return "INVALID"


def checksum_ok(number: int) -> bool:
    module = 0
    second_digit = 0
    sum_first_digits = 0
    sum_second_digits = 0
    while number != 0:
        # Obtener los dos últimos dígitos de la tarjeta de crédito.
        module = number % 100
        # Obtener el primer dígito y sumarlo.
        sum_first_digits += module % 10
        # De esos dos últimos dígitos, obtener el de la izquierda.
        second_digit = module // 10
        second_digit *= 2

        # Sumar los dígitos de los productos.
        if second_digit >= 10:
            # Si el producto tiene dos dígitos separarlos y sumarlos.
            sum_second_digits += second_digit // 10
            sum_second_digits += second_digit % 10
        else:
            sum_second_digits += second_digit

        # Quitar los dos últimos números de la tarjeta de crédito.
        number //= 100

    # Si último número de las sumas es 0, el número es válido.
    if (sum_second_digits + sum_first_digits) % 10 == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    main()
