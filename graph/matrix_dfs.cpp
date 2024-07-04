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
  Counting Rooms ✅
  cses.fi/problemset/task/1192 */
void dfs(int i, int j, char dot, vector<vector<char>> &g) {
  int n = g.size();
  int m = g[0].size();

  if(i < 0 || j < 0) return;
  if(i >= n || j >= m) return;
  if(g[i][j] != dot) return;

  g[i][j] = 1;

  dfs(i-1, j, dot, g);
  dfs(i+1, j, dot, g);
  dfs(i, j-1, dot, g);
  dfs(i, j+1, dot, g);
}

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<char>> g(n, vector<char>(m, '.'));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) cin >> g[i][j];
  }

  int cnt = 0;
  char dot = '.';

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(g[i][j] == dot) {
        dfs(i, j, dot, g);
        cnt++;
      }

    }


  }

  writeln(cnt);
}

int main() {
  _ios;

  solve();




  return 0;
}