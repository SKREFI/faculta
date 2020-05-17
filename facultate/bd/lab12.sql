update emp_rsa
SET salary = salary * 1.05;

select * from emp_rsa;

ROLLBACK;

UPDATE emg_rsa
set job_id = upper('sa_rep')
where DEPARTMENT_ID = 80
and COMMISSION_PCT;

UPDATE emg_rsa
set job_id = upper('&job')
where DEPARTMENT_ID = 80
and COMMISSION_PCT = '&comission');

rollback;

create table jobs_rsa as select * from jobs;

alter table jobs_rsa add constraint pk_jobs_rsa PRIMARY KEY(job_id);

ALTER table EMP_RSA
add CONSTRAINT fk_emp_JOBS_rsa
foreign key(job_id) REFERENCES jobs_rsa(job_id);

delete from emp_rsa where EMPLOYEE_ID > 206;
select * from emp_rsa;
commit;

select * from departments;

update dept_rsa
set manager_id = (select EMPLOYEE_ID from emp_rsa where upper(LAST_NAME) = 'GRANT'
and upper(first_name) = 'DOUGLAS')
where DEPARTMENT_ID = 20;

update EMP_RSA
set salary = SALARY + 1000
where EMPLOYEE_ID = (select EMPLOYEE_ID from emp_rsa where upper(LAST_NAME) = 'GRANT'
and upper(first_name) = 'DOUGLAS');

select *
from (select EMPLOYEE_ID
from EMP_RSA
order by salary)
where ROWNUM <= 1; 

update EMP_RSA
set salary = (select salary from emp_rsa where EMPLOYEE_ID = 
                                                (select * from (select MANAGER_ID from EMP_RSA order by salary) where ROWNUM <= 1))
where EMPLOYEE_ID = (select * from (select EMPLOYEE_ID from EMP_RSA order by salary) where ROWNUM <= 1);

-- with helper as (select * from (select EMPLOYEE_ID, MANAGER_ID from EMP_RSA order by salary) where ROWNUM <= 1)
-- update EMP_RSA 
-- set salary = (select salary from emp_rsa where employee_id = helper.manager_id)
-- where EMPLOYEE_ID = heper.EMPLOYEE_ID;

update EMP_RSA
set email = SUBSTR(last_name, 1, 1) || NVL(FIRST_NAME, '.')
and EMPLOYEE_ID in (select EMPLOYEE_ID from EMP_RSA
             where (SALARY, DEPARTMENT_ID) in (select max(SALARY), DEPARTMENT_ID
                                            from EMP_RSA
                                            group by DEPARTMENT_ID));

delete from DEPT_RSA
where DEPARTMENT_ID in (select DEPARTMENT_ID
                        from dept_rsa
                        where MANAGER_ID is null);

select * from EMPLOYEES;

select * from emp_rsa where EMPLOYEE_ID = &&id;
delete from emp_rsa where EMPLOYEE_ID = &id;

COMMIT;

Insert into emp_rsa(employee_id, last_name,first_name,salary,email, hire_date, job_id)
values(1000,'Io','Totio', 42, 'email@ul.meu', sysdate, 'SA_REP');

savepoint acum;

delete from emp_rsa;
select * from emp_rsa;

ROLLBACK;