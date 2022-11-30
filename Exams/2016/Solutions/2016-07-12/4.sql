-- 2016-07-12, 4
USE Movies

-- 4.1 A)
SELECT t.name, title
FROM movie m JOIN ( SELECT name, cert#
                    FROM Movieexec
                    WHERE cert# IN (SELECT producerc#
                                    FROM movie      
                                    WHERE title='Prety Woman')) T
ON m.producerc#=t.cert#

-- 4.2. Г)
SELECT studioname, starname, COUNT(*)
FROM Movie m JOIN StarsIn ON title = movieTitle AND year = movieYear 
WHERE studioName IS NOT NULL
GROUP BY studioName, starName
HAVING COUNT(*) >= ALL (SELECT COUNT(*)
						FROM Movie, StarsIn
						WHERE title = movieTitle AND year = movieYear AND studioName = m.studioName
						GROUP BY studioName, starName)