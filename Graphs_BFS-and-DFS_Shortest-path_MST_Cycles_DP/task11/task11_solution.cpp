#include <iostream>
using namespace std;

int n;
int a[1001];
long long dp[1001][10081];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 10080; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i-1]) {
                dp[i][j] += dp[i-1][j-a[i-1]] % 1000000007;
            }
        }
    }

    long long count = 0;
    for (int i = 0; i <= 10080; i++)
        count += dp[n][i];

    cout << count % 1000000007 << endl;
    return 0;
}




