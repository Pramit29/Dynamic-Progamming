#include<iostream>
using namespace std;

int Knapsack(int arr[], int sum, int n)
{
    int t[n+1][sum+1];

    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            t[0][0] = true;
            if(i==0 && j!=0)
            {
                t[i][j]= false;
            }
            else if(j==0 && i!=0)
            {
                t[i][j] = true;
            }

            else{

                if(arr[i-1]<=j)
                {
                    t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
                }
                else if(arr[i-1]>j)
                {
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


    for(int j=sum/2; j>=0; j--)
    {
        if(t[n][j]==true)
        {
            return(sum-2*j);
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 6 ,5};
    int sum=0;
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
    }
    cout<<sum/2<<endl;
    int minDiff = Knapsack(arr,sum,n);
    cout<<"Min difference is "<<minDiff<<endl;
}