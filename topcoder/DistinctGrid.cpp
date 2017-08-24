#include <bits/stdc++.h>

using namespace std;

#define INF 1111111111

// things that handle max flow
struct edge {
    int j, flow, cap;
    edge *pair;
    edge(int j, int cap): j(j), flow(0), cap(cap), pair(NULL) {}
};

struct flow {
    int n;
    vector<edge*> *adj;
    edge **parent;
    int *flowto;
    int ans;
    flow(int n): n(n), ans(0) {
        adj = new vector<edge*>[n];
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        parent = new edge*[n];
        flowto = new int[n];
    }   
    void add_edge(int i, int j, int front, int back = 0) {
        // back is the capacity of the backward direction.
        // if back = 0, then edge is directed.
        edge *ef = new edge(j, front);
        edge *eb = new edge(i, back);
        ef->pair = eb;
        eb->pair = ef;
        adj[i].push_back(ef);
        adj[j].push_back(eb);
    }

    int aug(int s, int t) {
        // BFS-augment from s to t
        vector<int> queue;
        for (int i = 0; i < n; i++) flowto[i] = 0;
        queue.push_back(s);
        flowto[s] = INF;
        for (int f = 0; f < queue.size(); f++) {
            int i = queue[f];
            for (int nb = 0; nb < adj[i].size(); nb++) {
                edge *e = adj[i][nb];
                int j = e->j;
                if (!flowto[j]) {
                    int delta = e->cap - e->flow;
                    if (delta > 0) {
                        flowto[j] = min(flowto[i], delta);
                        parent[j] = e;
                        if (j == t) return flowto[j];
                        queue.push_back(j);
                    }
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        // edmonds karp
        for (int flow = 0;;) {
            int res = aug(s, t);
            if (!res) return flow;
            flow += res;
            for (int j = t; j != s; j = parent[j]->pair->j) {
                parent[j]->flow += res;
                parent[j]->pair->flow -= res;
            }
        }
    }
};



class DistinctGrid {
public:
	vector <int> findGrid(int n, int k) {
		flow fl(2 * n + 2);
		int s = 2 * n, t = s+1;
		for (int i = 0; i < n; i++) {
			fl.add_edge(s, i, k-1);
			fl.add_edge(i + n, t, k-1);
			for (int j = 0; j < n; j++) {
				fl.add_edge(i, j + n, 1);
			}
		}
		int tot = fl.max_flow(s, t);
		vector<int> ans(n * n, 0);
		int cur = 1;
		for (int i = 0; i < n; i++) {
			for (auto it : fl.adj[i]) {
				if (it->flow) {
					int j = (it->j)-n;
					if (j >= n) continue;
					ans[i * n + j] = cur++;
				}
			}
		}
		return ans;
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
		cout << "Testing DistinctGrid (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1503574102;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DistinctGrid _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int k = 1;
				int __expected[] = {0, 0, 0, 0, 0, 0, 0, 0, 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
			}
			case 1:
			{
				int n = 6;
				int k = 3;
				int __expected[] = {1, 0, 0, 0, 0, 2, 0, 3, 0, 0, 4, 0, 0, 0, 5, 6, 0, 0, 0, 0, 7, 8, 0, 0, 0, 9, 0, 0, 10, 0, 11, 0, 0, 0, 0, 12 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
			}
			case 2:
			{
				int n = 4;
				int k = 2;
				int __expected[] = {123, 999, 999, 999, 999, 999, 999, 456, 999, 789, 999, 999, 999, 999, 240, 999 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
			}
			/*case 3:
			{
				int n = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
			}*/
			/*case 4:
			{
				int n = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.findGrid(n, k); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
