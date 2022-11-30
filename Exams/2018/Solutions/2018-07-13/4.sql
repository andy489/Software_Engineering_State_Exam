-- 2018-07-13, 4
USE Movie

-- 4.1. EXCLUDING STUDIOS WITH 0 MOVIES
SELECT studioName, MIN(year) AS first_movie_year, MAX(year) AS last_movie_year, COUNT(title) AS cnt_movies
FROM Studio LEFT JOIN Movie ON name = studioName
WHERE studioName LIKE 'M%'
GROUP BY name;

-- 4.1. INCLUDING STUDIOS WITH 0 MOVIES
SELECT name, MIN(year) AS first_movie_year, MAX(year) AS last_movie_year, COUNT(title) AS cnt_movies 
FROM Studio LEFT JOIN Movie ON name = studioName
WHERE studioName LIKE 'M%'
GROUP BY name;

-- 4.2. 
SELECT starName, COUNT(movieTutle) AS cnt_movies
FROM StarsIn LEFT JOIN MovieStar ON starName = name
WHERE gedner = 'F'
GROUP BY name
HAVING COUNT(movieTitle) >= ALL(SELECT COUNT(movieTitle)
								FROM MovieStar LEFT JOIN StarsIn ON name = starName
								WHERE gender = 'F'
								GROUP BY name);