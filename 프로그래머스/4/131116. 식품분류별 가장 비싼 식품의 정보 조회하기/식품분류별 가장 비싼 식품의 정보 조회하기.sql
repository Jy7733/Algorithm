-- 코드를 입력하세요
-- 식품분류별 
    -- 가격이 제일 비싼 식품의 분류 / 가격 / 이름 조회
    -- 식품분류가 과자 / 국 / 김치 / 식용유인 경우만
-- order by 식품가격
SELECT
category,
price as max_price,
product_name
from food_product

where (price, category) in 
-- 식품분류별 가격이 제일 비싼 식품 
(
    select max(price) as price, category 
    from food_product 
    group by category 
    having category in ('과자', '국', '김치', '식용유')
)
order by max_price desc;