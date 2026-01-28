# Write your MySQL query statement bel

WITH tmp AS (
    SELECT event_date, MIN(event_date) OVER (PARTITION BY player_id) AS first_date FROM Activity
)

SELECT 
ROUND((SELECT COUNT(*) FROM tmp WHERE DATEDIFF(event_date, first_date) = 1) / COUNT(DISTINCT player_id), 2) AS fraction  
FROM Activity