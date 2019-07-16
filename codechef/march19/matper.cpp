#include <bits/stdc++.h>

using namespace std;

/** Aho-Corasick Dictionary Matching **/
const int NALPHABET = 26;
 
struct Node {
  Node** children, ** go;
  bool leaf;
  char charToParent;
  Node* parent, * suffLink, * dictSuffLink;
  int count, value;
 
  Node(){
    children = new Node*[NALPHABET];
    go = new Node*[NALPHABET];
    for(int i = 0; i < NALPHABET;++i){
      children[i] = go[i] = NULL;
    }
    parent = suffLink = dictSuffLink = NULL;
    leaf = false;
    count = 0;
  }
};
 
Node* createRoot() {
  Node* node = new Node();
  node->suffLink = node;
  return node;
}
 
void addString(Node* node, const string& s, int value =-1) {
  for(int i = 0; i < s.length(); ++i){
    int c = s[i] - 'a';
    if(node->children[c] == NULL){
      Node* n = new Node();
      n->parent = node;
      n->charToParent = s[i];
      node->children[c] = n;
    }
    node = node->children[c];
  }
  node->leaf = true;
  node->count++;
  node->value = value;
}
 
Node* suffLink(Node* node);
Node* dictSuffLink(Node* node);
Node* go(Node* node, char ch);
int calc(Node* node);
 
Node* suffLink(Node* node) {
  if (node->suffLink == NULL){
    if (node->parent->parent == NULL){
      node->suffLink = node->parent;
    } else {
      node->suffLink = go(suffLink(node->parent),node->charToParent);
    }
  }
  return node->suffLink;
}
 
Node* dictSuffLink(Node* node) {
  if(node->dictSuffLink == NULL){
    Node* n = suffLink(node);
    if (node == n){
      node->dictSuffLink = node;
    } else {
      while (!n->leaf && n->parent != NULL){
        n = dictSuffLink(n);
      }
      node->dictSuffLink = n;
    }
  }
  return node->dictSuffLink;
}
 
Node* go(Node* node, char ch) {
  int c = ch -'a';
  if (node->go[c] == NULL){
    if (node->children[c] != NULL) {
      node->go[c]= node->children[c];
    } else {
      node->go[c]= node->parent == NULL? node : go(suffLink(node), ch);
    }
  }
  return node->go[c];
}

int calc(Node* node) {
  if (node->parent == NULL) {
    return 0;
  } else {
    return node->count + calc(dictSuffLink(node));
  }
}

const int N = 1e5 + 5, mod = 1e9 + 7;

char buff[N];
string s;
vector<string> p;
map<int, long long> dp[N];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", buff);
  s = buff;
  unordered_map<string, int> mp;
  vector<int> pos;
  for (int i = 0; i < m; ++i) {
    scanf("%s", buff);
    auto it = mp.find(buff);
    int id = p.size();
    if (it == mp.end()) {
      mp[buff] = p.size();
      p.push_back(buff);
    }
    else
      id = it->second;
    pos.push_back(id);
  }
  Node * root = createRoot();
  for (int i = 0; i < (int)p.size(); ++i) {
    addString(root, p[i], i);
  }
  vector<vector<int> > occ(p.size());
  Node * cur = root;
  for (int i = 0; i < (int)s.size(); ++i) {
    cur = go(cur, s[i]);
    Node * explore = cur->count ? cur : dictSuffLink(cur);
    while (explore->parent != NULL) {
      occ[explore->value].push_back(i);
      explore = dictSuffLink(explore);
    }
  }
  dp[0][0] = 1;
  int nmask = 1 << m;
  for (int mask = 0; mask < nmask; ++mask) {
    for (int i = 0; i < m; ++i) {
      if (mask & (1 << i)) continue;
      int id = pos[i];
      vector<int>::iterator res = occ[id].begin();
      int newmask = mask | (1 << i);
      for (auto it : dp[mask]) {
        res = lower_bound(res, occ[id].end(), it.first + (int)p[id].size() - 1);
        if (res == occ[id].end())
            break;
        dp[newmask][*res + 1]  += it.second;
      }
    }
  }
  long long ans = 0;
  for (auto it : dp[nmask-1]) {
    ans += it.second;
  }
  printf("%lld\n", ans);
  return 0;
}