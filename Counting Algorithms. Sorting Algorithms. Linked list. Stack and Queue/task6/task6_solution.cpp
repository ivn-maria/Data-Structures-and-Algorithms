#include <iostream>
using namespace std;

int main() {
    string arr;
    cin >> arr;

    int counts[127];
    for (int i = 0; i < 127; i++)
        counts[i] = 0;
    for (int i = 0; i < arr.length(); i++)
        counts[arr[i]]++;

    for (int i = 0; i < arr.length(); i++)
        if(counts[arr[i]] == 1)
            cout << i << ' ';

    return 0;
}