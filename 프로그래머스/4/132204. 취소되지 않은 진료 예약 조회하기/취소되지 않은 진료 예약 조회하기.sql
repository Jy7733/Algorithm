-- 코드를 입력하세요
select
apnt.apnt_no,
patient.pt_name,
apnt.pt_no,
apnt.mcdp_cd,
doctor.dr_name,
apnt.apnt_ymd 
from 

(SELECT
apnt_ymd,
apnt_no,
pt_no,
mcdp_cd,
mddr_id
from appointment
where year(apnt_ymd) = '2022' and month(apnt_ymd) = '04' and day(apnt_ymd) = '13'
and apnt_cncl_yn = 'N') as apnt
join patient on apnt.pt_no = patient.pt_no
join doctor on apnt.mddr_id = doctor.dr_id 

order by apnt_ymd