-- 2014-09-11
USE Ships;

-- 6.1 Б)
SELECT DISTINCT Ships.name
FROM Battles, Ships
WHERE launched = YEAR(date);

-- 6.2. Д)
SELECT DISTINCT country, (SELECT COUNT(*)
FROM Classes c2 JOIN Ships s ON c2.class = s.class
JOIN Outcomes o on s.name = o.ship
WHERE c2.country = c.country AND result = 'sunk') AS cnt_sink
FROM Classes c
WHERE (SELECT COUNT(*)
FROM Classes c2 JOIN Ships s ON c2.class = s.class
WHERE c2.country = c.country) <= 3;