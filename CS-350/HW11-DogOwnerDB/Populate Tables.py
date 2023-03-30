import mysql.connector

# read in text files
owners_file = open('owners.txt', 'r')
breeds_file = open('breeds.txt', 'r')
dogs_file = open('dogs.txt', 'r')
dogs_breeds_file = open('dogs-breeds.txt', 'r')
owners_dogs_file = open('owners-dogs.txt', 'r')

owners = []
breeds = []
dogs = []
dog_breeds = []
owner_dogs = []

# populate owners list
for line in owners_file:
    owners.append(line.strip())

# populate breeds list
for line in breeds_file:
    breeds.append(line.strip())

# populate dogs list
for line in dogs_file:
    dogs.append(line.strip())

# populate dog_breeds list
for line in dogs_breeds_file:
    dog, breed = line.strip().split(';')
    dog_breeds.append((dog, breed))

# populate owner_dogs list
for line in owners_dogs_file:
    owner, dog_list = line.strip().split(';')
    dog_list = dog_list.split(',')
    owner_dogs.append((owner, dog_list))

# connect to MySQL database
cnx = mysql.connector.connect(user='rakowicz', password='rakowicz98', host='localhost', database='rakowicz')
cursor = cnx.cursor()

# create owners table
cursor.execute('CREATE TABLE rakowicz_owners (ownerID INT AUTO_INCREMENT PRIMARY KEY, ownerName VARCHAR(255) NOT NULL)')

# populate owners table
for owner in owners:
    cursor.execute('INSERT INTO rakowicz_owners (ownerName) VALUES (%s)', (owner,))

# create breeds table
cursor.execute('CREATE TABLE rakowicz_breeds (breedID INT AUTO_INCREMENT PRIMARY KEY, breedName VARCHAR(255) NOT NULL)')

# populate breeds table
for breed in breeds:
    cursor.execute('INSERT INTO rakowicz_breeds (breedName) VALUES (%s)', (breed,))

# create dogs table
cursor.execute('CREATE TABLE rakowicz_dogs (dogID INT AUTO_INCREMENT PRIMARY KEY, dogName VARCHAR(255) NOT NULL, breedID INT, FOREIGN KEY (breedID) REFERENCES rakowicz_breeds(breedID))')

# populate dogs table
for dog, breed in dog_breeds:
    cursor.execute('SELECT breedID FROM rakowicz_breeds WHERE breedName = %s', (breed,))
    breedID = cursor.fetchone()[0]
    cursor.execute('INSERT INTO rakowicz_dogs (dogName, breedID) VALUES (%s, %s)', (dog, breedID))

# create owners_dogs table
cursor.execute('CREATE TABLE owners_dogs (ownerID INT, dogID INT, FOREIGN KEY (ownerID) REFERENCES rakowicz_owners(ownerID), FOREIGN KEY (dogID) REFERENCES rakowicz_dogs(dogID))')

# populate owners_dogs table
for owner, dog_list in owner_dogs:
    cursor.execute('SELECT ownerID FROM rakowicz_owners WHERE ownerName = %s', (owner,))
    ownerID = cursor.fetchone()[0]
    for dog in dog_list:
        cursor.execute('SELECT dogID FROM rakowicz_dogs WHERE dogName = %s', (dog,))
        dogID = cursor.fetchone()[0]
        cursor.execute('INSERT INTO owners_dogs (ownerID, dogID) VALUES (%s, %s)', (ownerID, dogID))

# commit changes to the database
cnx.commit()

# close cursor and connection
cursor.close()
cnx.close()