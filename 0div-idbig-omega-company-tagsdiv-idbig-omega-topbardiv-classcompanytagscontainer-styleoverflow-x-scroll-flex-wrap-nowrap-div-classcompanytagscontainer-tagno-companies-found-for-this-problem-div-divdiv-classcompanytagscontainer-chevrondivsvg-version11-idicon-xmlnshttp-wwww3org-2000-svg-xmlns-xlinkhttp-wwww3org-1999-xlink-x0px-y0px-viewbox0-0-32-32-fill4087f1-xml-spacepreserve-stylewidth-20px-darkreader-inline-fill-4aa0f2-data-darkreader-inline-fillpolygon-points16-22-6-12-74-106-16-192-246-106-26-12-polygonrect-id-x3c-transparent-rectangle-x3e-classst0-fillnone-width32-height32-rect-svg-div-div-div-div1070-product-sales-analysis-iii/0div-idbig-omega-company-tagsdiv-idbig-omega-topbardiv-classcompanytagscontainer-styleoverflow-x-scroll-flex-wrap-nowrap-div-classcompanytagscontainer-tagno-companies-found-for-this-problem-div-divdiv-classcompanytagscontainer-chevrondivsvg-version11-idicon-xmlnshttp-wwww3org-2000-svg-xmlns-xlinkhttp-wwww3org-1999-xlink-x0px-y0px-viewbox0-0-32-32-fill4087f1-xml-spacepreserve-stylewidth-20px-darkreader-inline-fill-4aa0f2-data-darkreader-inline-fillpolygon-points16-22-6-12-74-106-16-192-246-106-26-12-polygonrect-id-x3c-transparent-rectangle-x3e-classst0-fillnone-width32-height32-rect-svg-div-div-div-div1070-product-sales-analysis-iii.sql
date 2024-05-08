# Write your MySQL query statement below

WITH rank_table_sale AS 
(
    SELECT *, (DENSE_RANK() OVER(PARTITION BY product_id ORDER BY year ASC)) AS rnk_year
    FROM Sales 
)

SELECT 
    product_id, year AS first_year, quantity, price
FROM 
    rank_table_sale
WHERE 
    rnk_year = 1;