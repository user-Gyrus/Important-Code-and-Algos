 //Cloning of linked list is done in two ways- Brute force and Optimal approaches
 //Brute force approach uses hashmap where the actual node and cloned node are stored and traversed accordingly
 //time complexity for such case is TC: O(N) + O(N) + O(NlogN)
 //space complexity SC: O(N) + O(N)

//In the optimal approach we are diving the entire process into three parts - 
//1) Creating and inserting the new node in between the given linked lists
//2) Assigning the random pointers
//3) Assigning the next pointers

#include <iostream>
using namespace std;

class Node {
public:
    int data;           
    Node *next;        
    Node *random;       

    Node() : data(0), next(nullptr), random(nullptr){}; 
    Node(int x) : data(x), next(nullptr), random(nullptr) {} 

    Node(int x, Node *nextNode, Node *randomNode) :
            data(x), next(nextNode), random(randomNode) {}  
};

void insertCopyInBetween(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);  
        copy->next = nextElement;  
        temp->next = copy;         
        temp = nextElement;         
    }
}

void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;    
        if(temp->random){   
            copyNode->random = temp->random->next; 
        }
        else{
            copyNode->random = NULL;   
        }
        temp = temp->next->next;   
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);   
    Node* res = dummyNode;             

    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;   
}


Node *cloneLL(Node *head){
    if(!head) return nullptr;   

    insertCopyInBetween(head); 
    connectRandomPointers(head);  
    return getDeepCopyList(head); 
}


void printClonedLinkedList(Node *head) {
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;  
    }
}


int main() {
    Node* head = new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);


    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printClonedLinkedList(head);

    Node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printClonedLinkedList(clonedList);

    return 0;
}

//Time Complexity - O(N) + O(N) + O(N)
//Space Complexity - O(N) + O(N)                          
                            