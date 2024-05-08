# Write your MySQL query statement below

SELECT pr.product_id, IFNULL(ROUND(SUM(pr.price*us.units) / SUM(us.units), 2), 0) AS average_price 
FROM Prices AS pr
LEFT JOIN UnitsSold AS us
ON pr.product_id = us.product_id
WHERE us.purchase_date BETWEEN pr.start_date AND pr.end_date OR us.product_id IS NULL 
GROUP BY pr.product_id;