#include <bits/stdc++.h>

using namespace std;

const int N = 105;

vector< int > ch[N];
int live[N], st[N], en[N], cntr, lv[N], contain[N];

void pre(int v = 0) {
	st[v] = cntr++;
	for (int u : ch[v]) {
		lv[u] = lv[v] + 1;
		pre(u);
	}
	en[v] = cntr++;
}

bool descendant(int u, int v) {
	if (lv[u] > lv[v]) swap(u, v);
	return st[u] <= st[v] && en[v] <= en[u];
}

int dfs(int v = 0) {
	int ret = 0, add = 0;
	contain[v] = live[v];
	for (int u : ch[v]) {
		ret += dfs(u);
		contain[v] |= contain[u];
		add += contain[u];
	}
	if (add) add--;
	ret += add;
	if (live[v] && ret)
		ret--;
	return ret;
}

class EllysTree {
public:
	vector <int> getMoves(vector <int> parent) {
		int n = parent.size();
		for (int i = 0; i <= n; i++)
			ch[i].clear(), live[i] = 1;
		for (int i = 0; i < n; i++)
			ch[parent[i]].push_back(i+1);
		cntr = 0;
		lv[0] = 0;
		pre();
		live[0] = 0;
		if (dfs() > 0)
			return vector< int > ();
		vector< int > ans;
		int now = 0;
		for (int t = 0; t < n; t++) {
			for (int i = 1; i <= n; i++) {
				if (!live[i]) continue;
				if (!descendant(i, now)) continue;
				live[i] = 0;
				if (dfs() <= 0) {
					now = i;
					break;
				}
				else
					live[i] = 1;
			}
			ans.push_back(now);
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
		cout << "Testing EllysTree (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1491221110;
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
		EllysTree _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int parent[] = {9, 13, 7, 9, 8, 14, 14, 0, 6, 9, 2, 2, 5, 5, 7};
				int __expected[] = {1, 5, 2, 11, 13, 12, 8, 3, 7, 15, 14, 4, 6, 9, 10 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 1:
			{
				int parent[] = {3, 4, 5, 0, 2};
				int __expected[] = {1, 2, 3, 4, 5 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 2:
			{
				int parent[] = {0, 0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			case 3:
			{
				int parent[] = {0, 6, 6, 2, 6, 1, 3, 5};
				int __expected[] = {2, 4, 1, 3, 7, 6, 5, 8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}
			/*case 4:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int parent[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getMoves(vector <int>(parent, parent+sizeof(parent)/sizeof(int))); break;
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
