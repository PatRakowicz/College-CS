# noinspection SqlNoDataSourceInspectionForFile

# noinspection SqlNoDataSourceInspection
DROP TABLE Rakowicz_owners;
DROP TABLE Rakowicz_dogs;
DROP TABLE Rakowicz_breeds;

CREATE TABLE Rakowicz_owners
(
    ownerID   INT          NOT NULL AUTO_INCREMENT PRIMARY KEY,
    ownerName VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE Rakowicz_breeds
(
    breedID   INT          NOT NULL AUTO_INCREMENT PRIMARY KEY,
    breedName VARCHAR(255) NOT NULL UNIQUE
);

CREATE TABLE Rakowicz_dogs
(
    dogID   INT          NOT NULL AUTO_INCREMENT PRIMARY KEY,
    dogName VARCHAR(255) NOT NULL UNIQUE,
    breedID INT          NULL,
    ownerID INT          NULL,
    FOREIGN KEY (breedID) REFERENCES Rakowicz_breeds (breedID),
    FOREIGN KEY (ownerID) REFERENCES Rakowicz_owners (ownerID)
);

LOAD DATA INFILE '/Volumes/500 GB/Applications/XAMPP/xamppfiles/htdocs/Testing/HW11-DogOwnerDB/owners.txt' INTO TABLE Rakowicz_owners
    (ownerName);

LOAD DATA INFILE '/Volumes/500 GB/Applications/XAMPP/xamppfiles/htdocs/Testing/HW11-DogOwnerDB/breeds.txt' INTO TABLE Rakowicz_breeds
    (breedName);

drop table Rakowicz_dogs;
LOAD DATA INFILE '/Volumes/500 GB/Applications/XAMPP/xamppfiles/htdocs/Testing/HW11-DogOwnerDB/dogs.txt' INTO TABLE Rakowicz_dogs
    (dogName);


CREATE TABLE temp_dog_owners
(
    ownerName VARCHAR(255),
    dogName   VARCHAR(255)
);

LOAD DATA INFILE '/Volumes/500 GB/Applications/XAMPP/xamppfiles/htdocs/Testing/HW11-DogOwnerDB/owners-dogs.txt' INTO TABLE temp_dog_owners
    FIELDS TERMINATED BY ';'
    (ownerName, dogName);


CREATE TABLE temp_dogs_breed
(
    dogName VARCHAR(255),
    breedName VARCHAR(255)
);

LOAD DATA INFILE '/Volumes/500 GB/Applications/XAMPP/xamppfiles/htdocs/Testing/HW11-DogOwnerDB/dogs-breeds.txt' INTO TABLE temp_dogs_breed
    FIELDS TERMINATED BY ';'
    (dogName, breedName);

SELECT * FROM Rakowicz_breeds b, Rakowicz_dogs d, temp_dogs_breed t where b.breedName = t.breedName and d.dogName = t.dogName;
update Rakowicz_dogs d set d.breedID = (select b.breedID from temp_dogs_breed t, Rakowicz_breeds b where b.breedName = t.breedName and t.dogName = d.dogName);

SELECT * FROM Rakowicz_owners o, Rakowicz_dogs d, temp_dog_owners t where o.ownerName = t.ownerName and FIND_IN_SET(d.dogName, t.dogName) > 0;
update Rakowicz_dogs d set d.ownerID = (select o.ownerID from temp_dog_owners t, Rakowicz_owners o where o.ownerName = t.ownerName and FIND_IN_SET(d.dogName, t.dogName) > 0);
