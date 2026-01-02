-- 코드를 작성해주세요
with 
gen1 as (select id as id from ecoli_data where parent_id is null), 
gen2 as (select e.id from ecoli_data e join gen1 g on g.id = e.parent_id )


select 
e.id
from ecoli_data e
join gen2 g on g.id=e.parent_id
order by e.id

