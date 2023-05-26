//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    long long int cnt = 0;
    
    void merge(long long arr[],int low,int mid,int high)
    {
        vector<long long> temp;
        int i = low;
        int j = mid +1;
        
        while(i<=mid && j<=high)
        {
            if(arr[i] <= arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                cnt += (mid-i+1);
                j++;
                
            }
        }
        
        for(;i<=mid;i++)
        {
            temp.push_back(arr[i]);
        }
        for(;j<=high;j++)
        {
            temp.push_back(arr[j]);
        }
        
        for(int i=low;i<=high;i++)
        {
            arr[i] = temp[i-low];
        }
    }
    
    void mergeSort(long long arr[],int low,int high)
    {
        if(low>=high)return;
        int mid = (low + high)/2;
        
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        mergeSort(arr,0,N-1);
        
        return cnt;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends