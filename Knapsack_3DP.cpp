#include<iostream>
using namespace std;

int Knapsack(int* wt, int* val, int W, int n)
{
    int t[n+1][W+1];

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<W+1; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else
            {
                if(wt[i-1]<=j)
                {
                    t[i][j] = max( val[i-1]+ t[i-1][j-wt[i-1]], t[i-1][j]);
                }

                else if(wt[i-1]>j)
                {
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }
    for(int i=0; i<n+1;i++)
    {
        for(int j=0; j<W+1; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
    return t[n][W];
}


int main()
{
    int wt[] = {1,3,4};
    int val[] = {1,4,5};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    int MaxProfit = Knapsack(wt,val,W,n);
    cout<<MaxProfit; 
}

// t matrix
// 0  0  0  0  0  0  0  0  
// 0  1  1  1  1  1  1  1
// 0  1  1  4  5  5  5  5
// 0  1  1  4  5  6  6  9
// Here all for all possible values of n and W, max profit is calculated, even when that value is not needed(in recursive code) in calculation of final value(n=3 and W=7)