# Write your MySQL query statement below

WITH rnk_employee AS (
    SELECT e1.name AS Employee , e1.salary, e2.name AS Department, DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) AS rnk
    FROM Employee e1
    JOIN Department e2
    ON e1.departmentId = e2.id
)

SELECT Department, Employee, Salary
FROM rnk_employee
WHERE rnk <= 3