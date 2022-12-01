-- 2014-07-15, 6
USE PC

-- 6.1 A)
SELECT DISTINCT maker
FROM Product
WHERE Product.type = 'PC'
AND maker in (SELECT maker
FROM Product JOIN Laptop ON Product.model = Laptop.model);

-- 6.2. Г)
SELECT l.code, l.model, l.screen
FROM Product p LEFT JOIN Laptop l ON p.model = l.model 
LEFT JOIN Printer on p.model = Printer.model
GROUP BY l.code
HAVING COUNT(DISTINCT Printer.code) <= 3;