-- 시작일 기준 2022.08 ~ 2022.10 까지 총 대여 횟수가 5회 이상인 자동차 중 
    -- 해당 기간 동안의 월별, ID별 총 대여횟수 
-- 월 기준 오름차순, id기준 내림차순 
SELECT
month(start_date) as month,
car_id,
count(car_id) as records

from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where start_date between '2022-08-01' and '2022-10-31'
and 
car_id in
(select car_id from CAR_RENTAL_COMPANY_RENTAL_HISTORY
    where start_date between '2022-08-01' and '2022-10-31' 
    group by car_id
    having count(*) >= 5
)
group by month(start_date), car_id 
order by month(start_date), car_id desc; 