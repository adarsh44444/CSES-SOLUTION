/* Write your T-SQL query statement below */
/* Write your T-SQL query statement below */
SELECT customer_id FROM customer_transactions
GROUP BY customer_id
HAVING 
    SUM(CASE WHEN transaction_type = 'purchase' THEN 1 ELSE 0 END) >= 3
    AND
    DATEDIFF(day, MIN(transaction_date), MAX(transaction_date)) >= 30
    AND
    SUM(CASE WHEN transaction_type = 'refund' THEN 1 ELSE 0 END)*1.0 / COUNT(transaction_id) < 0.2
ORDER BY customer_id;
