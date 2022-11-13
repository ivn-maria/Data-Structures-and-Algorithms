#include <iostream>
#include <algorithm>
using namespace std;

struct Student {
    int score = 0;
    string name;
};

bool compare(const Student& a, const Student& b) {
    return a.name < b.name;
}

void CountingSort(Student array[], int n) {
    int copy[n];
    for(int i = 0; i < n; i++)
        copy[i] = array[i].score;

    string copy2[n];
    for(int i = 0; i < n; i++)
        copy2[i] = array[i].name;

    int output[100001];
    for (int i = 0; i < 100001; i++)
        output[i] = 0;
    for (int i = 0; i < n; i++)
        output[array[i].score]++;
    for (int i = 1; i < 100001; i++)
        output[i] += output[i-1];

    for (int i = 0; i < n; i++) {
        array[output[copy[i]] - 1].score = copy[i];
        array[output[copy[i]] - 1].name = copy2[i];
        output[copy[i]]--;
    }
}

int main() {
    int n;
    cin >> n;

    string names[n];
    int scores[n];
    Student array[n];
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        array[i].name = names[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        array[i].score = scores[i];
    }

    sort(array, array + n, compare);

    CountingSort(array, n);

    for(int i = n - 1; i >= 0; i--)
        cout << array[i].name << ' ' << array[i].score << '\n';

    return 0;
}