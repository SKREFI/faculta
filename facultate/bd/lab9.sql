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