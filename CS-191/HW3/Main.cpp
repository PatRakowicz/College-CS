#include <iostream>
#include <string>

using namespace std;

namespace snowInfo {
	double inches;
	string mountainRange;
    double snowDensity;
	int time;
}

int main() {

	cout << "Enter the new snow amount in inches: ";
	cin >> snowInfo::inches;

	cout << "Enter the mountain range: ";
    cin.ignore();
    getline(cin, snowInfo::mountainRange);

	cout << "Enter the snow density ( between 0 and 1): ";
	cin >> snowInfo::snowDensity;

	cout << "Enter the time (hours) that snow fell over: ";
	cin >> snowInfo::time;

	cout << snowInfo::inches << " Inches of snow fell in " << snowInfo::mountainRange << " over a period of "
		<< snowInfo::time << " hours, resulting in " << snowInfo::inches * snowInfo::snowDensity << " inches of SWE.";
}
