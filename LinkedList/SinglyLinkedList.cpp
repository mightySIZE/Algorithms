#include <iostream>
using namespace std;

// Linked List example with seperate classes

class Node {
    public:
        int data;
        Node* next;

        Node(int data=-1, Node* next=nullptr) {
            this->data = data;
            this->next = next;
        }

        // can implement constructor like this too 
        // Node(int value) {
        //     data = value;
        //     next = nullptr;
        // }
};

class SinglyLinkedList {
    public:
        Node* head;
        SinglyLinkedList() {
            head = nullptr;
        }
    public:
        void insert(int value) {
            Node* temp = new Node(value);
            
        }

};






int main()
{

    return 0;
}