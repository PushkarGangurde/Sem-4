CREATE USER 'pushkar'@'localhost' IDENTIFIED BY 'Gangurde@156';
GRANT SELECT, INSERT ON db1.* TO 'pushkar'@'localhost';
CREATE DATABASE db1;
USE db1;

CREATE TABLE suppliers (
    Sno INT PRIMARY KEY,
    name VARCHAR(50),
    status INT,
    city VARCHAR(50) DEFAULT 'Pune'
);

SHOW TABLES;
DESC suppliers;

ALTER TABLE suppliers
ADD phone VARCHAR(15);

ALTER TABLE suppliers
MODIFY name VARCHAR(100) NOT NULL;

ALTER TABLE suppliers
DROP COLUMN status;

ALTER TABLE suppliers
ADD CONSTRAINT uq_supplier_name UNIQUE (name);

CREATE TABLE parts (
    Pno INT PRIMARY KEY,
    Pname VARCHAR(50) NOT NULL,
    colour VARCHAR(50),
    weight DECIMAL(7,2),
    city VARCHAR(50) DEFAULT 'Pune',
    CHECK (weight >= 0)
);

SHOW TABLES;
DESC parts;

ALTER TABLE parts
ADD category VARCHAR(30);

ALTER TABLE parts
MODIFY weight DECIMAL(10,2);

ALTER TABLE parts
RENAME COLUMN colour TO color;

CREATE TABLE projects (
    Jno INT PRIMARY KEY,
    Jname VARCHAR(50) NOT NULL,
    city VARCHAR(50) DEFAULT 'Pune'
);

SHOW TABLES;
DESC projects;

ALTER TABLE projects
ADD start_date DATE;

ALTER TABLE projects
ALTER city SET DEFAULT 'Mumbai';

CREATE TABLE shipment (
    Sno INT,
    Pno INT,
    Jno INT,
    Quantity INT CHECK (Quantity > 0),
    PRIMARY KEY (Sno, Pno, Jno),
    FOREIGN KEY (Sno) REFERENCES suppliers(Sno),
    FOREIGN KEY (Pno) REFERENCES parts(Pno),
    FOREIGN KEY (Jno) REFERENCES projects(Jno)
);

DESC shipment;

ALTER TABLE shipment
ADD ship_date DATE;

ALTER TABLE shipment
MODIFY Quantity INT NOT NULL;

ALTER TABLE shipment
ADD INDEX idx_quantity (Quantity);

ALTER TABLE shipment RENAME TO shipments;

REVOKE ALL PRIVILEGES ON db1.* FROM 'pushkar'@'localhost';
Delete user 'pushkar'@'localhost'
drop database db1;