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

long long findMins(const long long arr[], long long n, long long k) {
    Dequeue dequeue;

    for (long long i = 0; i < k; i++) {
        while(!dequeue.isEmpty() && arr[i] <= arr[dequeue.peek_back()])
            dequeue.pop_back();
        dequeue.push(i);
    }

    long long sum = 0;
    for (long long i = k; i < n; i++) {
        sum += arr[dequeue.peek_front()];

        while (!dequeue.isEmpty() && dequeue.peek_front() <= i - k)
            dequeue.pop_front();
        while (!dequeue.isEmpty() && arr[i] <= arr[dequeue.peek_back()])
            dequeue.pop_back();

        dequeue.push(i);
    }

    sum += arr[dequeue.peek_front()];

    return sum;
}

int main() {
    long long n, k;
    cin >> n >> k;

    long long arr[n];
    for(long long i = 0; i < n; i++)
        cin >> arr[i];

    cout << findMins(arr, n, k);

    return 0;
}