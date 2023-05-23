#include <iostream>
using namespace std;

bool check(int mid, const int array[], int n, int K)
{
    int count = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] > mid)
            return false;

        sum += array[i];

        if (sum > mid) {
            count++;
            sum = array[i];
        }
    }
    count++;

    if (count <= K)
        return true;

    return false;
}

int solve(int array[], int n, int K)
{
    int* max = max_element(array, array + n);
    int start = *max;
    int end = 0;

    for (int i = 0; i < n; i++)
        end += array[i];

    int answer = 0;
    while (start <= end) {
        int mid = (start + end) / 2;

        if (check(mid, array, n, K)) {
            answer = mid;
            end = mid - 1;
        } else start = mid + 1;
    }

    return answer;
}

int main()
{
    int n, t;
    cin >> n >> t;

    int skills[n];
    for (int i = 0; i < n; i++)
        cin >> skills[i];

    cout << solve(skills, n, t);
}