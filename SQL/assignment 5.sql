CREATE DATABASE ecommerce_db;
USE ecommerce_db;


CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    first_name  VARCHAR(50),
    last_name   VARCHAR(50),
    email       VARCHAR(100),
    join_date   DATE
);


CREATE TABLE products (
    product_id   INT PRIMARY KEY,
    product_name VARCHAR(100),
    category     VARCHAR(50),
    price        DECIMAL(10,2)
);


CREATE TABLE employees (
    employee_id INT PRIMARY KEY,
    first_name  VARCHAR(50),
    last_name   VARCHAR(50),
    hire_date   DATE,
    department  VARCHAR(50)
);


CREATE TABLE orders (
    order_id     INT PRIMARY KEY,
    customer_id  INT,
    employee_id  INT,               
    order_date   DATE,
    total_amount DECIMAL(10,2),
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id),
    FOREIGN KEY (employee_id) REFERENCES employees(employee_id)
);


CREATE TABLE order_items (
    item_id    INT PRIMARY KEY,
    order_id   INT,
    product_id INT,
    quantity   INT,
    FOREIGN KEY (order_id)   REFERENCES orders(order_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);


INSERT INTO customers VALUES
(101, 'john',  'doe',   'john@example.com',  '2024-01-15'),
(102, 'alice', 'smith', 'alice@example.com', '2024-03-10'),
(103, 'bob',   'brown', 'bob@example.com',   '2023-05-20');


INSERT INTO products VALUES
(201, 'Rice',   'Food',        100.00),
(202, 'Oil',    'Food',        200.00),
(203, 'Laptop', 'Electronics', 50000.00);


INSERT INTO employees VALUES
(1, 'rahul', 'mehta',  '2018-01-01', 'Sales'),
(2, 'neha',  'sharma', '2021-06-01', 'Support');


INSERT INTO orders VALUES
(1, 101, 1, '2025-01-01',  5000.00),
(2, 101, 2, '2025-02-01',  7000.00),
(3, 102, 1, '2025-03-01', 15000.00);


INSERT INTO order_items VALUES
(1, 1, 201,  5),
(2, 2, 202,  3),
(3, 3, 201, 10),
(4, 3, 203,  1);


-- 1. Customer & Employee Analysis - Functional Single Row Functions & Data Sorting
SELECT
    -- 1.1 Capitalise first letter of first_name and last_name
    CONCAT(
        UPPER(LEFT(first_name, 1)), LOWER(SUBSTR(first_name, 2)),
        ' ',
        UPPER(LEFT(last_name, 1)),  LOWER(SUBSTR(last_name, 2))
    ) AS full_name,


    -- 1.2 Months since joining
    TIMESTAMPDIFF(MONTH, join_date, CURDATE()) AS membership_months,


    -- 1.3 keep first 3 chars, then '...', then everything from '@' onward
    CONCAT(
        LEFT(email, 3),
        '...',
        SUBSTRING(email, LOCATE('@', email))
    ) AS masked_email


FROM customers
WHERE YEAR(join_date) = 2024
ORDER BY join_date ASC;




-- 2: Sales Aggregation & Filtering - Aggregate Functions, GROUP BY, HAVING
SELECT
    p.category,
    SUM(p.price * oi.quantity)  AS total_revenue,
    AVG(oi.quantity)            AS avg_qty,
    COUNT(DISTINCT oi.order_id) AS total_orders
FROM products    p
JOIN order_items oi ON p.product_id = oi.product_id
GROUP BY p.category
HAVING SUM(p.price * oi.quantity) > 1000000;




-- 3: Employee Performance (Subqueries)
SELECT
    e.first_name,
    e.last_name,
    e.hire_date
FROM employees e
WHERE e.employee_id IN (
    -- employees linked to qualifying orders
    SELECT DISTINCT o.employee_id
    FROM orders o
    WHERE o.customer_id IN (
        -- customers whose total spending > avg customer spending
        SELECT customer_id
        FROM orders
        GROUP BY customer_id
        HAVING SUM(total_amount) > (
            SELECT AVG(total_spent)
            FROM (
                SELECT SUM(total_amount) AS total_spent
                FROM orders
                GROUP BY customer_id
            ) AS per_customer_totals
        )
    )
);




-- 4: Data Consolidation (Set Operations – UNION)
SELECT first_name, last_name
FROM employees
WHERE TIMESTAMPDIFF(YEAR, hire_date, CURDATE()) > 5


UNION


SELECT c.first_name, c.last_name
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name 
HAVING COUNT(o.order_id) >= 10;




-- 5: Simplified Access (VIEW)
CREATE VIEW v_top_customer_revenue AS
SELECT
    CONCAT(c.first_name, ' ', c.last_name) AS full_name,
    c.email,
    SUM(o.total_amount)                    AS total_spending
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id
GROUP BY c.customer_id, c.first_name, c.last_name, c.email
ORDER BY total_spending DESC
LIMIT 10;


SELECT * FROM v_top_customer_revenue;




-- 6: Data Integrity & Control (TCL Commands)
START TRANSACTION;
– update1
INSERT INTO customers (customer_id, first_name, last_name, email, join_date)
    SELECT 201, first_name, last_name, email, join_date
    FROM customers WHERE customer_id = 101;


UPDATE orders SET customer_id = 201 WHERE customer_id = 101;
DELETE FROM customers WHERE customer_id = 101;


—-savepoint
SAVEPOINT after_first_update;   


—-update 2
INSERT INTO customers (customer_id, first_name, last_name, email, join_date)
    SELECT 202, first_name, last_name, email, join_date
    FROM customers WHERE customer_id = 102;


UPDATE orders SET customer_id = 202 WHERE customer_id = 102;
DELETE FROM customers WHERE customer_id = 102;


ROLLBACK TO SAVEPOINT after_first_update;


INSERT INTO customers (customer_id, first_name, last_name, email, join_date)
    SELECT 202, first_name, last_name, email, join_date
    FROM customers WHERE customer_id = 102;


UPDATE orders SET customer_id = 202 WHERE customer_id = 102;
DELETE FROM customers WHERE customer_id = 102;


--Correct update
INSERT INTO customers (customer_id, first_name, last_name, email, join_date)
    SELECT 203, first_name, last_name, email, join_date
    FROM customers WHERE customer_id = 103;


UPDATE orders SET customer_id = 203 WHERE customer_id = 103;
DELETE FROM customers WHERE customer_id = 103;


COMMIT;


SELECT * FROM customers;
SELECT * FROM orders;


DROP DATABASE ecommerce_db;