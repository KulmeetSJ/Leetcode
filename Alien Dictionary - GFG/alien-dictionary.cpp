//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define pb push_back
class Solution{
    private:
    vector<int> topoSort(vector<vector<int>>& adj,int K){
        vector<int> inDegree(K);
        
        for(int i=0;i<K;i++){
            for(auto it:adj[i]){
                inDegree[it]++;
            }
        }
        queue<int> q;
        
        for(int i=0;i<K;i++){
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.pb(node);
            
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        
    return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int j=0;
            int minLen = min(s1.size(),s2.size());
            // while(j<minLen && s1[j] == s2[j]) j++;
            for(int j=0;j<minLen;j++){
                if(s1[j] != s2[j]){
                    adj[s1[j]-'a'].pb(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int> topoOrder = topoSort(adj,K);
        
        string ans = "";
        
        for(int i=0;i<topoOrder.size();i++){
            ans += topoOrder[i]+'a';
        }
        
    return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends