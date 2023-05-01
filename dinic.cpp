#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T> class Dinic {
    public:
    struct edge {
        int v, rev;
        T c;
    };
    int n;
    vector <vector <edge> > ad;
    vector <int> lvl, ptr;
    Dinic(int n) {
        this->n = n;
        ad.resize(n);
    }
    void addEdge (int x, int y, T c) {
        ad[x].push_back({y, (int) ad[y].size(), c});
        ad[y].push_back({x, (int) ad[x].size() - 1, 0});
    }
    bool bfs (int s, int t) {
        lvl = ptr = vector <int> (n, 0);
        lvl[s] = 1;
        queue <int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto [v, rev, c]: ad[u]) {
                if (!lvl[v] && c) {
                    lvl[v] = lvl[u] + 1;
                    q.push(v);
                    if (v == t) return 1;
                }
            }
        }
        return 0;
    }
    T dfs (int u, int t, T flow) {
        if (u == t) return flow;
        for (int& i = ptr[u]; i < (int) ad[u].size(); i++) {
            auto& [v, rev, c] = ad[u][i];
            if (lvl[v] != lvl[u] + 1 || !c) continue;
            if (T f = dfs(v, t, min(flow, c))) {
                c-=f;
                ad[v][rev].c+=f;
                return f;
            }
        }
        return 0;
    }
    T maxFlow (int s, int t) {
        T rs = 0;
        while (bfs(s, t)) {
            while (T k = dfs(s, t, 1e9)) rs+=k;
        }
        return rs;
    }
};

int main(){
    
    return 0;
}
