#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
bool vis[N];
vector< int > fac[N];
class GCDGraph {
public:
	string possible(int n, int k, int x, int y) {
		if (k == 0)
			return "Possible";
		memset(vis, 0, sizeof vis);
		for (int i = k+1; i <= n; i++) {
			for (int j = i; j <= n; j += i)
				fac[j].push_back(i);
		}
		vis[x] = 1;
		queue< int > q;
		q.push(x);
		while (!q.empty()) {
			int now = q.front(); q.pop();
			if (now == y)
				break;
			if (now > k)
				for (int i = now + now; i <= n; i += now) {
					if (!vis[i]) {
						vis[i] = 1;
						q.push(i);
					}
				}
			for (int f : fac[now]) if (!vis[f]) {
				vis[f] = 1;
				q.push(f);
			}
		}
		return vis[y] ? "Possible" : "Impossible";
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
		cout << "Testing GCDGraph (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1486961284;
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
		GCDGraph _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 12;
				int k = 2;
				int x = 8;
				int y = 9;
				_expected = "Possible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 1:
			{
				int n = 12;
				int k = 2;
				int x = 11;
				int y = 12;
				_expected = "Impossible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 2:
			{
				int n = 12;
				int k = 2;
				int x = 11;
				int y = 11;
				_expected = "Possible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 3:
			{
				int n = 10;
				int k = 2;
				int x = 8;
				int y = 9;
				_expected = "Impossible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 4:
			{
				int n = 1000000;
				int k = 1000;
				int x = 12345;
				int y = 54321;
				_expected = "Possible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 5:
			{
				int n = 1000000;
				int k = 2000;
				int x = 12345;
				int y = 54321;
				_expected = "Impossible";
				_received = _obj.possible(n, k, x, y); break;
			}
			case 6:
			{
				int n = 2;
				int k = 0;
				int x = 1;
				int y = 2;
				_expected = "Possible";
				_received = _obj.possible(n, k, x, y); break;
			}
			/*case 7:
			{
				int n = ;
				int k = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.possible(n, k, x, y); break;
			}*/
			/*case 8:
			{
				int n = ;
				int k = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.possible(n, k, x, y); break;
			}*/
			/*case 9:
			{
				int n = ;
				int k = ;
				int x = ;
				int y = ;
				_expected = ;
				_received = _obj.possible(n, k, x, y); break;
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
