//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
       void quickSort(int v[], int start, int end)
    {
        // code here
        if(start>=end) return;

    int ind = partition(v,start,end);
    quickSort(v,ind+1,end);
    quickSort(v,start,ind-1);
    }
    
    public:
    int partition (int v[], int start, int end)
    {
       // Your code here
        int pi=start;
    for(int j=start ; j<end ; j++){
        if(v[j]<v[end]){
            int temp=v[pi];
            v[pi]=v[j];
            v[j]=temp;
            pi++;
        }
    }
    int temp=v[pi];
    v[pi]=v[end];
    v[end]=temp;
    return pi;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends