-- What are all the names of all golden retrievers in this dataset?
SELECT dogName FROM Rakowicz_dogs
WHERE breedName = 'Golden Retriever';

-- Which dogs do NOT have any owners?
SELECT dogName FROM Rakowicz_dogs
WHERE ownerName IS NULL;

-- Which owners do NOT Have any dogs?
SELECT ownerName FROM Rakowicz_owners
WHERE NOT EXISTS (SELECT * FROM Rakowicz_dogs WHERE Rakowicz_owners.ownerName = Rakowicz_dogs.ownerName);

-- Which owners have 2 or more dogs?
SELECT ownerName, COUNT(*) AS numDogs
FROM Rakowicz_dogs
WHERE ownerName IS NOT NULL
GROUP BY ownerName
HAVING COUNT(*) >= 2;

-- Amongst the dogs. which breed was most common in this dataset?
SELECT breedName, COUNT(*) AS numDogs
FROM Rakowicz_dogs
GROUP BY breedName
ORDER BY numDogs DESC
    LIMIT 1;
