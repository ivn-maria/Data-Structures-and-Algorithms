#include <iostream>
#include <stdexcept>
#include <list>
using namespace std;

class Dequeue {
private:
    list<int> data;
public:
    void push(int number) {
        data.push_back(number);
    }

    void pop_front() {
        data.pop_front();
    }

    void pop_back() {
        data.pop_back();
    }

    int peek_front() const {
        if (data.size() > 0) {
            return data.front();
        } else {
            throw std::underflow_error("Queue is empty.");
        }
    }

    int peek_back() const {
        if (data.size() > 0) {
            return data.back();
        } else {
            throw std::underflow_error("Queue is empty.");
        }
    }

    bool isEmpty() const {
        return data.size() == 0;
    }
};

long long k = 0;
Dequeue pos;

void func(long long arr[], long long n) {
    while (k < n && arr[k] > 0) {
        pos.push(arr[k]);
        k++;
    }

    while (k < n && arr[k] < 0) {
        if (pos.isEmpty()) {
            cout << arr[k] << ' ';
            k++;
        } else {
            long long num = -arr[k];
            if (pos.peek_back() > num)
                k++;
            else if (pos.peek_back() < num)
                pos.pop_back();
            else if (pos.peek_back() == num) {
                k++;
                pos.pop_back();
            }
        }
    }
}

int main() {
    long long n;
    cin >> n;

    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    while (arr[k] < 0) {
        cout << arr[k] << ' ';
        k++;
    }

    while (k < n)
        func(arr, n);


    if (!pos.isEmpty()) {
        while(!pos.isEmpty()) {
            cout << pos.peek_front() << ' ';
            pos.pop_front();
        }
    }

    return 0;
}