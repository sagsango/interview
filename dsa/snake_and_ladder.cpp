// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1

/*
	 => BFS, edge weight is 1, and cycle are present but will be handelled.
	 The idea is to consider the given snake and ladder board as a directed graph 
	 with number of vertices equal to the number of cells in the board. The problem 
	 reduces to finding the shortest path in a graph. 
  
  	 WRONG (Every vertex of the graph has 
	 an edge to next six vertices if next 6 vertices do not have a snake or ladder. 
	 If any of the next six vertices has a snake or ladder, then the edge from 
	 current vertex goes to the top of the ladder or tail of the snake.) what if there are
         ladder back to back?

  	 RIGHT (
         1. vertex with no ladder have edge to next 6 vertex with weight 1.
	 2. vertex with ladder tail have (6 vertex as case 1) + (edge weight 0, fro current vertex to 
            ladder head)
	 3. snake head vertex (do not have 6 vertex as case 1) and they have only one edge of 0 weight
            to the snake tail.

          )
  
  
  	 Since all 
	 edges are of equal weight, we can efficiently find shortest path using Breadth 
	 First Search of the graph.
 */


