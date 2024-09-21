#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class Student {
public:
    string name;
    int num;

    Student() {
        name = "";
        num = 0;
    }
    Student(string s, int n) {
        name = s;
        num = n;
    }

    bool isEqual(Student other) {
        return (name == other.name && num == other.num);
    }

    void print() { cout << "(" << name << ", " << num << ")"; }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node *nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class LinkedList {
private:
    Node<T> *headNode;

public:
    LinkedList() { headNode = nullptr; }
    // ToDo ADD reverseLinkedList method

    // Insert at the head of the list
    void insertAtHead(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            newNode->nextNode = headNode;
            headNode = newNode;
        }
    }

    void insertAtTail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            Node<T> *temp = headNode;
            while (temp->nextNode != nullptr) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }
    void deleteSpecificNode(T value) {
        if (headNode == nullptr) {
            cout << "List is empty. Cannot delete." << endl;
            return;
        }

        //same as delete at head
        if (headNode->data.isEqual(value)) {
            Node<T>* toDelete = headNode;
            headNode = headNode->nextNode;
            delete toDelete;
            return;
        }

        Node<T>* temp = headNode;
        while (temp->nextNode != nullptr && !temp->nextNode->data.isEqual(value)) {
            temp = temp->nextNode;
        }

        if (temp->nextNode == nullptr) {
            cout << "Value not found in the list." << endl;
        } else {
            Node<T>* toDelete = temp->nextNode;
            temp->nextNode = temp->nextNode->nextNode;
            delete toDelete;
        }
    }

    // Search for a node with a specific value
    bool search(T value) {
        Node<T>* temp = headNode;
        while (temp != nullptr) {
            if (temp->data.isEqual(value)) {
                return true;
            }
            temp = temp->nextNode;
        }
        return false;
    }


    // Delete a node with a specific value

    // Print the linked list
    void printList() {
        Node<T> *temp = headNode;
        while (temp != nullptr) {
            temp->data.print();
            cout << " -> ";
            temp = temp->nextNode;
        }
        cout << "NULL" << endl;
    }
};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    LinkedList<Student> list;

    // Insert elements at the end
    list.insertAtHead(Student("A", 25));

    cout << "Linked List after insertions:" << endl;
    list.printList();

    return 0;
}