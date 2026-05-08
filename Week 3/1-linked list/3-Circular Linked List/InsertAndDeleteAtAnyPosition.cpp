#include <iostream>
using namespace std;

// Singly Circular Linked List

struct Node{
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// print circular linked list
void printCircularLinkedList(Node* head){

    // if list is empty
    if(head == NULL){
        cout << "Circular linked list is empty." << endl;
        return;
    }

    Node* temp = head;

    // do-while is important in circular linked list
    // because head must also be printed
    do{
        cout << temp->data << " ";
        temp = temp->next;

    }while(temp != head);

    cout << endl;
}

// insert at head
void insertAtHead(Node*& head, Node* newNode){

    // if list is empty
    if(head == NULL){

        head = newNode;

        // point node to itself
        newNode->next = head;

        return;
    }

    Node* temp = head;

    // move to last node
    while(temp->next != head){
        temp = temp->next;
    }

    // connect last node to new node
    temp->next = newNode;

    // new node points to old head
    newNode->next = head;

    // move head
    head = newNode;
}

// insert at tail
void insertAtTail(Node*& head, Node* newNode){

    // if list is empty
    if(head == NULL){

        head = newNode;
        newNode->next = head;

        return;
    }

    Node* temp = head;

    // move to last node
    while(temp->next != head){
        temp = temp->next;
    }

    // last node points to new node
    temp->next = newNode;

    // new node points to head
    newNode->next = head;
}

// insert at any position
void insertAtAnyPosition(Node*& head, int position, Node* newNode){

    // insert at head
    if(position <= 1 || head == NULL){

        insertAtHead(head, newNode);
        return;
    }

    Node* temp = head;
    int index = 1;

    // move to one node before position
    while(temp->next != head && index < position - 1){

        temp = temp->next;
        index++;
    }

    // insert at tail
    if(temp->next == head){

        temp->next = newNode;
        newNode->next = head;

        return;
    }

    // middle insertion
    newNode->next = temp->next;
    temp->next = newNode;
}

// delete head
void deleteAtHead(Node*& head){

    // if list empty
    if(head == NULL){
        return;
    }

    // only one node exists
    if(head->next == head){

        delete head;
        head = NULL;

        return;
    }

    Node* temp = head;

    // move to last node
    while(temp->next != head){
        temp = temp->next;
    }

    Node* nodeToDelete = head;

    // move head
    head = head->next;

    // last node points to new head
    temp->next = head;

    delete nodeToDelete;
}

// delete tail
void deleteAtTail(Node*& head){

    // if list empty
    if(head == NULL){
        return;
    }

    // only one node exists
    if(head->next == head){

        delete head;
        head = NULL;

        return;
    }

    Node* temp = head;

    // move to second last node
    while(temp->next->next != head){
        temp = temp->next;
    }

    Node* nodeToDelete = temp->next;

    // second last points to head
    temp->next = head;

    delete nodeToDelete;
}

// delete at any position
void deleteAtAnyPosition(Node*& head, int position){

    // invalid cases
    if(head == NULL || position <= 0){
        return;
    }

    // delete head
    if(position == 1){

        deleteAtHead(head);
        return;
    }

    Node* temp = head;
    int index = 1;

    // move to one node before delete position
    while(temp->next != head && index < position - 1){

        temp = temp->next;
        index++;
    }

    // position out of bound
    if(temp->next == head){
        return;
    }

    Node* nodeToDelete = temp->next;

    // deleting tail
    if(nodeToDelete->next == head){

        temp->next = head;

        delete nodeToDelete;

        return;
    }

    // middle delete
    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}

int main(){

    Node* head = NULL;

    // insertions
    insertAtHead(head, new Node(10));
    insertAtTail(head, new Node(20));
    insertAtTail(head, new Node(30));

    printCircularLinkedList(head);
    // 10 20 30

    insertAtAnyPosition(head, 2, new Node(50));

    printCircularLinkedList(head);
    // 10 50 20 30

    insertAtAnyPosition(head, 10, new Node(100));

    printCircularLinkedList(head);
    // 10 50 20 30 100

    // deletions
    deleteAtHead(head);

    printCircularLinkedList(head);
    // 50 20 30 100

    deleteAtTail(head);

    printCircularLinkedList(head);
    // 50 20 30

    deleteAtAnyPosition(head, 2);

    printCircularLinkedList(head);
    // 50 30

    return 0;
}