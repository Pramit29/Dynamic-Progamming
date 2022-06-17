#include<iostream>
#include<algorithm>
using namespace std;

int t[4][8];

int knapsack(int* wt, int * val, int W, int n)
{
      if(n==0 || W==0)
      {
        return 0;
      }
      
      if(t[n][W]!=-1)
      {
        return t[n][W];
      }
      else
      {
        if(wt[n-1]<=W)
        {
            t[n][W] = max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1), knapsack(wt,val,W,n-1));
            return t[n][W];
        }
        else if(wt[n-1]>W)
        {
            t[n][W] = knapsack(wt,val,W,n-1);
            return t[n][W];
        }
      }

      return 0;
}

int main()
{
    fill(*t,*t+ 4*8, -1);
    int wt[] = {1,3,4};
    int val[] = {1,4,5};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[1]);
    int max_profit = knapsack(wt,val,W,n);
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
// -1  -1  -1   1   1  -1  -1   1
// -1  -1  -1   4  -1  -1  -1   5
// -1  -1  -1  -1  -1  -1  -1   9
// Here all values are not computed and all possible combinations are not calculated