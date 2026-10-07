#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;
    node* tail;

    linkedlist() {
        head = tail = NULL;
    }

    void pushback(int val) {
        node* newnode = new node(val);

        if (head == NULL) {
            head = tail = newnode;
        }
        else {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display() {
        node* temp = head;

        while (temp != NULL) {
            cout << temp->data << "->";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
    void insertionsort(){
    	node* curr=head->next;
    	
    	while(curr!=NULL){
    		node* temp=head;
    		
    		while(temp!=curr){
    		if(temp->data > curr->data){
    			int val=curr->data;
    			curr->data=temp->data;
    			temp->data=val;
			}
			temp=temp->next;
		}
		curr=curr->next;
		}
	}
	void selectionsort(){
		node* curr=head;
		while (curr!=NULL){
			node* smallest = curr;
			node *temp=curr->next;
			while(temp!=NULL){
				if(temp->data < smallest->data){
					smallest=temp;
				}
				temp=temp->next;
			}
			int val = curr->data;
			curr->data=smallest->data;
			smallest->data=val;
			
			curr=curr->next;
		}
	}
	void bubblesort(){
		for(int i=0;i<4;i++){
			
			node *curr=head;
			while(curr->next!=NULL){
				if(curr->data > curr->next->data){
					int val=curr->next->data;
					curr->next->data=curr->data;
					curr->data=val;
					
				}
				curr=curr->next;
			}
		}
	}

    void mergeAlternate(linkedlist& l2) {
        node* curr1 = head;
        node* curr2 = l2.head;

        while (curr1 != NULL && curr2 != NULL) {

            node* next1 = curr1->next;
            node* next2 = curr2->next;

            curr1->next = curr2;
            curr2->next = next1;

            curr1 = next1;
            curr2 = next2;
        }

        tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
        }
    }
};

int main() {

    linkedlist l1;
    linkedlist l2;

    l1.pushback(9);
    l1.pushback(6);
    l1.pushback(3);
    l1.pushback(2);

    l2.pushback(2);
    l2.pushback(4);
    l2.pushback(6);
    l2.pushback(8);

    cout << "List 1: ";
    l1.display();

    cout<<"Sorted list: ";
    l1.insertionsort();
    l1.display();

    cout << "List 2: ";
    l2.display();

    l1.mergeAlternate(l2);

    cout << "After merging: ";
    l1.display();
    
    
    return 0;
}
