#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int len;
        cin >> len;

        char arr[len];
        for (int k = 0; k < len; k++)
            cin >> arr[k];

        int ans = 0;
        for (int j = 0; j < len - 1; j++) {
            if ((arr[j] == 'P' && arr[j+1] == 'P') || (arr[j] == 'I' && arr[j+1] == 'I'))
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
