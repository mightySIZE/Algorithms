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
        void insert(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr)
                head = newNode;
            else {
                newNode->next = head;
                head = newNode;
            }
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
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.insert(20);

    // Print the list
    myList.printList();
    return 0;
}