<?php
// Retrieve form data
$fname = $_POST['fname'];
$lname = $_POST['lname'];

// Validate form data
if ($fname && $lname) {
    // Save the data to the database or perform any other actions
    // For demonstration purposes, we'll just display the saved data
    echo "First Name: $fname<br>";
    echo "Last Name: $lname";
} else {
    echo "Please fill in all fields.";
}
?>