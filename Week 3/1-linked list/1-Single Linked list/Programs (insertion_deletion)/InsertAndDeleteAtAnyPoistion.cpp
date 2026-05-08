// #include <iostream>
// using namespace std;

// // Creating a node for a singly linked list using struct
// struct Node{
//     int data;
//     Node* next; // Pointer that stores address of next node

//     // Constructor to initialize node
//     Node(int d){
//         data = d;
//         next = NULL;
//     }
// };

// void printLinkedList(Node* temp){
//    while(temp != NULL){
//         cout << temp->data << " ";
//         temp = temp->next;
//     }

// }

// int main()
// {
//     // Creating first node dynamically
//     Node* head = new Node(10);

//     // head stores address of the created node
//     cout << head << endl;//address of the first node

//     // Accessing data of the node
//     cout << head->data << endl; //10

//     // Accessing next of the node
//     cout << head->next << endl;//NULL

//     // Creating a new node and linking it at the end
//     head->next = new Node(20);

//     // Accessing data of second node
//     cout << head->next->data << endl;

//     // Creating a new node
//     Node* newNode = new Node(5);//yahan mena node bnaka var mai save kardi upper directly head->next mai mai daldi thi yahan "   head->next = new Node(20);"

//     // New node points to current head node
//     newNode->next = head;

//     // head now stores address of newNode, linking it at the front
//     head = newNode;

//     // Printing linked list
//     // temp is used to traverse the linked list without changing the original head pointer
// // if head is used directly, it will move forward and eventually become NULL
// // ex :
// // head → 5 → 10 → 20 → NULL
// // while(head != NULL){
// //     cout << head->data << " ";
// //     head = head->next;
// // }
// // Dry Run (head direct use)
// // Initial state
// // head → 5 → 10 → 20 → NULL
// // Iteration 1

// // Condition:
// // Print:

// // 5

// // Move:
// // head = head->next; //now head points to the address of 10

// // Now:

// // head → 10 → 20 → NULL

// // head != NULL   // true

// // Iteration 2

// // Print:

// // 10

// // Move:

// // head = head->next; // now head points to the address of 20
// // Now:

// // head →  20 → NULL

// // Iteration 3

// // Print:

// // 20

// // Move:

// // head → NULL// now head points to NULL

// // Iteration 4

// // Condition:

// // head != NULL

// // FALSE → loop stops

// ////////////////
// // Final State
// // head = NULL

// // thats why we use a temp pointer to traverse the linked list without modifying the head pointer
//     Node* temp = head; // temp is used to traverse the linked list
//     printLinkedList(temp);
//     return 0;
// }


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) {
        this -> data = d;//this is used to refer to the current object of the class, it is a pointer that points to the current object
        this -> next = NULL;//this is used to refer to the current object of the class, it is a pointer that points to the current object
    }
};

// create node
Node* createNode(int data) {//this function is used to create a new node with the given data and return the address of the new node
    return new Node(data);
}

// insert at front
void addNodeAtHead(Node*& head, Node* newNode) {//refernce islya lya qka mai chat hin original link list ko change karna . refernce nahi keta toh copy banti
    
    // if(head == NULL){//agar linked list empty ho toh front pe insert kar do
    //      head = newNode;
    //      return;
    // }
    newNode->next = head;
    head = newNode;
}

// insert at end (correct)
void addNodeAtTail(Node*& head, Node* newNode) {
//     NULL->next // isssa bachna ka lya if condition lagate hai taki jab linked list empty ho toh front pe insert kar de nahi toh temp->next->next mai NULL->next hoga jo ki invalid hai aur segmentation fault ya crash hoga

// 💥 segmentation fault / crash.
    if (head == NULL) {//agar linked list empty ho toh front pe insert kar do
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;//matlab temp moves to the next node until it reaches the last node where temp->next is NULL
    }

    temp->next = newNode;
}

//
void addNodeAtAnyPosition(Node*& head ,int position,Node* newNode ){
Node* temp = head;
   // agar front pe insert karna ho
    if(position <=  1 || head == NULL){ //agar position 1 se choti ya barabar ho ya linked list empty ho toh front pe insert kar do
      addNodeAtHead(head, newNode);
        return;
    }


int index = 1;
while(temp->next != NULL && index < position - 1){
temp  =  temp->next;
index++;
}



// Case 2: insert at end (if position is greater than list size)
// If we reach the last node before reaching the required position,
// it means position is bigger than the list length.
// So we simply add the new node at the end of the list.
if(temp->next == NULL){//agar temp->next NULL hai toh iska matlab hum last node pe pahuch gaye hai aur position list size se badi hai toh hum new node ko end pe insert kar denge
temp->next = newNode;
    return;
}
// Case 3: insert in middle
newNode ->next = temp->next;
temp->next = newNode;



}
// https://youtu.be/tLeSDFqch3I?si=7yoxo-hLgUWA3Qcl (revise deletion from here) 
//delete node from head
void deleteNodeAtHead(Node*& head){
    if(head == NULL){ //if linked list empty return from the function
        return;
    }
    Node* temp = head;
    head = head->next;//head pointer is moved to the next node, now head points to the second node in the list
    delete temp;//the original head node is deleted using the temp pointer, which still holds the address of the original head node
     
}

//deleteNodeAtTail
void deleteNodeAtTail(Node*& head ){

    if(head == NULL){ //if linked list empty return from the function

     return;

    }

    if(head->next == NULL){
        delete head;//if there is only one node in the linked list, it is deleted and head is set to NULL
        head = NULL;
        return;
    }

    // Node* temp = head;
    //  while(temp->next != NULL){
    //         temp = temp->next;
            
    //  }
    // //  delete temp;//delete the last node in the linked list
    // //lkn abhi second last node ka address null nahi hua woh abhi bhi woh last node ko point karraha hai jo delete hogai hai toh yeh logic nahi laga sakta yah 
    // //toh cur , prevs wala logic lagaye yah condition mai temp->next->next != NULL lagaye taki ham second last node pe aa jaye aur uske next ko delete kareden aur phr uska next ko null bhi
      
//   correct code

    Node* temp = head;
     while(temp->next->next != NULL){//temp->next->next != NULL condition is used to stop the loop when temp is at the second last node, because temp->next is the last node and temp->next->next is NULL, so we want to stop at the second last node to delete the last node
            temp = temp->next;//matlab temp moves to the next node until it reaches the second last node where temp->next->next is NULL
            
     }
     delete temp->next;//delete the last node in the linked list
     temp->next = NULL;//after deleting the last node, the next pointer of the second last node is set to NULL to indicate that it is now the last node in the linked list

     
    }
void deleteNodeAtAnyPosition(Node*& head , int pos){
    if(head == NULL || pos <= 0){
        return;
    }
    if(pos == 1){
        deleteNodeAtHead(head);
        return;
    }


    Node* temp = head;
    int index = 1;
    while(temp->next != NULL && index < pos - 1){
        temp = temp->next;
        index++;
    }

   // if temp->next is NULL, it means there is no node available
// at the required position to delete, so we safely return
//ex user give position 100 yah woh jo position jo list mai hai hi nahi
if(temp->next == NULL){
    return;
}

    Node*  nodeTodelete =  temp->next;
    temp->next  = temp->next->next;
    delete nodeTodelete;



     
}
// print list
void printLinkedList(Node* temp) {//yahan refernce nahi lya qka print karte waqt original linked list ko change nahi karna hai, temp pointer is used to traverse the linked list without modifying the head pointer
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;//matlab temp moves to the next node until it reaches the end of the linked list where temp becomes NULL
    }
    cout << endl;
}

int main() {

    Node* head = NULL;

    addNodeAtHead(head, createNode(5));   // 5 //no loop
    printLinkedList(head); // 5
    addNodeAtTail(head, createNode(20));    // 5 → 20//loop is requires wahana jana ka lya jahan ka baad add karna hai node

    addNodeAtTail(head, createNode(30));    // 5 → 20 → 30
    addNodeAtAnyPosition(head, 2, createNode(10)); // 5 → 10 → 20 → 30
    addNodeAtAnyPosition(head, 1, createNode(1)); // 1 → 5 → 10 → 20 → 30
    addNodeAtAnyPosition(head, 10, createNode(40)); // 1 → 5 → 10 → 20 → 30 → 40
    printLinkedList(head); // 1 5 10 20 30 40
    deleteNodeAtHead(head); // 5 → 10 → 20 → 30 → 40
    printLinkedList(head); // 5 10 20 30 40
    deleteNodeAtTail(head); // 5 → 10 → 20 → 30
    printLinkedList(head); // 5 10 20 30
    deleteNodeAtAnyPosition(head, 2); // 5 → 20 → 30 
    printLinkedList(head); // 5 20 30
    addNodeAtAnyPosition(head, 4, createNode(50));
        printLinkedList(head); // 5 20 30 50

           addNodeAtAnyPosition(head, 100, createNode(80));
        printLinkedList(head); 
          addNodeAtAnyPosition(head, 5, createNode(10));
        printLinkedList(head); 
                  addNodeAtAnyPosition(head, 7, createNode(15));
        printLinkedList(head); 

    return 0;
}