# Write your MySQL query statement below

SELECT s.user_id, ROUND(CASE WHEN cf.user_id IS NULL THEN 0 ELSE avg_action END, 2) AS confirmation_rate
FROM Signups s
LEFT JOIN (
    SELECT cf.user_id, AVG(CASE WHEN cf.action = 'timeout' THEN 0 ELSE 1 END) AS avg_action
    FROM Confirmations cf
    GROUP BY cf.user_id
) cf
ON s.user_id = cf.user_id