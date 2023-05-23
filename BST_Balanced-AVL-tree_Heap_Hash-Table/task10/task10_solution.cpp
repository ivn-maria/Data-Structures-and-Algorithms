#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    int arr[N], ans = 0, j = 0;
    unordered_map<int, int> array;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        j = max(array[arr[i]], j);
        ans = max(ans, i - j + 1);
        array[arr[i]] = i + 1;
    }
    cout << ans;

    return 0;
}