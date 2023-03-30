CREATE TABLE Rakowicz_owners (
    ownerID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    ownerName VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE Rakowicz_breeds (
    breedID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    breedName VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE Rakowicz_dogs (
    dogID INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    dogName VARCHAR(255) NOT NULL UNIQUE,
    breedName VARCHAR(255) NOT NULL,
    ownerID INT,
    FOREIGN KEY (breedName) REFERENCES Rakowicz_breeds (breedName),
    FOREIGN KEY (ownerID) REFERENCES Rakowicz_owners (ownerID)
);

LOAD DATA INFILE 'M:/Livid/Desktop/Dev/College-CS/CS-350/HW11-DogOwnerDB/owners.txt' INTO TABLE Rakowicz_owners
(ownerName);

LOAD DATA INFILE 'M:/Livid/Desktop/Dev/College-CS/CS-350/HW11-DogOwnerDB/breeds.txt' INTO TABLE Rakowicz_breeds
(breedName);

LOAD DATA INFILE 'M:/Livid/Desktop/Dev/College-CS/CS-350/HW11-DogOwnerDB/dogs-breeds.txt' INTO TABLE Rakowicz_dogs
FIELDS TERMINATED BY ';'
(dogName, breedName);

LOAD DATA INFILE 'M:/Livid/Desktop/Dev/College-CS/CS-350/HW11-DogOwnerDB/owners-dogs.txt'
INTO TABLE Rakowicz_dogs
FIELDS TERMINATED BY ';'
(ownerName, dogNames)
SET ownerID = (SELECT ownerID FROM Rakowicz_owners WHERE ownerName = @ownerName),
    dogID = (SELECT d.dogID FROM Rakowicz_dogs d WHERE d.dogName = SUBSTRING_INDEX(@dogNames, ',', 1));

UPDATE Rakowicz_dogs d
JOIN Rakowicz_breeds b ON b.breedName = d.breedName
SET d.dogID = b.breedID;
