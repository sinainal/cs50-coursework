-- Keep a log of any SQL queries you execute as you solve the mystery.
#
select name from people where license_plate in(select license_plate from bakery_security_logs where day = 28 and month = 7 and minute > 14 and minute < 25 and activity = 'exit'); #parking
#
select name from people where id in(select person_id from bank_accounts where account_number in(select account_number from atm_transactions where atm_location = 'Leggett Street' and day = 28 and month = 7)); #atm
#
select name from people where phone_number in(select caller from phone_calls where month = 7 and day = 28); #phone

###
select name from people where (license_plate in(select license_plate from bakery_security_logs where day = 28 and month = 7 and minute > 14 and minute < 26 and hour > 9 and activity = 'exit')and id in(select person_id from bank_accounts where account_number in(select account_number from atm_transactions where day = 28 and month = 7 and atm_location = 'Leggett Street'))and phone_number in(select caller from phone_calls where month = 7 and day = 28));

alt
select name from people where id in(select person_id from bank_accounts where account_number in(select account_number from atm_transactions where atm_location = 'Leggett Street' and day = 28 and month = 7)) and phone_number in(select caller from phone_calls where month = 7 and day = 28));


şüpheli:
+-------+
| Diana |
| Bruce |
+-------+

flight id : 36

suçlu = Bruce !!!

yardımcı_numara = '(375) 555-8161'
'
yRDIMCI = Robin

destination no = 4

_New York City
