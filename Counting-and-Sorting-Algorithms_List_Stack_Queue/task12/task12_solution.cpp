#include <vector>
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

Node* arr[20001];
int k = 0;

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

    void insertAfter(int idx, Node* newNode) {
        if (arr[idx]->next == nullptr) {
            arr[idx]->next = newNode;
            newNode->previous = arr[idx];
            newNode->next = nullptr;
            tail = tail->next;

            return;
        }

        newNode->next = arr[idx]->next;
        arr[idx]->next->previous = newNode;
        arr[idx]->next = newNode;
        newNode->previous = arr[idx];
    }

    bool IsEmpty() const {
        return (head == nullptr && tail == nullptr);
    }

    void print() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    void Check(Node* added, int& deleted) {
        Node* before = added;
        Node* after = added;

        int counter = 0;
        while (before->previous != nullptr && before->previous->value == added->value) {
            counter++;
            before = before->previous;
        }
        while (after->next != nullptr && after->next->value == added->value) {
            counter++;
            after = after->next;
        }

        if (counter >= 2) {
            deleted += (counter + 1);

            Node* copy = after->next;
            while (before != copy) {
                Node* tmp = before->next;

                if (before->previous != nullptr)
                    before->previous->next = before->next;
                if (before->next != nullptr)
                    before->next->previous = before->previous;
                if (before->previous == nullptr)
                    head = head->next;
                if (before->next == nullptr)
                    tail = tail->previous;

                delete before;
                before = tmp;
            }

            if (before != nullptr && before->previous!=nullptr && before->value == before->previous->value)
                Check(before, deleted);
        }
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < 200001; i++)
        arr[i] = nullptr;

    DoublyLinkedList list;
    vector<int> res;

    for (int i = 0; i < n; i++) {
        int color;
        cin >> color;
        list.push_back(color);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int p, c;
        cin >> p >> c;

        int deleted = 0;

        if (!list.IsEmpty()) {
            arr[k] = new Node(c);
            list.insertAfter(p, arr[k]);
            list.Check(arr[k], deleted);
            res.push_back(deleted);
            deleted = 0;
            k++;
        }
        else {
            res.push_back(-1);
        }
    }

    for (int i = 0; i < res.size(); i++) {
        if (res[i] != -1)
            cout << res[i] << "\n";
        else cout << "Game Over\n";
    }

    if (!list.IsEmpty())
        list.print();
    else cout << "-1" << '\n';

    return 0;
}