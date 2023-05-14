# Write your MySQL query statement below
SELECT name AS Customers FROM Customers AS A
WHERE A.id NOT IN (SELECT B.customerId FROM Orders AS B)