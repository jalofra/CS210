#include <iostream>
#include <string>

using namespace std;

// Data class to store a string and an integer
class MonopolyBoard {
public:
    string propertyName;
    string propertyColor;
    int value;
    int rent;

    MonopolyBoard() {
        propertyName = "";
        propertyColor = "";
        value = 0;
        rent = 0;
    }


    MonopolyBoard(string propertyName,string propertyColor,int value, int rent){
        this->propertyName=propertyName;
        this->propertyColor=propertyColor;
        this->value=value;
        this->rent=rent;
    }


    bool isEqual(MonopolyBoard other) {
        return value == other.value && rent == other.rent && propertyName == other.propertyName && propertyColor == other.propertyColor;
    }


    void print() {
        cout << propertyName << " " << propertyColor << " " << value << " " << rent << endl;
    }
};

// Template Node class
template <typename T> class Node {
public:
    T data;
    Node* nextNode;

    Node(T value) {
        data = value;
        nextNode = nullptr;
    }
};

// Template LinkedList class
template <typename T> class CircularLinkedList {
private:
    Node<T>* headNode;
    Node<T>* tailNode;

public:
    CircularLinkedList() {
        headNode = nullptr;
        tailNode = nullptr;
    }

// Mandatory Tasks
    /*void insertAtHead() {
        cout<<"Insert at head unwritten"<<endl;
    }*/
    void insertAtHead(T value) {
        Node<T> *newNode = new Node<T>(value);//ToDo update the tailNode pointer
        if (headNode == nullptr) {
            headNode = newNode;
        } else {
            newNode->nextNode = headNode;
            headNode = newNode;
            tailNode->nextNode = newNode;
        }
    }


    void insertAtTail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (tailNode == nullptr) {
            tailNode  = newNode;
        } else {
            while (tailNode->next != nullptr) {
                tailNode = tailNode->next;
            }
            tailNode->next = newNode;
            tailNode = newNode;
        }
    }

    void insertAtPosition(T value, int position) {
        Node<T> *newNode = new Node<T>(value);
        Node<T> *currentNode = headNode;
        int positionIndex = 0;

        if (position == 0) {//ToDo update tail node if position is 0
            newNode->nextNode = currentNode;
            headNode = newNode;
            if (tailNode == nullptr) {
                tailNode = newNode;
            }
            return;
        }

        for (int i =0; i < position - 1 && currentNode != nullptr; i++) {
        currentNode = currentNode->nextNode;
        }

        if (currentNode == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }

        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
    }
    void deleteAtHead() {
        Node<T> *currentNode = headNode;
        if (headNode == nullptr) {
            return;
        }
        if (headNode == tailNode) {
            headNode = nullptr;
            tailNode = nullptr;
        } else {
            headNode = headNode->nextNode;
        }
        delete currentNode;
    }


    void deleteAtTail() {
        Node<T> *currentNode = tailNode;


        delete currentNode;

    }

    void deleteAtPosition() {
        cout<<"Delete at Position unwritten"<<endl;
    }


    void search(T value) {

        cout<<"Search unwritten"<<endl;
    }
    void printList() {
        cout << "Print List unwritten" << endl;
    }

    //Optional Tasks
    //Basic Funtions
    void reverseCLList() {
        cout << "Reverse List unwritten" << endl;
    } void sortCLList() {
        cout << "Sort List unwritten" << endl;
    } void printHeadNode() {
        cout << "Print Head Node unwritten" << endl;
    } void printLastNode() {
        cout << "Print Last Node unwritten" << endl;
    } void isListEmpty() {
        cout << "Is List Empty unwritten" << endl;
    }
    void countNodes() {
        cout << "Count Nodes unwritten" << endl;
    }

    //Optional Tasks
    // Advanced Functions
    void convertCLList() {
        cout << "Convert Circular List Unwritten." << endl;
    } void updateNodeValue() {
        cout << "update Node value unwritten" << endl;
    } void displaySpecificColorNode() {
        cout << "Display Specific color Node" << endl;
    } void mergeCLList() {
        cout << "Merge Circular Linked List Unwritten" << endl;
    }

};

// Main function to demonstrate the LinkedList class
int main() {
    // Create a LinkedList of Data objects
    CircularLinkedList<MonopolyBoard> list;

    // Insert elements at the end
    //list.insertAtHead(); ToDo make all these functions work

    list.insertAtTail();

    list.insertAtPosition(5);

    list.deleteAtHead();

    list.deleteAtTail();

    list.deleteAtPosition();

    //Optional Basic Tasks

    list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();

    //Optional Advanced Tasks
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();

    return 0;
}