#include<iostream>
using namespace std;

int LCS(string x, string y, int m, int n)
{
    int t[m+1][n+1];
    int maxVal=0;

    for(int i=0; i<m+1; i++)
    {
        for(int j=0 ; j<n+1 ; j++)
        {
            if(i==0 || j==0)
            {
                t[i][j] = 0;
            }
            else
            {
                if(x[i-1]==y[j-1])
                {
                    t[i][j] = 1 + t[i-1][j-1];
                    maxVal = max(t[i][j], maxVal);
                    
                }
                else
                {
                    t[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<m+1;i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
    return maxVal;
}

int main()
{
    string x = "abcdef";
    string y = "abdefl";
    int m = x.length();
    int n = y.length();
    int length = LCS(x,y,m,n);
    cout<<"Length "<<length<<endl;
}

// t matrix
// 0  0  0  0  0  0  0  
// 0  1  0  0  0  0  0
// 0  0  2  0  0  0  0
// 0  0  0  0  0  0  0
// 0  0  0  1  0  0  0
// 0  0  0  0  2  0  0
// 0  0  0  0  0  3  0
// Length 3