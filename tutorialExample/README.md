The following graph is contained in the file `test1.txt`:



The contents of `test1.txt` are as follows:
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

There is obviously only one maixmal tripartite clique, 2-5-7, and thus should be printed when the code is run with the following command line argument:
`./kpartite test1.txt 3 0-3 4-5 6-8`
