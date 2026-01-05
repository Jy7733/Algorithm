-- 코드를 입력하세요
with mem as (
SELECT
member_id,
count(member_id) as cnt 
from rest_review 
group by member_id
order by cnt desc
limit 1
)

select 
m.member_name,
rr.review_text,
date_format(rr.review_date,'%Y-%m-%d') as review_date
from rest_review rr 
join member_profile m on rr.member_id = m.member_id 
where m.member_id = (select member_id from mem)
order by rr.review_date, rr.review_text
