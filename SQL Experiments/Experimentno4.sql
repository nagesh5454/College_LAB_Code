-- Step 1: Create the Database
CREATE DATABASE company_db;

-- Step 2: Use the Database
USE company_db;

-- Step 3: Create the Tables
CREATE TABLE employees (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    dept_id INT,
    salary DECIMAL(10, 2),
    hire_date DATE
);

CREATE TABLE departments (
    dept_id INT PRIMARY KEY AUTO_INCREMENT,
    dept_name VARCHAR(50) NOT NULL
);

-- Step 4: Insert Data into Tables
INSERT INTO departments (dept_name) VALUES ('Sales'), ('Engineering'), ('HR'), ('Marketing');

INSERT INTO employees (name, dept_id, salary, hire_date) VALUES 
('John Doe', 1, 60000, '2020-01-15'),
('Jane Smith', 2, 80000, '2019-05-22'),
('Alice Johnson', 1, 75000, '2018-07-30'),
('Robert Brown', 3, 50000, '2021-02-17'),
('Michael White', 2, 90000, '2017-09-10'),
('Emily Davis', 4, 65000, '2020-11-25'),
('Linda Wilson', 1, 70000, '2019-03-14');


--conversion function example 
--Task: Convert the salary to an integer and display it with employee names.
SELECT name, CAST(salary AS UNSIGNED) AS salary_int
FROM employees;


--string function example 
--Task: Concatenate employee names with their department names.
SELECT e.name, CONCAT(e.name, ' - ', d.dept_name) AS name_dept
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id;


--Date Function Example
--Task: Calculate the number of days each employee has been with the company.
SELECT name, DATEDIFF(CURDATE(), hire_date) AS days_with_company
FROM employees;
