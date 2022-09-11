#include <iostream>
#include <string>

using namespace std;

namespace snowInfo {
	int inches;
//	string mountainRange;
	float snowDensity;
	int time;

	int SWE = inches * snowDensity;

}

int main() {
	
	cout << "Enter the new snow amount in inches: ";
	cin >> snowInfo::inches;
	cout << "\n";

	cout << "Enter the mointain range: ";
	string mountainRange;
	getline(cin, mountainRange);
//	getline(cin, snowInfo::mountainRange);
	cout << "\n";

	cout << "Enter the snow density ( between 0 and 1): ";
	cin >> snowInfo::snowDensity;
	cout << "\n";

	cout << "Enter the time (hours) that snow fell over: ";
	cin >> snowInfo::time;
	cout << "\n";

	cout << snowInfo::inches << " Inches of snow fell in " << mountainRange << " over a period of " 
		<< snowInfo::time << " hours, resulting in " << snowInfo::SWE << " inches of SWE.";
}
