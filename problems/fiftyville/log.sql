-- Keep a log of any SQL queries you execute as you solve the mystery.
/*
Comprobar las descripciones de los informes de escenas de crimen en la fecha y
lugar correspondientes.
 */
SELECT
    crime_scene_reports.description
FROM
    crime_scene_reports
WHERE
    crime_scene_reports.year = 2023
    AND crime_scene_reports.month = 7
    AND crime_scene_reports.day = 28
    AND crime_scene_reports.street = 'Humphrey Street';

/*
Comprobar las entrevistas de los testigos en los que se menciona la panadería.
 */
SELECT
    interviews.transcript
FROM
    interviews
WHERE
    interviews.year = 2023
    AND interviews.month = 7
    AND interviews.day = 28;

/*
Comprobar el registro de las cámaras de seguridad de la panadería para ver
los vehículos que salieron en los 10 minutos del robo y a quien pertenecen.
 */
SELECT
    bakery_security_logs.hour,
    bakery_security_logs.minute,
    bakery_security_logs.license_plate,
    people.name
FROM
    bakery_security_logs
    JOIN people ON bakery_security_logs.license_plate = people.license_plate
WHERE
    bakery_security_logs.activity = 'exit'
    AND bakery_security_logs.year = 2023
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute BETWEEN 10 AND 25;

/*
Obtener la primera lista de sospechosos.
 */
SELECT
    people.name AS 'suspect'
FROM
    people
    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
WHERE
    bakery_security_logs.activity = 'exit'
    AND bakery_security_logs.year = 2023
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute BETWEEN 10 AND 25;

/*
Comprobar las personas que sacaron dinero del cajero automático de la
calle Leggett Street el día del robo.
 */
SELECT
    people.name,
    atm_transactions.amount
FROM
    people
    JOIN bank_accounts ON people.id = bank_accounts.person_id
    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE
    atm_transactions.year = 2023
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw';

/*
Obtener una segunda lista de sospechosos comparando los nombres de las personas
que salieron del estacionamiento en los 10 minutos del robo con los nombres de las
personas que extrajeron dinero del cajero de la calle Leggett.
 */
SELECT
    first_list_suspects.name AS 'suspect'
FROM
    (
        SELECT
            people.name
        FROM
            people
            JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
        WHERE
            bakery_security_logs.activity = 'exit'
            AND bakery_security_logs.year = 2023
            AND bakery_security_logs.month = 7
            AND bakery_security_logs.day = 28
            AND bakery_security_logs.hour = 10
            AND bakery_security_logs.minute BETWEEN 10 AND 25
    ) AS first_list_suspects
    INNER JOIN (
        SELECT
            people.name,
            atm_transactions.amount
        FROM
            people
            JOIN bank_accounts ON people.id = bank_accounts.person_id
            JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
        WHERE
            atm_transactions.year = 2023
            AND atm_transactions.month = 7
            AND atm_transactions.day = 28
            AND atm_transactions.atm_location = 'Leggett Street'
            AND atm_transactions.transaction_type = 'withdraw'
    ) AS second_list_suspects ON first_list_suspects.name = second_list_suspects.name;

/*
Comprobar las llamadas telefónicas del día del robo y que hayan durado menos
de un minuto.
 */
SELECT
    callers.name AS 'caller',
    receivers.name AS 'receiver',
    phone_calls.duration
FROM
    phone_calls
    JOIN people AS callers ON callers.phone_number = phone_calls.caller
    JOIN people AS receivers ON receivers.phone_number = phone_calls.receiver
WHERE
    phone_calls.year = 2023
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND phone_calls.duration < 60;

/*
Obtener la tercer lista de sospechosos comparando la última lista de
sospechosos con las personas que realizaron llamadas de menos de un
minuto el día del robo.
 */
SELECT
    third_list_suspects.name AS 'suspect'
FROM
    (
        SELECT
            first_list_suspects.name
        FROM
            (
                SELECT
                    people.name
                FROM
                    people
                    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
                WHERE
                    bakery_security_logs.activity = 'exit'
                    AND bakery_security_logs.year = 2023
                    AND bakery_security_logs.month = 7
                    AND bakery_security_logs.day = 28
                    AND bakery_security_logs.hour = 10
                    AND bakery_security_logs.minute BETWEEN 10 AND 25
            ) AS first_list_suspects
            INNER JOIN (
                SELECT
                    people.name,
                    atm_transactions.amount
                FROM
                    people
                    JOIN bank_accounts ON people.id = bank_accounts.person_id
                    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                WHERE
                    atm_transactions.year = 2023
                    AND atm_transactions.month = 7
                    AND atm_transactions.day = 28
                    AND atm_transactions.atm_location = 'Leggett Street'
                    AND atm_transactions.transaction_type = 'withdraw'
            ) AS second_list_suspects ON first_list_suspects.name = second_list_suspects.name
    ) AS third_list_suspects
    INNER JOIN (
        SELECT
            callers.name AS 'caller',
            receivers.name AS 'receiver',
            phone_calls.duration
        FROM
            phone_calls
            JOIN people AS callers ON callers.phone_number = phone_calls.caller
            JOIN people AS receivers ON receivers.phone_number = phone_calls.receiver
        WHERE
            phone_calls.year = 2023
            AND phone_calls.month = 7
            AND phone_calls.day = 28
            AND phone_calls.duration < 60
    ) AS fourth_list_suspects ON third_list_suspects.name = fourth_list_suspects.caller;

/*
Comprobar los nombres de las personas que tomarán vuelos desde Fiftyville el día 29-07-2023
 */
SELECT
    people.name,
    origin.city AS 'origin',
    destination.city AS 'destination',
    flights.hour,
    flights.minute
FROM
    flights
    JOIN passengers ON flights.id = passengers.flight_id
    JOIN people ON passengers.passport_number = people.passport_number
    JOIN airports AS origin ON flights.origin_airport_id = origin.id
    JOIN airports AS destination ON flights.destination_airport_id = destination.id
WHERE
    origin.city = 'Fiftyville'
    AND flights.year = 2023
    AND flights.month = 7
    AND flights.day = 29
ORDER BY
    flights.hour ASC
LIMIT
    1;

/*
Comprobar el ladrón comparando la última lista de sospechosos
con las personas que tomaron vuelos desde Fiftyville el 29-07-2023.
Elegir el sospechoso que toma el primer vuelo de la mañana.
 */
SELECT
    last_lists_suspects.name AS 'thief',
    travellers.city AS 'destination'
FROM
    (
        SELECT
            third_list_suspects.name
        FROM
            (
                SELECT
                    first_list_suspects.name
                FROM
                    (
                        SELECT
                            people.name
                        FROM
                            people
                            JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
                        WHERE
                            bakery_security_logs.activity = 'exit'
                            AND bakery_security_logs.year = 2023
                            AND bakery_security_logs.month = 7
                            AND bakery_security_logs.day = 28
                            AND bakery_security_logs.hour = 10
                            AND bakery_security_logs.minute BETWEEN 10 AND 25
                    ) AS first_list_suspects
                    INNER JOIN (
                        SELECT
                            people.name,
                            atm_transactions.amount
                        FROM
                            people
                            JOIN bank_accounts ON people.id = bank_accounts.person_id
                            JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                        WHERE
                            atm_transactions.year = 2023
                            AND atm_transactions.month = 7
                            AND atm_transactions.day = 28
                            AND atm_transactions.atm_location = 'Leggett Street'
                            AND atm_transactions.transaction_type = 'withdraw'
                    ) AS second_list_suspects ON first_list_suspects.name = second_list_suspects.name
            ) AS third_list_suspects
            INNER JOIN (
                SELECT
                    callers.name AS 'caller',
                    receivers.name AS 'receiver',
                    phone_calls.duration
                FROM
                    phone_calls
                    JOIN people AS callers ON callers.phone_number = phone_calls.caller
                    JOIN people AS receivers ON receivers.phone_number = phone_calls.receiver
                WHERE
                    phone_calls.year = 2023
                    AND phone_calls.month = 7
                    AND phone_calls.day = 28
                    AND phone_calls.duration < 60
            ) AS fourth_list_suspects ON third_list_suspects.name = fourth_list_suspects.caller
    ) AS last_lists_suspects
    INNER JOIN (
        SELECT
            people.name,
            flights.hour,
            destination.city
        FROM
            flights
            JOIN passengers ON flights.id = passengers.flight_id
            JOIN people ON passengers.passport_number = people.passport_number
            JOIN airports AS origin ON flights.origin_airport_id = origin.id
            JOIN airports AS destination ON flights.destination_airport_id = destination.id
        WHERE
            origin.city = 'Fiftyville'
            AND flights.year = 2023
            AND flights.month = 7
            AND flights.day = 29
    ) AS travellers ON last_lists_suspects.name = travellers.name
ORDER BY
    travellers.hour ASC
LIMIT
    1;

/*
Buscar el cómplice del ladrón filtrando el registro de llamadas para ver
quién es el receptor de la llamada realizada el 28-07-2023 de menos de un
minuto.
 */
SELECT
    data_thief.thief,
    data_thief.destination,
    phone_calls_record.receiver AS 'accomplice'
FROM
    (
        SELECT
            last_lists_suspects.name AS 'thief',
            travellers.city AS 'destination'
        FROM
            (
                SELECT
                    third_list_suspects.name
                FROM
                    (
                        SELECT
                            first_list_suspects.name
                        FROM
                            (
                                SELECT
                                    people.name
                                FROM
                                    people
                                    JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.license_plate
                                WHERE
                                    bakery_security_logs.activity = 'exit'
                                    AND bakery_security_logs.year = 2023
                                    AND bakery_security_logs.month = 7
                                    AND bakery_security_logs.day = 28
                                    AND bakery_security_logs.hour = 10
                                    AND bakery_security_logs.minute BETWEEN 10 AND 25
                            ) AS first_list_suspects
                            INNER JOIN (
                                SELECT
                                    people.name,
                                    atm_transactions.amount
                                FROM
                                    people
                                    JOIN bank_accounts ON people.id = bank_accounts.person_id
                                    JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
                                WHERE
                                    atm_transactions.year = 2023
                                    AND atm_transactions.month = 7
                                    AND atm_transactions.day = 28
                                    AND atm_transactions.atm_location = 'Leggett Street'
                                    AND atm_transactions.transaction_type = 'withdraw'
                            ) AS second_list_suspects ON first_list_suspects.name = second_list_suspects.name
                    ) AS third_list_suspects
                    INNER JOIN (
                        SELECT
                            callers.name AS 'caller',
                            receivers.name AS 'receiver',
                            phone_calls.duration
                        FROM
                            phone_calls
                            JOIN people AS callers ON callers.phone_number = phone_calls.caller
                            JOIN people AS receivers ON receivers.phone_number = phone_calls.receiver
                        WHERE
                            phone_calls.year = 2023
                            AND phone_calls.month = 7
                            AND phone_calls.day = 28
                            AND phone_calls.duration < 60
                    ) AS fourth_list_suspects ON third_list_suspects.name = fourth_list_suspects.caller
            ) AS last_lists_suspects
            INNER JOIN (
                SELECT
                    people.name,
                    flights.hour,
                    destination.city
                FROM
                    flights
                    JOIN passengers ON flights.id = passengers.flight_id
                    JOIN people ON passengers.passport_number = people.passport_number
                    JOIN airports AS origin ON flights.origin_airport_id = origin.id
                    JOIN airports AS destination ON flights.destination_airport_id = destination.id
                WHERE
                    origin.city = 'Fiftyville'
                    AND flights.year = 2023
                    AND flights.month = 7
                    AND flights.day = 29
            ) AS travellers ON last_lists_suspects.name = travellers.name
        ORDER BY
            travellers.hour ASC
        LIMIT
            1
    ) AS data_thief
    INNER JOIN (
        SELECT
            callers.name AS 'caller',
            receivers.name AS 'receiver',
            phone_calls.duration
        FROM
            phone_calls
            JOIN people AS callers ON callers.phone_number = phone_calls.caller
            JOIN people AS receivers ON receivers.phone_number = phone_calls.receiver
        WHERE
            phone_calls.year = 2023
            AND phone_calls.month = 7
            AND phone_calls.day = 28
            AND phone_calls.duration < 60
    ) AS phone_calls_record ON phone_calls_record.caller = data_thief.thief;
