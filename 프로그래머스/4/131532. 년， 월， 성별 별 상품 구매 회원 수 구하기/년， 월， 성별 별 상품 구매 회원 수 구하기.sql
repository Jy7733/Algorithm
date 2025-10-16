-- 년 / 월 / 성별 별로 상품을 구매한 회원수 
-- 년 / 월 / 성별 오름차순
-- 성별정보가 없으면 제외 
SELECT
year(sale.sales_date) as year,
month(sale.sales_date) as month,
gender,
count(distinct users.user_id) as users
from user_info users
join online_sale sale on users.user_id = sale.user_id 
where users.gender is not null
group by year(sale.sales_date), month(sale.sales_date), gender
order by year, month, gender
