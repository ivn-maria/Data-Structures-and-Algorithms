#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;

    Node() : value(0), left(nullptr), right(nullptr) {}
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

Node* idxes[1000000];

class BST {
private:
    Node *root = nullptr;
    int count = 0;

public:
    void insert(int value, int left, int right) {
        if (root == nullptr) {
            root = new Node(value);
            idxes[count] = root;

            if (left != -1) {
                idxes[left] = new Node();
                root->left = idxes[left];
            }

            if (right != -1) {
                idxes[right] = new Node();
                root->right = idxes[right];
            }

            count++;
        } else {
            idxes[count]->value = value;

            if (left != -1) {
                idxes[left] = new Node();
                idxes[count]->left = idxes[left];
            }

            if (right != -1) {
                idxes[right] = new Node();
                idxes[count]->right = idxes[right];
            }

            count++;
        }
    }

    bool check() {
        return check(root, nullptr);
    }

    bool check(Node* current, Node* prev) {
        if (current != nullptr) {
            if (!check(current->left, prev))
                return false;
            if (!check(current->right, current))
                return false;
            if (prev != nullptr && current->value <= prev->value)
                return false;
        }
        return true;
    }
};

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        BST tree;

        for (int j = 0; j < N; j++) {
            int A;
            cin >> A;
            int left;
            cin >> left;
            int right;
            cin >> right;

            tree.insert(A, left, right);
        }

        if(tree.check()) cout << '1' << '\n';
        else cout << '0' << '\n';
    }

    return 0;
}