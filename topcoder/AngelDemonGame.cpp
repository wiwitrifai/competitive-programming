#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 55;

typedef long long ll;

int nodes = maxnodes;
int prio[maxnodes], curflow[maxnodes], prevedge[maxnodes], prevnode[maxnodes], q[maxnodes], pot[maxnodes];
bool inqueue[maxnodes];

           
struct Edge {
  int to, f, cap, cost, rev;
};

vector<Edge> graph[maxnodes];

void addEdge(int s,int t,int cap,int cost){
  Edge a ={t,0, cap, cost, graph[t].size()};
  Edge b ={s,0, 0,-cost, graph[s].size()};
  graph[s].push_back(a);
  graph[t].push_back(b);
}


void bellmanFord(int s,int dist[]){
  fill(dist, dist + nodes,1000000000);
  dist[s]=0;
  int qt =0;
  q[qt++]= s;
  for(int qh =0;(qh - qt)% nodes !=0; qh++){
    int u = q[qh % nodes];
    inqueue[u]=false;
    for(int i =0; i <(int) graph[u].size(); i++){
      Edge &e = graph[u][i];
      if(e.cap <= e.f)continue;
      int v = e.to;
      int ndist = dist[u]+ e.cost;
      if(dist[v]> ndist){
        dist[v]= ndist;
        if(!inqueue[v]){
          inqueue[v]=true;
          q[qt++% nodes]= v;
        }
      }
    }
  }
}

vector< string > GG;
bool ok;

pair<int, int> minCostFlow(int s,int t,int maxc){
  // bellmanFord can be safely commented if edges costs are non-negative
  bellmanFord(s, pot);
  int flow =0;
  int flowCost =0;
  while(true){
    priority_queue<ll, vector<ll>, greater<ll>> q;
    q.push(s);
    fill(prio, prio + nodes,1000000000);
    prio[s]=0;
    curflow[s]=1000000000;
    while(!q.empty()){
      ll cur = q.top();
      int d = cur >>32;
      int u = cur;
      q.pop();
      if(d != prio[u]) continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f) continue;
        int nprio = prio[u]+ e.cost + pot[u]- pot[v];
        if(prio[v]> nprio){
          prio[v]= nprio;
          q.push(((ll) nprio <<32)+ v);
          prevnode[v]= u;
          prevedge[v]= i;
          curflow[v]= min(curflow[u], e.cap - e.f);
        }
      }
    }
    if(prio[t]==1000000000) break;
    for(int i =0; i < nodes; i++) pot[i]+= prio[i];
    int df = curflow[t];
    flow += df;
    for(int v = t; v != s; v = prevnode[v]){
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
      if (e.cost == 1) {
      	GG[prevnode[v]][v] = GG[v][prevnode[v]] = 'Y';
      	ok = 1;
      }
    }
    if (flowCost > maxc) {
    	flow -= df;
    	break;
    }
  }
  return make_pair(flow, flowCost);
}


class AngelDemonGame {
public:
	string winner(vector <string> G, int A, int D) {
		int n = G.size();
		int ans = 0;
		GG = G;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				addEdge(i, j, 1, G[i][j] == 'N');
			}
		}
		pair<int,int> res = minCostFlow(0, n-1, A);
		ans = res.first;
		if (ans == 0)
			return "Demon";
		if (ans > D)
			return "Angel";
		ans = 0;
		ok = 1;
		while (ok) {
			ok = 0;
			for (int i = 0; i < n; i++)
				graph[i].clear();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == j) continue;
					addEdge(i, j, 1, GG[i][j] == 'N');
				}
			}
			pair<int,int> res = minCostFlow(0, n-1, A);
			if (ans < res.first)
				ans = max(ans, res.first);
		}
		if (ans <= D)
			return "Demon";
		return "Unknown";
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing AngelDemonGame (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1500741094;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		AngelDemonGame _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string G[] = {"NYNY",
				              "YNYY",
				              "NYNN",
				              "YYNN"};
				int A = 2;
				int D = 2;
				_expected = "Angel";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 1:
			{
				string G[] = {"NYNY",
				              "YNYY",
				              "NYNN",
				              "YYNN"};
				int A = 6;
				int D = 6;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 2:
			{
				string G[] = {"NNNN",
				              "NNNN",
				              "NNNN",
				              "NNNN"};
				int A = 2;
				int D = 2;
				_expected = "Unknown";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 3:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 4;
				int D = 4;
				_expected = "Unknown";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 4:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 8;
				int D = 4;
				_expected = "Angel";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 5:
			{
				string G[] = {"NYNNNY",
				              "YNNYNN",
				              "NNNNYN",
				              "NYNNNN",
				              "NNYNNN",
				              "YNNNNN"};
				int A = 4;
				int D = 8;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			case 6:
			{
				string G[] = {"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN",};
				int A = 1225;
				int D = 1225;
				_expected = "Demon";
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}
			/*case 7:
			{
				string G[] = ;
				int A = ;
				int D = ;
				_expected = ;
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}*/
			/*case 8:
			{
				string G[] = ;
				int A = ;
				int D = ;
				_expected = ;
				_received = _obj.winner(vector <string>(G, G+sizeof(G)/sizeof(string)), A, D); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
