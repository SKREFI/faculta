select * from project;

select * from WORKS_ON
order by EMPLOYEE_ID;

select distinct EMPLOYEE_ID from WORKS_ON where PROJECT_ID in (select PROJECT_ID from project where budget = 10000);

select *
from WORKS_ON a
where not exists ((select project_id from project
                    where TO_CHAR(START_DATE, 'dd/mm/yyyy') > '01/01/2006'
                    and TO_CHAR(START_DATE, 'dd/mm/yyyy') <= '06/31/2006')
                    MINUS
                    (select p.project_id from project p, works_on B
                    where p.project_id = b.project_id
                    and b.EMPLOYEE_ID = a.EMPLOYEE_ID));


select EMPLOYEE_ID from works_on where project_id IN
                                        (select project_id from project
                                        where TO_CHAR(START_DATE, 'dd/mm/yyyy') > '01/01/2006'
                                        and TO_CHAR(START_DATE, 'dd/mm/yyyy') <= '06/31/2006')
group by EMPLOYEE_ID
having count(PROJECT_ID) = (select count(*) from project where TO_CHAR(START_DATE, 'dd/mm/yyyy') > '01/01/2006'
                                        and TO_CHAR(START_DATE, 'dd/mm/yyyy') <= '06/31/2006');



-- L10
DEFINE p_cod 100;
select EMPLOYEE_ID, last_name, salary, department_id
from employees
where EMPLOYEE_ID = &p_cod;
UNDEFINE p_cod;


DEFINE location = Oxford;
select a.last_name || ' ' || a.first_name name, a.job_id, a.salary, b.department_name
from employees a,
(select department_id, location_id, department_name from departments) b,
(select location_id, city from locations) c
where a.department_id = b.department_id and
b.location_id = c.location_id and
lower(c.city) = lower('&location');

