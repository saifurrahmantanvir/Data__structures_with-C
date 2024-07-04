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
vector<bool> visited(n, false);

bool dfs(int node, int parent = -1) {
  visited[node] = true;

  bool isLoopExists = false;

  for(int child : g[node]) {
    if(visited[child] && child == parent) continue;
    if(visited[child]) return true;

    isLoopExists |= dfs(child, node);
  }

  return isLoopExists;
}

int main() {
  _ios;

  int n, e; readln(n, e);

  for(int i = 0; i < e; i++) {
    int a, b; readln(a, b);

    g[a].push_back(b); g[b].push_back(a);
  }

  bool isLoopExists = false;

  for(int i = 1; i <= n; i++) {
    if(visited[i]) continue;

    if(dfs(i)) {
      isLoopExists = true;
      break;
    }

  }

  cout << isLoopExists << endl;

  return 0;
}