/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: GraphList.h                                         😎
  😎 Author:   John Herron & Matthew Love                          😎
  😎 Date:     2024-04-16                                          😎
  😎 Purpose:  A program that stores integers in a directed graph  😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#ifndef GraphList_h
#define GraphList_h

#include "Stack.h"
#include <iostream>

using namespace std;

class GraphList
{
    // * Private members *
    private: 
        struct ListNode       // Structure list nodes for the graph
        {
            int value;        // Holds the number the user is entering in and will be helping within the node
            ListNode* next;   // Points to the next node in the graph
        };

        ListNode** headArray; // Array of linked lists that will point to other connected nodes

        int numVertices;      // Keeps track of the number of nodes
        int numEdges;         // Keeps track of the number of connected edges
    
    // * Public members *
    public:
        // * Constructor *
        GraphList(int vertices)
        {
            this->numVertices = vertices; // Update the number of vertices
            headArray = new ListNode* [numVertices]; // Set the headArray to point to the array of list node pointers

            // Since we are working with ListNodes its good programming practice to set them to point to null just as a precaution
            for(int i = 0; i < numVertices; i++)
            {
                headArray[i] = nullptr;
            }
        }

        // * Destructor *
        ~GraphList()
        {
            ListNode* currNode; // Current node will help for traversal through the list to delete items
            ListNode* succNode; // Successor node will help us to not lose access to the list while deleting
        
            for(int i = 0; i < numVertices; i++) // Search through the array
            {
                currNode = headArray[i];   // Set current node to the index of the array to begin traversal through the list
            
                while(currNode != nullptr) // While current node is not null
                {
                    succNode = currNode->next; // Set successor node to current nodes next, we are about to delete the current node
                    delete currNode;           // Delete the current node
                    currNode = succNode;       // Set current node to the successor node
                }
            }

            delete [] headArray; // Delete the array
        }

        // Adds the edge between two vertices
        void addEdge(int vertex1, int vertex2)
        {
            ListNode* newNode = new ListNode; // Create a new list node
            newNode->value = vertex2; // Set its value to the second vertex since the array index will point to this item
            newNode->next = nullptr;
            numEdges++; // TODO: Ask Matthew if he found a use for this variable in his code
        
            ListNode* currNode = headArray[vertex1]; // Set current node to the index of the array which will be the first element within the list
        
            // If the current node is nullptr then our list is empty so insert the newNode at the first spot in the list
            if(currNode == nullptr)
            {
                headArray[vertex1] = newNode;
                return;
            }

            // Find the spot where the next nullptr is to insert the newNode at after the while loop finishes
            while(currNode->next != nullptr)
            {
                currNode = currNode->next;; // Traverse the list
            }

            currNode->next = newNode; // Set the nullptr spot to the newNode
        }

        // Prints the graph to the user as a way to see what it looks like in memory
        void printGraph()
        {
            // Create a for loop to loop through the array and then use use a while loop to loop through the list at the index in the array
            for(int i = 0; i < numVertices; i++)
            {
                cout << i << "--->";

                ListNode* currNode = headArray[i];

                while(currNode != nullptr) // Loop through the connected nodes
                {
                    cout << currNode->value << "--->";
                    currNode = currNode->next;
                }

                cout << "NULL" << endl;
            }
        }

};

#endif