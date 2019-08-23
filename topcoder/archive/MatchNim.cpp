#include <bits/stdc++.h>

using namespace std;

const string win = "Yvonne";
const string lose = "Zara";

vector<vector<int>> cand;
set<vector<int>> loser;

void dfs(int n, vector<int> & v, int mak) {
	if (v.size() == n) {
		cand.push_back(v);
		return;
	}
	for (int i = 1; i <= mak; ++i) {
		v.push_back(i);
		dfs(n, v, i);
		v.pop_back();
	}
}

vector<int> cmaks[10][10];

class MatchNim {
public:
	string whoWins(vector <int> piles) {
		for (int i = 0; i < piles.size(); ++i) {
			if (piles[i] >= (int)piles.size()-1)
				return win;
		}
		// for (int i = 1; i < 10; ++i) {
		// 	for (int j = 0; j < (1 << i); ++j) {
		// 		for (int k = __builtin_popcount(j); k <= i; ++k)
		// 			cmaks[i][k].push_back(j);
		// 	}
		// }
		// vector<int> v;
		sort(piles.begin(), piles.end());
		reverse(piles.begin(), piles.end());
		// for (int n = 3; n <= piles.size(); ++n) {
		// 	cand.clear();
		// 	dfs(n, v, n-2);
		// 	sort(cand.begin(), cand.end());
		// 	for (auto now : cand) {
		// 		bool ok = 1;
		// 		for (int i = 0; i < n && ok; ++i) {
		// 			if (i + 1 < n && now[i] == now[i+1]) continue;
		// 			for (int pick = 1; pick <= now[i] && ok; ++pick) {
		// 				vector<int> s = now;
		// 				s[i] -= pick;
		// 				sort(s.begin(), s.end());
		// 				reverse(s.begin(), s.end());
		// 				for (int mask : cmaks[n][pick]) {
		// 					vector<int> cur;
		// 					for (int j = 0; j < n; ++j) {
		// 						if (s[j] == 0 || (mask & (1 << j))) continue;
		// 						cur.push_back(s[j]);
		// 					}
		// 					if (loser.count(cur)) {
		// 						ok = 0;
		// 						break;
		// 					}
		// 				}
		// 			}
		// 		}
		// 		if (ok) {
		// 			loser.insert(now);
		// 			cerr << "{";
		// 			bool comma = 0;
		// 			for (int x : now) {
		// 				if (comma)
		// 					cerr << ",";
		// 				comma = 1;
		// 				cerr << x ;
		// 			}
		// 			cerr << "},";
		// 		}
		// 	}
		// }
		set<vector<int>> loser = {{1,1,1},{2,2,2,1},{3,3,3,2,1},{3,3,3,3,3},{1,1,1,1,1,1},{2,2,2,2,2,2},{3,3,2,2,1,1},{4,4,3,3,2,2},{4,4,4,3,2,1},{4,4,4,3,3,3},{4,4,4,4,2,2},{4,4,4,4,4,1},{2,2,2,1,1,1,1},{3,3,3,2,2,2,2},{4,4,4,2,2,1,1},{5,5,4,4,3,3,1},{5,5,4,4,4,4,3},{5,5,5,3,3,2,2},{5,5,5,4,3,2,1},{5,5,5,4,3,3,3},{5,5,5,4,4,2,2},{5,5,5,4,4,4,1},{5,5,5,5,3,3,1},{5,5,5,5,4,4,3},{5,5,5,5,5,2,1},{5,5,5,5,5,5,3},{3,3,3,2,1,1,1,1},{3,3,3,3,3,1,1,1},{4,4,3,3,3,3,1,1},{4,4,4,3,2,2,2,2},{5,5,4,4,3,2,1,1},{5,5,4,4,4,4,1,1},{5,5,5,4,2,2,1,1},{6,6,5,5,4,3,2,2},{6,6,5,5,4,4,2,1},{6,6,5,5,5,5,2,2},{6,6,5,5,5,5,4,1},{6,6,6,4,4,3,3,1},{6,6,6,4,4,4,4,3},{6,6,6,5,3,3,2,2},{6,6,6,5,4,3,2,1},{6,6,6,5,4,3,3,3},{6,6,6,5,4,4,2,2},{6,6,6,5,4,4,4,1},{6,6,6,5,5,3,3,1},{6,6,6,5,5,4,4,3},{6,6,6,5,5,5,2,1},{6,6,6,5,5,5,5,3},{6,6,6,6,4,3,2,2},{6,6,6,6,4,4,2,1},{6,6,6,6,5,5,2,2},{6,6,6,6,5,5,4,1},{6,6,6,6,6,3,2,1},{6,6,6,6,6,3,3,3},{6,6,6,6,6,4,4,3},{6,6,6,6,6,5,4,2},{6,6,6,6,6,5,5,3},{6,6,6,6,6,6,2,2},{6,6,6,6,6,6,4,1},{6,6,6,6,6,6,6,3},{1,1,1,1,1,1,1,1,1},{2,2,2,2,2,2,1,1,1},{3,3,2,2,1,1,1,1,1},{4,4,4,3,2,1,1,1,1},{4,4,4,4,3,3,1,1,1},{4,4,4,4,4,1,1,1,1},{5,5,5,3,3,3,3,1,1},{5,5,5,4,3,2,2,2,2},{5,5,5,5,5,2,2,2,2},{6,6,5,4,4,3,3,1,1},{6,6,5,4,4,3,3,3,3},{6,6,5,5,5,3,3,1,1},{6,6,5,5,5,5,2,1,1},{6,6,6,4,4,3,2,1,1},{6,6,6,4,4,4,4,1,1},{6,6,6,5,4,2,2,1,1},{6,6,6,6,6,2,2,1,1},{7,7,6,5,5,4,3,3,2},{7,7,6,5,5,4,4,4,2},{7,7,6,5,5,5,5,3,2},{7,7,6,5,5,5,5,5,4},{7,7,6,6,5,4,3,3,1},{7,7,6,6,5,4,4,3,2},{7,7,6,6,5,4,4,4,4},{7,7,6,6,5,5,3,2,1},{7,7,6,6,5,5,3,3,3},{7,7,6,6,5,5,5,4,2},{7,7,6,6,6,4,3,3,2},{7,7,6,6,6,4,4,4,2},{7,7,6,6,6,6,3,3,1},{7,7,6,6,6,6,5,2,1},{7,7,6,6,6,6,5,4,3},{7,7,6,6,6,6,5,5,5},{7,7,6,6,6,6,6,6,5},{7,7,7,5,5,4,3,2,2},{7,7,7,5,5,4,4,2,1},{7,7,7,5,5,5,5,2,2},{7,7,7,5,5,5,5,4,1},{7,7,7,6,4,4,3,3,1},{7,7,7,6,4,4,4,4,3},{7,7,7,6,5,3,3,2,2},{7,7,7,6,5,4,3,2,1},{7,7,7,6,5,4,3,3,3},{7,7,7,6,5,4,4,2,2},{7,7,7,6,5,4,4,4,1},{7,7,7,6,5,5,3,3,1},{7,7,7,6,5,5,4,4,3},{7,7,7,6,5,5,5,2,1},{7,7,7,6,6,4,3,2,2},{7,7,7,6,6,4,4,2,1},{7,7,7,6,6,5,5,2,2},{7,7,7,6,6,5,5,4,1},{7,7,7,6,6,5,5,5,3},{7,7,7,6,6,6,3,2,1},{7,7,7,6,6,6,3,3,3},{7,7,7,6,6,6,4,4,3},{7,7,7,6,6,6,5,4,2},{7,7,7,6,6,6,6,2,2},{7,7,7,6,6,6,6,4,1},{7,7,7,6,6,6,6,6,3},{7,7,7,7,5,4,3,3,1},{7,7,7,7,5,4,4,3,2},{7,7,7,7,5,4,4,4,4},{7,7,7,7,5,5,3,2,1},{7,7,7,7,5,5,3,3,3},{7,7,7,7,5,5,5,4,2},{7,7,7,7,5,5,5,5,3},{7,7,7,7,6,4,3,3,2},{7,7,7,7,6,4,4,4,2},{7,7,7,7,6,6,3,3,1},{7,7,7,7,6,6,5,2,1},{7,7,7,7,6,6,5,4,3},{7,7,7,7,6,6,6,5,5},{7,7,7,7,7,3,3,2,2},{7,7,7,7,7,4,3,2,1},{7,7,7,7,7,4,3,3,3},{7,7,7,7,7,4,4,2,2},{7,7,7,7,7,4,4,4,1},{7,7,7,7,7,5,5,2,2},{7,7,7,7,7,5,5,4,1},{7,7,7,7,7,6,4,4,3},{7,7,7,7,7,6,5,3,1},{7,7,7,7,7,6,5,4,2},{7,7,7,7,7,6,5,5,5},{7,7,7,7,7,6,6,2,2},{7,7,7,7,7,6,6,4,1},{7,7,7,7,7,6,6,6,3},{7,7,7,7,7,7,3,3,1},{7,7,7,7,7,7,5,2,1},{7,7,7,7,7,7,5,4,3},{7,7,7,7,7,7,6,3,2},{7,7,7,7,7,7,6,6,5},{7,7,7,7,7,7,7,2,2},{7,7,7,7,7,7,7,4,1},{7,7,7,7,7,7,7,5,5},{7,7,7,7,7,7,7,7,3}};
		if (loser.count(piles))
			return lose;
		return win;
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
		cout << "Testing MatchNim (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1556586817;
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
		MatchNim _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int piles[] = {1, 1, 1};
				_expected = "Zara";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			case 1:
			{
				int piles[] = {2, 2, 2, 2};
				_expected = "Yvonne";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			case 2:
			{
				int piles[] = {3, 1, 3, 2, 3};
				_expected = "Zara";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			case 3:
			{
				int piles[] = {1, 3, 3, 3, 4, 3};
				_expected = "Yvonne";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			case 4:
			{
				int piles[] = {23, 6, 1, 1, 4, 6};
				_expected = "Yvonne";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			case 5:
			{
				int piles[] = {7, 7, 7, 7, 7, 7, 7, 7, 7};
				_expected = "Yvonne";
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}
			/*case 6:
			{
				int piles[] = ;
				_expected = ;
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int piles[] = ;
				_expected = ;
				_received = _obj.whoWins(vector <int>(piles, piles+sizeof(piles)/sizeof(int))); break;
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
