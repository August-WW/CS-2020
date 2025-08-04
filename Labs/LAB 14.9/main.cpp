#include "MileageTrackerNode.h"
#include <string>
#include <iostream>

using namespace std;

int main () {
   // References for MileageTrackerNode objects
   MileageTrackerNode* headNode;
   MileageTrackerNode* currNode;
   MileageTrackerNode* lastNode;

   double miles;
   string date;
   int i;

   // Front of nodes list
   headNode = new MileageTrackerNode();
   // End of nodes list
   lastNode = headNode;

   // TODO: Read in the number of nodes
   int nodes;
   cin >> nodes;


   // TODO: For the input number of nodes, read the number of miles and date
   //       from user input. Insert each node into the end of the linked list (after the last node)
   for (i = 0; i < nodes; ++i) {
    cin >> miles;
    cin >> date;

    MileageTrackerNode* newNode = new MileageTrackerNode(miles, date);

    lastNode->InsertAfter(newNode);

    lastNode = newNode;
   }

   // TODO: Print the entire linked list with PrintNodeData() function calls   
   currNode = headNode->GetNext();  
   while (currNode != nullptr) {
    currNode->PrintNodeData();
    currNode = currNode->GetNext();
   }
   

   // MileageTrackerNode Destructor deletes all following nodes
   delete headNode;
   
   return 0;
}
