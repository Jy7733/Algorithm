-- 코드를 입력하세요
with val as(
    select 
    c.car_id, c.car_type, c.daily_fee, h.history_id, datediff(h.end_date, h.start_date)+1 as period,
    CASE 
        WHEN DATEDIFF(h.end_date, h.start_date) + 1 < 7 THEN NULL
        WHEN DATEDIFF(h.end_date, h.start_date) + 1 < 30 THEN '7일 이상'
        WHEN DATEDIFF(h.end_date, h.start_date) + 1 < 90 THEN '30일 이상'
        ELSE '90일 이상'
    END as duration_type
    from CAR_RENTAL_COMPANY_CAR c join CAR_RENTAL_COMPANY_RENTAL_HISTORY h on c.car_id = h.car_id
    where c.car_type = '트럭'
)

select val.history_id,
round(val.daily_fee * val.period* (100-ifnull(p.discount_rate,0))/100) as fee 
from val
left join car_rental_company_discount_plan p on p.duration_type = val.duration_type
and p.car_type = val.car_type
order by fee desc, val.history_id desc