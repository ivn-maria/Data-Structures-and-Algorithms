#include <iostream>
using namespace std;

long long blue[5000001];
long long yellow[5000001];
long long violet[5000001];

int main() {
    int n;
    cin >> n;

    blue[0] = 1;
    yellow[0] = 0;
    violet[0] = 1;

    for (int i = 1; i <= n; i++) {
        blue[i] = (yellow[i - 1] + violet[i - 1]) % 1000000007;
        if (i == 1) yellow[i] = 0;
        else yellow[i] = (blue[i - 1]) % 1000000007;
        violet[i] = (blue[i - 1] + yellow[i - 1]) % 1000000007;
    }

    cout << (blue[n] + violet[n]) % 1000000007 << endl;

    return 0;
}