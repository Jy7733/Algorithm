-- 공간을 둘 이상 등록한 사람 = 헤비유저
-- 헤비유저가 등록한 공간의 정보 
-- 아이디 순 
SELECT
id,
name,
host_id
from places 
where host_id 
in
(select host_id
from places
group by host_id 
having count(host_id) >= 2)
order by id;
