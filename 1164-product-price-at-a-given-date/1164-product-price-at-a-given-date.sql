# Write your MySQL query statement below

WITH Fil AS (
    SELECT product_id, MAX(change_date) AS cd FROM Products WHERE DATEDIFF(change_date, '2019-08-16') <= 0
    GROUP BY product_id
)

SELECT product_id,
CASE 
WHEN (product_id, change_date) in (SELECT * FROM Fil) THEN new_price
ELSE 10 END AS price
FROM Products
WHERE (product_id, change_date) in (SELECT * FROM Fil)
UNION
SELECT product_id, 
10 AS price
FROM Products AS p
WHERE p.product_id not in (SELECT f.product_id FROM Fil as f)