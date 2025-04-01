def map(movieID, ratings):
    pairlist = []
    for rating in ratings:
        pairlist.append((movieID, float(rating)))
    return pairlist

def reduce(key, valuelist):
    total = 0.0
    count = 0
    smallest = None
    largest = None

    for value in valuelist:
        total += value
        count += 1

        if smallest is None or value < smallest:
            smallest = value

        if largest is None or value > largest:
            largest = value

    if count > 0:
        average = total / count
    else:
        average = 0.0

    average = round(average, 2)
    return (key, average, count, smallest, largest)

def shuffle(tuplelist):
    keydict = {}
    for (key, value) in tuplelist:
        if key in keydict:
            print(key, "Exists")
            keydict[key].append(value)
        else:
            print("New Key: ", key)
            keydict[key] = []
            keydict[key].append(value)
    return keydict

if __name__ == "__main__":
    contents = []
    with open("movie_ratings_dataset.csv") as f:
        for line in f:
            colum = line.strip().split(",")
            if colum[0].lower() == "userid":
                continue
            movie_id = colum[1]
            rating = colum[2]
            contents.append((movie_id, rating))

    result = []
    for movie_id, rating in contents:
        result.extend(map(movie_id, [rating]))
    print(result)

    shuffled = shuffle(result)
    print(shuffled)

    with open("moveStats.csv", "w") as f:
        for movie_id in shuffled:
            ratings_list = shuffled[movie_id]
            stats = reduce(movie_id, ratings_list)
            f.write(str(stats) + "\n")
