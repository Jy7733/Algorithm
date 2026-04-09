-- 코드를 작성해주세요
with recursive ecoli_tree as(
    select id, parent_id, 1 as generation from ecoli_data where parent_id is null
    union all
    select e.id, e.parent_id, t.generation+1
    from ecoli_data e
    join ecoli_tree t on e.parent_id = t.id 
)

select count(*) as count, t.generation as generation
from ecoli_tree t
where not exists (
    select 1 from ecoli_data e where t.id = e.parent_id
)
group by generation 
order by generation
