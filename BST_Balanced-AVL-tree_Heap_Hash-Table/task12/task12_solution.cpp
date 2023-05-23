#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    long long N, M;
    cin >> N >> M;

    int nums[N];

    cin >> nums[0];
    unordered_map<long long, int> nums1;
    nums1[nums[0]]++;

    cin >> nums[1];
    long long middle = nums[1];

    unordered_map<long long, int> nums2;
    for (int i = 2; i < N; ++i) {
        cin >> nums[i];
        nums2[nums[i]]++;
    }

    long long count = 0;

    auto it2 = nums2.find(middle * M);
    if (it2 != nums2.end()) {
        for (auto & it : nums1) {
            if (it.first * M == middle) {
                count += it.second * it2->second;
                break;
            }
        }
    }

    unordered_map<long long, int>::iterator it1;
    for (int i = 2; i < N - 1; i++) {
        nums1[middle]++;
        middle = nums[i];

        it1 = nums2.find(middle);
        if (it1 != nums2.end() && it1->second == 1) nums2.erase(middle);
        else if (it1 != nums2.end() && it1->second > 1) nums2[middle]--;

        it2 = nums2.find(middle * M);
        if (it2 != nums2.end()) {
            for (auto & it : nums1) {
                if (it.first * M == middle) {
                    count += it.second * it2->second;;
                    break;
                }
            }
        }
    }

    cout << count;

    return 0;
}