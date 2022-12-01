-- 2018-09-10, 4
USE Ships;

-- 4.1. 
SELECT C.class, MIN(YEAR(B.date)) AS firts_battle_year,    
MAX(YEAR(B.date)) AS last_battle_year, 
COUNT(DISTINCT B.name) AS cnt_battles 
FROM Classes C LEFT JOIN Ships S ON C.class = S.class 
LEFT JOIN Outcomes O ON S.name = O.ship 
LEFT JOIN Battles B ON O.battle = B.name
WHERE C.class LIKE "N%"
GROUP BY C.class;

-- 4.2. version 1
SELECT O.battle, COUNT(*) AS cnt_bb
FROM Classes C INNER JOIN Ships S ON C.class = S.class
INNER JOIN Outcomes O ON S.name = O.ship
WHERE C.type LIKE 'bb'
GROUP BY O.battle
HAVING COUNT(*) > (SELECT COUNT(*)
FROM Classes C1 INNER JOIN Ships S1 ON C1.class = S1.class
INNER JOIN Outcomes O1 ON S1.name = O1.ship
WHERE C1.type LIKE 'bc' AND O1.battle = O.battle);
-- 4.2. version 2 
SELECT TABLE_BB.battle, TABLE_BB.cnt_bb
FROM (SELECT O.battle, COUNT(*) AS cnt_bb
FROM Classes C INNER JOIN Ships S ON C.class = S.class
INNER JOIN Outcomes O ON S.name = O.ship
WHERE C.type LIKE 'bb'
GROUP BY O.battle) TABLE_BB
LEFT JOIN (SELECT O.battle, COUNT(*) AS cnt_bc
FROM Classes C INNER JOIN Ships S ON C.class = S.class
INNER JOIN Outcomes O ON S.name = O.ship
WHERE C.type LIKE 'bc'
GROUP BY O.battle) TABLE_BC
ON TABLE_BB.battle = TABLE_BC.battle
WHERE TABLE_BB.cnt_bb >= TABLE_BC.cnt_bc;