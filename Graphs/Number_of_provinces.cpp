class Solution {
private:
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjls[V];
        for(int i = 0 ; i < V ; i++)
        {
            for(int j = 0 ; j < V ; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int vis[V];
        for(int k = 0 ; k < V ; k++)
        {
            vis[k] =0;
        }

        int cnt = 0 ; 
        for(int i = 0 ; i < V ; i++)
        {
            if(!vis[i])
            {
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};