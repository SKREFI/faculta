-- 4, 6, 8 HW
-- aliasuri, nr coloane
-- Prin aliasuri inteleg unde totusi este nume mai amre sau operator pe coloana, daca este salary/department_name etc. nu am cu ce sa inlocuiesc

-- 1
-- Rezultate: 11
select d.department_id, DEPARTMENT_NAME, a.suma
from departments d, (select department_id, sum(salary) suma from EMPLOYEES group by department_id) a
where d.department_id = a.department_id;

-- 2 numele, salariu, id, salariu mediu din deparamentul respectiv:
-- Resultate: 106
select e.last_name, e.salary, d.department_id, d.medie
from EMPLOYEES e, (select DEPARTMENT_ID, avg(salary) medie from EMPLOYEES group by DEPARTMENT_ID) d
where e.department_id = d.department_id;

-- 3 
-- Resultate: 106
select e.last_name, e.salary, d.department_id, d.medie, d.nr
from EMPLOYEES e, (select DEPARTMENT_ID, avg(salary) medie, count(*) nr from EMPLOYEES group by DEPARTMENT_ID) d 
where e.department_id = d.department_id;

--HW 4
-- Rezultate: 12
select e.FIRST_NAME name, deps.DEPARTMENT_NAME, e.salary
from departments deps, EMPLOYEES e, (select DEPARTMENT_ID, min(salary) min from EMPLOYEES group by DEPARTMENT_ID) d 
where e.department_id = d.department_id
and e.department_id = deps.department_id
and e.salary = d.min;

-- 5 select: detalii
-- conditie: salary > avg(salary din dipartmentul propriu)
--Rezultate: 38
-- a)
select first_name
from EMPLOYEES e
where salary > (select avg(SALARY)
                from EMPLOYEES
                where DEPARTMENT_ID = e.department_id);

-- b) conditie: salary > avg(salary) grupat pe dep 
-- select: nume dep,           avg salary   ,  nr angajati
        -- dep_id + dep_name | dep_id + avg |  dep_id + count(*) group by

-- Rezultate: 38
select DEPARTMENT_ID, SALARY
from EMPLOYEES e
where salary > (select avg(salary) from EMPLOYEES where DEPARTMENT_ID = e.department_id);

--Rezultate: 38
select distinct(e.employee_id) emp_id, e.salary, a.nume_dep, round(b.medie) "medie/dep", c.numar "nr/dep"
from EMPLOYEES e,
     (select department_id, department_name nume_dep from departments) a,
     (select DEPARTMENT_ID, avg(salary) medie from EMPLOYEES group by DEPARTMENT_ID) b,
     (select department_id, count(*) numar from EMPLOYEES group by DEPARTMENT_ID) c
where a.department_id = e.department_id 
and   b.department_id = e.department_id
and   c.department_id = e.department_id 
and e.salary > b.medie;

-- 6 select: numele, salary
-- conditie: salary > salariile medii din toate departamentele ???
--Rezultate: 1
select e.employee_id, e.first_name || ' ' || e.last_name name, e.salary
from EMPLOYEES e
where e.salary > (select max(avg(salary)) from EMPLOYEES group by DEPARTMENT_ID);
-- cu operatorul all pe care l-am invatat acum :))
-- Rezultate: 1
select e.employee_id, e.first_name || ' ' || e.last_name name, e.salary
from EMPLOYEES e
where e.salary > ALL (select avg(salary) from EMPLOYEES group by DEPARTMENT_ID);

-- 7 select: numele
-- conditie: worst paid employee per dep
--Rezultate: 12
select FIRST_NAME, salary
from EMPLOYEES main
where salary = (select min(salary)
                from EMPLOYEES e
                where main.department_id = e.department_id);

-- Rezultate: 12
select e.department_id, e.salary, a.minim
from (select department_id, min(salary) minim from EMPLOYEES group by DEPARTMENT_ID) a,
     (EMPLOYEES) e
where e.department_id = a.department_id
and e.salary = a.minim
;

-- 8 select: nume
-- conditie: salariatul cu cea mai mare vechime /departament
--Rezultate: 12
select e.department_id, e.hire_date, b.department_name, c.city
FROM
(select DEPARTMENT_ID, min(hire_date) oldest from EMPLOYEES group by DEPARTMENT_ID) a,
(select DEPARTMENT_ID, DEPARTMENT_NAME from departments) b,
(select DEPARTMENT_ID, city from departments d, locations l where l.location_id = d.location_id) c,
(EMPLOYEES) e
where e.department_id = a.department_id
and e.department_id = b.department_id
and e.department_id = c.department_id
and e.hire_date = a.oldest;

-- 9 select: nume salariat
-- conditie: lucreaza intr-un departament in care exista
--           cel putin un angajat cu salariu egal cu max(salary) in dep 30
--Rezultate: 40
--Solutie valida comparand cu cea din PDF
select department_id, FIRST_NAME, salary
from EMPLOYEES
where DEPARTMENT_ID in
                (select e.department_id FROM
                (EMPLOYEES) e, (select max(salary) salariu_max
                from EMPLOYEES where DEPARTMENT_ID = 30) a
where e.salary = a.salariu_max);

--10 select: numar
-- conditie: departamente inactive
--Rezultate: 15
--HELP: Numarul din pdf este 16 ?!?!
select b.dep_total - a.dep_active dep_inactive
from
(select count(count(*)) dep_active from EMPLOYEES group by DEPARTMENT_ID) a,
(select count(*) dep_total from departments) b;
-- pdf
select count(*)
from departments d
where not exists (select 'x' from employees where department_id = d.department_id);

--11 select: id, nume, prenume
-- conditie: >2 subalterni
--Rezultate: 103
select e.employee_id, e.first_name || ' ' || e.last_name name, a.nr
from EMPLOYEES e,
(select MANAGER_ID, count(*) nr from EMPLOYEES group by MANAGER_ID having count(*) > 2) a
where e.EMPLOYEE_ID = a.MANAGER_ID
and a.nr > 2;

--12 select: locatiile
-- conditie: cu minim un departament
--Rezultate: 7
select distinct(d.location_id), l.city
from DEPARTMENTS d, locations l
where d.LOCATION_ID in l.location_id;

--13 select: dep_name, sum(salary)
-- conditie: sum(salary)/dep > avg(sum(toti_angajatii)) 
--Rezultate: 10
--Ma indoiesc ca ceva nu e bine, nu cred ca am inteles eu problema
--Cerinta ma cam baga in ceata si nici din solutie nu prea inteleg ce se cere
select department_name, a.sum
from
(select DEPARTMENT_ID, sum(salary) sum from EMPLOYEES group by DEPARTMENT_ID) a,
(select sum(salary)/count(*) avg from EMPLOYEES) b,
(departments) d
where d.department_id = a.department_id
and a.sum > b.avg;

--14 select: nume manageri, sum(subordonati's salary)
-- conditie: suma aia < avg(salary din deparatmentul unde lucreaza managerul)
--           Si cum poate fi suma aia mai mica decat media
--Rezultate: