SELECT a.customer_id
FROM (
    SELECT customer_id
    FROM customer
    GROUP BY customer_id
    HAVING COUNT(DISTINCT product_key) = (SELECT COUNT(*) FROM product)
) AS a;
