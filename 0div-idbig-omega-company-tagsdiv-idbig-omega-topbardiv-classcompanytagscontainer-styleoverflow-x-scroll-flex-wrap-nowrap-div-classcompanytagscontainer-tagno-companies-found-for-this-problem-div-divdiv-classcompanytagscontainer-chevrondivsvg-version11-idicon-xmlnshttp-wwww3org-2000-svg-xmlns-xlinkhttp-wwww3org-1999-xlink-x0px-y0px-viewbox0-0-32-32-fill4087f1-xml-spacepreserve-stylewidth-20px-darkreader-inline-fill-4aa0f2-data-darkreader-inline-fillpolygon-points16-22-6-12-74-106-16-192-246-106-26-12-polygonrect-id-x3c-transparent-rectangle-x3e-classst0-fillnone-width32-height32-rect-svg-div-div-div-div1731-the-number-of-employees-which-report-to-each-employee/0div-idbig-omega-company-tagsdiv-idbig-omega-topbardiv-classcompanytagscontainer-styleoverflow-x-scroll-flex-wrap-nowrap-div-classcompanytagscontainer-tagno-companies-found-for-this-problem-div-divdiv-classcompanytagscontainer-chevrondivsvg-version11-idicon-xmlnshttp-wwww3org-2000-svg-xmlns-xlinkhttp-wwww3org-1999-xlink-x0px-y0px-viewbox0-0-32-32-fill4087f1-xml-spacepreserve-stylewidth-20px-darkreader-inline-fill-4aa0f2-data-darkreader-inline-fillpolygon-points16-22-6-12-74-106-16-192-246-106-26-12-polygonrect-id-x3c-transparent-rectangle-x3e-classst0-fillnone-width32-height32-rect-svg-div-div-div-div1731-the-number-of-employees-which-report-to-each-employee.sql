# Write your MySQL query statement below

SELECT em.employee_id, em.name, pr.cnt_report AS reports_count , ROUND(pr.avg_age) AS average_age 
FROM Employees em
JOIN
(
    SELECT reports_to, COUNT(reports_to) AS cnt_report, AVG(age) as avg_age
    FROM Employees
    WHERE NOT reports_to IS NULL
    GROUP BY reports_to
) pr ON em.employee_id = pr.reports_to
ORDER BY em.employee_id