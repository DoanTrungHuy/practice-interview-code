# Write your MySQL query statement below

SELECT eu.unique_id, es.name
FROM Employees AS es
LEFT JOIN EmployeeUNI AS eu
ON es.id = eu.id