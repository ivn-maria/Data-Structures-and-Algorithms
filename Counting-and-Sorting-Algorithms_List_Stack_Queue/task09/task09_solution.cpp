#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> skills;
    long long sum = 0;
    long long max = 0;

    for (int i = 0; i < n; i++) {
        int skill;
        cin >> skill;
        
        sum += skill;
        if (skill > max)
            max = skill;
        skills.push_back(skill);
    }

    long long best = max;
    long long low = best, high = sum;
    long long ans = 0;

    while (low <= high) {
        int count = 0;
        sum = 0;
        
        for (int i = 0; i < n; i++) {
            if (skills[i] + sum > best) {
                count++;
                sum = 0;
            }
            sum += skills[i];
        }

        if (sum != 0)
            count++;

        if (count > t)
            low = best + 1;
        else
            high = best - 1;

        if (count == t)
            ans = best;

        best = low + (high - low) / 2;
    }

    cout << ans;
    
    return 0;
}
