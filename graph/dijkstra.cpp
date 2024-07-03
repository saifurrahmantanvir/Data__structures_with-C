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

const ll n = 1e5+10;
const ll inf = 1e18+10;

vector<pair<ll, ll>> g[n];

vector<ll> dist(n, inf);
vector<bool> visited(n, false);

// Time complexity O(V+Elog(V))
void dijkstra(ll source) {
  set<pair<ll, ll>> s;

  s.insert({ 0, source });
  dist[source] = 0;

  while(s.size()) {
    pair<ll, ll> p = *s.begin();
    ll _vdist = p.first, v = p.second;
    s.erase(s.begin());

    if(visited[v]) continue;
    visited[v] = true;

    for(auto child : g[v]) {
      ll c = child.first, cdist = child.second;

      /* if (dist[c] > dist[v] + cdist) {
        dist[c] = dist[v] + cdist;

        s.insert({ dist[c], c });
      } */

      if (dist[c] > _vdist + cdist) {
        dist[c] = _vdist + cdist;

        s.insert({ dist[c], c });
      }

    }


  }


}

void solve() {
  int n, m; readln(n, m);

  for(int i = 0; i < m; i++) {
    ll x, y, w;
    readln(x, y, w);

    g[x].push_back({ y, w });
  }

  dijkstra(1);

  for(int i = 1; i <= n; i++) cout << dist[i] << " ";
}

int main()
{
  _ios;

  solve();



  return 0;
}