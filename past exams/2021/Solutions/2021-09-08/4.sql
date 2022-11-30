-- 2021-09-08, 4
USE Movies;

-- 4.1. В)
SELECT studioName
FROM Movie
WHERE inColor = 'Y' 
INTERSECT 
SELECT studioName
FROM Movie
WHERE length IS NULL;

-- Alternative solution
SELECT DISTINCT studioName
FROM Movie
WHERE inColor = 'Y' AND studioName IN ( SELECT studioName
                                        FROM Movie
                                        WHERE length IS NULL);

-- 4.2 Б)
SELECT name, COUNT(title)
FROM MovieStar
LEFT JOIN StarsIn ON name = starName
LEFT JOIN Movie 
    ON movieTitle = title 
    AND movieYear = year 
    AND inColor = 'N'
WHERE gender = 'F'
GROUP BY name;