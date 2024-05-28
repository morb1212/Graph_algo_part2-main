//314923822
//morberger444@gmail.com
#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <ostream>
#include <string>
using namespace std;
using namespace ariel;

Graph::Graph() {}

Graph::~Graph() {}

void Graph::loadGraph(const vector<vector<int>> &adjMatrix) {
    size_t n = adjMatrix.size();
    for (const vector<int> &row : adjMatrix) {
        if (row.size() != n) {
             throw std::invalid_argument("Input graph is not a square matrix.");
        }
    }
    this->matrix = adjMatrix;
}


std::string Graph::printGraph() const {
    size_t n = graphSize();
    std::string matrixprint;  
    for (size_t i = 0; i < n; ++i) {
        matrixprint += "[";  
        for (size_t j = 0; j < n; ++j) {
            matrixprint += std::to_string(matrix[i][j]);  
            if (j < n - 1) {
                matrixprint += ", ";
            }
        }
        matrixprint += "]";
        if (i < n - 1) {
            matrixprint += "\n";  
        }
    }
    return matrixprint;
}

const vector<vector<int>> &Graph::getMatrix() const {
    return this->matrix;
}

size_t Graph::graphSize() const {
    return this->matrix.size();
}

Graph Graph::operator+(const Graph &other) const {
    if (this->graphSize() != other.graphSize()) {
        throw invalid_argument("Graphs must be of the same size");
    }
    vector<vector<int>> result(this->matrix.size(), vector<int>(this->matrix.size()));
    for (size_t i = 0; i < this->matrix.size(); ++i) {
        for (size_t j = 0; j < this->matrix.size(); ++j) {
            result[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    Graph newGraph;
    newGraph.loadGraph(result);
    return newGraph;
}

Graph Graph::operator-(const Graph &other) const {
    if (this->graphSize() != other.graphSize()) {
        throw invalid_argument("Graphs must be of the same size for subtraction.");
    }
    vector<vector<int>> result(this->matrix.size(), vector<int>(this->matrix.size()));
    for (size_t i = 0; i < this->matrix.size(); ++i) {
        for (size_t j = 0; j < this->matrix.size(); ++j) {
            result[i][j] = this->matrix[i][j] - other.matrix[i][j];
        }
    }
    Graph newGraph;
    newGraph.loadGraph(result);
    return newGraph;
}

Graph Graph::operator*(const Graph &other) const {
    if (this->graphSize() != other.graphSize()) {
        throw std::invalid_argument("Graphs must be of the same size for multiplication.");
    }
    size_t n = this->matrix.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            for (size_t k = 0; k < n; ++k) {
                result[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    Graph newGraph;
    newGraph.loadGraph(result);
    return newGraph;
}
Graph Graph::operator+=(const Graph &other)  {
    if (this->graphSize() != other.graphSize()) {
        throw invalid_argument("Graphs must be of the same size");
    }
    vector<vector<int>> result(this->matrix.size(), vector<int>(this->matrix.size()));
    for (size_t i = 0; i < this->matrix.size(); ++i) {
        for (size_t j = 0; j < this->matrix.size(); ++j) {
            result[i][j] = this->matrix[i][j] + other.matrix[i][j];
        }
    }
    this->loadGraph(result);
    return *this;
}

Graph Graph::operator-=(const Graph &other)  {
    if (this->graphSize() != other.graphSize()) {
        throw invalid_argument("Graphs must be of the same size for subtraction.");
    }
    vector<vector<int>> result(this->matrix.size(), vector<int>(this->matrix.size()));
    for (size_t i = 0; i < this->matrix.size(); ++i) {
        for (size_t j = 0; j < this->matrix.size(); ++j) {
            result[i][j] = this->matrix[i][j] - other.matrix[i][j];
        }
    }
    this->loadGraph(result);
    return *this;
}

Graph Graph::operator+() const {
    return *this;
}

Graph Graph::operator-() const {
    return *this;
}


bool Graph::operator==(const Graph &other) const {
    return this->matrix == other.matrix;
}

bool Graph::operator!=(const Graph &other) const {
    return !(*this == other);
}

bool Graph::operator<(const Graph &other) const {
    if (this->graphSize() < other.graphSize()) {
        return true;
    }
    if (this->graphSize() > other.graphSize()) {
        return false;
    }
    size_t thisEdges = countEdges();
    size_t otherEdges = other.countEdges();
    if (thisEdges < otherEdges) {
        return true;
    }
    if (thisEdges > otherEdges) {
        return false;
    }
    return this->matrix < other.matrix;
}

bool Graph::operator<=(const Graph &other) const {
    return *this < other || *this == other;
}

bool Graph::operator>(const Graph &other) const {
    return other < *this;
}

bool Graph::operator>=(const Graph &other) const {
    return other <= *this;
}

Graph &Graph::operator++() {
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
            (*this).matrix[i][j] ++;
        }
    }
    return *this;
}

Graph Graph::operator++(int) {
    Graph temp = *this;
    ++(*this);
    return temp;
}

Graph &Graph::operator--() {
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
            (*this).matrix[i][j] --;
        }
    }
    return *this;
}

Graph Graph::operator--(int) {
    Graph temp = *this;
    --(*this);
    return temp;
}

Graph Graph::operator*(int scalar) const {
    vector<vector<int>> result(this->matrix.size(), vector<int>(this->matrix.size()));
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
           result[i][j] = this->matrix[i][j] * scalar;
        }
    }
    
    Graph newGraph;
    newGraph.loadGraph(result);
    return newGraph;
}

Graph &Graph::operator*=(int scalar) {
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
           (*this).matrix[i][j] *= scalar;
        }
    }
    return *this;
}

Graph &Graph::operator/=(int scalar) {
    if (scalar == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
           (*this).matrix[i][j] /= scalar;
        }
    }
    return *this;
}

size_t Graph::countEdges() const {
    size_t count = 0;
    for (size_t i = 0; i < this->graphSize(); ++i) {
        for (size_t j = 0; j < this->graphSize(); ++j) {
            if ((*this).matrix[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

std::ostream &ariel::operator<<(std::ostream &out, const Graph &gr)
{
    const auto &matrix = gr.getMatrix();
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size(); ++j) {
            out << matrix[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}
