// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

/*
	 => BFS, edge weight is 1, and cycle are present but will be handelled.
	 The idea is to consider the given snake and ladder board as a directed graph 
	 with number of vertices equal to the number of cells in the board. The problem 
	 reduces to finding the shortest path in a graph. Every vertex of the graph has 
	 an edge to next six vertices if next 6 vertices do not have a snake or ladder. 
	 If any of the next six vertices has a snake or ladder, then the edge from 
	 current vertex goes to the top of the ladder or tail of the snake. Since all 
	 edges are of equal weight, we can efficiently find shortest path using Breadth 
	 First Search of the graph.
 */


