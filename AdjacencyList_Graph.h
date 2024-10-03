#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<algorithm>
#include<iomanip>
using namespace std;


class Graph
{
private:
    // map representing graph; first is the from, then to, and finally weight 
    map<int, vector<pair<int, float>>> graph;
    // map mapping each URL with an integer, which represents it in the graph
    map<string, int> indexURL;
    // map storing URL indexes and respective page ranks
    map<int, float> pageRanks;
    // map storing sum of rank contributions for each vertex
    map<int, float> initialRanks;

public:
    void setVertexIndex(string URL);
    void insertEdge(string from, string to);
    void setRankContributions();
    void setPowerIterations(int powerIterations);
    void printPowerRanks();
};