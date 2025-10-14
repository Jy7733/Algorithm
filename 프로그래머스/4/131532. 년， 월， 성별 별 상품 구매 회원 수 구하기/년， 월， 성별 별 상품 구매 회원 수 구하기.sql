-- 코드를 입력하세요
-- 년 / 월 / 성별 별로 상품을 구매한 회원 수 
-- order by 년 -> 월 > 성별 asc 
-- 성별 정보가 없으면 제외 ㅇ
SELECT
year(os.sales_date) as year,
month(os.sales_date) as month, 
users.gender, 
count(distinct users.user_id) as users
from 

(select user_id, gender from user_info where gender is not null) users
join
online_sale os on users.user_id = os.user_id 

group by year(os.sales_date), month(os.sales_date), users.gender
order by year, month, gender 
