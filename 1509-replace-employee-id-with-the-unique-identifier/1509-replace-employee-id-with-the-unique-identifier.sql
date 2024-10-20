select un.unique_id, e.name 
from employees as e
left join EmployeeUNI as un
on e.id=un.id