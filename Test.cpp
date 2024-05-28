//314923822
//morberger444@gmail.com
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};
    CHECK(g4.printGraph() == "[1, 0, 2]\n[1, 3, 1]\n[1, 0, 2]");
    vector<vector<int>> graphf = {
        {0, 1, 0, 5},
        {1, 0, 1, 7},
        {0, 1, 0, 7},
        {0, 1, 0, 7}};
    ariel::Graph g5;
    g5.loadGraph(graphf);
    CHECK_THROWS(g5*g2);
    CHECK_THROWS(g5+g2);
}

TEST_CASE("Test 1")
{
    ariel::Graph g;
    ariel::Graph g2;
    vector<vector<int>> graphTest1 = {
        {0, -2, 4, 0},
        {0, 0, -3, 0},
        {0, 0, 0, 2},
        {-1, 0, 0, 0}};
    g.loadGraph(graphTest1);
    g2.loadGraph(graphTest1);
    CHECK(g==g2);
    CHECK(g<=g2);
    CHECK(g>=g2);
    CHECK(!(g!=g2));
    CHECK(!(g<g2));
    CHECK(!(g>g2));
    ariel::Graph g3 = g + g2;
    CHECK(g3.printGraph() == "[0, -4, 8, 0]\n[0, 0, -6, 0]\n[0, 0, 0, 4]\n[-2, 0, 0, 0]");
    CHECK(!(g3==g2));
    CHECK(g3<=g2);
    CHECK(!(g3>=g2));
    CHECK(g3!=g2);
    CHECK(g3<g2);
    CHECK(!(g3>g2));
}

TEST_CASE("Test 2")
{
    ariel::Graph g;
    vector<vector<int>> graphTest2 = {
        {0, 3, 0, 0},
        {0, 4, 0, 0},
        {0, -4, 0, 0},
        {1, 0, 0, 0}};
    g.loadGraph(graphTest2);
    g++;
    CHECK(g.printGraph() == "[1, 4, 1, 1]\n[1, 5, 1, 1]\n[1, -3, 1, 1]\n[2, 1, 1, 1]");
    ariel::Graph g2;
    g2.loadGraph(g.getMatrix());
    CHECK(ariel::Algorithms::isConnected(g2) == true);
    CHECK(ariel::Algorithms::shortestPath(g2, 0, 3) == "0->3");
    CHECK(ariel::Algorithms::isContainsCycle(g2) == true);
    CHECK(ariel::Algorithms::isBipartite(g2) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g2) == "There is no negative cycle");
    g2++;
    g2++;
    g2++;
    CHECK(g2.printGraph() == "[4, 7, 4, 4]\n[4, 8, 4, 4]\n[4, 0, 4, 4]\n[5, 4, 4, 4]");
    ariel::Graph g3=g*4;
    CHECK(g3.printGraph() == "[4, 16, 4, 4]\n[4, 20, 4, 4]\n[4, -12, 4, 4]\n[8, 4, 4, 4]");
    g3--;
    CHECK(g3.printGraph() == "[3, 15, 3, 3]\n[3, 19, 3, 3]\n[3, -13, 3, 3]\n[7, 3, 3, 3]");
    g3+=g2;
    CHECK(g3.printGraph() == "[7, 22, 7, 7]\n[7, 27, 7, 7]\n[7, -13, 7, 7]\n[12, 7, 7, 7]");
    CHECK(ariel::Algorithms::isConnected(g2) == true);
    CHECK(ariel::Algorithms::shortestPath(g2, 0, 3) == "0->3");
    CHECK(ariel::Algorithms::isContainsCycle(g2) == true);
    CHECK(ariel::Algorithms::isBipartite(g2) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g2) == "There is no negative cycle");
}



TEST_CASE("Test 3")
{
    ariel::Graph g;
    vector<vector<int>> graphTest3 = {
        {0, 3, 1},
        {0, 4, 0},
        {0, -4, 5}};
    g.loadGraph(graphTest3);
    ariel::Graph g1;
    vector<vector<int>> graphTest4 = {
        {0, 7, 0},
        {1, 5, 0},
        {0, 2, 1}};
    g1.loadGraph(graphTest4);
    ariel::Graph g2=g*g1;
    CHECK(g2.printGraph() == "[3, 17, 1]\n[4, 20, 0]\n[-4, -10, 5]");
    ariel::Graph g3=g+g1;
    CHECK(g3.printGraph() == "[0, 10, 1]\n[1, 9, 0]\n[0, -2, 6]");
    CHECK(!(g3==g2));
    CHECK(g3<=g2);
    CHECK(!(g3>=g2));
    CHECK(g3!=g2);
    CHECK(g3<g2);
    CHECK(!(g3>g2));
}
