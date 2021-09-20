/*	DOUBLY LINKED LIST
	Structure of Node: Previous + Data + Next
	- next and previous of a node can be accessed
	- prev(first node) and next(last node) point to NULL
	-
*/


#include<bits/stdc++.h>
using namespace std;

class node {
public:
	node* prev;
	int data;
	node* next;

	node(int val) {
		prev = NULL;
		data = val;
		next = NULL;
	}
};

void insertAtHead(node* &head, int val) {
	node * n = new node(val);

	n->next = head;
	if (head != NULL) {
		head->prev = n;
	}
	head = n;
}

void insertAtTail(node* &head, int val) {
	if (head == NULL) {
		insertAtHead(head, val);
		return;
	}

	node* temp = head;
	node* n = new node(val);

	while (temp->next != NULL) {
		temp = temp->next;
	}

	n->prev = temp;
	temp->next = n;

}

void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void deleteHead(node* &head) {
	node* temp = head;
	head = head->next;
	head->prev = NULL;
	delete temp;
}
void deleteNode(node* &head, int pos) {
	if (head == NULL)
		return;

	if (pos == 1) {
		deleteHead(head);
		return;
	}

	node* temp = head;
	int count = 1;

	while (count < pos && temp != NULL) {
		temp = temp->next;
		count++;
	}

	temp->prev->next = temp->next;
	if (temp->next != NULL) {
		temp->next->prev = temp->next;
	}

	delete temp;

}

int main() {

	node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtTail(head, 4);
	insertAtTail(head, 5);
	display(head);
	insertAtHead(head, 11);
	insertAtHead(head, 9);
	display(head);

	deleteNode(head, 4);
	display(head);
	deleteNode(head, 1);
	display(head);
	return 0;
}








