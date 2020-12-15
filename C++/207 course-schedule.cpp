#define LIM 100010

class Solution {
public:
    
    int head[LIM], to[2 * LIM], nxt[2 * LIM], eidx;   // 邻接表
    unordered_map<int, int> indegree, vis;   // 入度与是否访问
    
    inline void addEdge(int u, int v) {
        nxt[++eidx] = head[u];
        to[eidx] = v;
        head[u] = eidx;
        indegree[v]++;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& edge: prerequisites) {
            addEdge(edge[0], edge[1]);
        }
        int cnt = 0;
        while(cnt < numCourses) {
            bool flag = true;
            for(size_t i=0; i < numCourses; i++) {
                if(indegree[i] == 0 && !vis[i]) {
                    flag = false;
                    vis[i] = true;
                    cnt++;
                    for(size_t e = head[i]; e; e = nxt[e]) {
                        indegree[to[e]]--;
                    }
                }
            }
            if(flag) return false;
        }
        return true;
    }
};