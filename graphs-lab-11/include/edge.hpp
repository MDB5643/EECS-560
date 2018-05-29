#ifndef EDGE_HPP
#define EDGE_HPP
#include <iostream>

class Edge {
  /**
   * vertices
   */
   int v1, v2;
  /**
   * cost of the edge
   */
  int cost;
public:
  /**
   * Constructor
   */


  Edge(int a, int b, int c): v1(a), v2(b), cost(c) {}

  void print() { std::cout << "(" << v1 << ", " << v2 << ") { " << cost << " }"; }

  int getV1()
  {
    return v1;
  }

  int getV2()
  {
    return v2;
  }

  int getCost()
  {
    return cost;
  }
};
#endif //EDGE_HPP defined
