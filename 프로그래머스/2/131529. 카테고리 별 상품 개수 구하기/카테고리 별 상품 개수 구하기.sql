-- 상품 카테고리 코드(앞 2자리) 별 상품 개수 출력
-- order by 코드 
SELECT
substr(product_code,1,2) as category,
count(*) as products
from 
product 
group by category
order by category 
