#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
#include "LinkedList.h"
#include "Stack.h"

template<typename T>
class Graph {
private:
    struct Edge {
        int dest;
        T weight;
    };

    int V; 
    std::vector<LinkedList<Edge>> adjList;

public:
    Graph(int vertices) : V(vertices), adjList(vertices) {}

    void addEdge(int src, int dest, T weight) {
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            throw std::out_of_range("Invalid vertex index.");
        }
        Edge edge = {dest, weight};
        adjList[src].insertAtEnd(edge);
    }

    void dijkstraShortestPath(int src, int dest) {
        if (src < 0 || src >= V || dest < 0 || dest >= V) {
            throw std::out_of_range("Invalid vertex index.");
        }

        std::vector<T> dist(V, std::numeric_limits<T>::max());
        std::vector<int> prev(V, -1);
        std::vector<bool> visited(V, false);

        dist[src] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1;
            T minDist = std::numeric_limits<T>::max();
            for (int v = 0; v < V; ++v) {
                if (!visited[v] && dist[v] < minDist) {
                    u = v;
                    minDist = dist[v];
                }
            }

            if (u == -1) break;

            visited[u] = true;

            for (auto it = adjList[u].begin(); it != adjList[u].end(); ++it) {
                int v = (*it).dest;
                T weight = (*it).weight;
                if (!visited[v] && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                }
            }
        }

        std::cout << "Shortest Path from " << src << " to " << dest << ": ";
        int vertex = dest;
        Stack<int> path;
        while (vertex != -1) {
            path.push(vertex);
            vertex = prev[vertex];
        }
        while (!path.isEmpty()) {
            std::cout << path.pop() << " ";
        }
        std::cout << "\nShortest Path Weight: " << dist[dest] << std::endl;
    }



    void dfsTraversal() {
        std::vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

private:
    void dfsUtil(int vertex, std::vector<bool>& visited) {
        Stack<int> stack;
        stack.push(vertex);

        while (!stack.isEmpty()) {
            int currVertex = stack.pop();
            if (!visited[currVertex]) {
                std::cout << currVertex << " ";
                visited[currVertex] = true;

                for (auto it = adjList[currVertex].begin(); it != adjList[currVertex].end(); ++it) {
                    int adjVertex = (*it).dest;
                    if (!visited[adjVertex]) {
                        stack.push(adjVertex);
                    }
                }
            }
        }
    }
};

int main() {
    try {
        Graph<int> graph(5);

        graph.addEdge(0, 1, 4);
        graph.addEdge(0, 2, 1);
        graph.addEdge(1, 2, 2);
        graph.addEdge(1, 3, 5);
        graph.addEdge(2, 3, 2);
        graph.addEdge(3, 4, 3);

        graph.dijkstraShortestPath(0, 4);

        std::cout << "DFS Traversal: ";
        graph.dfsTraversal();
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
