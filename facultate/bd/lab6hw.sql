SELECT LAST_NAME, FIRST_NAME
from employees;

select max(SALARY) - min(SALARY)
FROM EMPLOYEES;

-- Scrieţi o cerere pentru a se afişa numele departamentului, locaţia, numărul de
-- angajaţi şi salariul mediu pentru angajaţii din acel departament. Coloanele vor fi
-- etichetate corespunzător.
-- Mine
select sum(salary) suma,
      (select DEPARTMENT_NAME
       from DEPARTMENTS d
       where d.DEPARTMENT_ID = e.DEPARTMENT_ID) dep_name, count(*) nr_angajati
from EMPLOYEES e
group by DEPARTMENT_ID;
-- PDF
SELECT d.department_name “Departament”, l.city “Locatie”,
       COUNT(*) “Nr angajati”, AVG(salary) “Salariu mediu”
FROM locations l, departments d, employees e
WHERE l.location_id = d.location_id
AND d.department_id = e.department_id
GROUP BY department_name, l.city;

-- Să se afişeze codul şi numele angajaţilor care câstiga mai mult decât salariul mediu
-- din firmă. Se va sorta rezultatul în ordine descrescătoare a salariilor.

select EMPLOYEE_ID, FIRST_NAME
from EMPLOYEES
where SALARY > (select avg(salary) from EMPLOYEES)
order BY salary desc; 

-- HELP, ce este null-ul ala si la id si la name
select department_id,round(avg(salary)) medie, (select DEPARTMENT_NAME from DEPARTMENTS d where d.department_id = e.department_id) name
from employees e
group by DEPARTMENT_ID;

-- 16

select d.department_name, j.job_title, sum(e.salary)
from employees e, jobs j, DEPARTMENTS d
where e.job_id = j.job_id and e.department_id = d.department_id
group by d.department_name, j.job_title;

-- 17
-- Cel mai mic salariu din departamentul cu cel mai mare salariu mediu
-- abc :)
select d.department_name, min(e.salary) 
from EMPLOYEES e, departments d
where e.department_id = d.department_id 
and e.DEPARTMENT_ID = (select e.DEPARTMENT_ID
                        from EMPLOYEES e
                        group by e.DEPARTMENT_ID
                        having avg(e.salary) = (select max(avg(SALARY))
                                                from EMPLOYEES
                                                group by DEPARTMENT_ID))
group by d.department_name;

-- 18 a)

select e.department_id, d.department_name, count(*) nr_angajati
from EMPLOYEES e, DEPARTMENTS d
where e.department_id = d.department_id
group by e.department_id, d.department_name
having count(*) < 4;

-- 18 b)

select e.department_id, d.department_name, count(*) nr_angajati
from EMPLOYEES e, DEPARTMENTS d
where e.department_id = d.department_id
group by e.department_id, d.department_name
having e.department_id = (select DEPARTMENT_ID
                          from EMPLOYEES
                          group by DEPARTMENT_ID
                          having count(*) = (select max(count(*)) 
                                             from EMPLOYEES
                                             group by DEPARTMENT_ID));

-- 19

select count(*)
from EMPLOYEES
group by to_char(HIRE_DATE, 'dd');

select EMPLOYEE_ID
from EMPLOYEES
where to_char(HIRE_DATE, 'dd') in (select to_char(HIRE_DATE, 'dd')
                                    from EMPLOYEES
                                    group by to_char(HIRE_DATE, 'dd')
                                    having count(*) = (select max(count(*))
                                                                  from EMPLOYEES
                                                                  group by to_char(HIRE_DATE, 'dd')));


-- 20

select count(count(*)) deps
from EMPLOYEES
group by DEPARTMENT_ID
having count(*) > 15;

SELECT employee_id, last_name, TO_CHAR(hire_date, ‘dd’)
FROM employees
WHERE TO_CHAR(hire_date,'dd') IN
(SELECT TO_CHAR(hire_date,'dd')
FROM employees
GROUP BY TO_CHAR(hire_date,'dd')
HAVING COUNT(*)=(SELECT MAX(COUNT(*))
FROM employees
GROUP BY TO_CHAR(hire_date,'dd')));

-- 21

select DEPARTMENT_ID, sum(salary)
from EMPLOYEES
group by DEPARTMENT_ID
having count(*) > 10 and DEPARTMENT_ID != 30;

-- 22
-- Probabil trebuie right join
select e.DEPARTMENT_ID, d.DEPARTMENT_NAME, count(*) angajati, round(avg(salary)) salary
from EMPLOYEES e
left join departments d
on d.department_id = e.department_id
group by e.department_id, d.DEPARTMENT_NAME;

-- 23
-- salariu total pentru ficear job din departament unde id > 80,
-- numele departamentului, jobul si suma SALARY

select l.city city, d.department_name dep_name, j.job_title, sum(e.salary) sum
from EMPLOYEES e, DEPARTMENTS d, JOBS j, locations l
where e.DEPARTMENT_ID > 80 AND e.department_id = d.department_id
AND e.job_id = j.job_id AND d.location_id = l.location_id 
group by l.city, d.department_name, j.job_title;


-- 24

select EMPLOYEE_ID
from JOB_HISTORY
group by EMPLOYEE_ID
having count(*) > 1;























