#include <iostream>
using namespace std;

struct Node
{
    int color = 0;
    int number = 0;
    Node* previous = nullptr;
    Node* next = nullptr;

    Node(int color, int number) {
        this->color = color;
        this->number = number;
    }
};

struct List
{
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

    Node* push_after(Node* node, Node* after) {
        if (after == tail)
            return push_back(node);

        node->next = after->next;
        node->previous = after;
        after->next = node;
        node->next->previous = node;
        
        ++count;

        return node;
    }

    Node* push_back(Node* node) {
        ++count;
        
        if (count == 1) {
            head = tail = node;
            return node;
        }

        node->previous = tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;

        return node;
    }

    void remove(Node* left, Node* right) {
        Node* current;

        if (!left) current = head;
        else current = left->next;

        while (current != right) {
            Node* temp = current->next;
            delete current;
            current = temp;
            
            --count;
        }

        if(!left && !right) head = tail = nullptr;

        if (!left && right) {
            head = right;
            head->previous = nullptr;
        }

        if (!right && left) {
            tail = left;
            tail->next = nullptr;
        }

        if (left && right) {
            left->next = right;
            right->previous = left;
        }
    }


    int pop(Node* node, bool flag = false) {
        if (count == 0 || node == nullptr) return 0;

        Node* left = node;
        Node* right = node;

        long long leftCount = 0;
        long long rightCount = 0;

        bool tailContained = false;
        bool headContained = false;

        while (left->color == node->color) {
            ++leftCount;

            if (left == head) {
                headContained = true;
                break;
            }

            left = left->previous;
        }

        while (right->color == node->color) {
            ++rightCount;

            if (right == tail) {
                tailContained = true;
                break;
            }

            right = right->next;
        }

        --rightCount;

        if (((leftCount > 0 && rightCount > 0) || !flag) && leftCount + rightCount >= 3) {
            remove(headContained ? nullptr : left, tailContained ? nullptr : right);
            return leftCount + rightCount + (headContained || tailContained ? 0 : pop(left, true));
        }

        return 0;
    }

    void print() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->color << " ";
            current = current->next;
        }
    }
};

Node* originalBalls[100000]{};
Node* shootBalls[100000]{};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    
    List balls;
    int color;
    
    for (int i = 0; i < n; i++) {
        cin >> color;
        Node* node = new Node(color, i);
        originalBalls[i] = balls.push_back(node);
    }

    int q;
    cin >> q;
    
    Node* current;
    int ball;
    
    for (int i = 0; i < q; i++) {
        cin >> ball >> color;

        if (balls.count == 0) {
            cout << "Game Over\n";
            continue;
        }

        if (ball < n)
            current = originalBalls[ball];
        else
            current = shootBalls[ball % n];

        Node* node = new Node(color, n + 1);
        shootBalls[i] = balls.push_after(node, current);

        cout << balls.pop(shootBalls[i]) << "\n";
    }

    if (balls.count == 0)
        cout << "-1\n";
    else
        balls.print();

    return 0;
}
