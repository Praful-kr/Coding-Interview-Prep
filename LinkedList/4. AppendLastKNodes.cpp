/* Append the last k nodes of the linked list to the starting of the linked list
	eg. I/p:  1->2->3->4->5->6  and k = 3
		o/p:  4->5->6->1->2->3
*/

#include<bits/stdc++.h>
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

void insertAtHead(node* &head, int val) {
	node* n = new node(val);

	n->next = head;
	head = n;
}

void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

void append(node* &head, int k) {
	int pos = 1;
//	node* end;
	node* begin;
	node* temp = head;
	while (pos < k && temp != NULL) {
		temp = temp->next;
		pos++;
	}
	begin = temp;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = head;
	head = begin->next;
	begin->next = NULL;
}

int main() {
	node* head = NULL;
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	display(head);
	append(head, 3);
	display(head);
	return 0;
}