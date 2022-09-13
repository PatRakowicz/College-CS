/* 
   CS 195
   Patrick Rakowicz | Caleb Domenico
   Exam 3
   195_Exam3_PatrickRakowicz_CalebDomenico
*/
use customersAndProducts;

#1
select quantity,
if(quantity<= 5 and quantity<10, 'poor', if(quantity<=10, 'good', if(quantity>10, 'great', null))) as 'quantity info'
from orderLines;

#2
select orders.orderId as 'Order #', price*quantity as 'Order Total', customerName as 'Customer'
from orderLines join products join orders join customers
on orderLines.productId = products.productId
and orderLines.orderId = orders.orderId
and orders.customerId = customers.customerId;

#3
select distinct fname, lname, email
from orders join customerContacts
on orders.customerId = customerContacts.customerId
where email in (
select email
    from orders join customerContacts
    on orders.customerId = customerContacts.customerId
    where orderDate >= '2006-02-01' and orderDate < '2006-03-01');

#4
select distinct customerName
from orders join customers
on orders.customerId = customers.customerId
where customerName not in(
select customerName
    from orders join customers
    on orders.customerId = customers.customerId
    where orderDate >= '2006-02-01' and orderDate < '2006-03-01');


#5
select distinct customerName, email
from customers join customerContacts join orderLines join products join orders
on orderLines.orderId = orders.orderId
and customers.customerId = customerContacts.customerId
and orderLines.productId = products.productId
where orders.orderId in (
select orderId
    from orderLines join products
    on orderLines.productId = products.productId
    where productName = 'Medium Product');


#6
select customerName as 'Customer',products.productId as 'Id', max(quantity) as 'Max Qty'
from customers join products join orders join orderLines
on orders.orderId = orderLines.orderId
and orderLines.productId = products.productId
and customers.customerId = orders.customerId
group by customerName, products.productId
order by customerName;


#7
select customerName, orders.orderId
from customers join orders join orderLines join products
on customers.customerId = orders.customerId
and orders.orderId = orderLines.orderId
and orderLines.productId = products.productId
where quantity*price > (
	select sum(quantity*price/7)
	from orderLines join products
	on orderLines.productId = products.productId);


use studentsTeachersAndClasses;  
#8
select className from students 
join studentsXclasses join classes
on students.studentId = studentsXclasses.studentId
and studentsXclasses.classId = classes.classId
where stuName = 'Meghan';


#9
select distinct teachName as 'Teachers'
from students join studentsXclasses
            join classes join teachersXclasses join teachers
on students.studentId = studentsXclasses.studentId
            and studentsXclasses.classId = classes.classId
    and classes.classId = teachersXclasses.classId
    and teachersXclasses.teacherId = teachers.teacherId
where stuName = 'Meghan';


#10
select distinct stuName
from students
	join studentsXclasses 
	join teachersXclasses
	join teachers
on students.studentId = studentsXclasses.studentId
	and studentsXclasses.classId = teachersXclasses.classid
    and teachersXclasses.teacherId = teachers.teacherId
where teachName = 'H Keck' and stuName not in (
		select distinct stuName
		from students
			join studentsXclasses 
			join teachersXclasses
			join teachers
		on students.studentId = studentsXclasses.studentId
			and studentsXclasses.classId = teachersXclasses.classid
			and teachersXclasses.teacherId = teachers.teacherId
		where teachName = 'K Fix'
);


#11
select count(stuName)
from students join studentsXclasses join classes
on students.studentId = studentsXclasses.studentId and studentsXclasses.classId = classes.classId
where className = 'Automata';


#12
select distinct stuName
from students join studentsXclasses join classes
on students.studentId = studentsXclasses.studentId 
and studentsXclasses.classId = classes.classId
where className not in (
	select classname
	from students join studentsXclasses join classes
	on students.studentId = studentsXclasses.studentId 
    and studentsXclasses.classId = classes.classId
	where (stuName = 'Dan' or stuName = 'Meghan')
);


#13
select *
from students
where stuName like '%a%' and stuName not like '%e%' and stuName not like '%n%';


#14
create view stuInfo as
select stuName, students.studentId, className, classes.classId
from students join studentsXclasses join classes
on students.studentId = studentsXclasses.studentId
and studentsXclasses.classId = classes.classId;

select stuName, className
from stuInfo
order by stuName;


#15
drop procedure if exists StudentClasses;
DELIMITER //
CREATE PROCEDURE StudentClasses(IN Input char(10))
BEGIN
    select className from students 
    join studentsXclasses join classes
	on students.studentId = studentsXclasses.studentId
		and studentsXclasses.classId = classes.classId
	where stuName = Input;
END //
DELIMITER ;

call StudentClasses('Meghan');

#16
SELECT date_format(now(), '%W, %M %D, %Y, %l:%i %p') AS result;

#17
select date_add(date_add(curdate(), interval 1 month), interval 1 week);

#18
drop database if exists NameTest;
drop table if exists ListNames;
create database NameTest;
use NameTest;
create table ListNames (
	NameId int primary key,
    InputName varchar(10)
);
insert into ListNames 
values (1, 'sAmUel'); 
select * from ListNames;

select concat(upper(left(InputName, 1)), 
lower(substring(InputName, 2, length(InputName) - 1)))
as 'Cap First Lower last'
from ListNames;