#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int LCS(string x, string y, int m, int n, int count)
{
    map<vector<int>, int> memo;
    int maxVal =0;
    vector<int> key{m,n,count};
    
    if(n==0 || m==0)
    {
        return count;
    }

    if(memo.find(key)!=memo.end())
    {
        auto it = memo.find(key);
        return it->second;
    }

    if(x[m-1] == y[n-1])
    {
        count++;
        int result = LCS(x,y,m-1,n-1,count);
        memo.insert({{m,n,count},result});
        return result;
    }
    else
    {
        int result = max(count,max(LCS(x,y,m-1,n,0),LCS(x,y,m,n-1,0)));
        memo.insert({{m,n,count},result});
        return result;
    }

}

int main()
{
    string x = "abcdls";
    string y = "abedls";
    int m = x.length();
    int n = y.length();

    int length = LCS(x,y,m,n,0);
    cout<<"Length "<<length<<endl;
}