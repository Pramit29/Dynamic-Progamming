#include<iostream>
using namespace std;

int LCS(string x, string y, int m, int n)
{
    if(n==0 || m==0)
    {
        return 0;
    }
    if(x[m-1]==y[n-1])
    {
        return 1 + LCS(x,y,m-1,n-1);
    }

    else
    {
        return max(LCS(x,y,m-1,n),LCS(x,y,m,n-1));
    }

}

int main()
{
    string x = "abcd";
    string y = "abed";

    int m = x.length();
    int n = y.length();
    int length = LCS(x,y,m,n);
    cout<<"Length of LCS "<<length<<endl;
}