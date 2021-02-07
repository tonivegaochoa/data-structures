#include <iostream>
using namespace std;

class Node {
    public:
        int val;
        Node *prev;
        Node *next;
};

class Linked_List {
    public:
        Linked_List();
        int length();
        void push_back(int val);
        void push_front(int val);
        void pop_back();
        void pop_front();
        int top();
        int end();

        void print();
    private:
        int size;
        Node* head;
        Node* tail;
};

Linked_List::Linked_List() {
    size = 0;
    head = NULL;
    tail = NULL;
}

int Linked_List::length() {
    return size;
}

void Linked_List::push_back(int val) {
    Node *newNode = new Node();

    newNode->val = val;
    newNode->prev = tail;
    newNode->next = NULL;

    if(tail != NULL) {
        tail->next = newNode;
    }
    
    head = head == NULL ? newNode : head;
    tail = newNode;
    size++;
}

void Linked_List::push_front(int val) {
    Node *newNode = new Node();

    newNode->val = val;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    size++;
}

void Linked_List::pop_back() {
    if(size == 0) {
        throw "List is empty";
    }
}

void Linked_List::pop_front() {
    if(size == 0) {
        throw "List is empty";
    }
}

int Linked_List::top() {
    return head->val;
}

int Linked_List::end() {
    return tail->val;
}

void Linked_List::print() {
    Node *tmp = head;
    while(tmp != NULL) {
        if(tmp != head) {
            cout << "->";
        }
        cout << tmp->val;
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    Linked_List list;
    list.pop_front();
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_front(4);
    list.push_front(45);
    list.push_back(54);
    list.print();
    cout << list.length() << endl;
}