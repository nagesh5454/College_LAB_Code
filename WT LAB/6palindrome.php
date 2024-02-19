<?php
function isPalindrome($string) {
    
    
    // Reverse the string
    $reverse = strrev($string);
    
    // Compare 
    if ($string === $reverse) {
        return true;
    } else {
        return false;
    }
}


$word = "madam";
if (isPalindrome($word)==true) {
    echo "$word is a palindrome.";
} else {
    echo "$word is not a palindrome.";
}
?>
