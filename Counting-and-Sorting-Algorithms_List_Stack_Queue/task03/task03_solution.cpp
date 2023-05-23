#include <iostream>
using namespace std;

int main() {
    int count;
    cin >> count;

    int tickets[count];
    for (int i = 0; i < count; i++)
        cin >> tickets[i];

    int max = 1;
    for (int i = 0; i < count; i++)
        if(tickets[i] > max) max = tickets[i];

    int ans = max + 1;
    int arr[max];
    for (int i = 0; i < max; i++)
        arr[i] = 0;

    for (int i = 0; i < count; i++) {
        if(tickets[i] > 0) arr[tickets[i] - 1] = tickets[i];
        else tickets[i] = 0;
    }

    for (int i = 0; i < max; i++)
        if (arr[i] == 0) {
            ans = i + 1;
            break;
        }

    cout << ans;

    return 0;
}
