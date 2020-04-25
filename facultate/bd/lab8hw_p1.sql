--!1 select: dep_name, sum(salary) per dep 
-- conditie: sum(salary) > avg(salary) per total
--Rezultate: 3 ?? Diferit de solutie..
select b.dep_name, b.total
from
departments a,
(select d.department_name dep_name, sum(SALARY) total from departments d, EMPLOYEES e where e.department_id = d.department_id group by d.department_name) b
where
a.department_name = b.dep_name AND
b.total > (select round(avg(sum(salary))) avarage from EMPLOYEES group by department_id);   -- Media aici = 57k
                                                                                            -- Media din solutie = 62k

with val_dep as (select department_name, sum(salary) total from departments d, employees e where d.department_id = e.department_id group by DEPARTMENT_NAME),
    val_medie as (select avg(total) as medie from val_dep)
select *
from val_dep
where total > (select medie from val_medie);

-- 2 select: manager_name, sum(slary) al subordonatilor AS SS
-- conditie: SS < avg(sum(salary)) din departamentul in care lucreaza managerul respectiv 
--Rezultate: 7
with managers as (select a.employee_id manager_id, a.name name, a.department_id dep_id
                  from (select employee_id, DEPARTMENT_ID, FIRST_NAME || ' ' || LAST_NAME name from EMPLOYEES) a,
                       (select manager_id from departments) b
                  where a.employee_id = b.manager_id),
     salarii as (select manager_id, sum(salary) total from EMPLOYEES group by MANAGER_ID)
select m.manager_id, m.name, s.total
from managers m, salarii s
where s.manager_id = m.manager_id and
s.total < (select avg(sum(salary)) from EMPLOYEES group by DEPARTMENT_ID having DEPARTMENT_ID = m.dep_id);

-- 4 select: *
-- conditie: cele mai proaste 3 joburi based on avg(salary)
--Rezultate: obvsly 3 :)
select *
from (select job_id job_id, avg(salary) avarage from EMPLOYEES group by job_id order by avarage asc)
where  ROWNUM <= 3;

-- 5 select: dep_name, count(empls)
-- conditie: top 4 populated
--Rezultate: 45, 34, 6, 6
select * from (select b.department_name dep_name, a.empls as "Nr. Employees"
     from (select DEPARTMENT_ID, count(*) empls from EMPLOYEES group by DEPARTMENT_ID) a,
     (select DEPARTMENT_ID, DEPARTMENT_NAME from departments) b
     where a.department_id = b.department_id
     order by 2 desc)
where ROWNUM <= 4;

--6
select 'Departamentul ' || a.dep_name || 
NVL2(TO_CHAR(a.manager_id),
    ' este condus de ' || a.manager_id,
    ' nu este condus de nimeni')
    || ' si' ||
NVL2(TO_CHAR(b.nr_empls),
    ' are ' ||
    case b.nr_empls when 1 then 'un angajat!' else b.nr_empls || ' angajati!' end,  
    ' nu are salariati :(.') Detalii
from (select department_id dep_id, DEPARTMENT_NAME dep_name, MANAGER_ID from departments) a,
(select department_id dep_id, count(*) nr_empls from employees group by department_id) b
where a.dep_id = b.dep_id(+);

--8