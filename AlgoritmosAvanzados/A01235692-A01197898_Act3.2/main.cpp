/*
Act3.2
Implement Dijkstra and Floyd-Warshall algorithms

The program must read a number n followed by n x n nonnegative integer values that represent an adjacency matrix of a directed graph.
The first number represents the number of nodes, the following values in the array, the value at position i,j represents the weight of the arc from node i to node j. 
If there is no arc between node i and node j, the value in the array must be -1

David Gerardo Martínez Hidrogo - A01235692 
Humberto Ricardo Rodriguez Ruán - A01197898

Created: Oct 5, 2022 at 12:54pm    Last Moidification: Oct 5, 2022

*/

#include <iostream>
#include <vector>
using namespace std;


//Dijkstra

/*
Selects the vertex that has not been processed and has the minimum distance value
Receives list with value distances and processed vertex, returns vertex not processed and
    with minimum value.

comlexity
    time: O(n), n being the number of vertex
    extras space: O(1), no extra variable dependent on the input is used
*/
int selectMinVertex(vector<int> & distance, vector<bool> & processed, int & n){

    //declare variables
    int minimum = INT_MAX;  //minimu value
    int vertex; //vartex

    for(int i = 0; i < n; i++){

        if(processed[i] == false && distance[i] < minimum){
            vertex = i;
            minimum = distance[i];
        }
    }

    return vertex;

}

/*
Print value distances from source node to every other node
Receives list od value distances and the source node

complexity
    time: O(n), n being the number of vertices
    extra space: O(1), no extra variables dependent on the input is used
*/
void printDistance(vector<int> & distance, int & val){

    for(int i = 0; i < distance.size(); i++){
        if(distance[i] != 0){
            cout << "node: " << val + 1 << " to node " << i + 1 << ": " << distance[i] << endl;
        }  
    }
}

/*
Generates shortest path distances from source vertex to the rest of vertex
Receives an adjacency matrix, the matrix dimention and the source vertex

complexity:
    time: O(n^2), n being the number of vertex in the graph
    extra space: O(n), we have variables dependent on the input size
*/
void dijkstra(vector<vector<int> > & adjMatrix, int & n, int & val){

    //declare variables
    vector<int> parent(n);
    vector<bool> processed(n, false);
    vector<int> distance(n, INT_MAX);

    //mark first node as processed
    distance[val] = 0;  //value 0 to get picked first
    parent[val] = -1; //start node has no parent

    for(int i = 0; i < n-1; i++){

        //select minimum value node
        int U = selectMinVertex(distance, processed, n);

        //check if all vertices have been visited
        if(U == INT_MAX) break;

        //Mark as processed
        processed[U] = true;

        //relax adjacent vertices
       for(int j = 0; j < n; j++){
            /*
            conditions for relaxation
                1. Edge is present from U to j
                2. Vertex j is not inlcuded in shortest path graph
                3. edge weight is smaller than current edge weight
            */

           if(adjMatrix[U][j] != -1 && processed[j] == false && distance[U] != INT_MAX && (distance[U] + adjMatrix[U][j] < distance[j])){
            distance[j] = distance[U] + adjMatrix[U][j];
            parent[j] = U;
           }
       }
    }

    //print distances
    printDistance(distance, val);


}

int main()
{
    
    //declare varibles
    int n;  //matrix dimention
    cin >> n;

    //fill matrix
    vector<vector<int> > adjMatrix(n, vector<int>(n)); //matrix

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int aux;
            cin >> aux;
            adjMatrix[i][j] = aux;
        }
    }

    //call Dijkstra method
    for(int i = 0; i < n; i++){
        dijkstra(adjMatrix, n, i);
    }
    

    return 0;
}
