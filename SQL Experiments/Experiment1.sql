-- creating our first database
CREATE DATABASE  temp1;

-- delteting database 
DROP DATABASE temp1;

create database temp2;
drop database temp2;

create database dbatu;
use dbatu;

-- creating our first Table 

create table dbatu(
  id INT PRIMARY KEY,
  NAME varchar(50),
  age int not null
);

-- insert data into table 
insert into dbatu values(1,"Nagesh" ,26);
insert into dbatu values(3,"adesh",27);

--TO display the table dbatu
select * from dbatu;


-- create and drop  database if  exist

create database if not  exists dbatu;

drop database if exists mne;

show databases;

show tables;  -- it will show the tables of current database of currently we are using that database;

drop table dbatu;

-- create table

create table dbatu(
  rollno int primary key,
  name varchar(50)
);

-- insert data into table 
insert into dbatu values(1,"Nagesh" );
insert into dbatu values(3,"adesh");
-- method 2
insert into dbatu 
(rollno , name )
values
(101 ,"karan"),
(102 ,"arjun"),
(103 ,"ram");


-- select and view all columns 
select * from dbatu;
