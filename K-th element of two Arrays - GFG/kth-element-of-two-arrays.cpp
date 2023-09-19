//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n1, int n2, int k)
    {
        if(n1>n2) return kthElement(nums2,nums1,n2,n1,k);
        int low = max(k-n2,0) , high = min(k,n1);
        int n = n1+n2;
        int symmetry = k;

        while(low <= high){
            int mid1 = low + (high-low)/2;
            int mid2 = symmetry - mid1;
            
            int l1 = ((mid1-1) >= 0)? nums1[mid1-1]:INT_MIN;
            int l2 = ((mid2-1) >= 0)? nums2[mid2-1]:INT_MIN;
            int r1 = (mid1<n1)? nums1[mid1]:INT_MAX;
            int r2 = (mid2<n2)? nums2[mid2]:INT_MAX;
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1,l2);
            }
            else if(l1 > r2){
                high = mid1-1;
            }
            else{
                low = mid1+1;
            }
        }
    return 0;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends