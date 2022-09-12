#include <iostream>
#include <string>

using namespace std;

namespace father {
	string name;
	int age;
}
namespace mother {
	string name;
	int age;
}

int main() {
	cout << "Enter Fathers Name (string) and Age (int):" << "\n";
	cin >> father::name;
	cin >> father::age;
	cout << "Enter Mothers Name (string) and Age (int):" << "\n";
	cin >> mother::name;
	cin >> mother::age;

	cout << "Father " << father::name << " is " << father::age <<
		" Mother " << mother::name << " is " << mother::age << "\n";
	
	return 0;
}
