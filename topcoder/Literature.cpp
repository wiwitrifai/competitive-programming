#include <bits/stdc++.h>

using namespace std;

const int N = 1024;

bool vis[N][N];
double dp[N][N][3];

int n;

void rec(int a, int b) {
	if (vis[a][b]) {
		return;
	}
	vis[a][b] = 1;
	if (a == 0 || b == 0) {
		for (int i = 0; i < 3; ++i)
			dp[a][b][i] = 0;
		return;
	}
	if (a)
		rec(a-1, b);
	if (b)
		rec(a, b-1);
	double pb = (double)b / (2 * n), pa = (double)a / (2 * n);
	double x = b ? dp[a][b-1][2] : 0, y = a ? dp[a-1][b][0] : 0;
	double dp0 = 1 + (1 + pb * x + (1 - pb) * (1 + pa * y));
	double koef = (1 - (1 - pb) * (1 - pa));
	dp0 /= koef;
	dp[a][b][0] = dp0;
	dp[a][b][2] = 1 + pa * y + (1 - pa) * dp[a][b][0];
	dp[a][b][1] = 1 + pb * x + (1 - pb) * dp[a][b][2];
}

class Literature {
public:
	double expectation(int n, vector <int> Teja, vector <int> history) {
		set<int> sa, sb;
		::n = n;
		set<int> st;
		for (int x : Teja)
			st.insert(x);
		for (int i = 0; i < history.size(); ++i) {
			if (st.count(history[i]))
				continue;
			int r = i % 3;
			if (r == 0) continue;
			if (r == 2)
				sa.insert(history[i]);
			else
				sb.insert(history[i]);
			if (sa.size() == n || sb.size() == n)
				return i+1;
		}
		int a = n - (int)sa.size(), b = n - (int)sb.size();
		rec(a, b);
		int k = history.size();
		return (double)k + dp[a][b][k % 3];
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
		cout << "Testing Literature (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1551876274;
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
		Literature _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 1;
				int Teja[] = {3};
				int history[] = {1};
				_expected = 3.333333333333333;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
			}
			case 1:
			{
				int n = 2;
				int Teja[] = {1,4};
				int history[] = {3,1,6,6,2,5,2,4,1};
				_expected = 6.0;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
			}
			case 2:
			{
				int n = 10;
				int Teja[] = {5,29,12,16,25,17,18,30,27,10};
				int history[] = {4,6,5,23,22,29,20,8,12,3,13,16,1};
				_expected = 133.0880654696573;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
			}
			/*case 3:
			{
				int n = ;
				int Teja[] = ;
				int history[] = ;
				_expected = ;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int n = ;
				int Teja[] = ;
				int history[] = ;
				_expected = ;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int Teja[] = ;
				int history[] = ;
				_expected = ;
				_received = _obj.expectation(n, vector <int>(Teja, Teja+sizeof(Teja)/sizeof(int)), vector <int>(history, history+sizeof(history)/sizeof(int))); break;
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
