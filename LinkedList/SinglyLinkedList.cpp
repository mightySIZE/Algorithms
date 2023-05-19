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

        // Can implement constructor like this too 
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
        // Insert a node at the beginning of the list
        void insertAtStart(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr)
                head = newNode;
            else {
                newNode->next = head;
                head = newNode;
            }
        }

        // Insert a node at the end of the list
        void insertAtEnd(int value) {
            Node* traverse = head;
            Node* newNode = new Node(value);
            while (traverse->next != nullptr) {
                traverse = traverse->next;
            }
            traverse->next = newNode;
        }

        // Print the linked list
        void printList() {
            Node* current = head;
            while (current != nullptr) {
                cout << current->data << "->";
                current = current->next;
            }
            cout << endl;
        }

};

int main()
{
    // Create a linked list object
    SinglyLinkedList myList;

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
    myList.printList();
    return 0;
}