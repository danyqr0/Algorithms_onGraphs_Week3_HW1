//============================================================================
// Name        : Algorithms_onGraphs_Week3_HW1.cpp
// Author      : Daniel Ramirez
// Version     :
// Copyright   : HW3_Week1
// Description : Computing the minimum number of flight segments in C++
//============================================================================

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using std::vector;
using std::queue;

//global variables
int n,m;
queue <int> g_queue;

int distance(vector<vector<int> > &adj, int s, int t) {
   vector <int> distance(n,-1);
   vector <int>::iterator it;
   int u;
   distance[s]=0;
   g_queue.push(s);
   while(!g_queue.empty()){
	   u=g_queue.front();g_queue.pop();
	   for(it=adj[u].begin();it!=adj[u].end();it++){
		   if(distance[*it]==-1){
			   g_queue.push(*it);
			   distance[*it]=distance[u]+1;
		   }
	   }

   }
   if(distance[t]!=-1) return distance[t];
   return -1;
}

int main() {
	  std::cin >> n >> m;
	  if( (n>=2 && n<=1e5) && (m>=0 && m<=1e5) ){
		  vector<vector<int> > adj(n, vector<int>());
		  for (int i = 0; i < m; i++) {
			  int x, y;
			  std::cin >> x >> y;
			  adj[x - 1].push_back(y - 1);
			  adj[y - 1].push_back(x - 1);
		  }
		  int s, t;
		  std::cin >> s >> t;
		  s--, t--;
		  std::cout << distance(adj, s, t);
	}
	return 0;
}
