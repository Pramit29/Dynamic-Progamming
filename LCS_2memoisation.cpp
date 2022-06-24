#include<iostream>
using namespace std;

int t[10][10];

int LCS(string x, string y, int m, int n)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    if(t[m][n]!=-1)
    {
        return t[m][n];
    }
    if(x[m-1]==y[n-1])
    {
        t[m][n] = 1+LCS(x,y,m-1,n-1);
        return t[m][n];
    }
    else{
        t[m][n] = max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
        return t[m][n];
    }

    return t[m][n];

}

int main()
{
    fill(*t,*t+ 10*10, -1);
    string x = "abcd";
    string y = "abed";
    int m = x.length();
    int n = y.length();
    int length = LCS(x,y,m,n);
    cout<<"Length of string "<<length<<endl;

    for(int i=0; i<m+1;i++)
    {
        for(int j=0; j<n+1; j++)
        {
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
}

// t matrix
// -1  -1  -1  -1  -1
// -1   1   1   1  -1 
// -1   1   2   2  -1
// -1   1   2   2  -1
// -1  -1  -1  -1   3