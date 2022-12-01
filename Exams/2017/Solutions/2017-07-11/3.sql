-- 2017-07-11, 3
USE Movies;

-- 3.1 
SELECT studioName, title, year
FROM Movie m
WHERE year = (  SELECT MAX(year)
FROM Movie
WHERE studioName = M.studioName);


-- 3.2. ver-1
SELECT name, SUM(length) AS len_sum
FROM MovieExec JOIN Movie ON producerc# = cert#
GROUP BY cert#
HAVING MIN(year) < 1980

-- 3.2. ver-1
SELECT name, SUM(length) AS len_sum
FROM MovieExec JOIN Movie ON producerc# = cert#
WHERE producerc# IN (   SELECT producerc#
FROM Movie
WHERE year < 1980)
GROUP BY cert#


-- 3.3.
SELECT starName, title, name, networth
FROM starsIn JOIN movie ON movieTitle = title AND movieYear = year
JOIN ( SELECT cert#, networth, name
FROM movieExec
WHERE networth = (  SELECT MAX(networth)
FROM MovieExec)
) t
ON producerc# = t.cert#;


-- 3.4. В)
SELECT name, title, year
FROM Movie JOIN MovieExec ON producerc# = cert#
WHERE cert# = ANY ( SELECT producerc#
FROM Movie
WHERE title = "Interstellar");