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
 
select t1.*
from (select co.country_name,
            count(*) ttl, -- total invoice
            to_char(avg(i.total_price), 'FM99999999999.000000') avg_amt-- avg amount
    from country co,
        city ci,
        customer cu,
        invoice i
    where i.customer_id = cu.id
    and cu.city_id = ci.id
    and ci.country_id = co.id
    group by co.country_name) t1,
    (select avg(i2.total_price) avg_all from invoice i2) t2
where t1.avg_amt > t2.avg_all --their avg invoice > avg all invoice
;

exit;