-- 코드를 입력하세요
SELECT
YEAR(os.SALES_DATE) as YEAR,
MONTH(os.SALES_DATE) as MONTH,
ui.GENDER,
COUNT(DISTINCT ui.USER_ID) AS USERS 

from USER_INFO ui 
    JOIN ONLINE_SALE os ON ui.USER_ID = os.USER_ID 
where GENDER is not null and os.SALES_AMOUNT > 0
group by YEAR(os.SALES_DATE), MONTH(os.SALES_DATE), ui.GENDER 

-- Order by 년 - 월 - 성별 
order by YEAR, MONTH, ui.GENDER;