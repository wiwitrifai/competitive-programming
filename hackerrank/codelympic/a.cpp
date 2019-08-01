#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'predictAnswer' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY stockData
 *  2. INTEGER_ARRAY queries
 */

vector<int> predictAnswer(vector<int> stockData, vector<int> queries) {
    int n = stockData.size();
    int q = queries.size();
    vector<int> answer(q, -1);
    vector<pair<int, int>> sortedQueries(q);
    for (int i = 0; i < q; ++i)
        sortedQueries[i] = {queries[i], i};
    sort(sortedQueries.begin(), sortedQueries.end());
    vector<int> increasingData;
    for (int i = 0, j = 0; i < q; ++i) {
        int now = sortedQueries[i].second;
        int day = queries[now];
        while (j < n && j < day) {
            while (!increasingData.empty() && stockData[increasingData.back()] >= stockData[j]) {
                increasingData.pop_back();
            }
            increasingData.emplace_back(j);
            ++j;
        }
        if (day > n) {
            continue;
        }
        int pos = lower_bound(increasingData.begin(), increasingData.end(), day-1, [&](int dayA, int dayB) {
            return stockData[dayA] < stockData[dayB];
        }) - increasingData.begin() - 1;

        if (pos >= 0) {
            assert(stockData[increasingData[pos]] < stockData[day-1]);
        }
        if (pos + 1 < increasingData.size()) {
            assert(stockData[increasingData[pos+1]] >= stockData[day-1]);
        }
        if (pos >= 0)
            answer[now] = increasingData[pos] + 1;
    }
    vector<int> decreasingData;
    for (int i = q-1, j = n-1; i >= 0; --i) {
        int now = sortedQueries[i].second;
        int day = queries[now];
        while (j >= 0 && j >= queries[now]) {
            while (!decreasingData.empty() && stockData[decreasingData.back()] >= stockData[j]) {
                decreasingData.pop_back();
            }
            decreasingData.emplace_back(j);
            --j;
        }
        if (day > n) {
            continue;
        }
        int pos = lower_bound(decreasingData.begin(), decreasingData.end(), day-1, [&](int dayA, int dayB) {
            return stockData[dayA] < stockData[dayB];
        }) - decreasingData.begin() - 1;
        if (pos >= 0) {
            assert(stockData[decreasingData[pos]] < stockData[day-1]);
        }
        if (pos + 1 < decreasingData.size()) {
            assert(stockData[decreasingData[pos+1]] >= stockData[day-1]);
        }
        int nearest = pos >= 0 ? decreasingData[pos]+1 : -1;
        if (now == 11) {
            for (int x : decreasingData)
                cerr << x << " ";
            cerr << endl;
        }
        cerr << now << " " << nearest << endl;
        if (answer[now] == -1 || (nearest >= 0 && abs(day - nearest) < abs(day - answer[now])))
            answer[now] = nearest;
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string stockData_count_temp;
    getline(cin, stockData_count_temp);

    int stockData_count = stoi(ltrim(rtrim(stockData_count_temp)));

    vector<int> stockData(stockData_count);

    for (int i = 0; i < stockData_count; i++) {
        string stockData_item_temp;
        getline(cin, stockData_item_temp);

        int stockData_item = stoi(ltrim(rtrim(stockData_item_temp)));

        stockData[i] = stockData_item;
    }

    string queries_count_temp;
    getline(cin, queries_count_temp);

    int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        string queries_item_temp;
        getline(cin, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = predictAnswer(stockData, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
