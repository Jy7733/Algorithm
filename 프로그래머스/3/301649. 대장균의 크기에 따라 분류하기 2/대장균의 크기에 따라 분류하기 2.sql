-- 코드를 작성해주세요
select 
p.id as id,
case
when p.per <= 0.25 then 'CRITICAL'
when p.per <= 0.5 then 'HIGH'
when p.per <= 0.75 then 'MEDIUM'
else 'LOW'
end as colony_name
from 
(select id, percent_rank() over(order by size_of_colony desc) as per from ecoli_data) as p
order by id 