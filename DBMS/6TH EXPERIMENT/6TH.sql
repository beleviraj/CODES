CREATE DATABASE EX6;
USE EX6;
CREATE TABLE customer (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(50),
    city VARCHAR(50)
);
INSERT INTO customer (customer_id, customer_name, city) VALUES
(1, 'John Doe', 'Springfield'),
(2, 'Alice Smith', 'Seattle'),
(3, 'Bob Johnson', 'San Francisco'),
(4, 'Charlie Brown', 'Salt Lake City'),
(5, 'David White', 'Perryridge'),
(6, 'Emily Davis', 'Parkstreet'),
(7, 'Franklin Wood', 'Perryridge');

CREATE TABLE loan (
    loan_number INT PRIMARY KEY,
    loan_amount DECIMAL(10, 2),
    branch_name VARCHAR(50),
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id)
);
INSERT INTO loan (loan_number, loan_amount, branch_name, customer_id) VALUES
(101, 5000.00, 'Perryridge', 1),
(102, 7000.00, 'Perryridge', 5),
(103, 4000.00, 'Parkstreet', 6),
(104, 3000.00, 'Brooklyn', 2),
(105, 2000.00, 'Perryridge', 7),
(106, 8000.00, 'Parkstreet', 4);

CREATE TABLE account (
    account_number INT PRIMARY KEY,
    balance DECIMAL(10, 2),
    branch_name VARCHAR(50),
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id)
);
INSERT INTO account (account_number, balance, branch_name, customer_id) VALUES
(201, 1500.00, 'Brooklyn', 1),
(202, 500.00, 'Brooklyn', 2),
(203, 300.00, 'Perryridge', 5),
(204, 800.00, 'Parkstreet', 6),
(205, 100.00, 'Perryridge', 7),
(206, 1200.00, 'Parkstreet', 4);

SELECT customer_name, loan_number
FROM customer
JOIN loan ON customer.customer_id = loan.customer_id
WHERE branch_name = 'Perryridge';

SELECT DISTINCT customer_name
FROM customer
JOIN loan ON customer.customer_id = loan.customer_id
WHERE branch_name = 'Perryridge'
ORDER BY customer_name ASC;

SELECT DISTINCT branch_name
FROM customer
JOIN account ON customer.customer_id = account.customer_id
WHERE customer.city LIKE 'S%';

SELECT customer_name, loan_number, loan_amount
FROM customer
JOIN loan ON customer.customer_id = loan.customer_id;

SELECT DISTINCT customer_name
FROM customer
JOIN loan ON customer.customer_id = loan.customer_id
WHERE branch_name = 'Parkstreet'
ORDER BY customer_name ASC;

SELECT customer_name, loan_number,loan_number
FROM customer
JOIN loan ON customer.customer_id = loan.customer_id
WHERE branch_name = 'Perryridge';

SELECT customer_name,loan_number as loan_id
FROM customer
JOIN loan ON customer.customer_id=loan.customer_id;

SELECT customer_name, account_number, balance
FROM customer
JOIN account ON customer.customer_id = account.customer_id;

SELECT customer_name,loan_number,loan_amount
FROM customer
JOIN loan ON customer.customer_id=loan.customer_id
WHERE branch_name='Perryridge';

SELECT customer_name,account_number,balance
FROM customer
JOIN account ON customer.customer_id=account.customer_id
WHERE balance <= 400;

SELECT *
FROM account
WHERE branch_name = 'Brooklyn';

