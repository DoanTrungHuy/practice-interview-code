# Write your MySQL query statement below

WITH sort_employee AS (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
)

SELECT (
    SELECT salary
    FROM (
        SELECT salary, (ROW_NUMBER() OVER()) AS rnk
        FROM sort_employee
    ) AS tmp
    WHERE rnk = 2
) AS SecondHighestSalary;