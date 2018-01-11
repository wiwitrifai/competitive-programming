#include <bits/stdc++.h>

using namespace std;

string s;
string a = "SANTA";
string b = "SATAN";
string dp[2000][6][6];
int vis[2000][6][6];

int solved(int id, int x, int y) {
	// cerr << id << " " << x << " " << y<< " " << vis[id][x][y]<< endl;
	if (y >= 5) return 0;
	if (vis[id][x][y] != -1)
		return vis[id][x][y];
	if (id == s.size() && x == 5) {
		vis[id][x][y] = 1;
		return vis[id][x][y];
	}
	if (id < s.size()) {
		int xx = x, yy = y;
		if (xx < 5 && a[xx] == s[id]) xx++;
		if (yy < 5 && b[yy] == s[id]) yy++;
		if (solved(id+1, xx, yy)) {
			string awal = "a";
			awal[0] = s[id];
			dp[id][x][y] = awal + dp[id+1][xx][yy];
			vis[id][x][y] = 1;
			// cerr << " " << id << " " << x << " " << y << " " << xx << " " << yy << endl;
			// cerr << dp[id][x][y] << endl;
			return 1;
		}
	}
	if (x < 5) {
		int yy = y;
		if (yy < 5 && b[yy] == a[x]) yy++;
		if (solved(id, x+1, yy)) {
			string awal = "a";
			awal[0] = a[x];
			// cerr << "add " << id << " " << x << " " << y << " " <<  yy << endl;
			dp[id][x][y] = awal + dp[id][x+1][yy];
			// cerr << dp[id][x][y] << endl;
			vis[id][x][y] = 1;
			return 1;
		}
	}
	vis[id][x][y] = 0;
	return 0;
}


class OnlySanta {
public:
	string solve(string S) {
		s = S;
		memset(vis, -1, sizeof vis);
		cerr << solved(0, 0, 0) << endl;
		return dp[0][0][0];
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
		cout << "Testing OnlySanta (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1515636033;
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
		OnlySanta _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string S = "STANA";
				_expected = "STANTA";
				_received = _obj.solve(S); break;
			}
			case 1:
			{
				string S = "STN";
				_expected = "SANTNA";
				_received = _obj.solve(S); break;
			}
			case 2:
			{
				string S = "RATSNOOOA";
				_expected = "DEARATSNOOOSANTA";
				_received = _obj.solve(S); break;
			}
			case 3:
			{
				string S = "SXAYNTA";
				_expected = "OOOOSOXAYNTOOOOAOOO";
				_received = _obj.solve(S); break;
			}
			case 4:
			{
				string S = "SNTA";
				_expected = "SANTA";
				_received = _obj.solve(S); break;
			}
			case 5:
			{
				string S = "ASNTA";
				_expected = "SASNTAS";
				_received = _obj.solve(S); break;
			}
			case 6:
			{
				string S = "NIELATA";
				_expected = "SANIELATAJA";
				_received = _obj.solve(S); break;
			}
			case 7:
			{
				string S = "X";
				_expected = "SSAAXNNTTAA";
				_received = _obj.solve(S); break;
			}
			/*case 8:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 9:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
			}*/
			/*case 10:
			{
				string S = ;
				_expected = ;
				_received = _obj.solve(S); break;
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
