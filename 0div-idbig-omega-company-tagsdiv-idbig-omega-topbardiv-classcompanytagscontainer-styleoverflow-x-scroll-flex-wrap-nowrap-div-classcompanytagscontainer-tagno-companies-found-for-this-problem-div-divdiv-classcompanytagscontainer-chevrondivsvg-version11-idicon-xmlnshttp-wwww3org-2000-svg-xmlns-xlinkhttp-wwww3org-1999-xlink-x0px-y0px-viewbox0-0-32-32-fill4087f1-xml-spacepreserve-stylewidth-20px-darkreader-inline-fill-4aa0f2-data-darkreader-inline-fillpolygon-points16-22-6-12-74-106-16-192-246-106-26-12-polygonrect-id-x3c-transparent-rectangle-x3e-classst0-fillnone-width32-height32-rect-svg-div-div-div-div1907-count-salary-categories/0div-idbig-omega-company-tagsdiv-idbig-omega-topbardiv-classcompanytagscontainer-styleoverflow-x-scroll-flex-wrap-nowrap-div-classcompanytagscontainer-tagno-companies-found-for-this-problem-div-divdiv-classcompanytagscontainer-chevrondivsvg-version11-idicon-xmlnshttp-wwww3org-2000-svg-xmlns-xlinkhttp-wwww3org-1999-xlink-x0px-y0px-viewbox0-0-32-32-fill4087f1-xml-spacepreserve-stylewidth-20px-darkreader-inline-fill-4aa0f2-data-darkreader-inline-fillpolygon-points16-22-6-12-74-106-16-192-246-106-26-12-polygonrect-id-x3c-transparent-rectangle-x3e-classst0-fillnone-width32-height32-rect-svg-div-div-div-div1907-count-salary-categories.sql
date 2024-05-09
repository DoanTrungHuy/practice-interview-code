SELECT
    category,
    SUM(accounts_count) AS accounts_count
FROM 
(
    SELECT
        CASE 
            WHEN income < 20000 THEN 'Low Salary'
            WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END AS category,
        COUNT(*) AS accounts_count
    FROM 
        Accounts 
    GROUP BY category

    UNION
    SELECT 
        'Low Salary' AS category,
        0 AS accounts_count
    
    UNION
    SELECT 
        'Average Salary' AS category,
        0 AS accounts_count
    
    UNION
    SELECT 
        'High Salary' AS category,
        0 AS accounts_count
    
) AS grouped_categories
GROUP BY category;