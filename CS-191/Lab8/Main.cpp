#include <iostream>
#include <vector>

using namespace std;


/**
 * Tests to see whether any two ints in array sum to t
 *
 * @param array | the list we are testing for a palidrome
 * @param n | the (remaning) length of the array
 * @param left | the index on the left that im checking
 * @param rght | the index on the right that im checking
 * @return true | if the array is an integer palindrome, false otherwise
 */
bool even_palindrome(int* l, int n, int left, int right) {
	if (n == 2) { return l[left] == l[right]; }
	
	for(int i = 0; i < n; i++) {
		if (l[i] == l[i-1]) {
			cout << l[i] << endl;
			return true;
		} else {
			return false;
		}
	}
}

int main() {
	int length = 6;
	int x[length] = {1,2,3,3,2,1};
	cout << even_palindrome(x, length, 0, length-1);
	return 0;
}
