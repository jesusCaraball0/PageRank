#include<iostream>
#include<string>
#include"AdjacencyList_Graph.h"

using namespace std;

int main() {
	int noOfLines, powerIterations;
	string from, to;
	Graph graph;

	cin >> noOfLines;
	cin >> powerIterations;

	for (int i = 0; i < noOfLines; i++) {
		cin >> from;
		cin >> to;

		graph.setVertexIndex(from);
		graph.setVertexIndex(to);

		graph.insertEdge(from, to);

	}

	graph.setRankContributions();
	graph.setPowerIterations(powerIterations);

	graph.printPowerRanks();
}