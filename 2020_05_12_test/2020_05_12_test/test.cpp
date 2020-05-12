//������������
INSERT INTO actor
values(1, 'PENELOPE', 'GUINESS', '2006-02-15 12:34:33'), (2, 'NICK', 'WAHLBERG', '2006-02-15 12:34:33');
//�ҳ�����Ա����ǰ(to_date='9999-01-01')�����нˮsalary�����������ͬ��нˮֻ��ʾһ��,������������ʾ
select distinct salary from salaries where to_date = '9999-01-01' order by salary desc;
select salary from salaries where to_date = '9999-01-01' group by salary order by salary desc;
//����������ְԱ����������Ϣ
select * from employees order by hire_date desc limit 0, 1;
select * from employees where hire_date = (select max(hire_date) from employees);
//������ְԱ��ʱ����������������Ա��������Ϣ
select * from employees where hire_date = (select hire_date from employees group by hire_date order by hire_date desc limit 2, 1);
//����нˮ�Ƿ�����15�ε�Ա����emp_no�Լ����Ӧ���Ƿ�����t
select emp_no, count(emp_no) as t from salaries group by emp_no having t > 15;
//��ȡ���в��ŵ�ǰmanager�ĵ�ǰнˮ���������dept_no, emp_no�Լ�salary����ǰ��ʾto_date = '9999-01-01'
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
//��titles���ȡ����title���з���,ÿ��������ڵ���2������title�Լ���Ӧ����Ŀt
select title, count(*) as t from titles group by title having t >= 2;

//�����ظ��ĵ�������
select Email from Person group by Email having count(*)>1;

select Email
from(select Email, count(*) as num from Person group by Email)as tmptb
where num > 1;
//��Ĺ���
select name, population, area from World where area>3000000 or population>25000000;
//���Ź�����ߵ�Ա��
select Department.Name as Department, Employee.Name as Employee, Salary
from Employee join Department
on Employee.DepartmentId = Department.Id
where(DepartmentId, Salary)
in(select DepartmentId, max(Salary) from Employee group by DepartmentId);