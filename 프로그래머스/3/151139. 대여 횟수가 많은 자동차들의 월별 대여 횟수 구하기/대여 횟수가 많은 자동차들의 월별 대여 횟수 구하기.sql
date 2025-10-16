-- 코드를 입력하세요
-- 2022년 8월 ~ 2022년 10월 - 총 대여 횟수가 5회 이상인 자동차 중 
    -- 월별 + 자동차id별 총 대여 횟수 
-- order by 월, 자동차id desc
SELECT
month(start_date) as month, 
car_id, 
count(car_id) as records 
from CAR_RENTAL_COMPANY_RENTAL_HISTORY


where car_id in 
-- 대여횟수가 5회 이상
(
    select car_id
    from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between '2022-08-01' and '2022-10-31'
    group by car_id
    having(count(car_id) >= 5)
)
and 
start_date between '2022-08-01' and '2022-10-31 '
group by month(start_date), car_id
order by month, car_id desc;