create database ex62;
use ex62;
CREATE TABLE Sailors (
    sid INT PRIMARY KEY,
    sname VARCHAR(100),
    rating INT,
    age DECIMAL(4, 1)
);

CREATE TABLE Boats (
    bid INT PRIMARY KEY,
    bname VARCHAR(100),
    color VARCHAR(20)
);

CREATE TABLE Reserves (
    sid INT,
    bid INT,
    day DATE,
    PRIMARY KEY (sid, bid, day),
    FOREIGN KEY (sid) REFERENCES Sailors(sid),
    FOREIGN KEY (bid) REFERENCES Boats(bid)
);

INSERT INTO Sailors (sid, sname, rating, age) VALUES
(1, 'Bob', 10, 25.0),
(2, 'Alice', 8, 22.5),
(3, 'Charlie', 5, 35.0),
(4, 'David', 7, 28.0),
(5, 'Eva', 6, 19.5);

INSERT INTO Boats (bid, bname, color) VALUES
(101, 'Speedster', 'Red'),
(102, 'Wave Rider', 'Green'),
(103, 'Sea Breeze', 'Blue'),
(104, 'Ocean King', 'Red'),
(105, 'Wind Chaser', 'Green');

INSERT INTO Reserves (sid, bid, day) VALUES
(1, 101, '2024-09-01'),
(1, 102, '2024-09-02'),
(2, 104, '2024-09-01'),
(3, 101, '2024-09-03'),
(3, 103, '2024-09-03'),
(4, 105, '2024-09-01'),
(5, 101, '2024-09-04');


SELECT S.*
FROM Sailors S
JOIN Reserves R ON S.sid = R.sid
WHERE R.bid = 101;


SELECT B.bname
FROM Boats B
JOIN Reserves R ON B.bid = R.bid
JOIN Sailors S ON R.sid = S.sid
WHERE S.sname = 'Bob';

SELECT DISTINCT S.sname
FROM Sailors S
JOIN Reserves R ON S.sid = R.sid
JOIN Boats B ON R.bid = B.bid
WHERE B.color = 'Red'
ORDER BY S.age;

SELECT DISTINCT S.sname
FROM Sailors S
JOIN Reserves R ON S.sid = R.sid;

SELECT S.sid, S.sname
FROM Sailors S
JOIN Reserves R1 ON S.sid = R1.sid
JOIN Reserves R2 ON S.sid = R2.sid AND R1.day = R2.day AND R1.bid <> R2.bid;

SELECT DISTINCT R.sid
FROM Reserves R
JOIN Boats B ON R.bid = B.bid
WHERE B.color IN ('Red', 'Green');


SELECT sname, age
FROM Sailors
WHERE age = (SELECT MIN(age) FROM Sailors);

SELECT COUNT(DISTINCT sname) AS Num_Sailors
FROM Sailors;

SELECT rating, AVG(age) AS Avg_Age
FROM Sailors
GROUP BY rating;


SELECT rating, AVG(age) AS Avg_Age
FROM Sailors
GROUP BY rating
HAVING COUNT(sid) >= 2;

