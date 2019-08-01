#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'maxShared' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH friends as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */
vector<int> p;
int find(int x) {
  return p[x] < 0 ? x : p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  p[u] = v;
}

int maxShared(int friends_nodes, vector<int> friends_from, vector<int> friends_to, vector<int> friends_weight) {
  int num_edges = friends_from.size();
  vector<tuple<int, int, int>> edges(num_edges);
  for (int i = 0; i < num_edges; ++i) {
    edges[i] = {friends_weight[i], friends_from[i], friends_to[i]};
  }
  vector<vector<int>> interests(friends_nodes+1, vector<int>(friends_nodes+1, 0));
  sort(edges.begin(), edges.end());
  for (int i = 0; i < (int)edges.size(); ) {
    int weight = get<0>(edges[i]);
    p.assign(friends_nodes+1, -1);
    while (i < (int)edges.size() && get<0>(edges[i]) == weight) {
      int u, v;
      tie(ignore, u, v) = edges[i++];
      merge(u, v);
    }
    for (int u = 1; u <= friends_nodes; ++u) {
      for (int v = 1; v <= friends_nodes; ++v) {
        if (u == v) continue;
        interests[u][v] += find(u) == find(v);
      }
    }
  }
  int best = 0, ans = 0;
  for (int u = 1; u <= friends_nodes; ++u) {
    for (int v = u+1; v <= friends_nodes; ++v) {
      if (interests[u][v] > best) {
        best = interests[u][v];
        ans = u * v;
      }
      else if (interests[u][v] == best) {
        ans = max(ans, u * v);
      }
    }
  }
  return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string friends_nodes_edges_temp;
    getline(cin, friends_nodes_edges_temp);

    vector<string> friends_nodes_edges = split(rtrim(friends_nodes_edges_temp));

    int friends_nodes = stoi(friends_nodes_edges[0]);
    int friends_edges = stoi(friends_nodes_edges[1]);

    vector<int> friends_from(friends_edges);
    vector<int> friends_to(friends_edges);
    vector<int> friends_weight(friends_edges);

    for (int i = 0; i < friends_edges; i++) {
        string friends_from_to_weight_temp;
        getline(cin, friends_from_to_weight_temp);

        vector<string> friends_from_to_weight = split(rtrim(friends_from_to_weight_temp));

        int friends_from_temp = stoi(friends_from_to_weight[0]);
        int friends_to_temp = stoi(friends_from_to_weight[1]);
        int friends_weight_temp = stoi(friends_from_to_weight[2]);

        friends_from[i] = friends_from_temp;
        friends_to[i] = friends_to_temp;
        friends_weight[i] = friends_weight_temp;
    }

    int result = maxShared(friends_nodes, friends_from, friends_to, friends_weight);

    fout << result << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
