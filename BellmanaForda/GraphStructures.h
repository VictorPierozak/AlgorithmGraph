#pragma once

#include<list>

//Class for storing information about a path in a graph
class PathF
{

public:
    static const float DEFAULT_COST;
    static const int DEFAULT_PREV;

    float _cost;
    int _prevVertex;

    PathF() : _cost(INFINITY), _prevVertex(-1)
    {
    }
};

//Class representing adjacent vertex
class Adjacency
{
public:
    int _vertex;
    float _cost;

    Adjacency(const int vertex = 0, const float cost = 0) :
        _vertex(vertex), _cost(cost)
    {

    }
};

//Class represeting single edge in a graph
class Edge
{
public:
    int _beg;
    int _end;
    float _cost;

    Edge(const int beg = 0, const int end = 0, const float cost = 0) :
        _beg(beg), _end(end), _cost(cost)
    {
    }

    bool operator<(const Edge& toCompare)
    {
        if (_cost < toCompare._cost)
            return true;
        return false;
    }
};


typedef std::list<Edge> EdgeList;

typedef std::list<Adjacency> AdjacencyList;

//For algorithms use
enum Colors { WHITE = 0, GREY, BLACK };