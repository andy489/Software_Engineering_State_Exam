-- 2015-09-15, 4
USE Movies

-- 4.1 Б)
SELECT *
FROM (SELECT name, address
FROM MovieStar
WHERE gender = 'F'
UNION
SELECT name, address
FROM Studio) T
WHERE T.address LIKE '%Sofia%'
ORDER BY T.address;

-- 4.2. Г)
SELECT name, address, AVG(length) AS avgLength 
FROM Studio
LEFT JOIN Movie ON name = studioName
WHERE NAME NOT IN (SELECT studioName
FROM Movie
WHERE inColor = 'n'
GROUP BY studioName
HAVING COUNT(*) > 3)
GROUP BY name, address;