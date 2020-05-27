select * from EMP_RSA;

drop table EMP_RSA;

create table emp_rsa as select * from EMPLOYEES;

select * from emp_rsa;

commit;