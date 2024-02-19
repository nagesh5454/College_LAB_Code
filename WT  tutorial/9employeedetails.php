<?php
$employees = [];
function addEmployee($name, $role, $salary)
{
    global $employees;
    $employee = [
        'name' => $name,
        'role' => $role,
        'salary' => $salary
    ];
    $employees[] = $employee;
}


function display()
{
    global $employees;
    foreach ($employees as $employee) {
        echo "Name: " . $employee['name'] . "\n";
        echo "role: " . $employee['role'] . "\n";
        echo "Salary: " . $employee['salary'] . "\n";
        echo "\n";
    }
}
addEmployee("Nagesh Mane", "Manager", 50000);
addEmployee("rutvik lamture", "Developer", 300000);
addEmployee("soham ghamandi", "coder", 250000);

display();
?>