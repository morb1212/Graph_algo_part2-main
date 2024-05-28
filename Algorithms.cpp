//314923822
//morberger444@gmail.com
#include "Algorithms.hpp"
#include <list>
#define true 1
#define false 0
#define INT_MAX 999
using namespace std;
using namespace ariel;

int Algorithms::isConnected(const Graph &gr){
    size_t n = gr.graphSize();
    vector<int> checkVertex(n, 0);
    list<size_t> myList;
    myList.push_back(0);
    vector<vector<int>> grMatrix = gr.getMatrix();
    while (!myList.empty()){
        size_t node = myList.back();
        myList.pop_back();
        if (!checkVertex[node]){
            checkVertex[node] = 1;
            for (size_t i = 0; i < n; ++i){
                if (grMatrix[node][i] != 0)
                    myList.push_back(i);
            }
        }
    }
    for (int vertex : checkVertex){
        if (vertex==0)
            return false;
    }
    return true;
}

string Algorithms::shortestPath(const Graph &gr, size_t start, size_t end){
    size_t n = gr.graphSize();
    vector<int> distance(n, -1);
    vector<size_t> path(n, (size_t)-1);
    distance[start] = 0;
    list<size_t> myList;
    myList.push_front(start);
    vector<vector<int>> adjMatrix = gr.getMatrix();
    while (!myList.empty()){
        size_t node = myList.front();
        myList.pop_front();
        for (size_t i = 0; i < n; i++){
            if (adjMatrix[node][i] != 0){
                if (distance[i] == -1){
                    distance[i] = distance[node] + 1;
                    path[i] = node;
                    myList.push_front(i);
                }
            }
        }
    }
    string pathPrint;
    size_t current = end;
    if (path[current]==-1)
        return "-1";
    pathPrint = to_string(current);
    current = path[current];
    while (current != -1){
        pathPrint = to_string(current) + "->" + pathPrint;
        current = path[current];
    }

    return pathPrint;
}

int Algorithms::isContainsCycle(const Graph &gr){
    size_t n = gr.graphSize();
    vector<bool> visited(n, 0);
    vector<size_t> parent(n, (size_t)-1);
    vector<vector<int>> adjMatrix = gr.getMatrix();
    for (size_t i = 0; i < n; ++i){
        if (!visited[i]){
            list<size_t> myList;
            myList.push_back(i);
            while (!myList.empty()){
                size_t node = myList.back();
                myList.pop_back();
                if (!visited[node]){
                    visited[node] = 1;
                    for (size_t j = 0; j < n; ++j){
                        if (adjMatrix[node][j] != 0){
                            if (!visited[j]){
                                myList.push_back(j);
                                parent[j] = node;
                            }
                            else if (parent[node] != j)
                                return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


string Algorithms::isBipartite(const Graph &gr){
    size_t n = gr.graphSize();
    vector<int> divideToColor(n, -1);
    list<size_t> myList;  
    vector<vector<int>> adjMatrix = gr.getMatrix();
    myList.push_back(0);
    divideToColor[0] = 0;
    while (!myList.empty()) {
        size_t node = myList.front();
        myList.pop_front();
        for (size_t i = 0; i < n; ++i) {
            if (adjMatrix[node][i] != 0) {
                if (divideToColor[i] == -1) {
                    divideToColor[i] = 1 - divideToColor[node];
                    myList.push_back(i);
                } else if (divideToColor[i] == divideToColor[node])
                        return "0"; 
                }
            }
        }
    vector<int> groupA, groupB;
    for (size_t i = 0; i < n; ++i){
        if (divideToColor[i] == 0)
            groupA.push_back(i);
        else
            groupB.push_back(i);
    }
    string result = "The graph is bipartite: A={";
    for (size_t i = 0; i < groupA.size(); ++i){
        result += to_string(groupA[i]);
        if (i != groupA.size() - 1)
            result += ", ";
    }
    result += "}, B={";
    for (size_t i = 0; i < groupB.size(); ++i){
        result += to_string(groupB[i]);
        if (i != groupB.size() - 1)
            result += ", ";
    }
    result += "}";
    return result;
}

string Algorithms::negativeCycle(const Graph &gr){
    if(!isContainsCycle(gr))
        return "There is no negative cycle";
    size_t n = gr.graphSize();
    vector<int> distance(n, -1); 
    distance[0] = 0;
    vector<vector<int>> adjMatrix = gr.getMatrix();
    for (size_t i = 0; i < n - 1; ++i){
        for (size_t w = 0; w < n; ++w){
            for (size_t v = 0; v < n; ++v){
                if (adjMatrix[w][v] != 0){
                    if (distance[w] != -1 && distance[w] + adjMatrix[w][v] < distance[v])
                        distance[v] = distance[w] + adjMatrix[w][v];
                }
            }
        }
    }
    for (size_t w = 0; w < n; ++w){
        for (size_t v = 0; v < n; ++v){
            if (adjMatrix[w][v] != 0){
                if (distance[w] != -1 && distance[w] + adjMatrix[w][v] < distance[v])
                    return "found from "+ std::to_string(distance[w]);
            }
        }
    }
    return "There is no negative cycle";
}
