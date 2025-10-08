-- 코드를 입력하세요
SELECT
rs.USER_ID,
rs.NICKNAME,
rs.TOTAL_SALES
-- 완료된 중고 거래 총금액이 70만원 이상
from 
    (select 
        gu.USER_ID as USER_ID, 
        gu.NICKNAME as NICKNAME, 
        sum(gb.PRICE) as TOTAL_SALES
    from USED_GOODS_BOARD gb 
        JOIN USED_GOODS_USER gu ON gb.WRITER_ID = gu.USER_ID
    where gb.STATUS = 'DONE'
    group by gu.USER_ID) as rs 
where rs.TOTAL_SALES >= 700000
order by TOTAL_SALES; 