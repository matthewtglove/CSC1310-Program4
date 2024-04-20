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
    getline(cin, fileName);
    ifstream inFile;
    inFile.open(fileName);
    if (!inFile.good()) {
        cout << "Could not open the file " << fileName << ". Ending program." << endl;
        return 1;
    }

    // Reads in the number of verticies from the first line
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
    cout << "Here is the Adjecency Matrix: " << endl;
    graphMatrix->printGraph();
    cout << endl;
    cout << "Here is the Adjecnecy List: " << endl;
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

    cout << "Depth First Search: " << endl;
    while (!visitedStack->isEmpty()) {
        int currentVertex;
        visitedStack->pop(currentVertex);
        cout << "Visited: " << currentVertex << endl;

        for (int i = 0; i < numVertices; i++) {
            if (graphMatrix->isThereAnEdge(currentVertex, i) && !hasBeenVisited[i]) {
                visitedStack->push(i);
                hasBeenVisited[i] = true;
            }
        }
    }

    return 0;
}