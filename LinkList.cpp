/*			LINKED LIST:
	-->Array: Single block of memory with partitions
	-->Linked List: Multiple blocks of memory linked to each other

	--> Limitations of arrays:
		-> fixed size
		-> contiguous block of memory
		-> insertion and deletion is costly

	--> Properties of Linked list:
		-> size can be modified
		-> non-contiguous memory
		-> insertion and deletion at any point is easier

	--> structure of linked list: data + next
	--> head pointer stores the address of the first node so that it can be used to traverse the linked list further
	--> next of the last node is NULL
*/


#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) {
		data = val;
		next = NULL;
	}
};

void insertAtTail(Node* &head, int val) {			//head taken by address because we are modifying the link list here

	Node* n = new Node(val);

	if (head == NULL) {
		head = n;
		return;
	}

	Node* temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = n;
}

void insertAtHead(Node* &head, int val) {
	Node* n = new Node(val);

	n->next = head;
	head = n;

}

void display(Node* head) {							//here head is taken by value because there is no need to modify the link list
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

bool search(Node* head, int key) {
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == key)
			return true;
		temp = temp->next;
	}
	return false;
}



void del(Node* &head, int val) {
	if (head == NULL)					//if linked list is empty
		return;
	if (head->next == NULL) {			//if only one node present int the linked list
		if (head->data == val) {
			Node* todelete = head;
			head = head->next;
			delete todelete;
		}
		return;
	}

	if (head->data == val) {			//to delete head
		Node* todelete = head;
		head = head->next;
		delete todelete;
		return;
	}

	Node* temp = head;
	while ((temp->next->data != val) && (temp != NULL)) {
		temp = temp->next;
	}
	if (temp != NULL) {
		Node* todelete = temp->next;
		temp->next = temp->next->next;
		delete todelete;
	}
}

Node* reverseIterative(Node* head) {
	if (head == NULL || head->next == NULL)
		return head;
	Node* pptr = NULL;
	Node* cptr = head;
	Node* nptr;// = head->next;

	while (cptr != NULL) {
		nptr = cptr->next;
		cptr->next = pptr;
		pptr = cptr;
		cptr = nptr;
	}
	head = pptr;
	return head;
}

Node* reverseRecursive(Node* &head) {
	//we need change only for one node and call for other nodes recursively.  4->1<-2<-3    change to   4<-1<-2<-3

	if (head == NULL || head->next == NULL) {
		return head;
	}
	Node* newhead = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;

	return newhead;
}

Node* reversek(Node* &head, int k) {
	//reverse in groups of k, eg. 1->2->3->4  with k = 2   gives     2->1->4->3
	Node* pptr = NULL;
	Node* cptr = head;
	Node* nptr;
	int count = 0;
	while (cptr != NULL && count < k) {
		nptr = cptr->next;
		cptr->next = pptr;
		pptr = cptr;
		cptr = nptr;
		count++;
	}

	if (nptr != NULL) {
		head->next = reversek(nptr, k);
	}
	return pptr;
}

int main() {
	Node* head = NULL;
	insertAtTail(head, 1);
	insertAtTail(head, 2);
	insertAtTail(head, 3);
	insertAtHead(head, 4);
	display(head);

	if (search(head, 4))
		cout << "found\n";
	else
		cout << "Not found\n";

	if (search(head, 3))
		cout << "found\n";
	else
		cout << "Not found\n";
//	search(head, NULL);

	if (search(head, 7))
		cout << "found\n";
	else
		cout << "Not found\n";

//	del(head, 1);
//	Node* newhead =	reverseRecursive(head);
	Node* rev = reversek(head, 3);
	display(rev);
//	display(head);
	return 0;
}















