SET NULL "NULL";
SET FEEDBACK OFF;
SET ECHO OFF;
SET HEADING OFF;
SET WRAP OFF;
SET LINESIZE 10000;
SET TAB OFF;
SET PAGES 0;
SET DEFINE OFF;
SET SERVEROUTPUT ON;

/*
Enter your query below.
Please append a semicolon ";" at the end of the query
*/
select c.customer_id,
        c.name,
        '+' || cc.country_code || c.phone_number
from customers c,
    country_codes cc
where c.country = cc.country
order by c.customer_id;

exit;