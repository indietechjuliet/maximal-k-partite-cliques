## Example 1
The following graph is contained in the file `testTri1.txt`:

![image](https://github.com/indietechjuliet/maximal-k-partite-cliques/blob/main/tutorialExample/test1_graph.png)

The contents of `testTri1.txt` are as follows:
```
9 8
0 4
1 4
2 4
2 5
3 6
3 8
5 7
2 7
```
This graph is a tripartite graph, so our command argument that specifies the number k of partites will be 3. <br />
As you can see from the above image, our partitions are as follows: <br />
* Vectices 0 through 3
* Vertices 4 and 5
* Vertices 6 through 8

<br /> <br />
Thus, the code is run with the following command line argument:
`./kpartiteclique testTri1.txt 3 0-3 4-5 6-8`

There is obviously only one maixmal tripartite clique, {2,5,7}, and you should recieve this list as a maximal tripartite clique when run. Our maximal clique covering each partitie set:

![image](https://github.com/indietechjuliet/maximal-k-partite-cliques/blob/main/tutorialExample/test1results_graph.png)

## Example 2
he following graph is contained in the file `testTri2.txt`:

![image](https://github.com/indietechjuliet/maximal-k-partite-cliques/blob/main/tutorialExample/test2_graph.png)

The contents of `testTri2.txt` are as follows:
```
9 10
0 4
1 4
2 4
2 5
3 6
3 8
5 7
2 7
3 5
5 6
```
This graph is a tripartite graph, so our command argument that specifies the number k of partites will be 3. <br />
As you can see from the above image, our partitions are as follows: <br />
* Vectices 0 through 3
* Vertices 4 and 5
* Vertices 6 through 8

<br /> <br />
Thus, the code is run with the following command line argument:
`./kpartiteclique testTri2.txt 3 0-3 4-5 6-8`

This graph is similar to Example 1, with two more edges added in, creating another maximal clique: {3,5,6}. <br />
After running the above command line argument, both maximal cliques {2,5,7} and {3,5,6} will be listed in the output file.


![image](https://github.com/indietechjuliet/maximal-k-partite-cliques/blob/main/tutorialExample/test2results_graph.png)
