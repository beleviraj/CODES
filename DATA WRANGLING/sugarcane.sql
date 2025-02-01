CREATE DATABASE SUGARCANE;
USE SUGARCANE;

CREATE TABLE MACHINES (
    machine_id INT AUTO_INCREMENT PRIMARY KEY,
    machine_name VARCHAR(255) NOT NULL,
    machine_type VARCHAR(255) NOT NULL
);

CREATE TABLE WAREHOUSES (
    warehouse_id INT AUTO_INCREMENT PRIMARY KEY,
    warehouse_location VARCHAR(255) NOT NULL
);

CREATE TABLE CUSTOMERS (
    customer_id INT AUTO_INCREMENT PRIMARY KEY,
    customer_name VARCHAR(255) NOT NULL,
    contact_info VARCHAR(255)
);

CREATE TABLE PRODUCTS (
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name ENUM('Refined', 'Raw') NOT NULL,
    price_per_unit DECIMAL(10, 2) NOT NULL
);

CREATE TABLE DAILYSUGARPRODUCTION (
    production_date DATE NOT NULL,
    batch_id INT NOT NULL AUTO_INCREMENT,
    machine_id INT NOT NULL,
    production_quantity DECIMAL(10, 2) NOT NULL,
    sugar_type ENUM('Refined', 'Raw') NOT NULL,
    downtime DECIMAL(5, 2) NOT NULL, -- Downtime in hours
    PRIMARY KEY (batch_id),
    FOREIGN KEY (machine_id) REFERENCES MACHINES(machine_id)
);

CREATE TABLE INVENTORY (
    inventory_date DATE NOT NULL,
    material_type VARCHAR(255) NOT NULL, -- e.g., Raw materials, Sugar, Packaging, etc.
    stock_quantity DECIMAL(10, 2) NOT NULL,
    warehouse_id INT NOT NULL,
    reorder_level DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (warehouse_id) REFERENCES WAREHOUSES(warehouse_id)
);

CREATE TABLE SALES (
    sales_date DATE NOT NULL,
    customer_id INT NOT NULL,
    order_id INT NOT NULL AUTO_INCREMENT,
    product_id INT NOT NULL,
    sold_quantity DECIMAL(10, 2) NOT NULL,
    revenue DECIMAL(15, 2) NOT NULL, -- Revenue in dollars
    PRIMARY KEY (order_id),
    FOREIGN KEY (customer_id) REFERENCES CUSTOMERS(customer_id),
    FOREIGN KEY (product_id) REFERENCES PRODUCTS(product_id)
);


INSERT INTO MACHINES (machine_name, machine_type)
VALUES
('Centrifuge 01', 'Refining'),
('Evaporator 02', 'Raw Processing'),
('Boiler 03', 'Raw Processing'),
('Mixer 04', 'Refining'),
('Dryer 05', 'Packaging'),
('Centrifuge 06', 'Refining'),
('Crusher 07', 'Raw Processing'),
('Separator 08', 'Raw Processing'),
('Press 09', 'Raw Processing'),
('Dryer 10', 'Packaging');

INSERT INTO WAREHOUSES (warehouse_location)
VALUES
('New York, USA'),
('Mumbai, India'),
('São Paulo, Brazil'),
('Berlin, Germany'),
('Sydney, Australia'),
('Cairo, Egypt'),
('Shanghai, China'),
('Johannesburg, South Africa'),
('London, UK'),
('Mexico City, Mexico');

INSERT INTO CUSTOMERS (customer_name, contact_info)
VALUES
('Global Distributors', 'contact@globaldist.com'),
('SweetMart Ltd.', 'info@sweetmart.com'),
('SugarPlum Co.', 'support@sugarplum.co'),
('HappySugar Co.', 'hello@happysugar.com'),
('SweetDelight', 'sales@sweetdelight.com'),
('Refined Sugar Suppliers', 'contact@refinedsugar.com'),
('RawCane Distributors', 'info@rawcane.com'),
('SugarRush Inc.', 'support@sugarrush.com'),
('HealthySweets', 'contact@healthysweets.com'),
('SugarWorld', 'sales@sugarworld.com');

INSERT INTO PRODUCTS (product_name, price_per_unit)
VALUES
('Refined', 500.00),
('Raw', 300.00);

INSERT INTO DAILYSUGARPRODUCTION (production_date, machine_id, production_quantity, sugar_type, downtime)
VALUES
('2024-09-01', 1, 1500.00, 'Refined', 2.5),
('2024-09-01', 2, 2000.00, 'Raw', 1.5),
('2024-09-02', 3, 1800.00, 'Raw', 0.5),
('2024-09-02', 4, 1600.00, 'Refined', 1.0),
('2024-09-03', 5, 1400.00, 'Refined', 2.0),
('2024-09-03', 6, 1300.00, 'Refined', 1.5),
('2024-09-04', 7, 1200.00, 'Raw', 1.0),
('2024-09-04', 8, 1700.00, 'Raw', 0.5),
('2024-09-05', 9, 1500.00, 'Raw', 2.0),
('2024-09-05', 10, 1600.00, 'Refined', 1.5);

INSERT INTO INVENTORY (inventory_date, material_type, stock_quantity, warehouse_id, reorder_level)
VALUES
('2024-09-01', 'Sugar', 10000.00, 1, 500.00),
('2024-09-01', 'Raw Materials', 12000.00, 2, 600.00),
('2024-09-02', 'Packaging', 8000.00, 3, 400.00),
('2024-09-02', 'Sugar', 9000.00, 4, 500.00),
('2024-09-03', 'Raw Materials', 11000.00, 5, 600.00),
('2024-09-03', 'Sugar', 9500.00, 6, 500.00),
('2024-09-04', 'Packaging', 7000.00, 7, 400.00),
('2024-09-04', 'Sugar', 10500.00, 8, 500.00),
('2024-09-05', 'Raw Materials', 13000.00, 9, 600.00),
('2024-09-05', 'Packaging', 7500.00, 10, 400.00);

INSERT INTO SALES (sales_date, customer_id, product_id, sold_quantity, revenue)
VALUES
('2024-09-01', 1, 1, 500.00, 250000.00),
('2024-09-01', 2, 2, 700.00, 210000.00),
('2024-09-02', 3, 1, 600.00, 300000.00),
('2024-09-02', 4, 2, 900.00, 270000.00),
('2024-09-03', 5, 1, 800.00, 400000.00),
('2024-09-03', 6, 2, 1000.00, 300000.00),
('2024-09-04', 7, 1, 750.00, 375000.00),
('2024-09-04', 8, 2, 950.00, 285000.00),
('2024-09-05', 9, 1, 650.00, 325000.00),
('2024-09-05', 10, 2, 850.00, 255000.00);
