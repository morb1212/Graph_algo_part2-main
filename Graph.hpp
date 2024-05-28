//314923822
//morberger444@gmail.com
#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <ostream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace ariel {
    class Graph {
    private:
        vector<vector<int>> matrix;

    public:
        Graph();
        ~Graph();
        void loadGraph(const vector<vector<int>> &matrix);
        std::string printGraph() const;
        const vector<vector<int>>& getMatrix() const;
        size_t graphSize() const;
        
        Graph operator+(const Graph &other) const;
        Graph operator+=(const Graph &other) ;
        Graph operator+() const;

        Graph operator-(const Graph &other) const;
        Graph operator-=(const Graph &other) ;
        Graph operator-() const;

        Graph operator*(const Graph &other) const;
        
        Graph &operator++();
        Graph operator++(int);
        Graph &operator--();
        Graph operator--(int);

        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator<=(const Graph &other) const;
        bool operator>(const Graph &other) const;
        bool operator>=(const Graph &other) const;

        Graph operator*(int scalar) const;
        Graph &operator*=(int scalar); 
        Graph &operator/=(int scalar); 

        friend std::ostream& operator<<(std::ostream &out, const Graph &gr) ;
        
        size_t countEdges() const;
    };
}

#endif // GRAPH_HPP
