/* Write your T-SQL query statement below */

 WITH cte_output AS (
    SELECT d.id, d.name AS Department, MAX(e.salary) AS Salary
    FROM Employee e
    JOIN Department d ON e.departmentId = d.id
    GROUP BY d.id, d.name
 )
 
 -- SELECT * FROM cte_output
 
SELECT c.Department, e.name AS Employee, c.Salary
FROM Employee e
JOIN cte_output c
ON e.departmentId = c.id
WHERE c.Salary = e.salary