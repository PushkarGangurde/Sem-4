create database db2;
use db2;

SHOW TABLES;

CREATE TABLE employee (
    ename VARCHAR(50) PRIMARY KEY,
    street VARCHAR(100),
    city VARCHAR(50) DEFAULT 'Pune'
);

SHOW TABLES;
DESC employee;

CREATE TABLE company (
    cname VARCHAR(50) PRIMARY KEY,
    city VARCHAR(50) DEFAULT 'Pune'
);

SHOW TABLES;
DESC company;

CREATE TABLE works (
    ename VARCHAR(50),
    cname VARCHAR(50),
    salary DECIMAL(10,2) CHECK (salary >= 0),
    doj DATE NOT NULL,
    PRIMARY KEY (ename, cname),
    FOREIGN KEY (ename) REFERENCES employee(ename),
    FOREIGN KEY (cname) REFERENCES company(cname)
);

DESC works;

CREATE TABLE manages (
    ename VARCHAR(50),
    m_name VARCHAR(50),
    PRIMARY KEY (ename, m_name),
    FOREIGN KEY (ename) REFERENCES employee(ename),
    FOREIGN KEY (m_name) REFERENCES employee(ename)
);

DESC manages;
drop database db2;