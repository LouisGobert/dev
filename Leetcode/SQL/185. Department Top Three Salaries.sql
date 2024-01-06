SELECT * FROM 
(SELECT e.departmentId, e.salary FROM Employee e
JOIN Department d ON d.id = e.departmentId
WHERE d.id = 1
GROUP BY e.departmentId, e.salary
ORDER BY e.departmentId, e.salary desc LIMIT 3) as sub
JOIN Employee ee ON ee.salary = sub.salary and ee.departmentId =sub.departmentId