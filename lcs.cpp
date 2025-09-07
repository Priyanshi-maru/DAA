#include <iostream>
#include <vector>
using namespace std;

int lcs(string &x, string &y)
 {
    int m = x.length();
    int n = y.length();

    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
        {
        for (int j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else
            {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }

    return c[m][n];
}

int main()
{
    string a = "longest";
    string b = "priyanshi";

    cout << "Length of LCS: " << lcs(a, b) << endl;
    return 0;
}
