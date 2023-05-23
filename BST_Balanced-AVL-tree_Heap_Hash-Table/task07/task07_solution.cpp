#include <iostream>
#include <set>
#include <queue>
using namespace std;

struct item {
    int first_time;
    int second_time;
    int id;

    item(int f, int s, int i) {
        first_time = f;
        second_time = s;
        id = i;
    }
};

struct SortFirst {
    bool operator() (const item& first, const item& sec) const {
        if (first.first_time == sec.first_time) {
            return first.id < sec.id;
        }

        return first.first_time < sec.first_time;
    }
};

struct SortSecond {
    bool operator() (const item& first, const item& sec) const {
        if (first.second_time == sec.second_time) {
            return first.id > sec.id;
        }

        return first.second_time > sec.second_time;
    }
};

int main() {
    int N;
    cin >> N;

    multiset<item, SortFirst> ordersByFirst;
    for (int i = 0; i < N; ++i) {
        int t, f;
        cin >> t >> f;
        item num(t, f, i);
        ordersByFirst.insert(num);
    }

    int myTime;
    auto it = ordersByFirst.begin();
    item first = *it;
    cout << first.id << ' ';
    ordersByFirst.erase(it);
    myTime = first.first_time + first.second_time;

    priority_queue<item, vector<item>, SortSecond> ordersBySecond;
    it = ordersByFirst.begin();
    while (it != ordersByFirst.end()) {
        item current = *it;
        if (current.first_time <= myTime) {
            ordersBySecond.push(current);
            it++;
        } else {
            if (ordersBySecond.empty()) {
                cout << current.id << ' ';
                ordersByFirst.erase(it);
                myTime = current.first_time + current.second_time;
                it = ordersByFirst.begin();
            } else {
                item ans = ordersBySecond.top();
                cout << ans.id << ' ';
                myTime += ans.second_time;
                ordersByFirst.erase(ans);
                ordersBySecond.pop();
            }
        }
    }

    while (!ordersBySecond.empty()) {
        cout << ordersBySecond.top().id << ' ';
        ordersBySecond.pop();
    }

    return 0;
}