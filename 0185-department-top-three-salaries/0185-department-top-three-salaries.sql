SELECT Department, name AS Employee, salary AS Salary 
FROM (
    SELECT e.*, d.name AS Department, 
           DENSE_RANK() OVER (PARTITION BY e.departmentId ORDER BY e.salary DESC) AS rank1
    FROM employee e
    INNER JOIN department d ON e.departmentId = d.id
) AS ranked_data
WHERE rank1 <= 3;
