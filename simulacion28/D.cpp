//~ #pragma GCC optimization("O3")
#include <bits/stdc++.h> 
using namespace std; 

typedef int ll;
typedef vector<ll> vi; 
typedef vector<bool> vb; 
#define FIN ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define forr(i,a,b) for (ll i = (ll)a; i < (ll)b; i++) 
#define forn(i,n) forr(i,0,n)
#define DBG(x) cerr << #x << " = " << x << endl
#define RAYA cerr << "==============================\n"
#define pb push_back
#define SZ(x) int((x).size())
const int MAXN = 1e5;
typedef int tipo; 
const int NEUT = 0;  // TODO: 

struct node {
  vi ans; 
  tipo l, r, lazy = 0; 
  bool upd = false; 
  node () { 
    ans = vi(64, 0); 
    lazy = 0; 
    upd = false; 
    l = r = -1; 
  }
  node (tipo val, int pos) {
    ans = vi(64, 0); 
    if (val != -1) ans[val] = 1; 
    l = r = pos; 
  }
  void set_lazy(tipo x) { lazy += x; if(lazy>=64) lazy-=64; upd = true; }
}; 

struct segtree_lazy {
  #define l(x) int(x<<1) 
  #define r(x) int(x<<1|1) 

  vector<node> t; int tam; 

  node op(node a, node b) {
    node aux; 
    aux.ans = vector <int>(64,0); 
    forn(i,64) aux.ans[i] = a.ans[i] + b.ans[i]; 
    aux.l = a.l; aux.r = b.r; 
    return aux; 
  }

  void push(int p) {
    node &cur = t[p]; 
    if (cur.upd == true) {
      // shift
      vi nuevo(64,0); 
      for(int i=0; i<64; i+=2) {
	int k=i +cur.lazy, k2=i+1+cur.lazy;
	if(k>=64) k-=64;
	if(k2>=64) k2-=64;
        nuevo[k] = cur.ans[i];
	nuevo[k2] = cur.ans[i+1]; 
      }
      cur.ans = nuevo; 

      // paso a los hijos
      if (cur.l < cur.r) {
        t[l(p)].set_lazy(cur.lazy); 
        t[r(p)].set_lazy(cur.lazy);
      }

      // reset del lazy
      cur.lazy = 0; cur.upd = false; 
    }
  }

  node query(int l, int r, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return node(); 
    if (l <= cur.l and cur.r <= r) return cur; 
    return op(query(l,r,l(p)), query(l,r,r(p))); 
  }

  void update(int l, int r, int p = 1) {
    push(p); node &cur = t[p]; 
    if (l > cur.r or r < cur.l) return; 
    if (l <= cur.l and cur.r <= r) {
      cur.set_lazy(1); push(p); return; 
    }
    update(l, r, l(p)); update(l, r, r(p)); 
    cur = op(t[l(p)], t[r(p)]); 
  }

  void build(vector<tipo> &v, int n) {
    tam = sizeof(int) *8 - __builtin_clz(n); tam = 1<<tam; 
    t.resize(2*tam); v.resize(tam); 
    forn(i,tam) t[tam+i] = node(v[i], i); 
    for(int i = tam -1; i > 0; i--) t[i] = op(t[l(i)], t[r(i)]); 
  }
}; 

vi run, izq(MAXN), der(MAXN), color(MAXN), base; 
vb visto(MAXN); 
vector<vi> g(MAXN); 
void dfs(int v) {
  visto[v] = true; 
  izq[v] = SZ(run); 
  run.pb(v);
  base.pb(color[v]);
  for (auto u : g[v]) if (visto[u] == false) dfs(u); 
  der[v] = SZ(run)-1;
}

int main() {
  FIN; 

  int n, q; cin >> n >> q; 
  forn(i,n) cin >> color[i]; 

  forn(_,n-1) {
    int a, b; cin >> a >> b; 
    g[--a].pb(--b); 
    g[b].pb(a); 
  }
  dfs(0); 

  // init segtree-lazy
  segtree_lazy tree; 
  tree.build(base,n); 

  forn(_,q) {
    int op; cin >> op; 
    if (op == 1) {
      int v; cin >> v; 
      v--; 
      tree.update(izq[v], der[v]); 
    } else {
      int v, c; cin >> v >> c; 
      v--; 
      auto no = tree.query(izq[v], der[v]); 
      cout << no.ans[c] << "\n"; 
    }
  }


  return 0; 
}
