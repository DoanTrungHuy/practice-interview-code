# Write your MySQL query statement below

WITH tmp AS (
    SELECT customer_id    
    FROM Delivery 
    GROUP BY customer_id
    HAVING
    MIN(order_date) = MIN(customer_pref_delivery_date)
)

SELECT 
    ROUND(
        COUNT(*) * 100.0
        / (SELECT COUNT(DISTINCT customer_id) FROM Delivery),
        2
    ) AS immediate_percentage
FROM tmp;
