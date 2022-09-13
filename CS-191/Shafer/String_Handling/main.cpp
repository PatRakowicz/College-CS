/*
    191
    String Handling
    main.cpp
    Patrick Rakowicz
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Input Two names
    string input, input2, input3, input4, input5;

    cout << "Enter a Two Part Name:";
    cin >> input >> input2;

    cout << "Expected" << endl;
    cout << "properly capitalized two part name" << endl;
    cout << "Actual" << endl;

    if (!input.empty() && !input2.empty()) {
        transform(begin(input), end(input), begin(input),[](char const& c){return tolower(c);});
        input[0] = toupper(input[0]);

        transform(begin(input2), end(input2), begin(input2),[](char const& c){return tolower(c);});
        input2[0] = toupper(input2[0]);
    }
    cout << input << " " << input2 << endl;

    cout << endl;

    // Input three names
    cout << "Enter a Three Part Name:";
    cin >> input3 >> input4 >> input5;

    cout << "Expected" << endl;
    cout << "properly capitalized three part name" << endl;
    cout << "Actual" << endl;

    if(!input3.empty() && !input4.empty() && !input5.empty()) {
        transform(begin(input3), end(input3), begin(input3),[](char const& c){return tolower(c);});
        input3[0] = toupper(input3[0]);

        transform(begin(input4), end(input4), begin(input4),[](char const& c){return tolower(c);});
        input4[0] = toupper(input4[0]);

        transform(begin(input5), end(input5), begin(input5),[](char const& c){return tolower(c);});
        input5[0] = toupper(input5[0]);
    }
    cout << input3 << " " << input4 << " " << input5 << endl;
}