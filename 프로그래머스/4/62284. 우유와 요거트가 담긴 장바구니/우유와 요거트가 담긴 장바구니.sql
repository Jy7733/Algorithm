-- 코드를 입력하세요
select 
c.cart_id
from 
(SELECT
cart_id, group_concat(name) as names 
from cart_products
group by cart_id) as c
where c.names like '%Milk%' and c.names like '%Yogurt%' 
order by c.cart_id


