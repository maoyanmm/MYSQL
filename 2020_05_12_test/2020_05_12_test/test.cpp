//批量插入数据
INSERT INTO actor
values(1, 'PENELOPE', 'GUINESS', '2006-02-15 12:34:33'), (2, 'NICK', 'WAHLBERG', '2006-02-15 12:34:33');
//找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示
select distinct salary from salaries where to_date = '9999-01-01' order by salary desc;
select salary from salaries where to_date = '9999-01-01' group by salary order by salary desc;
//查找最晚入职员工的所有信息
select * from employees order by hire_date desc limit 0, 1;
select * from employees where hire_date = (select max(hire_date) from employees);
//查找入职员工时间排名倒数第三的员工所有信息
select * from employees where hire_date = (select hire_date from employees group by hire_date order by hire_date desc limit 2, 1);
//查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
select emp_no, count(emp_no) as t from salaries group by emp_no having t > 15;
//获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date = '9999-01-01'
select dept_manager.dept_no, dept_manager.emp_no, salaries.salary
from salaries inner join dept_manager
on salaries.emp_no = dept_manager.emp_no
and salaries.to_date = '9999-01-01'
and dept_manager.to_date = '9999-01-01';

select dept_manager.dept_no, dept_manager.emp_no, salaries.salary
from salaries, dept_manager
where dept_manager.emp_no = salaries.emp_no
and salaries.to_date = '9999-01-01'
and dept_manager.to_date = '9999-01-01';
//从titles表获取按照title进行分组,每组个数大于等于2，给出title以及对应的数目t
select title, count(*) as t from titles group by title having t >= 2;

//查找重复的电子邮箱
select Email from Person group by Email having count(*)>1;

select Email
from(select Email, count(*) as num from Person group by Email)as tmptb
where num > 1;
//大的国家
select name, population, area from World where area>3000000 or population>25000000;
//部门工资最高的员工
select Department.Name as Department, Employee.Name as Employee, Salary
from Employee join Department
on Employee.DepartmentId = Department.Id
where(DepartmentId, Salary)
in(select DepartmentId, max(Salary) from Employee group by DepartmentId);