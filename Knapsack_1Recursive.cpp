#include<iostream>
using namespace std;

int Knapsack(int wt[], int val[], int W, int n)
{
    cout<<"No of elements in array "<<n<<endl;
    cout<<"Capacity of bag "<<W<<endl;

    cout<<"Weight array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<wt[i]<<" ";
    }
    cout<<endl;
    cout<<"Value array"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<val[i]<<" ";
    }
    cout<<endl;

    int result, val1, val2;

    if(n==0 || W==0)
    {
        return 0;
    }
    if(wt[n-1]<=W)
    {
        val1 = val[n-1] + Knapsack(wt,val,W-wt[n-1],n-1);
        val2 = Knapsack(wt,val,W,n-1);
        cout<<"val1 "<<val1<<" val2 "<<val2<<endl;
        result = max(val1,val2);
        cout<<"val returned from second if "<<result<<endl;
        return(result);
    }
    else if(wt[n-1]>W)
    {
        result = Knapsack(wt,val,W,n-1);
        cout<<"val returned from third if "<<result<<endl;
        return(result);
    }
    
    return 0;
}

int main()
{
    int wt[] = {1,3,4};
    int val[] = {1,4,5};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    int MaxProfit;
    MaxProfit = Knapsack(wt,val,W,n);
    cout<<MaxProfit;
}

// Time Complexity is O(2^n)
// Space Complexity is O(1)