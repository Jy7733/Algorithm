with mem as (
select
member_id,
count(member_id) as cnt
from rest_review
group by member_id
order by cnt desc
limit 1
)

select 
p.member_name, 
r.review_text, 
date_format(r.review_date,'%Y-%m-%d') as review_date
from member_profile p 
join mem m on p.member_id = m.member_id 
join rest_review r on r.member_id = m.member_id
order by review_date, r.review_text