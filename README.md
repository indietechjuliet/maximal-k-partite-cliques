# Maximal k-Partite Cliques Implementation
A C++ implementation of maximal k-partite clique algorithm outlined in the paper:  doi: 10.3390/a12010023
<br /><br /><br />
Instructions: <br />
compile with the following <br />
g++ -std=c++11 -o kpartite kpartiteclique.cpp

The folllowing is an example of how to run the program:
```
./kpartite input.txt 3 0-20 21-30 31-58
```
Let's step through what each of the command line arguments mean in the example above:
* `input.txt` - a DIMACS format file with the first line consisting of the number of nodes followed by the number of edges, and every line after of the format `node1 node2`, denoting an edge between these two nodes <br />
* `3` - the number of k partitions of the graph <br />
* `0-20 21-30 31-58` - Partitions of the graph, the range is denoted by the starting node of the partition and the last node part of that partition, seperated by a -. In this example, nodes 0-20 form the first partition, 21-30 form the second partition, and 31-58 form the third partition <br />
**Note: You can only have as many partitions as the number k specified as command line argument 3** <br />
**Another Note: each partition is a disjoint set, meaning there are no edges between nodes in the partitions** <br />

The output of the program is a list of maximal k-partite cliques of the graph provided
