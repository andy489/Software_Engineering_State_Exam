-- 2020-08-05, 4
USE Movies;

-- 4.1.
SELECT DISTINCT namе, birthdate
FROM MovieStar INNER JOIN StarsIn ON namе = starName
INNER JOIN Movie ON movieTitle = title AND movieYear = year
WHERE name NOT LIKE "%Jr.%" AND inColor = "Y"
ORDER BY birthdate DESC, name ASC;

-- 4.2.
SELECT namе, YEAR(birthdate) AS birthdate, COUNT(DISTINCT studioName) AS studio_cnt
FROM MovieStar LEFT JOIN StarsIn ON name = starName
    LEFT JOIN Movie ON movieTitle = title AND movieYear = year
WHERE gender = 'F'
GROUP BY name
HAVING COUNT(studioName) < 7;