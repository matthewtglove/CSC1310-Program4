/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: graph.cpp                                           😎
  😎 Author:   John Herron & Matthew Love                          😎
  😎 Date:     2024-04-16                                          😎
  😎 Purpose:  A program that stores integers in a directed graph  😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#include "GraphList.h"
#include "GraphMatrix.h"
#include "Stack.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the graph program!\n"
         << endl;

    cout << "What is the name of the file you would like to import?" << endl;
    cout << "FILE: ";

    string fileName;
    
    getline(cin, fileName); // Read in user input for a file

    ifstream inFile;
    inFile.open(fileName);  // Attempt to open the file

    if (!inFile.good()) {   // If the file cant be opened tell the user
        cout << "Could not open the file " << fileName << ". Ending program." << endl;
        return 1;
    }

    // Reads in the number of vertices from the first line
    int numVertices = 0;
    inFile >> numVertices;

    GraphMatrix *graphMatrix = new GraphMatrix(numVertices);
    GraphList *graphList = new GraphList(numVertices);

    int fromNode;
    int toNode;
    // Stops reading the file at blank line or end of file

    while (inFile >> fromNode >> toNode) {
        graphMatrix->addEdge(fromNode, toNode);
        graphList->addEdge(fromNode, toNode);
    }

    inFile.close();

    cout << endl;
    cout << "Here is the Adjacency Matrix: " << endl;
    // Print the Adjacency Matrix
    graphMatrix->printGraph();
    cout << endl;

    // Print the Adjacency List
    cout << "Here is the Adjacency List: " << endl;
    graphList->printGraph();
    cout << endl;

    // FIXME: HELP!
    Stack<int> *visitedStack = new Stack<int>;
    
    bool hasBeenVisited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        hasBeenVisited[i] = false;
    }

    visitedStack->push(0);
    hasBeenVisited[0] = true;

    cout << "Now traversing & printing graph vertices with DFS.\n" << endl;
    while (!visitedStack->isEmpty()) {
        int currentVertex;
        visitedStack->pop(currentVertex);
        cout << currentVertex << "\t";

        for (int i = 0; i < numVertices; i++) {
            if (graphMatrix->isThereAnEdge(currentVertex, i) && !hasBeenVisited[i]) {
                visitedStack->push(i);
                hasBeenVisited[i] = true;

                
                // FIXME: John attempted to add the code and thought he was on to something but was bested by the machine and came up empty.
                //        this day man lost to the machine. All hail the AI overlords; the age of human dominion is over.
                // visitedStack->pop(i);
                // cout << i << "\t";

                cout << "\nhere is currentVertex " << currentVertex << " Here is i " << i << endl;
                currentVertex = i; // TODO: To Matthew: I thought this line had some promise but idk, i have an idea of how we are supposed to do it 
                                   //                   but i have no idea how to implement it. Lets try and figure it out and if we can't get it working
                                   //                   then we may have to reach out to Master Vandergriff because i spent more time on this than I should have and 
                                   //                   Didn't really feel like i got anywhere with it. 
            }
        }
    }


    return 0;
}