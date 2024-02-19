 <!DOCTYPE html>
 <html lang="en">
 <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
 </head>
 <body>
 <?php
    $text="I am Nagesh Mane pursuing Btech in IT from Dr Babasaheb Ambedkar Technological Univarsity";
    $character="a";
    $count=substr_count($text,$character);

    echo "the character '$character' appears $count times in the text";

    ?>

 </body>
 </html>