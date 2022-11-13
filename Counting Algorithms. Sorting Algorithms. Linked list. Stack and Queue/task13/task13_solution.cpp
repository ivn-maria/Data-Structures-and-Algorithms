#include <iostream>
#include <stdexcept>
#include <list>
using namespace std;

class Queue {
private:
    list<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }

    void pop() {
        data.pop_front();
    }

    int peek() const {
        if (data.size() > 0) {
            return data.front();
        } else {
            throw std::underflow_error("Queue is empty.");
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }

    int getSize() const {
        return data.size();
    }
};

Queue queue;
int map[1000][1000];

int check_next_day(int n, int m) {
    int count = 0;

    int row = queue.peek();
    queue.pop();
    int col = queue.peek();
    queue.pop();

    if (row < n) {
        if (map[row + 1][col] != 1) {
            queue.push(row + 1);
            queue.push(col);
            map[row + 1][col] = 1;
            count++;
        }
    }
    if (row > 0) {
        if (map[row - 1][col] != 1) {
            queue.push(row - 1);
            queue.push(col);
            map[row - 1][col] = 1;
            count++;
        }
    }
    if (col < m) {
        if (map[row][col + 1] != 1) {
            queue.push(row);
            queue.push(col + 1);
            map[row][col + 1] = 1;
            count++;
        }
    }
    if (col > 0) {
        if (map[row][col - 1] != 1) {
            queue.push(row);
            queue.push(col - 1);
            map[row][col - 1] = 1;
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            map[i][j] = 0;
        }
    }
    n -= 1;
    m -= 1;

    int t;
    cin >> t;

    int row, col;
    int count = 0;

    for (int i = 0; i < 2; ++i) {
        row = col = -1;
        cin >> row >> col;

        if (row != -1) {
            row -= 1;
            col -= 1;
            count++;
            map[row][col] = 1;
            queue.push(row);
            queue.push(col);
        }
    }

    while (t > 0) {
        int size = queue.getSize() / 2;
        for (int i = 0; i < size; i++)
            count += check_next_day(n, m);
        t--;
    }

    int all = (n + 1) * (m + 1);
    int ans = all - count;
    cout << ans;

    return 0;
}