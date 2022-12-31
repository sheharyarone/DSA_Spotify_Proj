#pragma once
#include <iostream>
#include <string>
#include "Graph.h"
using namespace std;

Edge::Edge()
{
    artist1 = nullptr;
    artist2 = nullptr;
}
Edge::Edge(Artist *artist1, Artist *artist2)
{
    this->artist1 = artist1;
    this->artist2 = artist2;
}
PointerToEdge::PointerToEdge(Artist *a1, Artist *a2)
{
    edgePointer = new Edge(a1, a2);
    next = nullptr;
}
EdgeLinkedList::EdgeLinkedList()
{
    head = nullptr;
}
