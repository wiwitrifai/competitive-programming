#include <bits/stdc++.h>

using namespace std;

/** Max Flow Min Cost **/
/* complexity: O(min(E^2 V log V, E log V F)) */
const int maxnodes = 2010;
const int inf = 1e7;
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
  Edge b ={s,0,0,-cost, graph[s].size()};
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


pair<int, int> minCostFlow(int s,int t,int maxf){
  // bellmanFord can be safely commented if edges costs are non-negative
  bellmanFord(s, pot);
  int flow =0;
  int flowCost =0;
  while(flow < maxf){
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
      if(d != prio[u])continue;
      for(int i =0; i <(int) graph[u].size(); i++){
        Edge &e = graph[u][i];
        int v = e.to;
        if(e.cap <= e.f)continue;
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
    if(prio[t]==1000000000)break;
    for(int i =0; i < nodes; i++) pot[i]+= prio[i];
    int df = min(curflow[t], maxf - flow);
    flow += df;
    for(int v = t; v != s; v = prevnode[v]){
      Edge &e = graph[prevnode[v]][prevedge[v]];
      e.f += df;
      graph[v][e.rev].f -= df;
      flowCost += df * e.cost;
    }
  }
  return make_pair(flow, flowCost);
}


/* usage example:
* addEdge (source, target, capacity, cost)
* minCostFlow(source, target, INF) -><flow, flowCost>
*/

class Cashback {
public:
	double findMax(vector <int> limit, vector <int> rate, vector <int> amount) {
		int n = limit.size(), m = amount.size();
		int s = n + m, t = s+1;
		for (int i = 0; i < n; i++) {
			addEdge(s, i, limit[i], 0);
		}	
		for (int i = 0; i < m; i++) {
			addEdge(n+i, t, amount[i], 0);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				addEdge(i, n+j, inf, -rate[i * m + j]);
		}
		nodes = t + 1;
		pair< int, int > res = minCostFlow(s, t, inf);
		return (double)-res.second/100.0;
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
		cout << "Testing Cashback (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486940915;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Cashback _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int limit[] = {1000,1000};
				int rate[] = {1,2};
				int amount[] = {58};
				_expected = 1.16;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 1:
			{
				int limit[] = {1,2};
				int rate[] = {1,2};
				int amount[] = {58};
				_expected = 0.05;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 2:
			{
				int limit[] = {100,100};
				int rate[] = {0,5,
				              5,0};
				int amount[] = {10,10};
				_expected = 1.0;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 3:
			{
				int limit[] = {7,8,9};
				int rate[] = {2, 3, 1,
				              5, 7, 10,
				              7, 6, 8};
				int amount[] = {20, 30, 40};
				_expected = 1.73;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			case 4:
			{
				int limit[] = {12,34,56,78,910};
				int rate[] = {100, 100, 0, 0, 0,
				              0, 100, 100, 0, 0,
				              0, 0, 100, 100, 0,
				              0, 0, 0, 100, 100,
				              100, 0, 0, 0, 100};
				int amount[] = {111,111,111,111,111};
				_expected = 402.0;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}
			/*case 5:
			{
				int limit[] = ;
				int rate[] = ;
				int amount[] = ;
				_expected = ;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int limit[] = ;
				int rate[] = ;
				int amount[] = ;
				_expected = ;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int limit[] = ;
				int rate[] = ;
				int amount[] = ;
				_expected = ;
				_received = _obj.findMax(vector <int>(limit, limit+sizeof(limit)/sizeof(int)), vector <int>(rate, rate+sizeof(rate)/sizeof(int)), vector <int>(amount, amount+sizeof(amount)/sizeof(int))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
