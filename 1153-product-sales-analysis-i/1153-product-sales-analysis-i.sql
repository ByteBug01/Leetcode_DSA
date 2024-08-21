# Write your MySQL query statement below
select a.product_name, b.year, b.price
from sales b
join
Product a
where a.product_id = b.product_id;