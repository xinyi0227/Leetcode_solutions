SELECT 
    id1 AS id, 
    coalesce(student2, student1) AS student 
FROM (
    SELECT 
        s1.id AS id1,
        s1.student AS student1,
        s2.id AS id2,
        s2.student AS student2
    FROM seat s1
    LEFT JOIN seat s2
    ON floor((s1.id+1)/2) = floor((s2.id+1)/2) AND s1.id <> s2.id
) seat_updated
ORDER BY id