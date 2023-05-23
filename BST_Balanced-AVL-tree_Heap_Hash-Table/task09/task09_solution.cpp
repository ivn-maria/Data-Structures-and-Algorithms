#include <iostream>
#include <set>
using namespace std;

int main() {
    int K, T, B, N;
    cin >> K >> T >> B >> N;

    multiset<int> nums;
    for (int i = 0; i < B; ++i) {
        for (int j = i*T; j < (i + 1)*T; ++j) {
            if(j >= N) break;
            int x;
            cin >> x;
            nums.insert(x);
        }
        for (int j = 0; j < K; ++j) {
            if(!nums.empty()) {
                auto itr = nums.begin();
                cout << *nums.begin() << ' ';
                nums.erase(nums.begin());
            }
        }
    }

    return 0;
}
