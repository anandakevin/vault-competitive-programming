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

select pt1.stock_code
from price_today pt1,
        price_tomorrow pt2
        where pt1.stock_code = pt2.stock_code
        and pt2.price > pt1.price
order by pt1.stock_code
;
exit;