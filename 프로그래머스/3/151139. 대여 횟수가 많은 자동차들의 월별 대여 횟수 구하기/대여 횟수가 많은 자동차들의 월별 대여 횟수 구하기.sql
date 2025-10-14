-- 대여시작일 기준 (2022-08 ~ 2022-10까지 ) 총 대여 횟수가 5회 이상인 자동차 중 
        -- 해당 기간 동안의 월별, 자동차id별 총 대여 횟수 
        -- 특정 월의 총 대여횟수가 0이면 제외 
-- 월 오름차순, id 내림차순  

select
month(start_date) as month, 
car_id, 
count(*) as records
    from 
    CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where car_id in 
        (select car_id 
        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
        where year(start_date) = 2022
        and month(start_date) between 8 and 10 
         group by car_id
        having count(*) >= 5
        )
        and year(start_date) = 2022 and month(start_date) between 8 and 10 
group by month, car_id
order by month, car_id desc;
