-- 아직 입양을 못 간 동물 중 
-- 가장 오래 보호소에 있었던 3마리  이름 / 보호시작일 
-- order by 보호시작일 
SELECT
name,
datetime

from animal_ins ins
where animal_id not in (select animal_id from animal_outs)
order by datetime
limit 3;