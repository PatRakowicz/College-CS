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

}



/************************************************************/
/**** feel free to add any other functions you need here ****/
/************************************************************/

void printArr(wordItem wordItemList[], int wordIndex) {
    for (int i = 0; i < wordIndex; i++) {
        cout << wordItemList[i].word << ", " << wordItemList[i].count << endl;
    }
}


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
    string inputFile = "shakespeare.txt";


    ifstream file(inputFile);
    string line;

    if (!file.is_open()) { cout << "File Does not Exists \n"; }

    while (getline(file, line)) {

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
    return 0; //return "success" status
}