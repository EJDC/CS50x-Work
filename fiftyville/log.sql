-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';

SELECT name, phone_number, passport_number, license_plate
FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE year = 2021
  AND month = 7
  AND day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';

SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;

SELECT  name, phone_number, passport_number, license_plate, amount
FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60 ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2021
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw';

SELECT  name, phone_number, passport_number, license_plate, amount
FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2021
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw'
  AND duration < 60;

SELECT  name, phone_number, license_plate, amount, origin_airport_id, destination_airport_id
FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports originair ON flights.origin_airport_id = airports.id
JOIN airports destair ON flights.destination_airport_id = airports.id
WHERE atm_transactions.year = 2021
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw'
  AND duration < 60;

SELECT  name, phone_number, bakery_security_logs.license_plate, amount, originair.full_name as origin_airport, destair.full_name as destination_airport
FROM atm_transactions
JOIN bank_accounts ON bank_accounts.account_number = atm_transactions.account_number
JOIN people ON bank_accounts.person_id = people.id
JOIN phone_calls ON people.phone_number = phone_calls.caller
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON passengers.flight_id = flights.id
JOIN airports originair ON flights.origin_airport_id = originair.id
JOIN airports destair ON flights.destination_airport_id = destair.id
JOIN bakery_security_logs ON people.license_plate = bakery_security_logs.licence_plate
WHERE atm_transactions.year = 2021
  AND atm_transactions.month = 7
  AND atm_transactions.day = 28
  AND atm_location = 'Leggett Street'
  AND transaction_type = 'withdraw'
  AND duration < 60
  AND origin_airport = 'Fiftyville Regional Airport';

SELECT name, bakery_security_logs.hour, bakery_security_logs.minute
  FROM people
  JOIN bakery_security_logs
    ON people.license_plate = bakery_security_logs.license_plate
 WHERE bakery_security_logs.year = 2021
   AND bakery_security_logs.month = 7
   AND bakery_security_logs.day = 28
   AND bakery_security_logs.activity = 'exit'
   AND bakery_security_logs.hour = 10
   AND bakery_security_logs.minute >= 15
   AND bakery_security_logs.minute <= 25
 ORDER BY bakery_security_logs.minute;

SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.receiver
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
   ORDER BY phone_calls.duration;

SELECT name, phone_calls.duration
  FROM people
  JOIN phone_calls
    ON people.phone_number = phone_calls.caller
 WHERE phone_calls.year = 2021
   AND phone_calls.month = 7
   AND phone_calls.day = 28
   AND phone_calls.duration <= 60
