-- SELECT id_distrib, name
-- FROM distrib
-- WHERE (id_distrib IN (42, 62, 63, 64, 65, 66, 67,68, 69, 71, 88, 89, 90))
-- OR name LIKE '%Y%Y%'
-- LIMIT 5
-- OFFSET 3;
SELECT id_distrib, name 
FROM distrib 
WHERE (id_distrib = 42 
        OR id_distrib = 62 
        OR id_distrib = 63 
        OR id_distrib = 64
        OR id_distrib = 65
        OR id_distrib = 66
        OR id_distrib = 67
        OR id_distrib = 68
        OR id_distrib = 69
        OR id_distrib = 71
        OR id_distrib = 88
        OR id_distrib = 89
        OR id_distrib = 90) 
OR name LIKE '%Y%Y%'
OR name LIKE '%y%'
LIMIT 5 OFFSET 3 