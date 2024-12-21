#include <iostream>
#include <fstream>
#include <vector>
#include "cyclebreak.cpp"
using namespace std;

int main(int argc, char* argv[]) {
  //read the input file content
  //AI generated begin
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
    return 1;
  }
  ifstream inFile(argv[1]);
  ofstream outFile(argv[2]);
  if (!inFile || !outFile) {
    cerr << "Error opening files!" << endl;
    return 1;
  }
  //AI generated end
  
  char graphType;
  int n, m;
  inFile >> graphType;
  inFile >> n >> m;
  vector<Edge> edges;
  vector<int> vertices(n);
  //construct the graph
  for (int i = 0; i < n; i++) {
    vertices[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int source, target, weight;
    inFile >> source >> target >> weight;
    edges.push_back(Edge(source, target, weight));
  }
  Graph G(edges, vertices);
  //according to directed or undirected graphType, we use different algorithm to solve the problem
  if (graphType == 'u') {
    //for undirected graph, I choose Maximum Spanning Tree to finds the remained edge after cyclebreaking
    //To find a Maximum ST, i choose Kruskal's algorithm with sorting in decreasing order
    //the correctness is still the same as the Minimum ST version.
    set<Edge> remainingEdges = Kruskal(G);
    int totalWeight = 0;
    vector<Edge> removedEdges;
    for (const Edge& e : G.E) {
      bool found = false;
      for (const Edge& re : remainingEdges) {
        if ((e.source == re.source && e.target == re.target) || (e.source == re.target && e.target == re.source)) {
          found = true;
          break;
        }
      }
      if (!found) {
        totalWeight += e.weight;
        removedEdges.push_back(e);
      }
    }
    outFile << totalWeight << endl;
    for (const Edge& e : removedEdges) {
      outFile << e.source << " " << e.target << " " << e.weight << endl;
    }
  } else {  // graphType == 'd'
    //Here I still dont have good algorithm to solve the directed weighted Minimum Feedback Arc Set problem
    //To avoid showing error and the entire program shutdown, I output 0 instead writing nothing
    outFile << 0 <<endl;
  }
  inFile.close();
  outFile.close();
  return 0;
}
