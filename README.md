# Simplified Google PageRank Algorithm
## Description
Simplified version of Google's initial page rank algorithm. Taking in webpages connections, the application converts the input into a graph implemented as an adjacency list. The graph is then parsed into the PageRank algorithm, where each edge is normalized to its respective rank contribution. Then, power iterations continue the process using matrix multiplication to assign final pageranks. URLs and their respective rankings are printed at the end. 
## Install Instructions
Since there are no external dependencies, PageRank can be ran locally through an IDE or Makefile. 
