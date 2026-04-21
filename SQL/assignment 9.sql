-- =========================
-- PROBLEM 1: COMPOUND INTEREST USING CURSOR
-- =========================

-- Create Customer Table
CREATE TABLE Customer (
    cust_id NUMBER PRIMARY KEY,
    principal_amount NUMBER,
    rate_of_interest NUMBER,
    no_of_years NUMBER
);

-- Create TempList Table
CREATE TABLE TempList (
    cust_id NUMBER,
    compound_interest NUMBER
);

-- Insert Sample Data
INSERT INTO Customer VALUES (1, 10000, 5, 2);
INSERT INTO Customer VALUES (2, 20000, 7, 3);

-- Cursor Program
DECLARE
    CURSOR cust_cursor IS
        SELECT cust_id, principal_amount, rate_of_interest, no_of_years FROM Customer;

    v_id Customer.cust_id%TYPE;
    p Customer.principal_amount%TYPE;
    r Customer.rate_of_interest%TYPE;
    n Customer.no_of_years%TYPE;
    ci NUMBER;
BEGIN
    OPEN cust_cursor;
    LOOP
        FETCH cust_cursor INTO v_id, p, r, n;
        EXIT WHEN cust_cursor%NOTFOUND;

        -- Compound Interest Formula
        ci := p * POWER((1 + r/100), n) - p;

        INSERT INTO TempList VALUES (v_id, ci);
    END LOOP;

    CLOSE cust_cursor;
END;
/

-- View Result
SELECT * FROM TempList;


-- =========================
-- PROBLEM 2: EMPLOYEE SALARY UPDATE USING CURSOR
-- =========================

-- Create Employee Table
CREATE TABLE Employee (
    eno NUMBER PRIMARY KEY,
    fname VARCHAR2(50),
    age NUMBER,
    grade VARCHAR2(20),
    salary NUMBER
);

-- Insert Sample Data
INSERT INTO Employee VALUES (1, 'Amit', 35, 'Asst Prof', 50000);
INSERT INTO Employee VALUES (2, 'Neha', 40, 'Associate Prof', 60000);
INSERT INTO Employee VALUES (3, 'Raj', 50, 'Professor', 80000);

-- Cursor Program
DECLARE
    CURSOR emp_cursor IS
        SELECT eno, grade, salary FROM Employee;

    v_eno Employee.eno%TYPE;
    v_grade Employee.grade%TYPE;
    v_salary Employee.salary%TYPE;
BEGIN
    OPEN emp_cursor;
    LOOP
        FETCH emp_cursor INTO v_eno, v_grade, v_salary;
        EXIT WHEN emp_cursor%NOTFOUND;

        IF v_grade = 'Asst Prof' THEN
            UPDATE Employee SET salary = salary + 10000 WHERE eno = v_eno;

        ELSIF v_grade = 'Associate Prof' THEN
            UPDATE Employee SET salary = salary + 20000 WHERE eno = v_eno;

        ELSIF v_grade = 'Professor' THEN
            UPDATE Employee SET salary = salary + 30000 WHERE eno = v_eno;
        END IF;

    END LOOP;

    CLOSE emp_cursor;
END;
/

-- View Updated Data
SELECT * FROM Employee;