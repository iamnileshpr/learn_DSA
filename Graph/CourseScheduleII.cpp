
//Approach-2 (Using DFS)
class Solution {
public:
    bool hasCycle = false;
    void DFS(unordered_map<int, vector<int>> &adj, int u, vector<bool>& visited, stack<int>& st, vector<bool>& inRecursion) {
	    visited[u] = true;
        inRecursion[u] = true;
	    
	    
	    //pehle mere ('u' ke node ke ) bachho ko daalo
	    for(int &v : adj[u]) {
            if(inRecursion[v] == true) {
                hasCycle = true;
                return;
            }
            
	        if(!visited[v])
	            DFS(adj, v, visited, st, inRecursion);
	    }
	    
	    
	    //ab mujhe daalo stack me
	    st.push(u);
        inRecursion[u] = false;
	    
	}
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(numCourses, false);
        vector<bool> inRecursion(numCourses, false);
        hasCycle = false;
        
        stack<int> st;
        
        for(auto &vec : prerequisites) {
            int a = vec[0];
            int b = vec[1];
            
            //b--->a
            adj[b].push_back(a);
        }
        
        for(int i = 0; i<numCourses; i++) {
            if(!visited[i])
                DFS(adj, i, visited, st, inRecursion);
        }
        
        vector<int> result;
        
        if(hasCycle)
            return {};
        
	    while(!st.empty()) {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
    }
};