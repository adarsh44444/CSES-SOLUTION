SELECT 
    a.machine_id,
    ROUND(AVG(e.timestamp - a.timestamp), 3) AS processing_time
FROM 
    Activity a
JOIN 
    Activity e
ON 
    a.machine_id = e.machine_id
    AND a.process_id = e.process_id
    AND a.activity_type = 'start'
    AND e.activity_type = 'end'
GROUP BY 
    a.machine_id;
