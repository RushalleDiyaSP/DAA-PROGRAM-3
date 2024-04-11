#include <iostream>
#include <cstring>
using namespace std;

// Function to find the length of the longest common subsequence
int lcsLength(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create a 2D array to store the length of LCS
    int dp[m + 1][n + 1];

    // Fill the dp array bottom-up
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

// Function to print the LCS
void printLCS(string X, string Y, int m, int n) {
    int dp[m + 1][n + 1];

    // Build dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Traverse dp array to find LCS
    int index = dp[m][n];
    char lcs[index + 1];
    lcs[index] = '\0';

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--; j--; index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the LCS
    cout << "Length of LCS: " << dp[m][n] << endl;
    cout << "LCS: " << lcs << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <input-string1> <input-string2>" << endl;
        return 1;
    }

    string X = argv[1];
    string Y = argv[2];
    int m = X.length();
    int n = Y.length();

    // Print the length of LCS and the LCS
    cout << "Length of LCS: " << lcsLength(X, Y) << endl;
    printLCS(X, Y, m, n);

    return 0;
}
