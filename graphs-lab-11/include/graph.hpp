#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "lib/doubly-linked-list/list.hpp"

class Graph {
private:

  int** edgeCosts;

  int numEdges;

public:
  /**
   * Initializes the graph
   */
  Graph(int** cost, int n);

  /**
   * performs a dfs over the graph
   */
  DoublyLinkedList** dfs();

  /**
   * performs a bfs over the graph
   */
  DoublyLinkedList** bfs();

  /**
   * Generates a minimum spanning tree using kruskals algorithm
   */
  DoublyLinkedList* kruskal();

  /**
   * Generates a minimum spanning tree using prims algorithm
   */
  DoublyLinkedList* prim();

};

#endif //GRAPH_HPP defined
