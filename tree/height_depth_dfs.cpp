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

const int n = 1e3+10;

vector<int> g[n];
int depth[n], height[n];

void dfs(int node, int parent = 0) {

  for(int child : g[node]) {
    if(child == parent) continue;

    depth[child] = depth[node] + 1;
    dfs(child, node);

    height[node] = max(height[node], height[child] + 1);
  }


}

int main() {
  _ios;

  int n; readln(n);

  for(int i = 0; i < n-1; i++) {
    int a, b;
    readln(a, b);

    g[a].push_back(b); g[b].push_back(a);
  }

  dfs(1);

  for(int i = 1; i <= n; i++) {
    cout << "DEpTh- " << depth[i] << ", HEiGhT- " << height[i] << endl;
  }

  return 0;
}