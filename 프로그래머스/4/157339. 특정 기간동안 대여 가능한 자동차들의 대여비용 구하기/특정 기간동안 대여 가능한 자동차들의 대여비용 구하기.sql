WITH able AS (
    SELECT c.car_id, c.car_type, c.daily_fee
    FROM car_rental_company_car c
    WHERE c.car_type IN ('세단', 'SUV')
    AND NOT EXISTS (
        SELECT 1
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY h
        WHERE h.car_id = c.car_id
        AND h.start_date <= '2022-11-30'
        AND h.end_date >= '2022-11-01'
    )
)

SELECT
    a.car_id, 
    a.car_type,
    ROUND((a.daily_fee*30*(100-p.discount_rate)/100),0) AS fee
FROM CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
JOIN able a 
    ON a.car_type = p.car_type
WHERE duration_type = '30일 이상'
AND ROUND((a.daily_fee*30*(100-p.discount_rate)/100),0)
    BETWEEN 500000 AND 2000000
ORDER BY fee DESC;