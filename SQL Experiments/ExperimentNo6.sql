-- What is a Trigger?:

-- A trigger is a database object that automatically performs an action in response to certain events on a particular table or view.

-- Step 1: Create the Database
CREATE DATABASE company_db;

-- Step 2: Use the Database
USE company_db;

-- Step 3: Create the Tables
CREATE TABLE departments (
    dept_id INT PRIMARY KEY AUTO_INCREMENT,
    dept_name VARCHAR(50) NOT NULL
);

CREATE TABLE employees (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    dept_id INT,
    salary DECIMAL(10, 2),
    FOREIGN KEY (dept_id) REFERENCES departments(dept_id)
);

CREATE TABLE employee_audit (
    audit_id INT PRIMARY KEY AUTO_INCREMENT,
    emp_id INT,
    action VARCHAR(50),
    action_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Step 4: Insert Data into Tables
INSERT INTO departments (dept_name) VALUES ('Sales'), ('Engineering'), ('HR'), ('Marketing');

INSERT INTO employees (name, dept_id, salary) VALUES 
('John Doe', 1, 60000),
('Jane Smith', 2, 80000),
('Alice Johnson', 1, 75000),
('Robert Brown', 3, 50000),
('Michael White', 2, 90000),
('Emily Davis', 4, 65000),
('Linda Wilson', 1, 70000);

-- Step 5: Create the Trigger
DELIMITER $$
CREATE TRIGGER before_employee_update
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_audit (emp_id, action) 
    VALUES (OLD.emp_id, CONCAT('Updated from salary ', OLD.salary, ' to ', NEW.salary));
END$$
DELIMITER ;

-- Step 6: Test the Trigger
UPDATE employees SET salary = 62000 WHERE emp_id = 1;
UPDATE employees SET salary = 83000 WHERE emp_id = 2;

-- Step 7: Check the Audit Log
SELECT * FROM employee_audit;
