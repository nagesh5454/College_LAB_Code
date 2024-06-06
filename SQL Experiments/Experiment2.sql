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

-- Step 5: Run Queries with Subqueries

-- Query 1: Find the names of employees who work in the "Sales" department.
SELECT name
FROM employees
WHERE dept_id = (
    SELECT dept_id
    FROM departments
    WHERE dept_name = 'Sales'
);

-- Query 2: Find the employees who earn more than the average salary.
SELECT name, salary
FROM employees
WHERE salary > (
    SELECT AVG(salary)
    FROM employees
);

-- Query 3: Find the average salary for each department and list departments with an average salary greater than 50000.
SELECT dept_name, avg_salary
FROM (
    SELECT d.dept_name, AVG(e.salary) AS avg_salary
    FROM employees e
    JOIN departments d ON e.dept_id = d.dept_id
    GROUP BY d.dept_name
) AS dept_avg
WHERE avg_salary > 50000;

-- Query 4: Find the departments that have no employees.
SELECT dept_name
FROM departments d
WHERE NOT EXISTS (
    SELECT 1
    FROM employees e
    WHERE e.dept_id = d.dept_id
);
