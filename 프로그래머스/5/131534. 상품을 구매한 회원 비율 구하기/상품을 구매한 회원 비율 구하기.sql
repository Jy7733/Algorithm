SELECT
    YEAR(os.sales_date) AS year,
    MONTH(os.sales_date) AS month,
    COUNT(DISTINCT os.user_id) AS purchased_users,
    ROUND(
        COUNT(DISTINCT os.user_id) / 
        (SELECT COUNT(*) FROM user_info WHERE YEAR(joined) = 2021),
        1
    ) AS purchased_ratio
FROM online_sale os
JOIN user_info u ON os.user_id = u.user_id
WHERE YEAR(u.joined) = 2021
GROUP BY YEAR(os.sales_date), MONTH(os.sales_date)
ORDER BY year, month;
