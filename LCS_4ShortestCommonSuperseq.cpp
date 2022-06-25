#include<iostream>
using namespace std;

int LCS(string x, string y, int m, int n)
{
    int t[m+1][n+1];
    
    for(int i=0; i<m+1; i++)
    {
        for(int j=0; j<n+1; j++)
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
                }
                else
                {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
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
    return m+n -t[m][n];
}

int main()
{
    string x = "abcd";
    string y = "abed";
    int m = x.length();
    int n = y.length();
    int length = LCS(x,y,m,n);
    cout<<"Shortest Common Supersequence "<<length<<endl;

}