// Problem:
// Input CFS (Cubic Feet Per sec)
//
// Output gunnison is moving 4170 gallons a sec, # gallons a minute, # gallons an hour, and # gallons per day

#include <iostream>
using namespace std;

int main() {
	int CFS = 556;
	int GalS = CFS * 7.5;
	int GalM = GalS * 60;
	int GalH = GalM * 60;
	int GalD = GalH * 24;

	cout << "Gunnison is moving " << GalS << " gallons a second, "<< GalM << " gallons a minute, " << GalH << " gallons an hour, "<< GalD << " gallons per day" << "\n";
}
