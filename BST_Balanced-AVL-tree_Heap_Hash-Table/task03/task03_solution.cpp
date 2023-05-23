#include <iostream>
using namespace std;

struct Node{
    long long value;
    Node* previous;
    Node *left;
    Node *right;
    long long level;

    explicit Node(long long value) : value(value), previous(nullptr), left(nullptr), right(nullptr), level(-1) {}
};

Node* idxes[1000000];

class BST {
private:
    Node *root = nullptr;

public:
    BST() {
        root = new Node(0);
        idxes[0] = root;
        idxes[0]->level = 0;
    }

    void insert(int a, int b) {
        if (idxes[a]->left == nullptr) {
            idxes[a]->left = new Node(b);
            idxes[b] = idxes[a]->left;
            idxes[b]->previous = idxes[a];
            idxes[b]->level = idxes[a]->level + 1;
        } else {
            idxes[a]->right = new Node(b);
            idxes[b] = idxes[a]->right;
            idxes[b]->previous = idxes[a];
            idxes[b]->level = idxes[a]->level + 1;
        }
    }

    bool check(Node* current, Node* other) {
        if (current->value == other->value)
            return true;

        if (current->value < other->value)
            return false;

        if (current->level <= other->level)
            return false;

        if (current->previous == nullptr)
            return false;

        if (check(current->previous, other))
            return true;

        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    BST *tree = new BST();

    int a;
    int b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a;
        cin >> b;

        tree->insert(a, b);
    }

    int Q;
    cin >> Q;
    bool ans[Q];

    int x;
    int y;
    for (int i = 0; i < Q; i++) {
        cin >> x;
        cin >> y;

        if (tree->check(idxes[y], idxes[x])) ans[i] = true;
        else ans[i] = false;
    }

    for (int i = 0; i < Q; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}