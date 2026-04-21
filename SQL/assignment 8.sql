-- =========================
-- CREATE TABLES
-- =========================

CREATE TABLE student (
    prn VARCHAR2(15) PRIMARY KEY,
    name VARCHAR2(50),
    address VARCHAR2(100),
    dob DATE,
    fees NUMBER
);

CREATE TABLE Parts (
    pno NUMBER PRIMARY KEY,
    pname VARCHAR2(50),
    qty_on_hand NUMBER,
    price NUMBER(10,2),
    level_no NUMBER
);

CREATE TABLE Parts_log (
    pno NUMBER,
    username VARCHAR2(30),
    update_date DATE,
    old_price NUMBER(10,2),
    new_price NUMBER(10,2)
);

-- =========================
-- TRIGGER 1: STUDENT VALIDATION
-- =========================

CREATE OR REPLACE TRIGGER student_validation
BEFORE INSERT OR UPDATE ON student
FOR EACH ROW
BEGIN
    IF LENGTH(:NEW.prn) < 10 THEN
        RAISE_APPLICATION_ERROR(-20001, 'PRN must be at least 10 characters');
    END IF;

    IF MONTHS_BETWEEN(SYSDATE, :NEW.dob)/12 < 18 THEN
        RAISE_APPLICATION_ERROR(-20002, 'Student must be at least 18 years old');
    END IF;

    IF :NEW.fees <= 0 THEN
        RAISE_APPLICATION_ERROR(-20003, 'Fees must be greater than 0');
    END IF;
END;
/

-- =========================
-- TRIGGER 2: PRICE UPDATE LOG
-- =========================

CREATE OR REPLACE TRIGGER price_update_log
AFTER UPDATE OF price ON Parts
FOR EACH ROW
BEGIN
    INSERT INTO Parts_log (pno, username, update_date, old_price, new_price)
    VALUES (:OLD.pno, USER, SYSDATE, :OLD.price, :NEW.price);
END;
/

-- =========================
-- SAMPLE DATA
-- =========================

INSERT INTO student VALUES (
    '1234567890',
    'Pushkar',
    'Pune',
    TO_DATE('2000-05-10','YYYY-MM-DD'),
    50000
);

INSERT INTO Parts VALUES (10503, 'Motor', 200, 19.50, 20);

-- =========================
-- TEST UPDATE (TRIGGER FIRES)
-- =========================

UPDATE Parts
SET price = 25.00
WHERE pno = 10503;

-- =========================
-- CHECK LOG
-- =========================

SELECT * FROM Parts_log;

-- =========================
-- DROP TRIGGERS (OPTIONAL)
-- =========================

-- DROP TRIGGER student_validation;
-- DROP TRIGGER price_update_log;