#include <iostream>
#include <vector>
using namespace std;

bool condition(const int count[]) {
    for (int i = 0; i <= 25; i++){
        if (count[i] != 0 && count[i] % 2 == 0) {
            return false;
        }
    }
    return true;
}

int minPartion(string& str) {
    int n = str.size();

    int** even = new int*[n];
    for (int i = 0; i < n; ++i)
        even[i] = new int[n];

    int** minSplits = new int*[n];
    for (int i = 0; i < n; ++i)
        minSplits[i] = new int[n];

    for (int i = 0; i < n; i++) {
        even[i][i] = true;
        minSplits[i][i] = 0;
    }


    for (int i = 0; i < n; i++) {
        int count2[26] = {0};
        for (int j = i; j < n; j++) {
            count2[str[j] - 'a']++;
            even[i][j] = condition(count2);
        }
    }



    for (int l = 2; l <= n; l++) {
        for (int i = 0; i < n - l + 1; i++) {
            int j = i + l - 1;

            if (even[i][j]) minSplits[i][j] = 0;
            else {
                minSplits[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                    minSplits[i][j] = min(minSplits[i][j], minSplits[i][k] + minSplits[k + 1][j] + 1);
            }
        }
    }

    return minSplits[0][n - 1] + 1;
}

int main() {
    string s;
    cin >> s;

    cout << minPartion(s);

    return 0;
}

