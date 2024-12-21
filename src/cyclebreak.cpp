#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
//In this program, I create several classes of datatype to help me finishing the algorithm

//In class Edge, there are three variant: source, target, weight
class Edge {
  public:
    int source;
    int target;
    int weight;
    Edge(int s = 0, int t = 0, int w = 0) : source(s), target(t), weight(w) {}
    //define operator to compare the weight of 2 different edges
    bool operator<(const Edge& other) const {
      if (weight != other.weight) return weight > other.weight;
      if (source != other.source) return source < other.source;
      return target < other.target;
    }
};

//class DisjointSet is created since Kruskal's algorithm needs it
class DisjointSet {
  private:
    vector<int> parent;
    vector<int> rank;
  public:
    DisjointSet(int size) {
      parent.resize(size);
      rank.resize(size, 0);
      for (int i = 0; i < size; i++) {
        parent[i] = i;
      }
    }
    //define a findset function to check whether they're in same set
    int find(int x) {
      if (parent[x] != x) {
        parent[x] = find(parent[x]);
      }
      return parent[x];
    }
    //define a union function to unite 2 vertices
    void unite(int x, int y) {
      int px = find(x);
      int py = find(y);
        if (px == py) return;
        if (rank[px] < rank[py]) {
          parent[px] = py;
        }else if (rank[px] > rank[py]) {
          parent[py] = px;
        }else {
          parent[py] = px;
          rank[px]++;
        }
    }
};
//In class Graph, it has 2 vectors: the Edge vector E and the Vertex vector V 
class Graph {
  public:
    vector<Edge> E;
    vector<int> V;
    Graph(vector<Edge>& edges, vector<int>& vertices) : E(edges), V(vertices) {}
};
//The main code of Kruskal's algorithm
//The code structure is almost the same as the version in the textbook
set<Edge> Kruskal(Graph& G) {
  set<Edge> remainingEdges;
  DisjointSet ds(G.V.size());
  sort(G.E.begin(), G.E.end());
  for (const Edge& e : G.E) {
    if (ds.find(e.source) != ds.find(e.target)) {
      remainingEdges.insert(e);
      ds.unite(e.source, e.target);
    }
  }
  return remainingEdges;
}