# Write your MySQL query statement below

SELECT st.student_id, st.student_name, sj.subject_name, COUNT(ex.subject_name) AS attended_exams 
FROM students st 
JOIN subjects sj
LEFT JOIN Examinations ex
ON st.student_id = ex.student_id AND sj.subject_name = ex.subject_name
GROUP BY st.student_id, sj.subject_name
ORDER BY st.student_id, sj.subject_name;