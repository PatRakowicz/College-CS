/**
	CS280 HW2
	@file HW2.cpp
	@author Sam Micka
	@version 8/29/2020
*/

#include <iostream>
#include <fstream> // for file IO
#include <typeinfo> // for typeid
#include <sstream> // for splitting strings
<<<<<<< HEAD
=======
#include <algorithm>
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505

using namespace std;

// array doubles variable
int numDoubles = 0;
// number of duplicates
int numDuplicates = 0;

// must use this struct
struct wordItem {
    string word;
    int count;
};

/**
********* REQUIRED FUNCTIONS!
*/

/*
* Function name: doubleArraySize
* Purpose: accepts an array and doubles the size
* @param wordItemList - pointer to your word item array
* @param length - the length of your wordItem array
* @return - none
* Note: create a new array with double the size, 
*		copy over the elements of wordItemList,
*		delete [] wordItemList,
*		reassign wordItemList to the new array
* Note: can call with doubleArraySize(wordItemList, length);
*/
void doubleArraySize(wordItem *&wordItemList, int &length) {
<<<<<<< HEAD

=======
    wordItem *temp = new wordItem[2 * length];
    for (int i = 0; i < length; i++) {
        temp[i] = wordItemList[i];
    }
    length *= 2;
    delete[] wordItemList;
    wordItemList = temp;
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
}

/*
* Function name: addWord
* Purpose: adds a new word to our list, everything is passed by ref!
* @param wordItemList - address of pointer to your word item array
* @param wordIndex - the current index in the array
* @param length - the length of your wordItem array
* @param nextWord - the word we want to add
* @return - none
* Note: handle two cases, the case where the word already
* 		has a wordItem in the array (increment count),
* 		and the case where it's not in there. In the second
* 		case we might have to double the size if wordIndex == length
* 		and add a new wordItem with count 1
*/
void addWord(wordItem *&wordItemList, int &wordIndex, int &length, string nextWord) {
<<<<<<< HEAD

=======
    bool found = false;
    for (int i = 0; i < wordIndex; i++) {
        if (wordItemList[i].word == nextWord) {
            found = true;
            wordItemList[i].count++;
            break;
        }
    }
    if (!found) {
        if (wordIndex == length) {
            doubleArraySize(wordItemList, length);
            numDoubles++;
        }
        wordItemList[wordIndex].word = nextWord;
        wordItemList[wordIndex].count = 1;
        wordIndex++;
    }
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
}


/*
* Function name: arraySort
* Purpose: sort an array of wordItems, decreasing, by their count fields 
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
* Note: should modify the original array but not return anything
* should be called with arraySort(wordItemList, wordIndex)
* can modify the array directly (list[0] = something)
*/
void arraySort(wordItem wordItemList[], int wordIndex) {
<<<<<<< HEAD

=======
    for (int i = 0; i < wordIndex; i++) {
        for (int j = i + 1; j < wordIndex; j++) {
            if (wordItemList[i].count < wordItemList[j].count) {
                wordItem temp = wordItemList[i];
                wordItemList[i] = wordItemList[j];
                wordItemList[j] = temp;
            }
        }
    }
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
}


/*
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of
wordItems 
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN) {
<<<<<<< HEAD

=======
    for (int i = 0; i < topN; i++) {
        cout << wordItemList[i].word << " - " << wordItemList[i].count << endl;
    }
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
}



/************************************************************/
/**** feel free to add any other functions you need here ****/
/************************************************************/

void printArr(wordItem wordItemList[], int wordIndex) {
    for (int i = 0; i < wordIndex; i++) {
        cout << wordItemList[i].word << ", " << wordItemList[i].count << endl;
    }
}

<<<<<<< HEAD
=======
/*
 * Function name: uniqueCount
 * Purpose: To find the number of unique words in a given array
 * @param wordItemList - A pointer that points to a *sorted Arr* of wordItems
 * @param wordIndex - the length of the words array
 * @return count - return of the count of words that have more than one match
 * */
int duplicatesCntr(wordItem wordItemList[], int wordIndex) {
    for (int i = 0; i < wordIndex; i++) {
        if (wordItemList[i].count > 1) { numDuplicates++; }
    }
    return numDuplicates;
}

>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505

/*
* Main function (driver)
* take care of reading in the file and creating the arrays here
*/

int main() {
    int wordIndex = 0; // keep track of where to insert new wordItems
    int length = 1; // keep track of total size of array
    wordItem *wordItemList = new wordItem[length]; // create a word item array starting with 1 spot

    // get command line arguments
    int topN = 4;
<<<<<<< HEAD
    string inputFile = "shakespeare.txt";


    ifstream file(inputFile);
    string line;

    if (!file.is_open()) { cout << "File Does not Exists \n"; }

    while (getline(file, line)) {

=======
    string winFile = "M:/Livid/Desktop/Dev/College-CS/CS-280/HW2/shakespeare.txt";
    string macFile = "/Users/patrak/Documents/Dev/College-CS/CS-280/HW2/shakespeare.txt";
    const string &inputFile = winFile;


    ifstream file(inputFile);

    if (!file.is_open()) { cout << "File Does not Exists \n"; }

    string nextWord;
    while (file >> nextWord) {
        addWord(wordItemList, wordIndex, length, nextWord);
    }

    arraySort(wordItemList, wordIndex);
    printTopN(wordItemList, topN);

    cout << " " << endl;
    cout << "Doubles Count: " << numDoubles << " " << endl;
    cout << "Duplicate Count: " << duplicatesCntr(wordItemList, wordIndex) << " " << endl;
    cout << " " << endl;

    if (true) {
        cout << "Printing Array \n";
        printArr(wordItemList, wordIndex);
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
    }

    // (1) parse line by line from file
    //   (1a) break up lines by spaces to get each word
    //   (1b) put each word into the array
    //        if there is already a wordItem for the word, increase the count
    // 		  if the word is not in the array, create a new wordItem with count = 1
    // (2) sort your array of wordItems
    // (3) print out the top n and their frequency
    // (4) print out number of array doubles (global variable up top for this)
    // (5) print out total number of unique words
    // (6) print out total number of duplicate words

    delete[] wordItemList; // clean up
<<<<<<< HEAD
=======
    file.close();
>>>>>>> ec5c677197708ec6e7f50946c7132f42adb45505
    return 0; //return "success" status
}