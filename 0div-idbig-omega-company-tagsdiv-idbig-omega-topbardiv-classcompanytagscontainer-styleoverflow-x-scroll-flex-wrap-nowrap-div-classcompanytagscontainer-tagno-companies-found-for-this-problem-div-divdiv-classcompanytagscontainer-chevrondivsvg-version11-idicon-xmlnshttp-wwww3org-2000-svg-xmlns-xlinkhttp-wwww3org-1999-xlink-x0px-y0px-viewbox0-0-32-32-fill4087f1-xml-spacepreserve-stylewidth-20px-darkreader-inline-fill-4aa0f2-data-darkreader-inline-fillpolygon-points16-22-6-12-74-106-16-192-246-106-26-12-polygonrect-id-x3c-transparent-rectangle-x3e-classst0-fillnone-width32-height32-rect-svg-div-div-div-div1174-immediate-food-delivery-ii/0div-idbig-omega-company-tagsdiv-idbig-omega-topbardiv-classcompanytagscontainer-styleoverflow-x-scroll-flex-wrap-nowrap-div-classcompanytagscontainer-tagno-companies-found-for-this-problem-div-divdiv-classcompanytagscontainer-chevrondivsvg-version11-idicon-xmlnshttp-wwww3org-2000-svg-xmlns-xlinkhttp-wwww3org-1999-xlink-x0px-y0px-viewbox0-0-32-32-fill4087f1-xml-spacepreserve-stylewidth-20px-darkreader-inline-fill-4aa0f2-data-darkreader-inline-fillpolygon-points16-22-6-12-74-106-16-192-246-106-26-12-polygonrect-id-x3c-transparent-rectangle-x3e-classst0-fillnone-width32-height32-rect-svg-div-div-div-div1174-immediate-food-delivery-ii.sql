# Write your MySQL query statement below

SELECT 
    (
        ROUND
        (
            (
                SELECT COUNT(*)
                FROM 
                (
                    SELECT customer_id FROM Delivery
                    GROUP BY customer_id
                    HAVING MIN(order_date) = MIN(customer_pref_delivery_date)
                ) AS customer_fo
            ) * 100 / COUNT(DISTINCT customer_id),
            2
        )
    ) AS immediate_percentage 
FROM Delivery