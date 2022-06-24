#include<iostream>
#include<limits.h>
using namespace std;

int UKnapsack(int coin[], int sum, int n)
{
    int t[n+1][sum+1];

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0 && j==0)
            {
                t[i][j] = 0;
            }
            else if(i==0)
            {
                t[i][j] = INT_MAX -1;

            }
            else if(j==0)
            {
                t[i][j] = 0;
            }
            else
            {
                if(coin[i-1]<=j)
                {
                    int val1 = 1+t[i][j-coin[i-1]];
                    int val2 = t[i-1][j];
                    cout<<"val1 "<<val1<<" val2 "<<val2<<endl;
                    
                    t[i][j] = min(val1, val2);
                    cout<<"t[i="<<i<<"][j="<<j<<"] "<<t[i][j]<<endl;
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
    }

    for(int i=0; i<n+1;i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }

    return t[n][sum];
}

int main()
{
    int coin[] = {1,2,3};
    int sum = 8;
    int n= sizeof(coin)/sizeof(coin[0]);
    int mincoins = UKnapsack(coin, sum , n);
    cout<<"min coins are "<<mincoins<<endl;
}