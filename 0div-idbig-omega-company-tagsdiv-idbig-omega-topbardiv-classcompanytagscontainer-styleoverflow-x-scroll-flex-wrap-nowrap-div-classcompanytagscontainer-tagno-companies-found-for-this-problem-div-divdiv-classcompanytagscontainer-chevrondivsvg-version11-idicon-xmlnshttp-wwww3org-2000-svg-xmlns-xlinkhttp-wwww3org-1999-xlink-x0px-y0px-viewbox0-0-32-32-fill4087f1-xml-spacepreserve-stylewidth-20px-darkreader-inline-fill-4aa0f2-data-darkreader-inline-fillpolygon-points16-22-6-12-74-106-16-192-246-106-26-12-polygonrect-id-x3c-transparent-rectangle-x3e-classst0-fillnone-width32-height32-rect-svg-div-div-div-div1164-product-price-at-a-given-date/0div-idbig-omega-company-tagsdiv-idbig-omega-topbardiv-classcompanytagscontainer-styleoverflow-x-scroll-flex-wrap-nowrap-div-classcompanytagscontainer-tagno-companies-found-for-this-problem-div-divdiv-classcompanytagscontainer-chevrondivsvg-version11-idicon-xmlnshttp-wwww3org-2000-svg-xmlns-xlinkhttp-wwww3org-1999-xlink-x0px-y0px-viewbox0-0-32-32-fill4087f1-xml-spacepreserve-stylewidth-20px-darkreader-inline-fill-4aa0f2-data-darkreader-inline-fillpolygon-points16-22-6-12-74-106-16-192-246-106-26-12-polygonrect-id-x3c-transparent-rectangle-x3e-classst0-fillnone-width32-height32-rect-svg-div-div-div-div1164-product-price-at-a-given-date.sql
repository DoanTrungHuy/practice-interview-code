# Write your MySQL query statement below

WITH cte AS (
    SELECT *
    FROM (
        SELECT product_id, new_price AS price, RANK() OVER(PARTITION BY product_id ORDER BY change_date DESC) AS rnk_date
        FROM Products
        WHERE DATEDIFF("2019-08-16", change_date) >= 0
    ) AS rank_products
    WHERE rnk_date = 1
)

SELECT p2.product_id, 
(CASE WHEN p1.product_id IS NULL THEN 10 ELSE p1.price END) AS price
FROM cte p1
RIGHT JOIN (
    SELECT product_id FROM Products
    GROUP BY product_id
) AS p2
ON p1.product_id = p2.product_id