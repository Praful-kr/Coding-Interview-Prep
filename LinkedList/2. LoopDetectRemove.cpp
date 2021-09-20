/*
	DETECT AND REMOVE LOOP IN LINK LIST


	proof of floyd's algorithm:
		-m: distance between starting of list and starting of loop
		-n: distance between start of loop and intersection point
		-l: size of loop

		Now, dist moved by fast ptr = m + n + l*j   (it moves some j loops)
			 dist moved by slow ptr = m + n + l*i   (it moves some i loops)
		also, dist moved by fast ptr = 2*(dist moved by slow ptr)
		i.e.   m + n + l*j = 2*(m + n + l*i)
			=> m+n = l(j-2i)
			=> m = l(j-2i) - n
		Now, (j-2i) is some integer value say 'k'
			=> m = l*k - n
		also, we can observe that convering a distance of l*k will lead us to starting point of the loop for any value of k

		Hence, distance(starting point of list to starting point of loop) = distance(intersection point in loop to starting point of loop)
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

bool detectLoop(node* &head) {
	node* slow = head;
	node* fast = head;


	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return true;
	}
	return false;
}

void removeLoop(node* &head) {
	node* slow = head;
	node* fast = head;

	do {
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	fast = head;
	while (slow->next != fast->next) {
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
}

void makeCycle(node* &head, int pos) {
	node* temp = head;
	node* startnode;
	int count = 1;
	while (temp->next != NULL) {
		if (count == pos)
			startnode = temp;
		count++;
		temp = temp->next;
	}
	temp->next = startnode;
}

void display(node* head) {
	node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

int main() {
	node* head = NULL;

	insertAtHead(head, 9);
	insertAtHead(head, 8);
	insertAtHead(head, 7);
	insertAtHead(head, 6);
	insertAtHead(head, 5);
	insertAtHead(head, 4);
	insertAtHead(head, 3);
	insertAtHead(head, 2);
	insertAtHead(head, 1);
	display(head);
	cout << endl;
	makeCycle(head, 1);
//	display(head);
	cout << detectLoop(head) << endl;
	removeLoop(head);
	cout << detectLoop(head) << endl;
	display(head);
	return 0;
}
