#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define _ios     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fill(a,b) memset(a, b, sizeof(a))
#define pr       pair<int, int>
#define ft       first
#define sn       second
#define vi       vector<int>
#define vll      vector<ll>
#define pb       push_back
#define endl     "\n"
#define printl(x) for (auto i : x) cout << i << " ";
#define all(x)   x.begin(), x.end()
#define loop(a)  for(int i=0; i<a; i++)
#define test(fn) int t; cin>>t; while(t--) fn();

const int mod =  1e9+7;
template<typename... T>
void readln(T&... args) { ((cin >> args), ...); }
template<typename... T>
void println(T&&... args) { ((cout << args << " "), ...); }
template<class T>
void writeln(const T &t) { cout << t << '\n'; }
template<class T, class...args>
void writeln(const T &t, const args &...rest) {
  cout << t << ' ';
  writeln(rest...);
}
template<class T>
void writeln(const vector<T> &v) {
  for (auto c : v) cout << c << ' ';
  cout << '\n';
}
template<class T, class T_>
void writeln(const vector<T> &v, T_ n) {
  for (T_ i = 1; i <= n; i++) cout << v[i] << ' ';
  cout << '\n';
}
template<class T, class T_>
void writeln(const pair<T, T_>p) { cout << p.first << ' ' << p.second << '\n'; }

/*
  Tree Diameter ✅
  cses.fi/problemset/task/1131 */
const int n = 2e5+10;

vector<int> g[n];
int depth[n], lLeaf, max_depth = 0;

void dfs(int node, int parent = -1) {
  for(int c : g[node]) {
    if(c == parent) continue;
    depth[c] = depth[node] + 1;

    dfs(c, node);
  }


}

int main() {
  _ios;

  int n; readln(n);

  if(n == 1) {
    cout << 0 << endl;
    return 0;
  }

  for(int i = 0; i < n-1; i++) {
    int a, b;
    readln(a, b);

    g[a].push_back(b); g[b].push_back(a);
  }

  dfs(1);

  int lLeaf, max_depth = 0;

  for(int i = 1; i <= n; i++) {
    if(max_depth < depth[i]) {
      lLeaf = i;
      max_depth = depth[i];

    }
    depth[i] = 0;

  }

  max_depth = 0;
  dfs(lLeaf);

  for(int i = 1; i <= n; i++) {
    if(max_depth < depth[i]) max_depth = depth[i];

  }

  writeln(max_depth);

  return 0;
}