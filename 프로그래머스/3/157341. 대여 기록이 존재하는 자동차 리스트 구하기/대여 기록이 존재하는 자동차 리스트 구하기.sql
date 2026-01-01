-- 세단 중 / 10월에 대여를 시작한 기록이 있는 ID 리스트  
-- ID중복 x, 내림차순
SELECT
distinct car.car_id
from 
(select car_id from car_rental_company_car where car_type = '세단') as car
inner join 
(select car_id from car_rental_company_rental_history 
 where start_date between '2022-10-01' and '2022-10-31') as his
 on car.car_id = his.car_id 
order by car.car_id desc