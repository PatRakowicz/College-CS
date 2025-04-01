def map(docid, doc):
    wordlist = []
    for word in doc:
        wordlist.append((word, 1))
    return wordlist

def reduce(key, valuelist):
    result = 0
    for value in valuelist:
        result += value
    return (key, result)

def shuffle(tuplelist):
    keydict = {}
    for (key, value) in tuplelist:
        if key in keydict:
            print("Exists")
            keydict[key].append(value)
        else:
            print("New Key: ", key)
            keydict[key] = []
            keydict[key].append(value)
    return keydict

if __name__ == "__main__":
    contents = []
    with open("example.txt") as f:
        for line in f:
            for word in line.strip().split(" "):
                contents.append(word.lower())

    result = map("example", contents)
    print(result)

    shuffled = shuffle(result)
    print(shuffled)

    with open("finalcount.txt", "w") as f:
        for k,v in shuffled.items():
            final = reduce(k, v)
            f.write(str(final) + "\n")

