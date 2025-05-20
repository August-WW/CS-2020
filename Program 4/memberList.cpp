//****************************************************
// Class: memberList.cpp (Implementation File)       *
// This class maintains a list of objects.           *
//											         *
// Programmer: Bryce Smith                           *
//****************************************************
#include "memberNode.h"
#include "memberList.h"

#include <iostream>
#include <iomanip>
using namespace std;

//****************************************************
// Function: memberList  (Constructor)               *
// This function initializes the nodes               *
// of the list.										 *
//****************************************************
memberList::memberList() : head(nullptr), tail(nullptr) {}

//****************************************************
// Function: ~memberList  (Destructor)               *
// This function destroys the entire list somewhat   *
// recusively?										 *
//****************************************************
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}
//****************************************************
// Function: operator=                               *
// This is an overloaded assignment function. It is  *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList& memberList::operator=(const memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currNode != nullptr) {

			PushBack(new memberNode(currNode->getId(), currNode->getName(), currNode->getPolicy(),
									currNode->getYear(), currNode->getPremium()));
			currNode = currNode->getNext();					//Traversal Statement
		}													//Important to point to the next node
	}
	return *this;
}
//****************************************************
// Function: memberList(memberList& rhs)             *
// This is an copy constructor function. It is       *
// needed when the object had dynamic memory		 *
// allocated										 *
//****************************************************
memberList::memberList(const memberList& rhs){
	memberNode* currNode = rhs.head;                // Copy List

	while (currNode != nullptr) {
		PushBack(new memberNode(currNode->getId(), currNode->getName(), currNode->getPolicy(),
			currNode->getYear(), currNode->getPremium()));
		currNode = currNode->getNext();					//Traversal Statement
	}													//Important to point to the next node
}

//****************************************************
// Function: PushBack                                *
// Takes the node passed in and adds it to the end   *
// of the linked list. Accounts for an empty list.	 *
//****************************************************
void memberList::PushBack(memberNode* currNode) {
	if (!head) {
		head = tail = currNode;
	}
	else {
		tail->setNext(currNode);
		tail = currNode;
	}
}

//****************************************************
// Function: AddOneMember                            *
// Adds a new member to							     *
// the front of the list							 *
//****************************************************
void memberList::AddOneMember(memberNode* currNode) {
	currNode->setNext(head);
	head = currNode;
	if (!tail) tail = currNode;

	cout << currNode->getId() << " member added." << endl;
}

//****************************************************
// Function: RemoveOneMember                         *
// Removes the member from the list if found and     *
// displays a message if that member was removed.	 *
// A message will display if the member is not found *
//****************************************************
void memberList::RemoveOneMember(int id) {
	memberNode* current = head;
	memberNode* prev = nullptr;

	while (current && current->getId() != id) {
		prev = current;
		current = current->getNext();
	}
	if (!current) {
		cout << id << " is not a member.\n";
		return;
	}
	if (prev) {
		prev->setNext(current->getNext());
	}
	else {
		head = current->getNext();
	}
	if (current == tail) {
		tail = prev;
	}
	delete current;
	cout << id << " member removed.\n";
}

//****************************************************
// Function: PrintMemberList                         *
// Displays all of the data about each member        *
// in tabular form.                              	 *
//****************************************************
void memberList::PrintMemberList() const {
	memberNode* current = head;
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;

	cout << left << setw(5) << "Id"
		<< setw(25) << "Name"
		<< setw(15) << "policy"
		<< setw(15) << "premium"
		<< setw(16) << "years" << endl;

	cout << left << setw(5) << "--" 
		<< setw(25) << "----" 
		<< setw(15) << "------" 
		<< setw(15) << "-------" 
		<< setw(16) << "-----" << endl;

	while (current) {
		cout << left << setw(5) << current->getId() 
			 << setw(25) << current->getName() 
			 << setw(15) << current->getPolicy()
			 << setw(15) << current->getPremium() 
			 << setw(10) << current->getYear() << endl;
		current = current->getNext();
	}
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
}

//****************************************************
// Function: PrintPolicy                             *
// Displays a list of members with                   *
// the given policy.                              	 *
//****************************************************
void memberList::PrintPolicy(const string& policy) const {
	memberNode* current = head;
	bool found = false;
	double totalPremium = 0; // Calculate average premium
	int count = 0;

	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
	cout << setw(13) << " " << "All " << policy << " members" << endl;
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;

	cout << left << setw(5) << "Id"
		<< setw(25) << "Name"
		<< setw(15) << "policy"
		<< setw(15) << "premium"
		<< setw(16) << "years" << endl;

	cout << left << setw(5) << "--"
		<< setw(25) << "----"
		<< setw(15) << "------"
		<< setw(15) << "-------"
		<< setw(16) << "-----" << endl;

	while (current) {
		if (current->getPolicy() == policy) {
			cout << left << setw(5) << current->getId()
				<< setw(25) << current->getName()
				<< setw(15) << current->getPolicy()
				<< setw(15) << current->getPremium()
				<< setw(10) << current->getYear() << endl;

			totalPremium += current->getPremium();
			count++;
			found = true;
		}
		current = current->getNext();
	}
	if (found) {
		cout << setw(79) << setfill('-') << "-" << setfill(' ') << endl;
		cout << "The average " << policy << " premium is: $" << fixed << setprecision(2) << (totalPremium / count) << endl; // Calculates average and outputs as $XX.XX
	}
	else {
		cout << "Sorry, no " << policy << " members\n";
	}
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
}

//****************************************************
// Function: PrintYear                               *
// Displays a list of members with who have been     *
// with the company for equal to or more         	 *
// than the given year.                              *
//****************************************************
void memberList::PrintYear(int year) const {
	memberNode* current = head;
	bool found = false;

	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
	cout << setw(13) << " " << "Members of at least: " << year << "    years" << endl;
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;

	cout << left << setw(5) << "Id"
		<< setw(25) << "Name"
		<< setw(15) << "policy"
		<< setw(15) << "premium"
		<< setw(16) << "years" << endl;

	cout << left << setw(5) << "--"
		<< setw(25) << "----"
		<< setw(15) << "------"
		<< setw(15) << "-------"
		<< setw(16) << "-----" << endl;

	while (current) {
		if (current->getYear() >= year) {
			cout << left << setw(5) << current->getId()
				<< setw(25) << current->getName()
				<< setw(15) << current->getPolicy()
				<< setw(15) << current->getPremium()
				<< setw(10) << current->getYear() << endl;
			found = true;
		}
		current = current->getNext();
	}

	if (!found) {
		cout << "Sorry, no members with " << year << " or more years\n";
		cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
	}
}

//****************************************************
// Function: PrintLowPremium                         *
// Prints the member(s) with the                     *
// lowest premium.                                	 *
//****************************************************
void memberList::PrintLowPremium() const {
	if (!head) return;
	memberNode* current = head;
	memberNode* lowest = head;

	while (current) {
		if (current->getPremium() < lowest->getPremium()) {
			lowest = current;
		}
		current = current->getNext();
	}
	cout << setw(79) << setfill('-') << "-" << setfill(' ') << endl;
	cout << lowest->getName() << " has the lowest premium of " << lowest->getPremium() << " dollar(s).\n";
	cout << setw(79) << setfill('=') << "=" << setfill(' ') << endl;
}
