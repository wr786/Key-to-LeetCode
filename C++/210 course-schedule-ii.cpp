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

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& edge: prerequisites) {
            addEdge(edge[1], edge[0]);
        }
        vector<int> ret;
        int cnt = 0;
        queue<int> q;
        for(size_t i=0; i<numCourses; i++)
            if(indegree[i] == 0) q.push(i);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            ret.push_back(u); cnt++;
            for(auto e=head[u]; e; e=nxt[e]) {
                indegree[to[e]]--;
                if(indegree[to[e]] == 0)    
                    q.push(to[e]);
            }
        }
        if(cnt < numCourses) return {};
        return ret;
    }
};