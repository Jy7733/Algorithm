-- 코드를 입력하세요
-- 보호 시작일보다 입양일이 더 빠른 동물 id, 이름 
-- order by 보호시작일 
SELECT
ins.animal_id,
ins.name
from animal_ins ins 
join animal_outs outs on ins.animal_id = outs.animal_id 
where ins.datetime > outs.datetime 
order by ins.datetime 