<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
$fact=1;
$num=5;
for($i=1;$i<=$num;$i++ ){
    $fact=$fact*$i;
}
echo "the factorial of $num  is ".$fact;
?>
</body>
</html>