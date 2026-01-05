-- 코드를 입력하세요
with recursive hours as (
    select 0 as hour 
    union all 
    select hour+1 from hours where hour < 23
)


SELECT
h.hour,
coalesce(count(o.animal_id),0) as count
from animal_outs o
right join 
hours h on h.hour = hour(o.datetime)
group by h.hour
order by h.hour


