#include <iostream>
#include <string.h>
using namespace std;

int LCS(const string& s1, const string& s2) {
    unsigned long len1 = s1.length();
    unsigned long len2 = s2.length();

    int result = 0;
    int len[2][len2];
    memset(len, 0, sizeof(len));
    int currRow = 0;

    for (unsigned long i = 1; i <= len1; i++) {
        for (unsigned long j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                len[currRow][j] = len[1 - currRow][j - 1] + 1;
                result = max(result, len[currRow][j]);
            } else len[currRow][j] = 0;
        }
        currRow = 1 - currRow;
    }

    return result;
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << LCS(s1, s2);

    return 0;
}
