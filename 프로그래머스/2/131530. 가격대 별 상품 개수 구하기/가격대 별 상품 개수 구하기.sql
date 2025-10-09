-- 코드를 입력하세요
SELECT
FLOOR(PRICE/10000)*10000 AS PRICE_GROUP,
COUNT(*) AS PRODUCTS
-- 만원 단위 가격대 별로 상품 개수를 출력
from product
group by price_group
order by price_group;