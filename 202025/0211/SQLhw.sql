CREATE DATABASE temp;

use temp;

CREATE TABLE students (
    id int(5) auto_increment PRIMARY KEY,
    name char(10) NOT NULL,
    age int(5) NOT NULL,
    grade char(3) NOT NULL
);


INSERT INTO students values (1, 'Alice', 20, 'A');
INSERT INTO students values (2, 'Bob', 22, 'B');
INSERT INTO students values (3, 'Charlie', 21, 'A');
INSERT INTO students values (4, 'Dave', 23, 'C');

UPDATE students set age = 22 where name = 'Charlie';

SELECT name, age
FROM students
WHERE GRADE = 'A';

DELETE FROM students WHERE name = 'Dave';

INSERT INTO students (name, age, grade) VALUES ('Eve', 24, 'B');

SELECT *
FROM students;
