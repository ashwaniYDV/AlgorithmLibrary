/*
 * This is a simple BFS implementation on a 2D grid
 * 2D array: grid is the main Grid in which we make a BFS operation. Visited just mark every cell wheater
 * it is already visited or not. Distance is storing every cell's distance or level from the source cell.
 * 1D array: dr is the direction for row and dc is the direction for collumn for every adjacent cell from the cell u.
 * Function isValid is just using to make sure that the operation will not happen outside of the grid, that means it 
 * ensure the operation will happen in the range of 0 to grid's ROW and 0 to grid's COLLUMN every time.
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define MAX 1000
#define SET(a, b) memset( a, b, sizeof a )
#define  pii pair <int, int>

void BFS(int, int);
bool isValid(pii);

int R = MAX, C = MAX;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int Distance[MAX][MAX];
int dr[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dc[]= {1, -1, 0, 0, -1, 1, -1, 1};

int main()
{
	/* 
	 * Take the input and other things here.....
	 * Just for a simple implementation we consider the sourceRow and sourceCol as 0
	 * That means we consider Cell(0, 0) as source. But the source could be any cell as the problem's question
	 * So do that kind of necessary code here then call BFS function :) .......
	 */

	int sourceRow = 0, sourceCol = 0;

	BFS(sourceRow, sourceCol);

	/*
	 * Ater the BFS operation the visited array and Distance array store the result as their job 
	 * You may need more array or variables to store the result as the problem want. Do that as the problem say
	 * Now use those containers and variables to do necessary things as the problem wants to solve..... print it or anything .... 
	 */

	return 0;
}

bool isValid (pii v){

	return (v.first>=0 && v.first<R) && (v.second>=0 && v.second<C);
}

void BFS (int sourceRow, int sourceCol){

	queue <pii> Q;

	Q.push( make_pair(sourceRow, sourceCol) );
	visited[sourceRow][sourceCol] = true;
	Distance[sourceRow][sourceCol] = 0;

	while( !Q.empty() ){

		pii u = Q.front();

		for(int direction=0; direction<8; direction++){

			int r1 = u.first + dr[direction];
			int c1 = u.second + dc[direction];

			pii v = make_pair( r1, c1 );

			if( isValid(v) && !visited[v.first][v.second] ){

				visited[v.first][v.second] = true;
				Distance[v.first][v.second] = Distance[u.first][u.second]+1;
				Q.push(v);
			}
		}
		Q.pop();
	}

	return;
}
