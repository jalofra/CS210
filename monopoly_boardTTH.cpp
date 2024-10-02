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
            tailNode->nextNode = newNode;
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

        if (currentNode == tailNode) {
            tailNode = newNode;
            tailNode->nextNode = headNode;
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



    void deleteAtTail() {
        Node<T> *currentNode = headNode;
        if (headNode == nullptr) {
            return;
        }
        if (headNode == tailNode) {
            delete headNode;
            tailNode = nullptr;
            headNode = nullptr;
        } else {
            while (currentNode->nextNode != tailNode) {
                currentNode = currentNode->nextNode;
            }
            delete tailNode;
            tailNode = currentNode;
            tailNode->nextNode = headNode;

        }

    }

    void deleteAtPosition(int position) {//ToDo finish
        Node<T> *currentNode = headNode;
        if (headNode == nullptr) {
            return;
        }
        if (position == 0){
            if (headNode == tailNode) {
                delete headNode;
                headNode = nullptr;
                tailNode = nullptr;
            } else {
                headNode = headNode->nextNode;
                tailNode->nextNode = headNode;
                delete currentNode;
            }


        }
    }


    void search(T value) {//ToDo finish

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

    /*ToDo 40 pts. 4 Basic or 2 Advanced.
     * All lvl 1 or 2 = 10 EC
     * ALL lvl 1 + 2 = 15 EC
     * Past 80 pts = 2pts per func
     * */

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


int main() {

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