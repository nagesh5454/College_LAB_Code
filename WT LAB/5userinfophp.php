<?php
  $user=[
  [
    'Name'=>'Nagesh Mane',
    'email'=>"mane45@gmal.com",
    'age'=>22
  ] ,
   [
    'Name'=>'vishwaraj sudrik',
    'email'=>"vish45@gmal.com",
    'age'=>21,
  ],
  [
    'Name'=>'adesh atole',
    'email'=>"adesh45@gmal.com",
    'age'=>19,
  ]
  ];
  //print informaation
  foreach($user as $users){
    echo "name :".$users['Name']."\n";
    echo "emain :".$users['email']."\n";
    echo "age :".$users['age']."\n";
  }
?>