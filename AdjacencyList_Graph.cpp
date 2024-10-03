#include"AdjacencyList_Graph.h"

using namespace std;

// gives an unique index to each unique URL
void Graph::setVertexIndex(string URL) {
    if (indexURL.find(URL) == indexURL.end()) {
        indexURL[URL] = indexURL.size() + 1;
    }
}

// adds a new edge between from and to vertices. 
void Graph::insertEdge(string from, string to)
{
    graph[indexURL[from]].push_back(make_pair(indexURL[to], 0));
    if (graph.find(indexURL[to]) == graph.end()) {
        graph[indexURL[to]] = {};
    }
}

// sets the weight of each edge to its respective rank contribution
void Graph::setRankContributions() {
    for (auto it = graph.begin(); it != graph.end(); it++) {
        for (int i = 0; i < it->second.size(); i++) {
            it->second[i].second = float(1) / float(it->second.size());
        }
    }
}

// sets page ranks after power iterations
void Graph::setPowerIterations(int powerIterations) {

    for (int i = 1; i < graph.size() + 1; i++) {
        pageRanks[i] = 0;
        initialRanks[i] = float(1) / float(graph.size());
    }

    if (powerIterations == 1) {
        pageRanks = initialRanks;
    }
    for (int i = 1; i < powerIterations; i++) {
        for (auto it = graph.begin(); it != graph.end(); it++) {
            for (int i = 0; i < it->second.size(); i++) {
                pageRanks[it->second[i].first] += it->second[i].second * initialRanks[it->first];
            }
        }
        initialRanks = pageRanks;
        if (i == powerIterations - 1) {
            break;
        }
        pageRanks.clear();
    }
}

// prints URLs in alphabetical order and their respective ranks
void Graph::printPowerRanks() {
    for (auto it = indexURL.begin(); it != indexURL.end(); it++) {
        cout << it->first << " " << fixed << setprecision(2) << pageRanks[it->second] << endl;
    }
}