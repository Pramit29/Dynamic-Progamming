#include<iostream>
#include<algorithm>
using namespace std;

int t[10][10];

int UKnapsack(int wt[], int val[], int W, int n)
{
    
    if(n==0 || W==0)
    {
        return 0;
    }
    else
    {
        if(t[n][W]!=-1)
        {
            return t[n][W];
        }
        else
        {
            if(wt[n-1]<=W)
            {
                t[n][W] = max(val[n-1]+UKnapsack(wt,val,W-wt[n-1],n), UKnapsack(wt,val,W,n-1));
                return t[n][W];
            }
            else if(wt[n-1]>W)
            {
                t[n][W] = UKnapsack(wt,val,W,n-1);
                return t[n][W];
            }
        }
    }
    return 0;
}

int main()
{
    fill(*t,*t+ 10*10, -1);
    int wt[] = {1,3,4};
    int val[] = {1,4,5};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[1]);
    int max_profit = UKnapsack(wt,val,W,n);
    cout<<"max profit "<<max_profit<<endl;
    for(int i=0; i<n+1;i++)
    {
        for(int j=0; j<W+1; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }

}

// t matrix
// -1  -1  -1  -1  -1  -1  -1  -1
// -1   1   2   3   4   5   6   7
// -1   1  -1   4   5  -1  -1   9  
// -1  -1  -1   4  -1  -1  -1   9
// More values are computed in case of unbounded Knapsack as compared to 0/1 Knapsack t matrix