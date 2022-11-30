-- 2017-09-09, 3
USE Ships

-- 3.1 
SELECT name, country
FROM ships LEFT JOIN outcomes ON name = ship
		   LEFT JOIN classes ON ships.class = classes.class
WHERE result NOT LIKE 'sunk';

-- 3.2
SELECT name, displacement, numguns
FROM classes c JOIN ships s ON s.class = c.class
WHERE displacement = (SELECT MIN(displacement)
					  FROM classes) AND numguns = (	SELECT MAX(numguns)
					  								FROM classes c1)
													WHERE c1.classes = c.classes);

-- 3.3.
SELECT battle
FROM outcomes o1
WHERE NOT EXISTS (	SELECT *
					FROM outcomes o2
					WHERE o2.battle = o1.battle AND o2.ship <> o1.ship);

-- 3.4.
SELECT s.class, COUNT(DISTINCT name)
FROM ships s 	JOIN outcomes o ON s.name = o.ship
				JOIN (	SELECT c.class FROM classes c JOIN ships s ON c.class = s.class
						GROUP BY c.class, name
						HAVING COUNT(name) > 5)t ON s.class = t. class
WHERE result = 'sunk'
GROUP BY s.class;