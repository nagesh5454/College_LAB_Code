<?php
   $marks= (int)readline('enter num');

   if($marks>=60){
          echo "first division";
   }else if($marks>=45 && $mark<=59){
          echo "second division";
   }else if($marks>=33 && $mark<=44){
    echo "Third division";
   }else if($marks<33){
         echo "fail";
   }else{
        echo "invalid marks";
   }

   
   
?>