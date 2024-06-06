DELIMITER $$

CREATE FUNCTION factorial(n INT) 
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE result INT DEFAULT 1;
    DECLARE i INT DEFAULT 1;
    
    IF n < 0 THEN
        RETURN NULL;  -- Factorial is not defined for negative numbers
    END IF;
    
    WHILE i <= n DO
        SET result = result * i;
        SET i = i + 1;
    END WHILE;
    
    RETURN result;
END$$

DELIMITER ;


SELECT factorial(5) AS result;
