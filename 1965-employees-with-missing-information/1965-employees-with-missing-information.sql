# Write your MySQL query statement below

SELECT EL.employee_id FROM Employees AS EL
LEFT JOIN Salaries AS SL
ON EL.employee_id = SL.employee_id
WHERE SL.salary IS NULL

UNION

SELECT SL.employee_id FROM Employees AS EL
RIGHT JOIN Salaries AS SL
ON EL.employee_id = SL.employee_id
WHERE EL.name IS NULL

ORDER BY employee_id