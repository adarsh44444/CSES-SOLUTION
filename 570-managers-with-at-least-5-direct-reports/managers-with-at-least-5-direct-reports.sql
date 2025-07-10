WITH CTE AS (
    SELECT managerId
    FROM Employee
    GROUP BY managerId
    HAVING COUNT(*) > 4
)

SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId FROM CTE
);
