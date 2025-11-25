/*
Take the pattern.

Move it over the text one character at a time.

At each position, check:

Does the pattern match the text exactly?

If it matches → print that index.

Continue till the end of the text.

This is basic string matching.
*/
#include <iostream>
#include <string>
using namespace std;

int main() {

    string text, pattern;

    // Taking user input
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();

    // Student logic: check each position
    for (int i = 0; i <= n - m; i++) {

        int j = 0;

        // Compare pattern with text
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }

        // If pattern matched fully
        if (j == m) {
            cout << "Pattern found at index " << i << endl;
        }
    }

    return 0;
}

