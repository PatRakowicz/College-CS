def map(movieID, ratings):
    pairlist = []
    for rating in ratings:
        pairlist.append((movieID, float(rating)))
    return pairlist

def reduce(key, valuelist):
    result = 0
    for value in valuelist:
        result += value
    if len(valuelist) > 0:
        average = result / len(valuelist)
    else:
        average = 0
    return (key, round(average, 2))

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

    with open("finalcount.txt", "w") as f:
        for k,v in shuffled.items():
            final = reduce(k, v)
            f.write(str(final) + "\n")
