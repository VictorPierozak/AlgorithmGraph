
#include <iostream>
#include<string>
#include<fstream>
#include<queue>
#include<list>

#include"GraphAlgo.h"
#include"GraphStructures.h"


int main()
{
    const std::string fileName("macierz.txt");

    int** matrix = nullptr;
    unsigned int verticesNum = readMatrix(matrix, fileName);
    showMatrix(matrix, verticesNum);

    EdgeList edges;
    makeEdgeList(matrix, verticesNum, edges);
    showEdgeList(edges);

    AdjacencyList* graph = nullptr;
    makeAdjacencyList(matrix, verticesNum, graph);
    showAdjacencyList(graph, verticesNum);

    PathF* result = nullptr;
    BellmanFord(edges, verticesNum, 0, result);
    showResultF(result, verticesNum);

    Dijkstra(graph, verticesNum, 0, result);
    showResultF(result, verticesNum);
    
    Prim(graph, verticesNum, result);
    showResultF(result, verticesNum);

    if (result != nullptr)
        delete result;
    delete2Darray(matrix, verticesNum);

    return 0;
}
