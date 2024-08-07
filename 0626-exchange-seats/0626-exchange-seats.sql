# Write your MySQL query statement below

SELECT
    (
        CASE 
            WHEN MOD(id, 2) = 0 THEN id - 1
            WHEN MOD(id, 2) = 1 AND (SELECT MAX(id) FROM seat) = id THEN id
            ELSE id + 1
        END
    ) AS id,
    student
FROM 
    seat
ORDER BY id