#include <bits/stdc++.h>

using namespace std;

const int N = 303, mod = 1e9 + 7;
vector< int > g[N];
bool al[N];
vector< int > node;

int count(int v, int lim, int depth = 0, int par = -1) {
	if (lim <= depth)
		return 1 + (depth != 0);
	int ret = 1;
	for (int u : g[v]) if (al[u] && u != par)
		ret = (1LL * ret * count(u, lim, depth+1, v)) % mod;
	ret += (depth != 0);
	if (ret >= mod) ret += mod;
	return ret;
}

int dfs(int v) {
	al[v] = 0;
	node.push_back(v);
	int ret = 1;
	if (node[0] <= v) {
		for (int i = 0; i < node.size(); i++) {
			int cnt = count(node[i], min(i, (int)node.size()-1-i)-1);
			ret = (1LL * ret * cnt) % mod;
		}
	}
	else
		ret = 0;
	for (int u : g[v]) if (al[u]) {
		ret += dfs(u);
		if (ret >= mod) ret -= mod;
	}
	al[v] = 1;
	node.pop_back();
	return ret;
}

class BearUniqueDiameter {
public:
	int countSubtrees(vector <int> a, vector <int> b) {
		memset(al, 1, sizeof al);
		int n = a.size() + 1;
		for (int i = 0; i < n; i++) g[i].clear();
		for (int i = 0; i < n-1; i++) {
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += dfs(i);
			if (ans >= mod) ans -= mod;
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
		cout << "Testing BearUniqueDiameter (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1487550994;
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
		BearUniqueDiameter _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int a[] = {0,0,0};
				int b[] = {1,2,3};
				_expected = 10;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int a[] = {3,2,1,4,0};
				int b[] = {1,3,4,0,5};
				_expected = 21;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int a[] = {0,1,2,3,2};
				int b[] = {1,2,3,4,5};
				_expected = 22;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int a[] = {1};
				int b[] = {0};
				_expected = 3;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int a[] = {36,23,33,33,33,24,33,33,33,33,37,33,33,33,33,28,33,33,22,33,
				          29,16,33,33,33,33,33,31,35,33,33,8,13,26,12,33,33,0,33,33};
				int b[] = {33,33,0,9,39,33,32,40,15,19,33,30,38,7,25,33,27,11,33,3,33,33,
				          21,18,5,6,4,33,11,14,10,33,33,33,33,20,2,1,34,17};
				_expected = 719477120;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 5:
			{
				int a[] = {0,0,0,1,2,3,4,5,6};
				int b[] = {1,2,3,4,5,6,7,8,9};
				_expected = 70;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 6:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int a[] = ;
				int b[] = ;
				_expected = ;
				_received = _obj.countSubtrees(vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
