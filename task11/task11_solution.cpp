#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int value;
    Node *previous;
    Node *next;

    Node(int value) {
        this->value = value;
        previous = nullptr;
        next = nullptr;
    }

    Node(int value, Node *next, Node *previous) {
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    int elementsCount;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;

        elementsCount = 0;
    }

    void push_back(int number) {
        elementsCount++;

        if (tail == nullptr) {
            head = new Node(number, nullptr, nullptr);
            tail = head;
            return;
        }

        tail->next = new Node(number, nullptr, tail);
        tail = tail->next;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }

        elementsCount--;

        Node *temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
    }
};

Node* values[100001];

bool search(int n, int m, DoublyLinkedList* list) {
    bool ans = false;

    if (list->tail->previous == nullptr) {
        values[m] = list->tail;
        return ans;
    }

    if (values[m] != nullptr) {
        if (values[m] == list->head)
            list->pop_front();
        else {
            Node* current = values[m]->previous;
            Node* temp = values[m];
            current->next = temp->next;
            current->next->previous = current;
            delete temp;
            list->elementsCount--;
        }

        values[m] = list->tail;
        ans = true;
    } else values[m] = list->tail;

    if (list->elementsCount > n) {
        if(list->head->value != m) values[list->head->value] = nullptr;
        list->pop_front();
    }

    return ans;
}

int main() {
    int t, n;
    cin >> t >> n;

    auto* list = new DoublyLinkedList();
    for (int i = 0; i < t; i++) {
        int m;
        cin >> m;

        list->push_back(m);

        if (search(n, m ,list)) cout << "true" << '\n';
        else cout << "false" << '\n';
    }

    return 0;
}