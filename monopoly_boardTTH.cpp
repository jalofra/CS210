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
        return value == other.value && rent == other.rent &&
        propertyName == other.propertyName && propertyColor == other.propertyColor;
    }


    void print() {
        cout << "Property: " << propertyName << ", color: " << propertyColor << ", value: " << value << ", rent: " << rent << endl;
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
    void insertAtHead(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (headNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        } else {
            newNode->nextNode = headNode;
            headNode = newNode;
            tailNode->nextNode = headNode;
        }
    }


    void insertAtTail(T value) {
        Node<T> *newNode = new Node<T>(value);
        if (tailNode == nullptr) {
            headNode = newNode;
            tailNode = newNode;
            tailNode->nextNode = headNode;
        } else {
            tailNode->nextNode = newNode;  // Link the current tail to the new node
            tailNode = newNode;            // Update tailNode
            tailNode->nextNode = headNode;
        }
    }

    void insertAtPosition(T value, int position) {
        Node<T>* newNode = new Node<T>(value);

        if (position == 0) {
            if (headNode == nullptr) {
                headNode = newNode;
                tailNode = newNode;
                tailNode->nextNode = headNode;
            } else {
                newNode->nextNode = headNode;
                headNode = newNode;
                tailNode->nextNode = headNode;
            }
            return;
        }

        Node<T>* currentNode = headNode;
        for (int i = 0; i < position - 1; i++) {
            currentNode = currentNode->nextNode;

            if (currentNode == headNode) {
                cout << "Position out of bounds when trying to insert: ";
                newNode->data.print();
                return;
            }
        }

        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;

        // Case 3: If inserting at the tail, update the tail pointer
        if (currentNode == tailNode) {
            tailNode = newNode;
            tailNode->nextNode = headNode;  // Maintain circular link
        }
    }

    void deleteAtHead() {
        if (headNode == nullptr) {
            return;
        }
        if (headNode == tailNode) {
            delete headNode;
            headNode = nullptr;
            tailNode = nullptr;
        } else {
            Node<T>* currentNode = headNode;
            headNode = headNode->nextNode;
            tailNode->nextNode = headNode;
            delete currentNode;
        }
    }



    void deleteAtTail() {//ToDo
        Node<T> *currentNode = tailNode;


        delete currentNode;

    }

    void deleteAtPosition(int position) {
        cout<<"Delete at Position unwritten"<<endl;
    }


    void search(T value) {

        cout<<"Search unwritten"<<endl;
    }
    void printList() {
        if (headNode == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node<T>* currentNode = headNode;


        do {
            currentNode->data.print();
            currentNode = currentNode->nextNode;
        } while (currentNode != headNode);

        cout << endl;
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
    MonopolyBoard myHouse = *new MonopolyBoard("MyHouse","red",1000, 500);
    MonopolyBoard yourHouse = *new MonopolyBoard("YourHouse","orange",900, 400);
    MonopolyBoard theirHouse = *new MonopolyBoard("TheirHouse","yellow",800, 400);
    MonopolyBoard herHouse = *new MonopolyBoard("HerHouse","green",600, 300);
    MonopolyBoard hisHouse = *new MonopolyBoard("HisHouse","blue",600, 300);

    list.insertAtHead(myHouse);
    list.insertAtTail(yourHouse);
    list.insertAtHead(theirHouse);
    list.insertAtPosition(herHouse, 3);
    list.insertAtHead(hisHouse);
    cout << myHouse.propertyColor << endl;

    cout << "List before deletion" << endl;

    list.printList();

   list.deleteAtHead();
    //list.deleteAtTail();
    //list.deleteAtPosition(2);

    //Optional Basic Tasks

   /* list.reverseCLList();
    list.sortCLList();
    list.printHeadNode();
    list.printLastNode();
    list.isListEmpty();
    list.countNodes();

    //Optional Advanced Tasks
    list.convertCLList();
    list.updateNodeValue();
    list.displaySpecificColorNode();
    list.mergeCLList();*/

   list.printList();
   cout << "List after deletion " << endl;

    return 0;
}