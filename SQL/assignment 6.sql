CREATE DATABASE Something;
USE Something;

-- CREATE TABLES

CREATE TABLE Employees (
    employee_id INT PRIMARY KEY,
    name VARCHAR(50),
    salary DECIMAL(10,2),
    hire_date DATE
);

CREATE TABLE EmployeeSalaryLog (
    log_id INT AUTO_INCREMENT PRIMARY KEY,
    employee_id INT,
    old_salary DECIMAL(10,2),
    new_salary DECIMAL(10,2),
    log_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- SAMPLE DATA
INSERT INTO Employees VALUES
(1,'Amit',40000,'2018-01-01'),
(2,'Ravi',30000,'2022-01-01'),
(3,'Neha',60000,'2010-01-01');

--------------------------------------------------
-- Q1: PROCEDURE UpdateEmployeeSalary

DELIMITER $$

CREATE PROCEDURE UpdateEmployeeSalary(
    IN p_emp_id INT,
    IN p_new_salary DECIMAL(10,2)
)
BEGIN
    DECLARE v_old_salary DECIMAL(10,2);
    DECLARE v_count INT;

    -- check if employee exists using COUNT
    SELECT COUNT(*) INTO v_count
    FROM Employees
    WHERE employee_id = p_emp_id;

    IF v_count > 0 THEN

        -- get old salary
        SELECT salary INTO v_old_salary
        FROM Employees
        WHERE employee_id = p_emp_id;

        -- update salary
        UPDATE Employees
        SET salary = p_new_salary
        WHERE employee_id = p_emp_id;

        -- insert log
        INSERT INTO EmployeeSalaryLog(employee_id, old_salary, new_salary)
        VALUES (p_emp_id, v_old_salary, p_new_salary);

    END IF;

END$$

DELIMITER ;

-- CALL PROCEDURE
CALL UpdateEmployeeSalary(1, 50000);

--------------------------------------------------
-- Q2: FUNCTION CalculateAnnualBonus

DELIMITER $$

CREATE FUNCTION CalculateAnnualBonus(p_emp_id INT)
RETURNS DECIMAL(10,2)
DETERMINISTIC
BEGIN
    DECLARE v_salary DECIMAL(10,2);
    DECLARE v_years INT;
    DECLARE v_bonus DECIMAL(10,2);

    -- check employee exists
    IF NOT EXISTS (SELECT 1 FROM Employees WHERE employee_id = p_emp_id) THEN
        RETURN NULL;
    END IF;

    -- get salary and years of service
    SELECT salary, TIMESTAMPDIFF(YEAR, hire_date, CURDATE())
    INTO v_salary, v_years
    FROM Employees
    WHERE employee_id = p_emp_id;

    -- bonus calculation
    IF v_years < 5 THEN
        SET v_bonus = v_salary * 0.10;
    ELSEIF v_years >= 5 AND v_years < 10 THEN
        SET v_bonus = v_salary * 0.15;
    ELSE
        SET v_bonus = v_salary * 0.20;
    END IF;

    RETURN v_bonus;
END$$

DELIMITER ;

-- CALL FUNCTION
SELECT CalculateAnnualBonus(1) AS bonus;

drop database Something;