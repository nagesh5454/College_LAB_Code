create database  mane2;

use mane2;

create table nagesh2(
   rollno int primary key ,
   name varchar(50),
   marks int not null,
   grade varchar(1),
   city varchar(20)
);

insert into nagesh2
(rollno , name , marks, grade ,city)
values
(101, "anil" ,78 ,"c" ,"pune"),
(102, "bhumika" ,93 ,"A" ,"mumbai"),
(103, "chetan" ,85 ,"B" ,"mumbai"),
(104, "dhuva" ,96 ,"A" ,"delhi"),
(105, "emanuel" ,12,"F" ,"delhi"),
(106, "farah" ,82,"B" ,"delhi");

-- ----------------------------------------------------------------------
-- select in detail    : used to select any data from the database 
-- basic syntax
   --  select col1 ,col2 from table_name;
   
  -- to select all                  
    -- select * from table_name ;
-- -----------------------------------------------------------------------

select name , marks from nagesh2;

 select *from nagesh2;
 
 select distinct city from  nagesh2;
 
 -- where clause ------------------------------------------------------------------------
   -- to define some conditions 
        -- select col1 ,col2 from table_name 
        --  where condtion;
        
	-- using operators in where
       -- Arithmatic operators :+(addition) ,-(substraction) , *(multiplication) ,/(division) ,%(modulus)
	   -- Comparison operators: =(eqal to ) ,!=(not equal to ) ,>, >=,<,<=
       -- Logical operator     : and ,or , not , in , between , all , like , any 
	   -- betwise operators :  &( betwise and )  , |(bitwise or)
       
-- ----------------------------------------------------------------------------------------
select * from nagesh2 where marks>80;
select * from nagesh2 where city="mumbai";

select * from nagesh2 where  marks+10 >90;
select *from nagesh2 where marks>80 and city ="mumbai";
select *from nagesh2 where marks>90 or city ="mumbai";

 -- between( select for a given range
select *from nagesh2 where marks between 85 and 90;

  -- IN (matches any value in the list)
select  * from nagesh2 where city in ("delhi" ,"mumbai");

  -- NOT ( to negate the given condition)
select * from nagesh2 where city not in ("delhi" , "mumbai");

-- limit clause--------------------------------------------------------------
  -- set an upper limit on number of (tuples ) rows to be returned 
    -- select col , col2  from table_name 
	--  limit number;
-- ------------------------------------------------------------------------------
 select * 
 from nagesh2 
 where marks> 75
 limit 3;
 
 -- order by clause----------------------------------------------
  -- to sort in ascending (ASC) or descending(DESV)
   --  select col1,col2 from table_name orderby col_names ASC  
 
-- -----------------------------------------------------------------
select * from nagesh2 order by  city ASC;
select * from nagesh2 order by  city DESC;
select * from nagesh2 order by  marks  DESC  limit 3 ;    -- TOP 3 toppers on the basis of marks 


-- Aggregare Functions ---------------------------------------------------------------
  -- Aggregate functions perform a calculation on a set of values  , and return  a single values

  --  . count()  , . MAX()  ,. MIN() ,  . SUM()  , . AVG()   
  
--  ---------------------------------------------------------------------------------------

select max(marks) from nagesh2;
select min(marks) from nagesh2;
select avg(marks) from nagesh2;
select sum(marks) from nagesh2;
select count(rollno) from nagesh2;

-- Group by Clause----------------------------------------------------------------
   -- group rows that have the same values into summary rows
   -- it collects data from multiple records and groups the result by one or more column
 
 -- generally we use group by with some aggregation function
-- count number of students in each city 

-- ---------------------------------------------------------------------------------

select city,count(rollno)
from nagesh2  group by city ;

-- Practice Que : write the query to find avg marks in each city in decending order
 
select city , avg (marks)
from nagesh2
group by city
order by avg(marks) DESC;   -- in descending order


-- practice que 
select grade , COUNT(rollno)
from nagesh2
group by grade 
order by grade ;

-- Having clause-----------------------------------------------------------------------
     -- similar to where i. e . applies some condition on rows .
	 -- used when we want to apply any condition after grouping
     

 -- ------------------------------------------------------------------------------
      -- conut number of student in each city wherer max marks cross 90
      
 select city,count(name)
 from nagesh2
 group by city 
 having max(marks)>90;
 
 -- general order--------------------------------------------------------------------
   -- select columns
   -- from table_name
   -- where condition
   -- group by column(s)
   -- having condition 
   -- order by column(s) ASC
-- ---------------------------------------------------------------------------------
   
-- ex
  select city
  from nagesh2
  where grade = "A"
  group by city 
  Having max(marks) >=90
  order by city  DESC;
  
  

 
 
 
     















