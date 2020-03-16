select employee_id, salary, commission_pct, NVL2(commission_pct, commission_pct, 1)*salary as salariu_dupa_comision
from employees;

select employee_id as rest
from employees
WHERE MOD(round(sysdate - hire_date), 7) = 0;

SELECT TO_CHAR(SYSDATE, 'MONTH DD HH24:MI:SS') "Data"
FROM DUAL;

select id, NVL(TO_CHAR((commission_pct, 0)*salary)) "Comision"
from employees;

select last_name, job_id, salary,
    DECODE(UPPER(job_id),
    'IT_PROG', salary * 1.2,
    'SA_REP', salary * 1.25,
    'SA_MAN', salary * 1.35,
    salary) "Salariu Renegociat"
from employees;

SELECT last_name, DEPARTMENTS.department_id, department_name
FROM EMPLOYEES, DEPARTMENTS
WHERE EMPLOYEES.department_id=DEPARTMENTS.department_id;

select e.last_name, d.department_id, d.department_id
from departments d  join location l
on (d.department_id=d.department_id);

SELECT e.first_name||' '||e.last_name as Name, j.job_id, j.job_title, d.department_name, e.salary, e.hire_date
FROM employees e
join jobs        j ON (e.job_id = j.job_id) 
join departments d ON (e.department_id = d.department_id)
WHERE TO_CHAR(hire_date, 'YYYY') = '1987' OR salary < 7000
ORDER BY salary;


select employee_id, job_id 
from employees NATURAL JOIN jobs;

select j.*
from employees e JOIN jobs using (job_id);


select employee_id
from employees

where manager_id=100;

select *
from employees e, departments d
where e.department_id = d.department_id;

select d.manager_id, employee_id
from employees e NATURAL JOIN departments d
where department_id = department_id;

select distinct e.last_name, e.department_id, e.employee_id, d.department_name
from employees e, employees e2, departments d
where LOWER(e2.last_name) like '%t%'
and e.department_id = d.department_id
order by 1;

select *
from employees e full outer join departments d
on e.department_id = d.department_id;





