/*
put even position nodes on even places and odd position nodes on odd places
	eg. 1->2->3->4->5->6     gives    1->3->5->2->4->6
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
	node* temp = head;

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

void oddeven(node* &head) {
	node* odd = head;
	node* even = head->next;
	node* odd_head = odd;
	node* even_head = even;
	while (odd->next != NULL && even->next != NULL) {
		odd->next = even->next;
		odd = odd->next;
		if (odd->next != NULL) {
			even->next = odd->next;
			even = even->next;
		}
	}

	if (odd->next == NULL) {
		odd->next = even_head;
		even->next = NULL;
	}

	else if (even->next == NULL) {
		odd->next = even_head;
	}

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
	oddeven(head);
	display(head);
	return 0;
}