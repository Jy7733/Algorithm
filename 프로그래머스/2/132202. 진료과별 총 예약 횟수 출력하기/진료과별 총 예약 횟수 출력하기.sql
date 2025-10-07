-- 코드를 입력하세요
SELECT

-- 2022년 5월 예약환자 수 
MCDP_CD AS '진료과코드',
COUNT(*) AS '5월예약건수'
FROM APPOINTMENT

WHERE YEAR(APNT_YMD) = 2022 AND MONTH(APNT_YMD) = 5

-- 진료과코드 별 
GROUP BY MCDP_CD 
ORDER BY 5월예약건수, 진료과코드;