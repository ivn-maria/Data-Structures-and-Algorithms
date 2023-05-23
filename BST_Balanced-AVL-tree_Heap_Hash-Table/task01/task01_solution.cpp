#include <iostream>
using namespace std;

struct Node{
    long long value;
    Node *left;
    Node *right;
    int X, Y;

    Node() : value(0), left(nullptr), right(nullptr) {}
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* idxes[1000000];

class BST {
private:
    Node *root = nullptr;
    long long count = 0;

public:
    long long minX = 0;
    long long maxX = 0;

    void insert(long long value, long long left, long long right) {
        if (root == nullptr) {
            root = new Node(value);
            idxes[count] = root;
            root->X = 0;
            root->Y = 0;

            if (left != -1) {
                idxes[left] = new Node();
                root->left = idxes[left];
                root->left->X = -1;
                root->left->Y = 1;
                minX = -1;
            }

            if (right != -1) {
                idxes[right] = new Node();
                root->right = idxes[right];
                root->right->X = 1;
                root->right->Y = 1;
                maxX = 1;
            }

            count++;
        } else {
            idxes[count]->value = value;

            if (left != -1) {
                idxes[left] = new Node();
                idxes[count]->left = idxes[left];
                idxes[count]->left->X = idxes[count]->X - 1;
                idxes[count]->left->Y = idxes[count]->Y + 1;
                if (idxes[count]->left->X < minX) minX = idxes[count]->left->X;
            }

            if (right != -1) {
                idxes[right] = new Node();
                idxes[count]->right = idxes[right];
                idxes[count]->right->X = idxes[count]->X + 1;
                idxes[count]->right->Y = idxes[count]->Y + 1;
                if (idxes[count]->right->X > maxX) maxX = idxes[count]->right->X;
            }

            count++;
        }
    }
};

int main()
{
    long long N;
    cin >> N;

    BST slope;

    for (long long i = 0; i < N; i++) {
        long long A;
        cin >> A;
        long long left;
        cin >> left;
        long long right;
        cin >> right;

        slope.insert(A, left, right);
    }

    long long start = slope.minX;
    long long end = slope.maxX;
    for (long long i = start; i <= end; i++) {
        long long sum = 0;
        for (int j = 0; j < N; j++)
            if (idxes[j]->X == i)
                sum += idxes[j]->value;
        cout << sum << ' ';
    }

    return 0;
}