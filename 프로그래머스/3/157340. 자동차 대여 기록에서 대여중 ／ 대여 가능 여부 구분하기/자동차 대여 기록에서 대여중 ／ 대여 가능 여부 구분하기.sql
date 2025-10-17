-- 2022.10.16일에 대여 중 / 대여 가능 구분 
-- order by car_id  desc 
SELECT
car_id, 
max(case 
        when '2022-10-16' between start_date and end_date then '대여중'
        else '대여 가능'
    end) as availability 

from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by car_id desc; 
