#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

set<int> st;	
vector<int> g[N];
bool vis[N][4];
int xr;
int batas;
void rem(int v, int lv = 0) {
	st.erase(v^xr);
	if (lv >= batas || vis[v][lv]) return;
	vis[v][lv] = 1;
	for (int u : g[v]) if (!vis[u][lv+1]) {
		rem(u, lv+1);
	}
}

class SixDegreesOfSeparation {
public:
	vector <int> getAdditionalEdges(int n, vector <int> a, vector <int> b) {
		srand(time(0));
		st.clear();
		memset(vis, 0, sizeof vis);
		xr = rand();
		for (int i = 0; i < n; i++)
			g[i].clear(), st.insert(i ^ xr);
		for (int i = 0; i < a.size(); i++) {
			g[a[i]].push_back(b[i]);
			g[b[i]].push_back(a[i]);
		}
		int patokan = rand() % n;
		batas = 3;
		rem(patokan);
		batas = 2;
		vector<int> ans;
		while (!st.empty()) {
			auto it = st.begin();
			int v = *it^xr;
			st.erase(it);
			ans.push_back(patokan);
			ans.push_back(v);
			rem(v);
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
		cout << "Testing SixDegreesOfSeparation (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1505061401;
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
		SixDegreesOfSeparation _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 3;
				int a[] = {0,1,2};
				int b[] = {1,2,0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 8;
				int a[] = {0,1,2,3,4,5,6};
				int b[] = {1,2,3,4,5,6,7};
				int __expected[] = {0, 7 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 12;
				int a[] = {0,1,2,3,4,5,6,7,8,9,10,11};
				int b[] = {1,2,3,4,5,6,7,8,9,10,11,0};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 3:
			{
				int n = 13;
				int a[] = {0,1,2,3,4,5,5,1,8,9,10,11};
				int b[] = {1,2,3,4,5,6,7,8,9,10,11,12};
				int __expected[] = {2, 9, 2, 5, 5, 9 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			case 4:
			{
				int n = 4;
				int a[] = {0,0,0,1,1,2};
				int b[] = {1,2,3,2,3,3};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}
			/*case 5:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int n = ;
				int a[] = ;
				int b[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getAdditionalEdges(n, vector <int>(a, a+sizeof(a)/sizeof(int)), vector <int>(b, b+sizeof(b)/sizeof(int))); break;
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
