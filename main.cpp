/**************************************

  COMSC 210 | Lab 17 | Skylar Robinson | IDE Used: Eclipse

**************************************/

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *); //Display the contents of a linked list
void addToHead(Node *&, float); //Add a node to the head of a list
void addToTail(Node *&, float); //Add a node to the end of a list
void insertNode(Node *, float, int); //Insert a node at a specified point
void deleteNode(Node *, int); //Delete a node at a specified point
void deleteList(Node *&); //Delete an entire list

int main() {
    Node *head = nullptr;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;

        // adds node at head
        addToHead(head, tmp_val);
    }
    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);

    output(head);

    // insert a node
    cout << "After which node to insert 10000? " << endl;
    output(head);
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, 10000, entry);

    output(head);

    // deleting the linked list
    deleteList(head);

    output(head);

    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addToHead(Node *&hd, float v) {
	Node *newVal = new Node;
	newVal->value = v;
		if (!hd) { // if this is the first node, it's the new head
		    newVal->next = nullptr;
		}
		else { // its a second or subsequent node; place at the head
		    newVal->next = hd;
		}
	hd = newVal;
}

void addToTail(Node *&hd, float v) {
	Node *newVal = new Node;
	newVal->next = nullptr;
	newVal->value = v;
		if (!hd) { // if this is the first node, it's the new head
			hd = newVal;
		}
		else { // its a second or subsequent node; place at the end
			//traverse to the end of the list
			Node * current = hd;
			while(current->next)
				current = current->next;
			//point last node to new node
			current->next = newVal;
		}
}

void insertNode(Node *hd, float v, int p) {
	Node *newVal = new Node;
	Node * current = hd;
	Node *prev = hd;
	newVal->value = v;

	//find the value at position p
	current = hd;
	for (int i = 0; i < (p-1); i++)
	    if (i == 0)
	    	current = current->next;
	    else {
	    	current = current->next;
	        prev = prev->next;
	     }
	//insert the node
	newVal->next = current;
	prev->next = newVal;
}

void deleteNode(Node * hd, int p) {
	Node * current = hd;
	Node *prev = hd;

	//find the value at position p
	current = hd;
	for (int i = 0; i < (p-1); i++)
	    if (i == 0)
	    	current = current->next;
	    else {
	    	current = current->next;
	        prev = prev->next;
	    }
	if (current) {  // checks for current to be valid before deleting the node
	        prev->next = current->next;
	        delete current;
	        current = nullptr;
	}
}

void deleteList(Node *&hd) {
	Node * current = hd;
	    while (current) {
	        hd = current->next;
	        delete current;
	        current = hd;
	    }
	    hd = nullptr;
}
