CREATE DATABASE EX7;
USE EX7;

CREATE TABLE customer (
    customer_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_name VARCHAR(100) NOT NULL,
    email VARCHAR(100),
    phone_number VARCHAR(15),
    region_id INT,
    address TEXT,
    FOREIGN KEY (region_id) REFERENCES region(region_id)
);

CREATE TABLE `order` (
    order_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT,
    order_date DATE,
    salesperson_id INT,
    total_amount DECIMAL(10, 2),
    FOREIGN KEY (customer_id) REFERENCES customer(customer_id),
    FOREIGN KEY (salesperson_id) REFERENCES person(person_id)
);

CREATE TABLE orderdetails (
    orderdetails_id INT AUTO_INCREMENT PRIMARY KEY,
    order_id INT,
    product_id INT,
    quantity INT NOT NULL,
    unit_price DECIMAL(10, 2),
    FOREIGN KEY (order_id) REFERENCES `order`(order_id),
    FOREIGN KEY (product_id) REFERENCES product(product_id)
);

CREATE TABLE region (
    region_id INT AUTO_INCREMENT PRIMARY KEY,
    region_name VARCHAR(100) NOT NULL
);

CREATE TABLE product (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    description TEXT,
    price DECIMAL(10, 2),
    stock_quantity INT
);

CREATE TABLE person (
    person_id INT AUTO_INCREMENT PRIMARY KEY,
    first_name VARCHAR(100) NOT NULL,
    last_name VARCHAR(100),
    email VARCHAR(100),
    phone_number VARCHAR(15),
    role VARCHAR(50) DEFAULT 'Salesperson'
);

INSERT INTO region (region_name) VALUES 
('North America'),
('Europe'),
('Asia'),
('South America'),
('Africa'),
('Oceania'),
('Middle East'),
('Eastern Europe');

INSERT INTO person (first_name, last_name, email, phone_number, role) VALUES 
('John', 'Smith', 'john.smith@example.com', '1234567890', 'Salesperson'),
('Mary', 'Johnson', 'mary.johnson@example.com', '1234567891', 'Salesperson'),
('Robert', 'Brown', 'robert.brown@example.com', '1234567892', 'Salesperson'),
('Linda', 'Davis', 'linda.davis@example.com', '1234567893', 'Salesperson'),
('James', 'Wilson', 'james.wilson@example.com', '1234567894', 'Salesperson'),
('Olivia', 'Taylor', 'olivia.taylor@example.com', '1234567895', 'Salesperson'),
('Lucas', 'Moore', 'lucas.moore@example.com', '1234567896', 'Salesperson'),
('Sophia', 'Anderson', 'sophia.anderson@example.com', '1234567897', 'Salesperson');

INSERT INTO customer (customer_name, email, phone_number, region_id, address) VALUES 
('Alice Cooper', 'alice.cooper@example.com', '2345678901', 1, '123 Maple Street, NY'),
('Bob Stone', 'bob.stone@example.com', '2345678902', 2, '456 Oak Street, London'),
('Charlie Baker', 'charlie.baker@example.com', '2345678903', 3, '789 Pine Street, Tokyo'),
('Diana Fox', 'diana.fox@example.com', '2345678904', 4, '101 Cherry Street, Rio'),
('Eva Green', 'eva.green@example.com', '2345678905', 5, '202 Birch Street, Cairo'),
('Frank Wright', 'frank.wright@example.com', '2345678906', 6, '303 Elm Street, Sydney'),
('Grace Hill', 'grace.hill@example.com', '2345678907', 7, '404 Cedar Street, Dubai'),
('Hannah King', 'hannah.king@example.com', '2345678908', 8, '505 Walnut Street, Warsaw'),
('Ian Parker', 'ian.parker@example.com', '2345678909', 1, '606 Redwood Street, NY'),
('Jenna Miller', 'jenna.miller@example.com', '2345678910', 2, '707 Chestnut Street, London');

INSERT INTO product (product_name, description, price, stock_quantity) VALUES 
('Laptop', 'High-end gaming laptop', 1500.00, 20),
('Smartphone', 'Flagship smartphone', 800.00, 50),
('Tablet', 'Portable tablet', 400.00, 30),
('Headphones', 'Wireless noise-cancelling headphones', 200.00, 100),
('Smartwatch', 'Wearable fitness tracker', 250.00, 40),
('Gaming Console', 'Next-gen gaming console', 500.00, 25),
('4K TV', 'Ultra HD smart TV', 1000.00, 15),
('VR Headset', 'Virtual Reality headset', 300.00, 10),
('Camera', 'Digital SLR camera', 1200.00, 5),
('Bluetooth Speaker', 'Portable Bluetooth speaker', 150.00, 60);

INSERT INTO `order` (customer_id, order_date, salesperson_id, total_amount) VALUES 
(1, '2024-09-01', 1, 2300.00),
(2, '2024-09-02', 2, 1000.00),
(3, '2024-09-03', 3, 1600.00),
(4, '2024-09-04', 4, 450.00),
(5, '2024-09-05', 1, 500.00),
(6, '2024-09-06', 5, 3000.00),
(7, '2024-09-07', 6, 1250.00),
(8, '2024-09-08', 7, 1500.00),
(9, '2024-09-09', 8, 1800.00),
(10, '2024-09-10', 5, 2500.00),
(1, '2024-09-11', 6, 900.00),
(2, '2024-09-12', 7, 1900.00),
(3, '2024-09-13', 8, 2100.00),
(4, '2024-09-14', 1, 300.00),
(5, '2024-09-15', 2, 700.00);

INSERT INTO orderdetails (order_id, product_id, quantity, unit_price) VALUES 
(1, 1, 1, 1500.00),  
(1, 2, 1, 800.00),   
(2, 3, 2, 400.00),   
(3, 4, 4, 200.00),   
(4, 5, 2, 250.00),   
(5, 4, 1, 200.00),
(6, 6, 3, 500.00),  
(6, 7, 1, 1000.00), 
(7, 8, 2, 300.00), 
(8, 9, 1, 1200.00), 
(8, 10, 2, 150.00), 
(9, 1, 1, 1500.00), 
(9, 5, 1, 250.00),  
(10, 3, 3, 400.00), 
(10, 6, 1, 500.00), 
(11, 4, 2, 200.00), 
(12, 2, 2, 800.00), 
(13, 9, 1, 1200.00),
(14, 10, 2, 150.00), 
(15, 7, 1, 1000.00), 
(15, 8, 1, 300.00);  
