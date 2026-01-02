-- 코드를 입력하세요
select 
info.user_id,
info.nickname,
info.address as '전체주소',
info.num as '전화번호'
from

(select 
user_id, 
nickname, 
concat(city,' ', STREET_ADDRESS1,' ',STREET_ADDRESS2) as address,
concat(
    substring(tlno, 1,3), '-',
    substring(tlno, 4,4), '-',
    substring(tlno, 8,4)
) as num
from used_goods_user) as info
join 
(SELECT
writer_id
from used_goods_board
group by writer_id
having count(writer_id) >= 3 ) as writer
on info.user_id = writer.writer_id 

order by info.user_id desc 