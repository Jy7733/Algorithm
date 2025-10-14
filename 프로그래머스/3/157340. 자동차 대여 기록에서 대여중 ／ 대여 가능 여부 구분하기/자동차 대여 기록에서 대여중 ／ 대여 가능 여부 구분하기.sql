-- 2022년 10월 16일에 대여 중인 자동차 -> 대여중 
-- 대여중이지 않은 자동차 -> 대여 가능 

SELECT
car_id, 
MAX(CASE
        WHEN '2022-10-16' BETWEEN START_DATE AND END_DATE
       THEN '대여중'
       ELSE '대여 가능'
        END) AS AVAILABILITY

from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by car_id desc; 
