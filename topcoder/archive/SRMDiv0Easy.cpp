#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e8;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
  from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;
 
  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}
 
  void AddEdge(int from, int to, int cap) {
  G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
  if (from == to) G[from].back().index++;
  G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
  fill(dad.begin(), dad.end(), (Edge *) NULL);
  dad[s] = &G[0][0] - 1;
    
  int head = 0, tail = 0;
  Q[tail++] = s;
  while (head < tail) {
    int x = Q[head++];
    for (int i = 0; i < G[x].size(); i++) {
  Edge &e = G[x][i];
  if (!dad[e.to] && e.cap - e.flow > 0) {
    dad[e.to] = &G[x][i];
    Q[tail++] = e.to;
  }
    }
  }
  if (!dad[t]) return 0;

  long long totflow = 0;
  for (int i = 0; i < G[t].size(); i++) {
    Edge *start = &G[G[t][i].to][G[t][i].index];
    int amt = INF;
    for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
  if (!e) { amt = 0; break; }
  amt = min(amt, e->cap - e->flow);
    }
    if (amt == 0) continue;
    for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
  e->flow += amt;
  G[e->to][e->index].flow -= amt;
    }
    totflow += amt;
  }
  return totflow;
  }

  long long GetMaxFlow(int s, int t) {
  long long totflow = 0;
  while (long long flow = BlockingFlow(s, t))
    totflow += flow;
  return totflow;
  }
};

class SRMDiv0Easy {
public:
	int get(int N, vector <int> L, vector <int> R, vector <int> X, vector <int> Y) {
		Dinic mf(N + 3);
		int s = N+1, t = N + 2;
		int q = L.size();
		int sum = 0;
		for (int i = 0; i < q; i++) {
			mf.AddEdge(L[i], R[i]+1, Y[i]-X[i]);
			mf.AddEdge(s, R[i]+1, X[i]);
			mf.AddEdge(L[i], t, X[i]);
			sum += X[i];
		}
		auto mf2 = mf;
		mf.AddEdge(N, 0, INF);
		if (mf.GetMaxFlow(s, t) < sum)
			return -1;
		mf2.AddEdge(s, 0, INF);
		mf2.AddEdge(N, t, INF);
		return mf2.GetMaxFlow(s, t) - sum;
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
		cout << "Testing SRMDiv0Easy (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487995507;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SRMDiv0Easy _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int N = 2;
				int L[] = {0,1};
				int R[] = {0,1};
				int X[] = {1,2};
				int Y[] = {2,3};
				_expected = 2;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 1:
			{
				int N = 2;
				int L[] = {0,1};
				int R[] = {0,1};
				int X[] = {1,3};
				int Y[] = {2,4};
				_expected = -1;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 2:
			{
				int N = 3;
				int L[] = {0,1,0,0,2};
				int R[] = {2,2,1,0,2};
				int X[] = {1,3,1,4,2};
				int Y[] = {11,13,19,15,17};
				_expected = 41;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 3:
			{
				int N = 12;
				int L[] = {0,0,1,4,9,7,0};
				int R[] = {6,11,11,4,10,11,0};
				int X[] = {1,73,334,1,1,5,362};
				int Y[] = {546,342,645,249,999,535,458};
				_expected = -1;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 4:
			{
				int N = 200;
				int L[] = {0,49,0,97,0,65,0,55,0,24,0,86,0,139,0,34,0,11,0,62,0,172,0,59,0,97,0,47,0,156,0,24,0,103,0,184,0,130,0,154,0,26,0,121,0,72,0,183,0,5};
				int R[] = {48,199,96,199,64,199,54,199,23,199,85,199,138,199,33,199,10,199,61,199,171,199,58,199,96,199,46,199,155,199,23,199,102,199,183,199,129,199,153,199,25,199,120,199,71,199,182,199,4,199};
				int X[] = {1,1,1,1,2,1,2,2,2,2,1,1,1,1,2,1,1,1,1,1,2,2,2,1,2,1,1,2,2,1,1,1,2,2,1,1,2,1,1,1,1,1,2,2,2,2,2,2,2,1};
				int Y[] = {964,962,952,993,983,973,971,954,978,980,958,999,991,978,977,991,971,976,977,998,968,992,951,955,987,981,986,958,968,966,992,957,975,995,958,995,983,985,956,974,966,986,985,999,959,989,980,998,971,973};
				_expected = 24202;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			case 5:
			{
				int N = 5;
				int L[] = {};
				int R[] = {};
				int X[] = {};
				int Y[] = {};
				_expected = 0;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}
			/*case 6:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int N = ;
				int L[] = ;
				int R[] = ;
				int X[] = ;
				int Y[] = ;
				_expected = ;
				_received = _obj.get(N, vector <int>(L, L+sizeof(L)/sizeof(int)), vector <int>(R, R+sizeof(R)/sizeof(int)), vector <int>(X, X+sizeof(X)/sizeof(int)), vector <int>(Y, Y+sizeof(Y)/sizeof(int))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
