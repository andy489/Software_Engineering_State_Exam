-- 2016-09-09, 4
USE Ships;

-- 4.1. Б)
SELECT country, COUNT(result)
FROM classes c JOIN ships a ON c.class = a.class
JOIN outcomes o ON s.name = o.ship
WHERE result = 'sunk'
GROUP BY c.country;

-- 4.2. A)
SELECT DISTINCT battle
FROM outcomes o1
WHERE ( SELECT COUNT(DISTINCT country)
FROM outcomes o, ships s, classes c
WHERE o.ship = s.name AND s.class = c.class AND battle = o1.battle)
>
( SELECT COUNT(DISTINCT country)
FROM outcomes o, ships s, classes c
WHERE o.ship = s.name AND s.class = c.class AND battle = 'Coral Sea');