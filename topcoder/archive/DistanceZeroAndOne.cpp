#include <bits/stdc++.h>

using namespace std;

int d[100];
vector< string > g;

void bfs(int v) {
	int n = g.size();
	memset(d, -1, sizeof d);
	queue< int > que;
	que.push(v);
	d[v] = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (int i = 0; i < n; i++) if (d[i] == -1 && g[u][i] == 'Y')
			d[i] = d[u] + 1, que.push(i);
	}
}


class DistanceZeroAndOne {
public:
	vector <string> construct(vector <int> dist0, vector <int> dist1) {
		int n = dist0.size();
		vector< string > ans(n, string(n, 'N'));
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (abs(dist0[i]-dist0[j]) <= 1 && abs(dist1[i]-dist1[j]) <= 1)
					ans[i][j] = ans[j][i] = 'Y';
			}
		}
		g = ans;
		bfs(0);
		for (int i = 0; i < n; i++)
			if (dist0[i] != d[i])
				return vector< string > ();
		bfs(1);
		for (int i = 0; i < n; i++)
			if (dist1[i] != d[i])
				return vector< string > ();
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
		cout << "Testing DistanceZeroAndOne (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1495296861;
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
		DistanceZeroAndOne _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {2,0,1};
				string __expected[] = {"NNY", "NNY", "YYN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 1:
			{
				int dist0[] = {0,2,1};
				int dist1[] = {1,0,2};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 2:
			{
				int dist0[] = {3,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 3:
			{
				int dist0[] = {0,1,1,1};
				int dist1[] = {1,0,1,1};
				string __expected[] = {"NYYY", "YNYY", "YYNN", "YYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 4:
			{
				int dist0[] = {0,3,1,2,2,3,4,4};
				int dist1[] = {3,0,2,1,2,3,4,4};
				string __expected[] = {"NNYNNNNN", "NNNYNNNN", "YNNYYNNN", "NYYNYNNN", "NNYYNYNN", "NNNNYNYY", "NNNNNYNN", "NNNNNYNN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			case 5:
			{
				int dist0[] = {0,1};
				int dist1[] = {1,0};
				string __expected[] = {"NY", "YN" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}
			/*case 6:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int dist0[] = ;
				int dist1[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.construct(vector <int>(dist0, dist0+sizeof(dist0)/sizeof(int)), vector <int>(dist1, dist1+sizeof(dist1)/sizeof(int))); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
