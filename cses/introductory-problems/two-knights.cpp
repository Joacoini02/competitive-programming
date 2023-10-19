/*   AUTHOR: Estufa en Piloto   */
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DBG(x) cerr << #x << " = " << (x) << endl
#define RAYA cerr << "===============================" << endl
#else
#define DBG(x)
#define RAYA
#endif

typedef long long ll;
typedef vector<ll> vi; typedef pair<ll,ll> ii;
typedef vector<ii> vii; typedef vector<bool> vb;
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define forr(i, a, b) for(ll i = (a); i < (ll) (b); i++)
#define forn(i, n) forr(i, 0, n)
#define SZ(x) int((x).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define esta(x,c) ((c).find(x) != (c).end())
const int INF = 1<<30; // const ll INF = (1LL<<60);
const int MOD = 1e9+7;  // const int MOD = 998244353;
const int MAXN  = 2e5+5;

int main(){  
  FIN;
  
  vector<ll> f(MAXN);
  f[0] = 1;
  f[1] = 1;
  forr(i,2,MAXN) f[i] = i*f[i-1];

  ll n; cin >> n;
  
  vector<ll> p(MAXN);
  p[3] = 8;
  p[4] = 24;
  
  forr(k,5,(n+1)) {
    ll news = k*k - (k-1)*(k-1);
    p[k] = p[k-1] + 16 + (news-7)*4 - 2;
    if (k >= 5) p[k] += 2;
    DBG(p[k]);
  }
  
  if (n >= 1) cout << "0\n"; 
  if (n >= 2) cout << "6\n";
  forr(i,3,(n+1)) {
    ll tot = ((i*i-1)*i*i)/2;
    cout << tot - p[i] << "\n";
  }

  return 0;
}
