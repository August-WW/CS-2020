//****************************************************
// Class: memberNode.cpp (Implementation File)       *
// Implementation file for memberNode class          *
// 											                             *
// Programmer: Bryce Smith                           *
//****************************************************

#include "memberNode.h"

#include <iostream>
using namespace std;

// Constructor
memberNode::memberNode(int id, string name, string policy, int year, int premium) : id(id), name(name), policy(policy), year(year), premium(premium), next(nullptr) {}

// Destructor
memberNode::~memberNode() {}

// Getters
int memberNode::getId() const { return id; }
string memberNode::getName() const { return name; }
string memberNode::getPolicy() const { return policy; }
int memberNode::getYear() const { return year; }
int memberNode::getPremium() const { return premium; }
memberNode* memberNode::getNext() const { return next; }

// Setter
void memberNode::setNext(memberNode* nextNode) { next = nextNode; }
