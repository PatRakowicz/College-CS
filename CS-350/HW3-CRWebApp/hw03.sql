CREATE DATABASE cs_350;

USE cs_350;

CREATE TABLE products (
    ID INT PRIMARY KEY,
    brand VARCHAR(255),
    name VARCHAR(255),
    price DECIMAL(10,2),
    year INT
);

GRANT ALL PRIVILEGES ON cs_350.*
TO 'student'@'localhost' IDENTIFIED BY 'CS350';