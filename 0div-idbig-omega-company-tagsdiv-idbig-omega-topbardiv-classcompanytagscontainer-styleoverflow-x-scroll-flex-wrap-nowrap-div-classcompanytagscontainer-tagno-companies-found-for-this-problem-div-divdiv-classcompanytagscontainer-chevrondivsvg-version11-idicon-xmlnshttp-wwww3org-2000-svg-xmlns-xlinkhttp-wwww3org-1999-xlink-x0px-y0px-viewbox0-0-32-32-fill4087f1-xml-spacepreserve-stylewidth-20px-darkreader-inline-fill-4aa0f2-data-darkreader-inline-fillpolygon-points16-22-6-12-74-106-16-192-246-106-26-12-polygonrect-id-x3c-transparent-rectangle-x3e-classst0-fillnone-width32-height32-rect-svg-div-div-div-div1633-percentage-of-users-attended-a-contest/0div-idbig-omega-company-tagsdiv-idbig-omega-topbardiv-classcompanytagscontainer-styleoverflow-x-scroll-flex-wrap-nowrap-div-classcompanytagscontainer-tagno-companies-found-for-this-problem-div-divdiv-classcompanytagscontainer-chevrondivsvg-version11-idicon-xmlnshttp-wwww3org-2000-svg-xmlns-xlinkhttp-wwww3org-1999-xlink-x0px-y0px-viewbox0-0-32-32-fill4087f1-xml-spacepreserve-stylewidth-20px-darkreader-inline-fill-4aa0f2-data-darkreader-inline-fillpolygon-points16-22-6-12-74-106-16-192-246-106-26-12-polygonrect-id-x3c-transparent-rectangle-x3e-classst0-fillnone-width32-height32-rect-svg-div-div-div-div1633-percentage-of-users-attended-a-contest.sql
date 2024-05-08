# Write your MySQL query statement below

SELECT contest_id, ROUND(COUNT(user_id) * 100 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM Register rr
GROUP BY contest_id
ORDER BY percentage DESC, contest_id ASC