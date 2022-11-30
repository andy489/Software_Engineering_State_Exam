-- 2021-07-13, 4
USE PC;

-- 4.1.
SELECT code, price
FROM Laptop
WHERE screen BETWEEN 13 AND 15
AND ram IN (SELECT ram FROM PC);

-- 4.2 version-1
SELECT maker, COUNT(code) AS cnt
FROM Laptop L RIGHT JOIN Product P
ON L.model = P.model AND screen = 15
GROUP BY maker
-- ORDER BY maker ASC;

-- 4.2 version-2
SELECT maker, COUNT(code) AS cnt
FROM Product P LEFT JOIN Laptop L 
ON P.model = L.model AND screen = 15
GROUP BY maker
-- ORDER BY maker ASC;