-- 2020-09-16, 4
USE Movies;

-- 4.1.
SELECT DISTINCT name, address
FROM Studio JOIN Movie ON name = studioName
WHERE inColor = 'Y' AND name IN (SELECT name 
                                 FROM Studio JOIN Movie ON name = studioName
                                 WHERE inColor = 'N')
ORDER BY address


-- 4.2.
SELECT name, address, ROUND(AVG(length), 0) AS avg_len
FROM Studio LEFT JOIN Movie ON name = studioName
GROUP BY name
HAVING COUNT(*) < 4;


