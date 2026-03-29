-- CREATE DATABASE
CREATE DATABASE company_db;
USE company_db;

-- CREATE TABLES
CREATE TABLE Employee (
    emp_no INT PRIMARY KEY,
    name VARCHAR(50) NOT NULL,
    skill VARCHAR(50),
    pay_rate DECIMAL(10,2)
);

CREATE TABLE position_1 (
    posting_no INT PRIMARY KEY,
    skill VARCHAR(50)
);

CREATE TABLE Duty_allocation (
    posting_no INT,
    emp_no INT,
    day DATE,
    shift VARCHAR(20),
    PRIMARY KEY (posting_no, emp_no, day),
    FOREIGN KEY (posting_no) REFERENCES position_1(posting_no),
    FOREIGN KEY (emp_no) REFERENCES Employee(emp_no)
);

-- INSERT DATA
INSERT INTO Employee VALUES
(1, 'Amit', 'Java', 50000),
(2, 'Ravi', 'Python', 45000),
(3, 'Neha', 'Java', 55000),
(4, 'Priya', 'C++', 40000);

INSERT INTO position_1 VALUES
(101, 'Java'),
(102, 'Python'),
(103, 'C++'),
(104, 'AI');

INSERT INTO Duty_allocation VALUES
(101, 1, '2026-03-20', 'Morning'),
(102, 2, '2026-03-20', 'Evening'),
(101, 3, '2026-03-20', 'Night');

-- Q1: INNER JOIN
SELECT E.name, D.posting_no, D.shift
FROM Employee E
INNER JOIN Duty_allocation D
ON E.emp_no = D.emp_no
WHERE D.day = '2026-03-20';

-- Q2: LEFT JOIN (all employees)
SELECT E.name, D.posting_no, D.shift
FROM Employee E
LEFT JOIN Duty_allocation D
ON E.emp_no = D.emp_no
AND D.day = '2026-03-20';

-- Q3: Positions + employees (LEFT JOIN)
SELECT P.posting_no, E.name
FROM position_1 P
LEFT JOIN Duty_allocation D
ON P.posting_no = D.posting_no
AND D.day = '2026-03-20'
LEFT JOIN Employee E
ON D.emp_no = E.emp_no;

-- Q4: FULL OUTER JOIN using UNION
SELECT E.name, P.posting_no, D.shift
FROM Employee E
LEFT JOIN Duty_allocation D
ON E.emp_no = D.emp_no
AND D.day = '2026-03-20'
LEFT JOIN position_1 P
ON D.posting_no = P.posting_no

UNION

SELECT E.name, P.posting_no, D.shift
FROM position_1 P
LEFT JOIN Duty_allocation D
ON P.posting_no = D.posting_no
AND D.day = '2026-03-20'
LEFT JOIN Employee E
ON D.emp_no = E.emp_no;

-- Q5: SELF JOIN (same skill employees)
SELECT E1.name AS Employee1, E2.name AS Employee2, E1.skill
FROM Employee E1
JOIN Employee E2
ON E1.skill = E2.skill
AND E1.emp_no < E2.emp_no;

drop database company_db;