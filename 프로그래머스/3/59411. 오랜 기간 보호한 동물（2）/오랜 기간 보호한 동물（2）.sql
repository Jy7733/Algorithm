-- 코드를 입력하세요
with outs as (
select 
    animal_ins.animal_id, 
    animal_ins.name, 
    timestampdiff(microsecond, animal_ins.datetime, animal_outs.datetime) as dur
    from 
    animal_ins inner join animal_outs 
    on animal_ins.animal_id = animal_outs.animal_id
    order by dur desc
    limit 2
)

SELECT
animal_id,
name
from 
outs



