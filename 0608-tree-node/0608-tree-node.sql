# Write your MySQL query statement below

SELECT T.id,
IF(T.p_id IS NULL, "Root", 
   IF(T.id IN (SELECT p_id FROM Tree), "Inner", 
      "Leaf")) AS Type
FROM Tree AS T