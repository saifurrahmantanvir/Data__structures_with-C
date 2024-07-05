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
#define test(fn) int t; cin >> t; while(t--) fn();
#define loop2d(n, m) for(int i=0; i<n; i++) for(int j=0; j<m; j++)

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
const int inf = 1e9+10;

int dist[n][n];

void solve() {
  loop2d(n, n) {
  if(i == j) {
    dist[i][j] = 0;

  }
  else dist[i][j] = inf;
  }

  int n, m; readln(n, m);

  for(int i = 0; i < m; i++) {
    int x, y, w; readln(x, y, w);
    dist[x][y] = w;
  }

  for(int k = 1; k <= n; k++) {
  for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) {
  if(dist[i][k] != inf && dist[k][j] != inf) {
    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

  }
  }
  }
  }

  for(int i = 1; i <= n; i++) { for(int j = 1; j <= n; j++) {
  if(dist[i][j] == inf) {
    cout << "I ";

  }
  else cout << dist[i][j] << " ";
  }
  cout << endl;
  }



}

int main()
{
  _ios;

  solve();



  return 0;
}