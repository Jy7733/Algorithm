-- 부서별 평균 연봉 

-- 평균연봉 소수점 첫째 자리 반올림

-- 부서별 평균 연봉 내림차순

select 
    rn.dept_id, 
    hd.dept_name_en,
    round(avg_sal) as avg_sal 
from

(select
    dept_id,
    avg(sal) as avg_sal
from hr_employees
group by dept_id) rn
join hr_department hd on hd.dept_id = rn.dept_id
order by avg_sal desc; 
