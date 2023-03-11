// Make a script that parses the file given to individual cadegorys
// and input them into a created database that has
// Color name (Name of color)
// HEX Value (######)
// RGB (255,255,255)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

string NAME;
string HEX;
int rgb[3];

int main() {
    ifstream file("M:/Livid/Desktop/Dev/College-CS/CS-350/HW2-colorDB/colors.txt");
    string line;
    ofstream sqlFile("M:/Livid/Desktop/Dev/College-CS/CS-350/HW2-colorDB/Inserted_Colors.sql");
    sqlFile << "CREATE TABLE colors (name VARCHAR(255) PRIMARY KEY, hex VARCHAR(7), red INT, green INT, blue INT);" << endl;

    while (getline(file, line)) {
        replace(line.begin(), line.end(), ',', ' ');

        stringstream ss(line);
        ss >> NAME >> HEX >> rgb[0] >> rgb[1] >> rgb[2];

        sqlFile << "INSERT INTO colors (name, hex, red, green, blue) VALUES ('" <<
                NAME << "', '" << HEX << "', " << rgb[0] << ", " << rgb[1] << ", " << rgb[2] << ");" << endl;
    }
}