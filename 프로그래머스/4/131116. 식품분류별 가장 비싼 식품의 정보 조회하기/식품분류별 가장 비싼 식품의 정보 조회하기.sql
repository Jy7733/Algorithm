-- 식품분류별로 가격이 제일 비싼 식품의 분류 / 가격 / 이름
-- 
SELECT
category,
price as max_price, 
product_name 
from 
food_product 
where (category, price) in 
(select category, max(price) 
    from food_product
    where category in ('과자', '국', '김치', '식용유')
    group by category
)
order by max_price desc; 
