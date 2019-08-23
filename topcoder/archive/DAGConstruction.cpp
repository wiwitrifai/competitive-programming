#include <bits/stdc++.h>

using namespace std;

const int N = 55;

long long vis[N];

class DAGConstruction {
public:
	vector <int> construct(vector <int> x) {
		vector< pair<int, int> > v;
		int n = x.size();
		for (int i = 0; i < n; i++)
			v.emplace_back(x[i], i);
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++) {
			if (v[i].first > i+1)
				return vector< int >(1, -1);
		}
		vector< int > pre, ans;
		for (int i = 0; i < n; i++) {
			int u = v[i].second;
			int need = v[i].first-1;
			vis[u] = (1LL<<u);
			while (need) {
				int used = pre[0], best = 0;
				for (int p : pre) {
					int cnt = __builtin_popcountll((~vis[u]) & vis[p]);
					if (cnt <= need && best < cnt)
						used = p, best = cnt;
				}
				ans.push_back(u);
				ans.push_back(used);
				vis[u] |= vis[used];
				need -= best;
			}
			pre.push_back(u);
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
		cout << "Testing DAGConstruction (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486963058;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		DAGConstruction _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int x[] = {2, 1};
				int __expected[] = {0, 1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 1:
			{
				int x[] = {1, 1};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 2:
			{
				int x[] = {1, 3, 1};
				int __expected[] = {1, 0, 1, 2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 3:
			{
				int x[] = {5,5,5,5,5};
				int __expected[] = {-1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			case 4:
			{
				int x[] = {4,2,2,1};
				int __expected[] = {0, 1, 0, 2, 1, 3, 2, 3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}
			/*case 5:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int x[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.construct(vector <int>(x, x+sizeof(x)/sizeof(int))); break;
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
