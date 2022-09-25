// Name - Akshaj Paintola
// SID - 21105030(ECE)

#include <iostream>                   
using namespace std;                  

//Creating a node class 
class Node{
    public:
    // class objects created 
    string name;
    int age;
    Node*next; //Node pointer for next node
    Node*prev; //Node pointer for previous node
    //calling constructor
    Node(string name,int age){
        this->name=name;
        this->age=age;
        next=NULL; 
        prev=NULL; 
    }
};

//Then a function to insert data at the end of linked list is created
void append(Node* &head,string name,int age){
    //Creating a node pointer and storing address of head in temp
    Node*temp=head;
    //creating a new node and storing name and age in it
    Node*new_node=new Node(name,age);
    //Inserting node in empty list
    if(temp==NULL){
        head=new_node;
    }
    //Inserting node in non empty list
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}

//Function to insert data at the start of linked list
void insert_at_head(Node*&head,string name,int age){
    //Creating a Node pointer and storing address of new node in it 
    Node*new_node=new Node(name,age);
    //Inserting new node at head
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

//Function to display data from start
void display_from_start(Node*head){
    Node*temp=head;
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->next;}
    cout<<endl;
}

//Function for displaying data
void display_from_end(Node*head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){cout<<"[Name:"<<temp->name<<" Age:"<<temp->age<<"]"<<"<=>";temp=temp->prev;}
    cout<<endl;
}

//For deletion of index(0,n-1)
void delete_ind(Node*&head,int i){
    if(i==0){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Node*temp=head;
        for(int j=0;j<i;j++){temp=temp->next;}
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

//Function to delete last element
void pop(Node*&head){
    Node*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    //Initialising an empty linked list
    Node*head=NULL;
	int fam_no;
	cout<<"Enter Number Of Family Members:";cin>>fam_no;
    //Inserting family members details in doubly linked list
	for(int i=1;i<=fam_no;i++){
		string name;
		int age;
		cout<<"Enter Family Member "<<i<<" Name:";cin.ignore();getline(cin,name);
		cout<<"Enter Family Member "<<i<<" Age:";cin>>age;
        //appending data name and age in doubly linked list
		append(head,name,age);
	}
    cout<<endl;
    //Displaying Family details
    cout<<"Doubly Linked list with family members as elements is shown below:"<<endl;
    cout<<endl;
    display_from_start(head);
}


//Family member's doubly-linked list can be linked by sorting the doubly linked list according to age in descending order.By doing so we will get a doubly linked list in which older generation people will be close to head in double linked list and new generation people will be close to tail in doubly linked list.

// Name - Akshaj Paintola
// SID - 21105030(ECE)

