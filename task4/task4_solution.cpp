#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int even = 0, odd = 0;
    int evenArr[n];
    int oddArr[n];

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x % 2 == 0) {
            evenArr[even] = x;
            even++;
            continue;
        }

        oddArr[odd] = x;
        odd++;
    }

    for (int i = 0; i < even; i++)
        cout << evenArr[i] << '\n';

    for (int i = 0; i < odd; i++)
        cout << oddArr[i] << '\n';

    return 0;
}
