/*😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎
  😎 Filename: GraphMatrix.h                                       😎
  😎 Author:   John Herron & Matthew Love                          😎
  😎 Date:     2024-04-16                                          😎
  😎 Purpose:  A program that stores integers in a directed graph  😎
  😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 😎 */

#ifndef GraphMatrix_h
#define GraphMatrix_h

#include "Stack.h"
#include <iostream>

using namespace std;

class GraphMatrix {
private:
    int **vertexMatrix;
    int numVertices;
    int numEdges;

public:
    GraphMatrix(int numVertices) {

        // Set the numVertices to the number read in from the file. 
        this->numVertices = numVertices;

        vertexMatrix = new int *[numVertices]; // set vertexMatrix to point to the array of pointers

        for (int i = 0; i < numVertices; i++) {

            vertexMatrix[i] = new int[numVertices]; // set index i's pointer to point to an array

            // Then initialize everything to 0.
            for (int j = 0; j < numVertices; j++) {

                (vertexMatrix[i])[j] = 0;
            }
        }
    }

    // Delete the array of pointers and the vertex Matrix double pointer
    ~GraphMatrix() {
        for (int i = 0; i < numVertices; i++) {
            delete[] vertexMatrix[i];
        }
        delete[] vertexMatrix;
    }

    // Increases the number of edges if the two vertexes are connected
    void addEdge(int vertex1, int vertex2) {

        if (vertexMatrix[vertex1][vertex2] == 1) {
            cout << "There is already an edge between " << vertex1 << " and " << vertex2 << endl;
            return;
        }
  
        // If the two vertices are connected then put a 1 in the matrix for the index at i and index at j to show a connection
        vertexMatrix[vertex1][vertex2] = 1; 
        numEdges++;
    }

    // Print the graph in a form that represents a matrix implementation
    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << vertexMatrix[i][j] << "  ";
            }
            cout << endl;
        }
    }

    // Return 1 (true) if the two vertices are connected and 0 (false) if not
    bool isThereAnEdge(int vertex1, int vertex2) {

        // If the value at that row and column is 1, then will return true. 0 will return false.
        return (vertexMatrix[vertex1][vertex2]);
    }
};

#endif