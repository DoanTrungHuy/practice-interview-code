# Write your MySQL query statement below

SELECT employee_id, IF(name LIKE 'M%' OR employee_id % 2 = 0, 0, salary) AS bonus 
FROM Employees
ORDER BY employee_id;