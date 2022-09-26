/* Q1) */
// Name - Akshaj Paintola
// SID - 21105030(ECE)

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void append(Node*&head,int data){
    Node*temp=head;
    Node*new_node=new Node(data);
    if(temp==NULL){head=new_node;new_node->next=head;return;}
    while(temp->next!=head){temp=temp->next;}   //CONDITION
/* This establishes that the traversing element/variable has reached the first element.
In circular linked list last node of linked list points to head of that linked list, by checking if any node points to head of linked list we can find out the end of circular linked list. 
*/
    temp->next=new_node;
    new_node->next=head;
}

void print_f(Node*&head){
    Node*temp=head;
    do{cout<<temp->data<<"->";temp=temp->next;}
    while(temp!=head);
}

int main(){
    Node*head=NULL;
    append(head,0);
    append(head,1);
    append(head,2);
    print_f(head);
}




/*Q2)  
PRACTICAL APPLICATIONS OF CIRCULAR LINKED LIST:
-It is used by the Operating system to share time for different users, generally uses a Round-Robin time-sharing mechanism.
-Multiplayer games use a circular list to swap between players in a loop.
-Implementation of Advanced data structures like Fibonacci Heap
-The browser cache which allows you to hit the BACK button
-Undo functionality in Photoshop or Word
-Circular linked list used Most recent list (MRU LIST)
*/

// Name - Akshaj Paintola
// SID - 21105030(ECE)