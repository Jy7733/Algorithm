-- 코드를 입력하세요


SELECT
year(os.sales_date) as year,
month(os.sales_date) as month,
count(distinct os.user_id) as purchased_users,
round(
    count(distinct os.user_id)/
    (select count(*) from user_info where year(joined) = '2021'),
    1
) as purchased_ratio
from
(select user_id from user_info where year(joined) = '2021') u
join online_sale os on u.user_id = os.user_id 
group by year(os.sales_date), month(os.sales_date)
order by year, month