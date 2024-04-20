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

        vertexMatrix = new int *[numVertices]; // Johns comment, This line looks right to me
        for (int i = 0; i < numVertices; i++) {
            // TODO: I'm not supposed to use a pointer here. Why?
            // FIXME: To answer the previous question i believe its because what is within the elements of the array
            /*
                * [numVertices] is the number of elements created its not what is within the list itself.
                * Also vertexMatrix is a pointer to the first element within the array which is a pointer itself
                * We use vertexMatrix to access this pointer, its not even named which is fine because through a pointer we have access, it doesnt need a name
                * Each element within the array is an integer that can point to another integer within that element it is a list.
                * Where this gets confusing and new to me is how its implemented with a 2D array.

                Here is how i believe it looks in memory, correct me if im wrong because this 2d thing is a little confusing

                                                  VertexMatrix
                                                        ↓
                                                      Index 1
                                                        i
                                                        ⊡ -> ⊡ ...
                                                        j
                                                        ⊡ -> ⊡ ...

                                                      Index 2
                                                        i... and so on
            */
            vertexMatrix[i] = new int[numVertices];
            // FIXME: wouldn't we also need a vertexMatrix [j] = new int[numVertices]

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
            // FIXME: Like i said previously I think we need to dynamically allocate for j as well so we would need to delete that here
        }
        delete[] vertexMatrix;
    }

    void addEdge(int vertex1, int vertex2) {
        // TODO: Might want to remove this check
        if (vertexMatrix[vertex1][vertex2] == 1) {
            cout << "There is already an edge between " << vertex1 << " and " << vertex2 << endl;
            return;
        }

        vertexMatrix[vertex1][vertex2] = 1;
        numEdges++;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << vertexMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    bool isThereAnEdge(int vertex1, int vertex2) {
        // If the value at that row and column is 1, then will return true. 0 will return false.
        return (vertexMatrix[vertex1][vertex2]);
    }
};

#endif