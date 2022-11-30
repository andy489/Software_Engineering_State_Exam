-- 2015-07-14, 4
USE Movies

-- 4.1 Г)
SELECT starName
FROM StarsIn
JOIN Movie ON movieTitle = title AND movieYear = year 
WHERE starName NOT LIKE '%a' AND inColor = 'y' 
INTERSECT
SELECT starName
FROM StarsIn
JOIN Movie ON movieTitle = title AND movieYear = year
WHERE inColor = 'N';

-- 4.2. Б)
SELECT name, YEAR(birthdate), COUNT(DISTINCT studioName) 
FROM MovieStar 
LEFT OUTER JOIN StarsIn ON name = starName
LEFT JOIN Movie ON movieTitle = title AND movieYear = year 
GROUP BY name
HAVING COUNT(title) <= 5;