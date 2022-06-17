#include<iostream>
using namespace std;

bool SubsetSum(int* arr, int sum, int n)
{
    int t[n+1][sum+1];
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            t[0][0] = true;
            if(i==0 && j!=0)
            {
                t[i][j] = false;
            }

            else if(j==0 && i!=0)
            {
                t[i][j] = true;
            }
            
            else
            {
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

    return t[n][sum];
}


int main()
{
    int arr[] = {2, 6 ,5};
    int sum = 7;
    int n = sizeof(arr)/sizeof(arr[1]);

    bool result=SubsetSum(arr,sum,n);

    cout<<result;

}