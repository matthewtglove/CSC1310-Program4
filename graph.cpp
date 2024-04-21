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
    inFile.open(fileName); // Attempt to open the file

    if (!inFile.good()) { // If the file cant be opened tell the user
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

    // * Depth First Search *
    Stack<int> *adjacentStack = new Stack<int>;
    // hasBeenVisited includes items that have been output and have been put into the adjacentStack
    bool hasBeenVisited[numVertices];
    for (int i = 0; i < numVertices; i++) {
        hasBeenVisited[i] = false;
    }

    cout << "Now traversing & printing graph vertices with DFS:\n"
         << endl;

    // Adds 0 to the stack and marks it as visited
    adjacentStack->push(0);
    hasBeenVisited[0] = true;
    int currentVertex;

    while (!adjacentStack->isEmpty()) {
        // Note: The next item in the adjecentStack would be 0 in the first loop
        adjacentStack->pop(currentVertex);
        // Prints out the visited item
        cout << currentVertex << "\t";

        for (int i = numVertices - 1; i > 0; i--) {
            if (graphMatrix->isThereAnEdge(currentVertex, i) && !hasBeenVisited[i]) {
                adjacentStack->push(i);
                hasBeenVisited[i] = true;
            }
        }
    }
    cout << endl;

    cout << endl
         << "Thank you for coming to my TedTalk." << endl;

    return 0;
}