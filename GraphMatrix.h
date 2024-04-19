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
        this->numVertices = numVertices;
        // TODO: Question for John, is this 2d array implemented correctly? I got this help from stackoverflow and ChatGPT on how to initialize a 2d array
        vertexMatrix = new int *[numVertices];
        for (int i = 0; i < numVertices; i++) {
            // TODO: I'm not supposed to use a pointer here. Why?
            vertexMatrix[i] = new int[numVertices];

            // Then initialize everything to 0.
            for (int j = 0; j < numVertices; j++) {
                vertexMatrix[i][j] = 0;
            }
        }
    }
    ~GraphMatrix() {
        // TODO: Is this correct?
        for (int i = 0; i < numVertices; i++) {
            delete[] vertexMatrix[i];
        }
        delete[] vertexMatrix;
    }

    void addEdge(int vertex1, int vertex2) {
    }

    void printGraph() {
    }

    bool isThereAnEdge(int vertex1, int vertex2) {
        // If the value at that row and column is 1, then will return true. 0 will return false.
        return (vertexMatrix[vertex1][vertex2]);
    }
};

#endif