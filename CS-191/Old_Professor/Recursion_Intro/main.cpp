/*
    191
    Recursion Intro
    main.cpp
    Patrick Rakowicz | Caleb Domenico
*/
#include <iostream>

using namespace std;

/*
    void hailstone(int n) - if n is 1 stop;
    if n is even then print n/2 and return hailstone(n/2);
    if n is odd then print 3*n+1 and return hailstone(3*n+1);
    assume n >= 1
 */
void hailstone(int n) {
    if (n == 1) {
        abort();
    } else if (n % 2 == 0) {
        cout << n / 2 << endl;
        cout << "hailstone(" << n << "/2)";
    } else {
        cout << 3 * n + 1 << " " << "hailstone(3*" << n << "+1)" << endl;
    }
}

/*
    int fibonacci(int n) - return 1 if n is 0 or 1;
    otherwise return fibonacci(n-1) + fibonacci(n-2).
 */
int fibonacci(int n) {
    if (n == 1 || n == 0) {
        return 1;
    } else {
        return (n - 1) + (n - 2);
    }
}

/*
    int sumDigits(int n) - return the sum of the digits of an integer n
*/
int sumDigits(int n) {
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

/*
    int sum(int n) - return the sum of the integers from 1 to n
*/
int sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n;
        n--;
    }
    return sum;
}

/*
    bool isPalindrome(string s) - test the string for reading the same
    front to back and back to front;
    ignore case in the comparisons.
*/
bool isPalindrome(string s) {
    if (equal(s.begin(), s.begin() + s.size()/2, s.rbegin()))
        return true;
    else
        return false;
}

int main() {
    cout << "hailstone(50)" << endl;
    hailstone(50);
    cout << endl;
    cout << "fibonacci(10)" << endl;
    cout << fibonacci(10) << endl;
    cout << "sumDigits(88497)" << endl;
    cout << sumDigits(88497) << endl;
    cout << "sum(10)" << endl;
    cout << sum(10) << endl;
    cout << "sum(1)" << endl;
    cout << sum(2) << endl;
    cout << boolalpha;
    cout << "isPalindrome(\"mom\")" << endl;
    cout << isPalindrome("mom") << endl;
    cout << "isPalindrome(\"momxmom\")" << endl;
    cout << isPalindrome("momxmom") << endl;
    cout << "isPalindrome(\"baker\")" << endl;
    cout << isPalindrome("baker") << endl;
    cout << "isPalindrome(\"bakkaB\")" << endl;
    cout << isPalindrome("bakkaB") << endl;
}