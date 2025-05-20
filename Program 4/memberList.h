//********************************************************
// Class: memberList.h (Class Declaration File)          *
// This class maintains a linked list of integer         *
// nodes.   				                             *
//											             *
// Programmer: Bryce Smith                               *
//********************************************************

#ifndef MEMBERLIST_H
#define MEMBERLIST_H

#include "memberNode.h"

using namespace std;

class memberList {
private:
    memberNode* head;
    memberNode* tail;

public:
    // Constructor
    memberList();

    // Destructor
    ~memberList();

    // Copy Constructor
    memberList(const memberList&);

    // Copy Assignment Operator
    memberList& operator=(const memberList&);

    // Push a member to the end of the list
    void PushBack(memberNode*);

    // Add a member to the front
    void AddOneMember(memberNode*);

    // Remove a member by ID
    void RemoveOneMember(int);

    // Print all members
    void PrintMemberList() const;

    // Print members with a specific policy
    void PrintPolicy(const std::string&) const;

    // Print members with a minimum number of years
    void PrintYear(int) const;

    // Print the member with the lowest premium
    void PrintLowPremium() const;
};

#endif
