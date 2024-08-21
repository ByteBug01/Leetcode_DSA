# Write your MySQL query statement below
select e.unique_id as unique_id, n.name as name
from Employees n
left join
EmployeeUNI e
on e.id = n.id;
