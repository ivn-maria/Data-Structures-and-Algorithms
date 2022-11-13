#include <iostream>
using namespace std;

int main() {
    int days;
    cin >> days;

    int prices[days];
    for (int i = 0; i < days; i++)
        cin >> prices[i];

    int profit = 0;
    for (int j = 0; j < days - 1; j++) {
        int test = prices[j + 1] - prices[j];
        if (test > 0)
            profit += test;
    }

    cout << profit;
    
    return 0;
}
