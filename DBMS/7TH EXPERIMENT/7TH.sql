CREATE DATABASE DBE7;
USE DBE7;
CREATE TABLE Branch (
    branchname VARCHAR(50) PRIMARY KEY,
    branchcity VARCHAR(50) NOT NULL,
    asset DECIMAL(15, 2) NOT NULL CHECK (asset > 0)
);

CREATE TABLE Customer (
    custname VARCHAR(50) PRIMARY KEY,
    custstreet VARCHAR(100),
    custcity VARCHAR(50) NOT NULL
);

CREATE TABLE Account (
    accnum INT PRIMARY KEY,
    branchname VARCHAR(50),
    balance DECIMAL(15, 2) NOT NULL CHECK (balance > 500),
    FOREIGN KEY (branchname) REFERENCES Branch(branchname)
);

CREATE TABLE Loan (
    loanno INT PRIMARY KEY,
    branchname VARCHAR(50),
    amount DECIMAL(15, 2) NOT NULL CHECK (amount > 0),
    FOREIGN KEY (branchname) REFERENCES Branch(branchname)
);

CREATE TABLE Borrower (
    custname VARCHAR(50),
    loanno INT,
    PRIMARY KEY (custname, loanno),
    FOREIGN KEY (custname) REFERENCES Customer(custname),
    FOREIGN KEY (loanno) REFERENCES Loan(loanno)
);

CREATE TABLE Depositor (
    custname VARCHAR(50),
    accnum INT,
    PRIMARY KEY (custname, accnum),
    FOREIGN KEY (custname) REFERENCES Customer(custname),
    FOREIGN KEY (accnum) REFERENCES Account(accnum)
);

INSERT INTO Branch (branchname, branchcity, asset) VALUES 
('Downtown', 'New York', 1000000.00),
('Uptown', 'New York', 1500000.00),
('Brooklyn', 'Brooklyn', 500000.00),
('Queens', 'Queens', 700000.00),
('Harlem', 'New York', 300000.00);
INSERT INTO Branch (branchname,branchcity,asset) VALUES
('Florida','Brooklyn',3000000.00),
('Kingslanding','Brooklyn',15000000.00);

INSERT INTO Customer (custname, custstreet, custcity) VALUES 
('John Doe', '123 Elm St', 'New York'),
('Jane Smith', '456 Oak St', 'Brooklyn'),
('Alice Brown', '789 Pine St', 'Queens'),
('Bob Johnson', '321 Maple St', 'New York'),
('Charlie Davis', '654 Cedar St', 'Harlem');

INSERT INTO Account (accnum, branchname, balance) VALUES 
(1001, 'Downtown', 2000.00),
(1002, 'Uptown', 3000.00),
(1003, 'Brooklyn', 1500.00),
(1004, 'Queens', 4000.00),
(1005, 'Harlem', 2500.00);
INSERT INTO Account (accnum,branchname,balance) VALUES
(1006,'Florida',3500.00),
(1007,'kingslanding',5000.00);

INSERT INTO Loan (loanno, branchname, amount) VALUES 
(2001, 'Downtown', 50000.00),
(2002, 'Uptown', 60000.00),
(2003, 'Brooklyn', 20000.00),
(2004, 'Queens', 30000.00),
(2005, 'Harlem', 10000.00);
INSERT INTO Loan (loanno, branchname, amount) VALUES
(2006,'Florida',70000),
(2007,'kingslanding',40000);

INSERT INTO Borrower (custname, loanno) VALUES 
('John Doe', 2001),
('Jane Smith', 2003),
('Alice Brown', 2004),
('Bob Johnson', 2005);

INSERT INTO Depositor (custname, accnum) VALUES 
('John Doe', 1001),
('Jane Smith', 1003),
('Alice Brown', 1004),
('Charlie Davis', 1005);

-- 1. Find the name of the branch with the smallest number of assets
SELECT branchname
FROM Branch
WHERE asset = (SELECT MIN(asset) FROM Branch);

-- 2. Find the names of all branches that have assets greater than atleast one branch located in Brooklyn
SELECT branchname
FROM Branch
WHERE asset = (SELECT MAX(asset) FROM Branch WHERE branchcity="Brooklyn");

-- 3. Find all customers who have both an account and a loan at the bank
SELECT DISTINCT custname
FROM Customer 
WHERE custname IN (SELECT custname FROM Depositor)
AND custname IN (SELECT custname FROM Borrower);

-- 4. Find all customers who do have a loan at the bank, but do not have an account at the bank
SELECT DISTINCT custname
FROM Customer 
WHERE custname NOT IN (SELECT custname FROM Depositor)
AND custname IN (SELECT custname FROM Borrower);

-- 5. Find the details of the largest loan at each branch, including the branch name and the amount of the loan
SELECT branchname,amount
FROM Loan
WHERE amount = (SELECT MAX(amount) FROM Loan);

-- 6. Find all customers who have both an account and a loan at the bank
SELECT DISTINCT custname
FROM Customer 
WHERE custname IN (SELECT custname FROM Depositor)
AND custname IN (SELECT custname FROM Borrower);

-- 7. Find customers with an account but not a loan
SELECT DISTINCT custname
FROM Customer 
WHERE custname  IN (SELECT custname FROM Depositor)
AND custname NOT IN (SELECT custname FROM Borrower);

-- 8. Find the names of all branches that have assets greater than those of at least one branch located in Brooklyn
SELECT branchname
FROM Branch
WHERE asset = (SELECT MAX(asset) FROM Branch WHERE branchcity="Brooklyn");

-- 9. Find the names of all branches that have an asset value greater than that of each branch in Brooklyn
SELECT branchname
FROM Branch
WHERE asset = (SELECT MAX(asset) FROM Branch);

-- 10. Create view to be called all-customer contain all the customers of bank
CREATE VIEW all_customer AS
SELECT * FROM Customer;

-- 11. Find the largest total account balance of any branch
SELECT branchname,balance
FROM Account
WHERE balance = (SELECT MAX(balance) FROM Account);
