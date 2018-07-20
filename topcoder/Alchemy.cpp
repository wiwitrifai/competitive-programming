#include <bits/stdc++.h>

using namespace std;

const int N = 10000, inf = 1e9 + 7;

bool used[N];
int dist[N], mi[N];

class Alchemy {
public:
	bool can(vector <int> leadOutput, vector <int> goldOutput, long long goal) {
		int n = leadOutput.size();
		vector<pair<int, int> > expe;
		for (int i = 0; i < n; ++i) {
			expe.emplace_back(leadOutput[i], goldOutput[i]);
		}
		sort(expe.begin(), expe.end());
		set<int> zero, one;
		set<int> mulone;
		mulone.insert(0);
		int now = 0;
		for (auto it : expe) {
			if (it.first == 0) {
				zero.insert(it.second);
			}
			else {
				while (now + 1 < it.first) {
					set<int> tmp;
					for (int z : zero)
						for (int m : mulone)
							tmp.insert(z + m);
					mulone.swap(tmp);
					++now;
				}
				for (int m : mulone)
					one.insert(m + it.second);
			}
		}
		one.erase(0);
		if (one.empty())
			return goal < inf && zero.count(goal);
		int mod = *one.begin();
		memset(used, 0, sizeof used);
		fill(dist, dist+mod, inf);
		fill(mi, mi+mod, inf);
		for (int o : one)
			mi[o % mod] = min(mi[o % mod], o);
		dist[0] = 0;
		while (1) {
			int v = -1;
			for (int i = 0; i < mod; ++i) {
				if (used[i]) continue;
				if (v == -1 || dist[i] < dist[v])
					v = i;
			}
			if (v == -1) break;
			used[v] = 1;
			for (int i = 0; i < mod; ++i) {
				int cost = mi[i];
				if (cost >= inf) continue;
				int u = (v + i) % mod;
				dist[u] = min(dist[u], dist[v] + cost);
			}
		}
		for (int x : zero) {
			if (x > goal) continue;
			long long sisa = goal - x;
			if (dist[sisa % mod] >= inf) continue;
			if (dist[sisa % mod] <= sisa) return true;
		}
		return false;
	}
	string leadToGold(vector <int> leadOutput, vector <int> goldOutput, long long goal) {
		return can(leadOutput, goldOutput, goal) ? "Possible" : "Impossible";		
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
		cout << "Testing Alchemy (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1532058930;
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
		Alchemy _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int leadOutput[] = {1,1,1};
				int goldOutput[] = {0,1,2};
				long long goal = 47LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 1:
			{
				int leadOutput[] = {4,0};
				int goldOutput[] = {1,3};
				long long goal = 23LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 2:
			{
				int leadOutput[] = {3,0,0};
				int goldOutput[] = {0,5,7};
				long long goal = 9876543210LL;
				_expected = "Impossible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			case 3:
			{
				int leadOutput[] = {3,0,0};
				int goldOutput[] = {0,5,7};
				long long goal = 123456789LL;
				_expected = "Possible";
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}
			/*case 4:
			{
				int leadOutput[] = ;
				int goldOutput[] = ;
				long long goal = LL;
				_expected = ;
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}*/
			/*case 5:
			{
				int leadOutput[] = ;
				int goldOutput[] = ;
				long long goal = LL;
				_expected = ;
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
			}*/
			/*case 6:
			{
				int leadOutput[] = ;
				int goldOutput[] = ;
				long long goal = LL;
				_expected = ;
				_received = _obj.leadToGold(vector <int>(leadOutput, leadOutput+sizeof(leadOutput)/sizeof(int)), vector <int>(goldOutput, goldOutput+sizeof(goldOutput)/sizeof(int)), goal); break;
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
