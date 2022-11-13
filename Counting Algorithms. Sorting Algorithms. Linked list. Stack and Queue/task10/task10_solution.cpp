#include <iostream>
using namespace std;

void CountingSort(int arr[], int n) {
    int copy[n];
    for (int i = 0; i < n; i++)
        copy[i] = arr[i];

    int counts[100001];
    for (int i = 0; i < n; i++)
        counts[arr[i]]++;
    for (int i = 2; i < 100001; i++)
        counts[i] += counts[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = counts[copy[i]] - 1;
        counts[copy[i]]--;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    CountingSort(arr, n);

    return 0;
}
