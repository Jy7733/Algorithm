-- 입양 간 기록은 있지만, 보호소에 들어온 기록이 없는 동물 ID/ 이름
-- order by id 
SELECT
outs.animal_id,
outs.name
from animal_outs outs
left join animal_ins ins on outs.animal_id = ins.animal_id 
where ins.animal_id IS NULL 