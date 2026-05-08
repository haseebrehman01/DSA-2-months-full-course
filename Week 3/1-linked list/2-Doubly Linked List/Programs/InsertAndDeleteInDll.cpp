#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int d) {

        // this refers to the current object of the class
        this->data = d;

        // initially previous pointer is NULL
        this->prev = NULL;

        // initially next pointer is NULL
        this->next = NULL;
    }
};

void addNodeAtHead(Node*& head, Node* newNode) {

    // if linked list is empty
    // directly make newNode the head
    if(head == NULL){

        head = newNode;
        return;
    }

    // connect new node with current head
    newNode->next = head;

    // connect current head back to new node
    head->prev = newNode;

    // move head to new node
    head = newNode;
}

// insert node at tail
void addNodeAtTail(Node*& head, Node* newNode) {

    // if linked list is empty
    if(head == NULL){

        head = newNode;
        return;
    }

    Node* temp = head;

    // move temp until last node
    while(temp->next != NULL){

        temp = temp->next;
    }

    // connect last node with new node
    temp->next = newNode;

    // connect new node back to previous node
    newNode->prev = temp;
}

void addNodeAtAnyPosition(Node*& head, int position, Node* newNode){

    // insert at head if:
    // position <= 1
    // OR linked list is empty
    if(position <= 1 || head == NULL){

        addNodeAtHead(head, newNode);
        return;
    }

    Node* temp = head;
    int index = 1;

    // move temp to one node before the given position
    while(temp->next != NULL && index < position - 1){

        temp = temp->next;
        index++;
    }

    // insert at tail if temp is last node
    if(temp->next == NULL){

        temp->next = newNode;
        newNode->prev = temp;

        return;
    }

    // insert in middle

    // connect new node with previous node
    newNode->prev = temp;

    // connect new node with next node
    newNode->next = temp->next;

    // connect previous node with new node
    temp->next = newNode;

    // connect next node back to new node
    newNode->next->prev = newNode;
}

// delete node at head
void deleteNodeAtHead(Node*& head){

    // if linked list is empty
    if(head == NULL){

        return;
    }

    Node* temp = head;

    // move head to next node
    head = head->next;

    // if new head exists
    // remove backward connection
    if(head != NULL){

        head->prev = NULL;
    }

    // delete old head node
    delete temp;
}

// delete node at tail
void deleteNodeAtTail(Node*& head){

    // if linked list is empty
    if(head == NULL){

        return;
    }

    // if only one node exists
    if(head->next == NULL){

        delete head;
        head = NULL;

        return;
    }

    Node* temp = head;

    // move temp to second last node
    while(temp->next->next != NULL){

        temp = temp->next;
    }

    // delete last node
    delete temp->next;

    // make second last node the new tail
    temp->next = NULL;
}

// delete node at any position
void deleteNodeAtAnyPosition(Node*& head, int position) {

    // if linked list is empty
    // OR invalid position is given
    if(head == NULL || position <= 0){

        return;
    }

    // delete head node
    if(position == 1){

        deleteNodeAtHead(head);
        return;
    }

    Node* temp = head;
    int index = 1;

    // move temp to one node before deleting position
    while(temp != NULL && index < position - 1){

        temp = temp->next;
        index++;
    }

    // position does not exist
    // because temp is last node
    // or temp itself became NULL
    if(temp == NULL || temp->next == NULL){

        return;
    }

    // node that will be deleted
    Node* nodeToDelete = temp->next;

    // deleting tail node
    if(nodeToDelete->next == NULL){

        // remove connection with tail node
        temp->next = NULL;

        // delete tail node
        delete nodeToDelete;

        return;
    }

    // middle delete

    // connect previous node with next node
    temp->next = nodeToDelete->next;

    // connect next node back to previous node
    nodeToDelete->next->prev = temp;

    // delete node
    delete nodeToDelete;
}

// print linked list
void printLinkedList(Node* temp){

    // if linked list is empty
    if(temp == NULL){

        cout << "Linked list is empty." << endl;
        return;
    }

    // print all nodes
    while(temp != NULL){

        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Node* head = NULL;

    addNodeAtHead(head, new Node(5));
    addNodeAtTail(head, new Node(20));
    addNodeAtAnyPosition(head, 1, new Node(10));

    printLinkedList(head); // 10 5 20

    addNodeAtAnyPosition(head, 2, new Node(70));

    printLinkedList(head); // 10 70 5 20

    addNodeAtAnyPosition(head, 9, new Node(100));

    printLinkedList(head); // 10 70 5 20 100

    addNodeAtAnyPosition(head, 5, new Node(800));

    printLinkedList(head); // 10 70 5 20 800 100

    deleteNodeAtHead(head);

    printLinkedList(head); // 70 5 20 800 100

    deleteNodeAtTail(head);

    printLinkedList(head); // 70 5 20 800

    deleteNodeAtAnyPosition(head, 2);

    printLinkedList(head); // 70 20 800

    return 0;
}