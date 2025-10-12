SELECT
    car.car_id,
    car.car_type,
    ROUND((car.daily_fee * (100 - plan.discount_rate) / 100) * 30) AS fee
FROM CAR_RENTAL_COMPANY_CAR car
JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN plan 
    ON car.car_type = plan.car_type
WHERE car.car_type IN ('세단', 'SUV')
  AND plan.duration_type = '30일 이상'
  AND car.car_id NOT IN (
        SELECT car_id
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE NOT (
            end_date < '2022-11-01' OR start_date > '2022-11-30'
        )
    )
  AND (car.daily_fee * (100 - plan.discount_rate) / 100) * 30 BETWEEN 500000 AND 1999999
ORDER BY fee DESC, car.car_type ASC, car.car_id DESC;
