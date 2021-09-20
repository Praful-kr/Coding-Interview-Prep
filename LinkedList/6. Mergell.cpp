/*Merge given 2 sorted linked lists
	Given: 1->3->5->7    and    2->4->6
	o/p:   1->2->3->4->5->6->7
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


void insertAtTail(node* &head, int val) {			//head taken by address because we are modifying the link list here

	node* n = new node(val);

	if (head == NULL) {
		head = n;
		return;
	}

	node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = n;
}

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

node* merge(node* head1, node* head2) {
	node* p1 = head1;
	node* p2 = head2;
	node* dummy = new node(-1);
	node* p3 = dummy;

	while (p1 != NULL && p2 != NULL) {
		if (p1->data < p2->data) {
			p3->next = p1;
			p1 = p1->next;
		}
		else {
			p3->next = p2;
			p2 = p2->next;
		}
		p3 = p3->next;
	}
	while (p1 != NULL) {
		p3->next = p1;
		p1 = p1->next;
		p3 = p3->next;
	}
	while (p2 != NULL) {
		p3->next = p2;
		p2 = p2->next;
		p3 = p3->next;
	}

	return dummy->next;
}


node* mergeRecursive(node* head1, node* head2) {
	node* result;
	if (head1 == NULL) {
		return head2;
	}

	if (head2 == NULL) {
		return head1;
	}

	// else if (head1 == NULL && head2 == NULL) {
	// 	return NULL;
	// }

	if (head1->data < head2->data) {
		result = head1;
		result->next = mergeRecursive(head1->next, head2);
	}
	else {
		result = head2;
		result->next = mergeRecursive(head1, head2->next);
	}
	return result;
}

int main() {
	node* head1 = NULL;
	node* head2 = NULL;
	int arr1[] = {1, 3, 5, 7};
	int arr2[] = {2, 4, 6};
	for (int i = 0; i < 4; i++)
		insertAtTail(head1, arr1[i]);
	for (int i = 0; i < 3; i++)
		insertAtTail(head2, arr2[i]);
	display(head1);
	display(head2);
//	node* head = merge(head1, head2);
	node* headRec = mergeRecursive(head1, head2);
	/	/ display(head);
	display(headRec);

	return 0;
}






















