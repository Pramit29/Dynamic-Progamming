#include<iostream>
using namespace std;

int LCS(string x, string y, int m, int n, int count)
{
    cout<<"X length "<<m<<endl;
    cout<<"y length "<<n<<endl;
    cout<<"Count of same letters in continuity "<<count<<endl;

    if(n==0 || m==0)
    {
        cout<<"string empty "<<endl;
        return count;
    }

    if(x[m-1]==y[n-1])
    {
        count++;
        cout<<"Count after the letter matched "<<count<<endl;
        return LCS(x,y, m-1, n-1,count);
    }
    else
    {
        int l1 = LCS(x,y,m-1,n,0);
        int l2 = LCS(x,y,m,n-1,0);
        cout<<"length left side "<<l1<<"   length right side "<<l2<<endl;
        cout<<"count previous "<<count<<endl;
        cout<<"max length "<<max(count, max(l1,l2))<<endl;
        return max(count, max(l1,l2));

    }
}

int main()
{
    string x = "abdfl";
    string y = "abedfl";
    int m = x.length();
    int n = y.length();
    int length = LCS(x,y,m,n,0);
    cout<<"Length "<<length<<endl;
}