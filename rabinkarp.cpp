#include <iostream>
#include <string>
using namespace std;

int main() {

    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();

    int base = 256;   // total characters
    int mod = 101;    // prime number

    int patHash = 0;  // hash of pattern
    int txtHash = 0;  // hash of text window
    int h = 1;

    // Calculate h = (base^(m-1)) % mod
    for (int i = 0; i < m - 1; i++) {
        h = (h * base) % mod;
    }

    // Find hash of pattern and first window of text
    for (int i = 0; i < m; i++) {
        patHash = (patHash * base + pattern[i]) % mod;
        txtHash = (txtHash * base + text[i]) % mod;
    }

    // Slide through the text
    for (int i = 0; i <= n - m; i++) {

        // Step 1: If both hash values match → check characters
        if (patHash == txtHash) {
            bool match = true;

            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }

            if (match) {
                cout << "Pattern found at index " << i << endl;
            }
        }

        // Step 2: Move the sliding window (calculate next hash)
        if (i < n - m) {
            txtHash = ( (txtHash - text[i] * h) * base + text[i + m] ) % mod;

            if (txtHash < 0) {
                txtHash = txtHash + mod;  // make hash positive
            }
        }
    }

    return 0;
}
