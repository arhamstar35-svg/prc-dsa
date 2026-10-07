#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node *next;
		node *child;
		
	node(int val){
		data=val;
		next=NULL;
		child=NULL;
	}
};
class linkedlist{
	public:
		node *head;
		node *tail;
		
		linkedlist(){
			head=tail=NULL;
		}
	void pushfront(int val){
		node *newnode=new node(val);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
		newnode->next=head;
		head=newnode;
	}
	}
	void pushback(int val){
		node *newnode=new node(val);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			node* curr=head;
			while(curr->next!=NULL){
				curr=curr->next;
			}
			curr->next=newnode;
			tail=newnode;
		}
	}
	void popfront(){
		if(head==NULL){
			cout<<"Linked list is empty"<<endl;
			return;
		}
		node* temp=head;
		head=head->next;
		delete temp;
	}
	void popback(){
		if(head==NULL){
			cout<<"Linked list is empty"<<endl;
			return;
		}
		node *temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		node *curr=temp->next;
		delete curr;
		tail=temp;
		
	}
	void reverse(){
		node *temp=head;
		node *prev=NULL;
		node *next;
		
		while(temp!=NULL){
			next=temp->next;
			temp->next=prev;
			prev=temp;
			temp=next;
		}
		head=prev;
	}
	void display(){
    node *temp=head;

    while(temp!=NULL){
        cout<<temp->data<<"->";

        temp=temp->next;
    }

    cout<<"NULL";
    cout<<endl;
}
void leftrotaionbyk(int k){
	node *temp=head;
	for(int i=1;i<k;i++){
		temp=temp->next;
	}
	tail->next=head;
	node* newnode=temp->next;
	temp->next=NULL;
	head=newnode;
	tail=temp;
}
void rotationbyk(int k){
	int count=1;
	node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
		count++;
	}
	int result=count-k;
	node* curr=head;
	for(int i=1;i<result;i++){		
		curr=curr->next;
	}
    node* newnode=curr->next;
    curr->next=NULL;
    
    tail->next=head;
    head=newnode;
    tail=curr;
}
	void flatten(){
		node*curr=head;
		while(curr!=NULL){
			if(curr->child!=NULL){
				node* childhead=curr->child;
				node* childtail=childhead;
				
				while(childtail->next!=NULL){
					childtail=childtail->next;
				}
				childtail->next=curr->next;
				curr->next=childhead;
				curr->child=NULL;
			}
			curr=curr->next;
		}
	}
	
	
};
int main(){
	linkedlist l;
	l.pushfront(10);
	l.pushfront(20);
	l.pushfront(30);
	l.pushfront(40);
	l.reverse();
	l.display();
	l.leftrotaionbyk(2);
	l.display();
	l.rotationbyk(2);
	l.display();
	
	
	l.head->next->child=new node(4);
	l.head->next->child->next=new node(5);
	l.head->next->child->next->child=new node(7);
	l.flatten();
	l.display();
	
	return 0;
}
