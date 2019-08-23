#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long inf = 1e18;

long long dp[N];

class SteelMill {
public:
	long long cheapest(int goal, vector <int> shipmentCost, vector <int> shipmentSize, vector <int> costPerKg) {
		int n = shipmentSize.size();
		vector<int> ids(n);
		iota(ids.begin(), ids.end(), 0);
		sort(ids.begin(), ids.end(), [&](int l, int r) {
			return costPerKg[l] < costPerKg[r];
		});
		fill(dp+1, dp+goal+1, inf);
		dp[0] = 0;
		long long ans = inf;
		for (int x : ids) {
			int cost = shipmentCost[x];
			int sz = shipmentSize[x];
			int kg = costPerKg[x];
			for (int i = max(goal-sz, 0); i <= goal; ++i) {
				if (dp[i] >= inf) continue;
				ans = min(ans, dp[i] + cost + (long long)(goal - i) * kg);
			}
			int til = goal - sz;
			long long tot = cost + 1LL * sz * kg;
			for (int i = til; i >= 0; --i) {
				if (dp[i] >= inf) continue;
				dp[i+sz] = min(dp[i+sz], dp[i] + tot);
			}
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
		cout << "Testing SteelMill (800.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1566574885;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 800.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		SteelMill _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int goal = 30;
				int shipmentCost[] = {100, 200, 300};
				int shipmentSize[] = {10, 10, 10};
				int costPerKg[] = {1, 2, 3};
				_expected = 660LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}
			case 1:
			{
				int goal = 20;
				int shipmentCost[] = {1234567, 50, 50};
				int shipmentSize[] = {20, 11, 13};
				int costPerKg[] = {1, 12345, 23456};
				_expected = 346999LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}
			case 2:
			{
				int goal = 20;
				int shipmentCost[] = {1234567, 50, 50};
				int shipmentSize[] = {20, 11, 13};
				int costPerKg[] = {1, 123456789, 234567890};
				_expected = 1234587LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}
			case 3:
			{
				int goal = 1000000;
				int shipmentCost[] = {1000000000};
				int shipmentSize[] = {1000000};
				int costPerKg[] = {1000000000};
				_expected = 1000001000000000LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}
			/*case 4:
			{
				int goal = ;
				int shipmentCost[] = ;
				int shipmentSize[] = ;
				int costPerKg[] = ;
				_expected = LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int goal = ;
				int shipmentCost[] = ;
				int shipmentSize[] = ;
				int costPerKg[] = ;
				_expected = LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int goal = ;
				int shipmentCost[] = ;
				int shipmentSize[] = ;
				int costPerKg[] = ;
				_expected = LL;
				_received = _obj.cheapest(goal, vector <int>(shipmentCost, shipmentCost+sizeof(shipmentCost)/sizeof(int)), vector <int>(shipmentSize, shipmentSize+sizeof(shipmentSize)/sizeof(int)), vector <int>(costPerKg, costPerKg+sizeof(costPerKg)/sizeof(int))); break;
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
