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
select ua.id,
        ua.first_name,
        ua.last_name,
        c.id,
        c.customer_name,
        count(*)
from customer c,
    user_account ua,
    contact co
where co.user_account_id = ua.id
    and co.customer_id = c.id
having count(*) > 1
group by ua.id,
        ua.first_name,
        ua.last_name,
        c.id,
        c.customer_name
order by c.id
;
exit;