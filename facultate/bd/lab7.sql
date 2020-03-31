-- sa se afiseze salariu maxim al angajatilor
-- doar daca acesta este mai amre decat 15k

select EMPLOYEE_ID id, FIRST_NAME || ' ' ||LAST_NAME name, d.department_name dep_name, l.city city
from EMPLOYEES e, departments d, locations l
where e.department_id = d.department_id
and d.location_id = l.location_id
and SALARY = (select max(SALARY)
                from EMPLOYEES
                where SALARY > 15000);


-- II
select e.LAST_NAME, e.salary, d.department_id, d.medie
from EMPLOYEES e, (select DEPARTMENT_ID, avg(SALARY) medie
                    from EMPLOYEES
                    group by DEPARTMENT_ID) d
where e.department_id = d.department_id;

-- III
select FIRST_NAME || ' ' || LAST_NAME name, HIRE_DATE
from EMPLOYEES
where DEPARTMENT_ID in (select DEPARTMENT_ID from EMPLOYEES group by DEPARTMENT_ID having count(*) > 8)
and HIRE_DATE > (select max(hire_date) from EMPLOYEES where DEPARTMENT_ID = 30);

-- 4, 6, 8 HW
-- aliasuri, nr coloane