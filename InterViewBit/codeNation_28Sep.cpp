// cities question
class Edge {
    public:
    int v, w;
    
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w) {
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

int getAllCost(vector<vector<Edge>> &graph, vector<int> &A, int idx, int cIdx, int vCost, vector<bool> &visited, vector<int> &cost) {
    if(cost[cIdx] != 0) {
        return cost[cIdx];
    }
    
    if(visited[idx]) {
        return 1e8;
    }
    
    visited[idx] = true;
    
    for(Edge e: graph[idx]) {
        int newCost = 2 * e.w + A[e.v - 1] + vCost;
        if(newCost < A[cIdx]) {
            A[cIdx] = newCost;
        }
        int rAns = getAllCost(graph, A, e.v, cIdx, vCost + 2 * e.w, visited, cost);
        
        A[cIdx] = min(A[cIdx], rAns);
    }
    
    return cost[cIdx] = A[cIdx];
}

vector<int> Solution::solve(vector<int> &A, vector<vector<int> > &B) {
    int cities = A.size();
    vector<vector<Edge>> graph(cities + 1, vector<Edge>());
    
    for(int i = 0; i < B.size(); i++) {
        addEdge(graph, B[i][0], B[i][1], B[i][2]);
    }
    
    vector<int> cost(cities + 1, 0);
    for(int i = 1; i < cities + 1; i++) {
        vector<bool> visited(cities + 1, false);
        getAllCost(graph, A, i, i - 1, 0, visited, cost);
    }
    
    return A;
}
