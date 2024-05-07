# Write your MySQL query statement below

SELECT e1.name
FROM Employee e1
WHERE (
    SELECT COUNT(*) FROM Employee e2
    WHERE e1.id = e2.managerId
) >= 5