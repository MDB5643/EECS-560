#include "graph.hpp"
#include "util/util.hpp"

Graph::Graph(int** costs, int n){
  edgeCosts = costs;
  numEdges = n;
  int visitArr[n];
}

DoublyLinkedList** Graph::dfs() {

  DoublyLinkedList** edge_set = new DoublyLinkedList*[2];
  visitArr[0] = 0;

  for (int i = 0; i < 2; i++)
  {
    edge_set[i] = new DoublyLinkedList();
  }



  return edge_set;
}

int findMinVal()
{
  
}

DoublyLinkedList** Graph::bfs() {
  DoublyLinkedList** edge_set = new DoublyLinkedList*[2];
  IMPLEMENT_ME();
  return edge_set;
}

DoublyLinkedList* Graph::kruskal() {
  IMPLEMENT_ME();
  return new DoublyLinkedList();
}

DoublyLinkedList* Graph::prim(){
  IMPLEMENT_ME();
  return new DoublyLinkedList();
}
