# Write your MySQL query statement below

select Department.name as Department , Employee.name as Employee , 
Employee.salary as Salary 
from Employee join Department on Employee.departmentId = Department.id
where Employee.salary = (
    select max(e2.salary) from Employee as e2
    where e2.departmentId= Employee.departmentId
)