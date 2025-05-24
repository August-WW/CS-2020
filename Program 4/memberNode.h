//********************************************************
// Class: memberNode.h (Class Declaration File)          *
// This class maintains a node object that can be        *
// used to create a linked list.                         *
//											                                 *
// Programmer: Bryce Smith                               *
//********************************************************

#ifndef MEMBERNODE_H
#define MEMBERNODE_H

#include <string>
using namespace std;

class memberNode {
public:
	memberNode(int, const string, const string, int, int); // Constructor
	
	~memberNode(); // Destructor

	// Getters
	int getId() const;
	string getName() const;
	string getPolicy() const;
	int getYear() const;
	int getPremium() const;
	memberNode* getNext() const;

	// Setters
	void setNext(memberNode*);

private:
	int id;
	string name;
	string policy;
	int year;
	int premium;
	memberNode* next;
};
#endif
