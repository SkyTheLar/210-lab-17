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
void addToTail(Node *, float); //Add a node to the end of a list
void insertNode(Node *, int); //Insert a node at a specified point
void deleteNode(Node *, int); //Delete a node at a specified point
void deleteList(Node *); //Delete an entire list

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;

        // adds node at head
        addToHead(head, tmp_val);
    }
    output(head);

    // deleting a node
    Node * current = head;
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    // traverse that many times and delete that node
    current = head;
    Node *prev = head;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
    output(head);

    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    current = head;
    prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;
    output(head);

    // deleting the linked list
    current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
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

void addToTail(Node * hd, float v) {
	Node *newVal = new Node;
		if (!hd) { // if this is the first node, it's the new head
			hd = newVal;
		    newVal->next = nullptr;
		    newVal->value = v;
		}
		else { // its a second or subsequent node; place at the end
			newVal->next = nullptr;
			newVal->value = v;
		}
}
