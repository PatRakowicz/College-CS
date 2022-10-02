// read names from user unit they ender "done"
// store each name in a structure in original order
// print names back out in same order
// ask the user for a name to remove, and remove it
// print vector again

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main() {
	
	vector<string> names; // storing all names entered
	string n; // storing individual names from user
	
	while (n != "done") {
		
		cout << "Enter a name: ";
		cin >> n;
		if (n != "done") { names.push_back(n); }
	}
	
	cout << "Here are the names you entered: " << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}

	cout << "Enter a name you would like to remove: " << endl;
	string name_to_remove;
	cin >> name_to_remove;
	int rem_index = 0;
	for (int i = 0; i < names.size(); i++) {
		if (names[i] == name_to_remove) {
			rem_index = i;
		}
	}

	cout << "Here are the names you w/ out your names you deleted: " << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << names[i] << endl;
	}

	names.erase(names.begin() + rem_index);

}
