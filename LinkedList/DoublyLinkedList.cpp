#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data=-1, Node* prev=nullptr, Node* next=nullptr) {
            this->data = data;
            this->prev = prev;
            this->next = next;
        }
};

class DoublyLinkedList {
    public:
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // Insert a node at the beginning of the list
        void insertAtStart(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        // Insert a node at the end of the list
        void insertAtEnd(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Print the linked list forward
        void printForward() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << "->";
                current = current->next;
            }
            cout << endl;
        }

        // Print the linked list backward
        void printBackward() {
            Node* current = tail;
            while (current != nullptr) {
                cout << current->data << "->";
                current = current->prev;
            }
            cout << endl;
        }

};

int main()
{
    // Create a linked list object
    DoublyLinkedList myList;

    // Insert nodes into the list
    myList.insertAtStart(5);
    myList.insertAtStart(10);
    myList.insertAtStart(15);
    myList.insertAtStart(20);

    myList.insertAtEnd(25);
    myList.insertAtEnd(30);
    myList.insertAtEnd(35);
    myList.insertAtEnd(40);

    // Print the list
    myList.printForward();
    myList.printBackward();

    return 0;
}