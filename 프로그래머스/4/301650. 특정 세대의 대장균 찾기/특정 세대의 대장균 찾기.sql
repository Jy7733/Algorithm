-- 코드를 작성해주세요

with recursive ecoli_tree as (
    select id, parent_id, 1 as gen from ecoli_data where parent_id is null
    union all 
    select e.id, e.parent_id, t.gen+1 
    from ecoli_tree t 
    join ecoli_data e on t.id = e.parent_id
)

select id
from ecoli_tree
where gen = 3
order by id













/*
with recursive gen as 
(
    select 
    id,
    parent_id,
    1 as generation 
    from ecoli_data where parent_id is null 
    
    union all 
    
    select e.id, e.parent_id, g.generation+1 
    from ecoli_data e 
    join gen g on e.parent_id = g.id 
    
)

select 
count(*) as count,
generation
from gen
where id not in (select distinct parent_id from ecoli_data where parent_id is not null)
group by generation
*/