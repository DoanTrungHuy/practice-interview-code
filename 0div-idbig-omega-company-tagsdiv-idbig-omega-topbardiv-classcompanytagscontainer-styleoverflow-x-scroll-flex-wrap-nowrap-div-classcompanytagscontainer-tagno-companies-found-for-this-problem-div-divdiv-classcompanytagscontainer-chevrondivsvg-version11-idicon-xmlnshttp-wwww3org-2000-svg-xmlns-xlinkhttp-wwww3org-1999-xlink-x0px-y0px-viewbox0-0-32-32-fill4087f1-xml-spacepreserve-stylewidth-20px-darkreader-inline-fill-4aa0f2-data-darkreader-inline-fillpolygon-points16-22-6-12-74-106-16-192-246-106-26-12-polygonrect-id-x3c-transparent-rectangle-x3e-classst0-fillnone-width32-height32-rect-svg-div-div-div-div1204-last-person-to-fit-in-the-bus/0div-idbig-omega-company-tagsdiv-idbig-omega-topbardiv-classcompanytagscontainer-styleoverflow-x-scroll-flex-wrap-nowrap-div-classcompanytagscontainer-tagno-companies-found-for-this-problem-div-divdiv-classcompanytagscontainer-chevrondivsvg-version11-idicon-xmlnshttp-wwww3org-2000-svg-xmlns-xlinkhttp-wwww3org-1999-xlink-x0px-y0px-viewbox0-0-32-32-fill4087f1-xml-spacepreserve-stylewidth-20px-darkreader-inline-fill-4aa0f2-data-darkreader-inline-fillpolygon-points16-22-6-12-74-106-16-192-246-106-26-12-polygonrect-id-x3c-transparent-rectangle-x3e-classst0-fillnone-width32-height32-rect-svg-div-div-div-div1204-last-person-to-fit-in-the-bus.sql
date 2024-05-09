# Write your MySQL query statement below

SELECT p1.person_name
FROM Queue p1
JOIN Queue p2 ON p1.turn >= p2.turn
GROUP BY p1.turn
HAVING SUM(p2.weight) <= 1000
ORDER BY p1.turn DESC
LIMIT 1