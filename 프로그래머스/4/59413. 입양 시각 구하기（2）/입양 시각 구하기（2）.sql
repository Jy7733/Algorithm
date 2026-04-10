-- 코드를 입력하세요
with recursive t as (
    select 0 as hour
    union all
    select t.hour+1 from t where hour<23
)

select
t.hour,
count(hour(o.datetime)) as count
from animal_outs o
right join t on t.hour = hour(o.datetime)
group by hour
order by hour















/*
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
order by h.hour*/