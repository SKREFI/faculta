-- prima incercare
select a.first_name || ' ' || a.last_name name, b.department_name
FROM
EMPLOYEES a,
(select DEPARTMENT_ID, DEPARTMENT_NAME from DEPARTMENTS) b
where a.department_id = b.department_id;

-- a 2-a
select a.first_name || ' ' || a.last_name name, b.department_name
FROM
EMPLOYEES a
full outer join
(select DEPARTMENT_ID, DEPARTMENT_NAME from DEPARTMENTS) b
on a.department_id = b.department_id;


-- a 3-a oara
select a.first_name || ' ' || a.last_name name, b.department_name
FROM
EMPLOYEES a,
(select DEPARTMENT_ID, DEPARTMENT_NAME from DEPARTMENTS) b
where a.department_id(+) = b.department_id
UNION
select a.first_name || ' ' || a.last_name name, b.department_name
FROM
EMPLOYEES a,
(select DEPARTMENT_ID, DEPARTMENT_NAME from DEPARTMENTS) b
where a.department_id = b.department_id(+);

-- CREATE TABLE DEPT_RSA as select * from DEPARTMENTS;
-- CREATE TABLE EMP_RSA as select * from EMPLOYEES;

select * from dept_rsa;

alter table emp_rsa add constraint pk_emp_rsa primary key(EMPLOYEE_ID); 
alter table dept_rsa add constraint pk_empt_rsa primary key(DEPARTMENT_ID); 

alter table emp_rsa
add constraint fk_emp_dept_rsa
foreign key(DEPARTMENT_ID) REFERENCES dept_rsa(DEPARTMENT_ID);

insert into DEPT_RSA (department_id, department_name, location_id)
values (300, 'Programar', null);

insert into emp_rsa values(250, null, 'Razvan', 'examplu@gmail.com', null, sysdate, 'watasdasd', null, null, null, 300);
select * from emp_rsa where EMPLOYEE_ID = 250;

create table emp1_rsa as select * from EMPLOYEES;
delete from emp1_rsa;

insert into emp1_rsa
select *
from EMPLOYEES
where commission_pct > 0.25;

insert into emp1_rsa
select *from EMPLOYEES
where ROWNUM <= 1
order by SALARY;


insert into emp1_rsa (EMPLOYEE_ID, LAST_NAME, FIRST_NAME, SALARY, EMAIL, HIRE_DATE, job_id)
values (&&employee_id, '&&last_name', '&&first_name', &&salary, 
SUBSTR('&last_name', 1, 7) || '_' || SUBSTR('&first_name', 1, 7) || '@gmail.com',sysdate, '123');

undefine last_name;
undefine first_name;

create table emp0_rsa as select * from EMPLOYEES;
delete from emp0_rsa;

insert first when salary < 5000 then into emp1_rsa
when salary >= 5000 and salary <= 10000 then into emp2_rsa
else into emp3_rsa
select * from employees;

commit;


