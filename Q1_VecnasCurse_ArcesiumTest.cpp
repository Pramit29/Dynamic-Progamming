#include<iostream>
#include<limits.h>
using namespace std;

float Knapsack(float damageScore[], float duration[], float thresholdScore, int n)
{
    cout<<"No of elements in array "<<n<<endl;
    cout<<"Threshold damage score to inflict Vecna "<<thresholdScore<<endl;

    cout<<"Damage scores of all the songs"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<damageScore[i]<<" ";
    }
    cout<<endl;
    cout<<"Duration of each song"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<duration[i]<<" ";
    }
    cout<<endl;

    int result, val1, val2;
    
    // Base case: when we don't have any element or we have reached the threshold limit, then return INT_MAX because answer has to be min and 
    // it will pick 0 if we return 0 in this case. Returning INT_MAX ensures that it picks the right answer.
    if(n==0 || thresholdScore==0)
    {
        return INT_MAX;
    }
    if(damageScore[n-1]<=thresholdScore)
    {
        val1 = duration[n-1] + Knapsack(damageScore,duration,thresholdScore-damageScore[n-1],n-1);
        val2 = Knapsack(damageScore,duration,thresholdScore,n-1);
        cout<<"val1 "<<val1<<" val2 "<<val2<<endl;
        result = min(val1,val2); // we need min duration to inflict Vecna
        cout<<"val returned from second if "<<result<<endl;
        return(result);
    }
    else if(damageScore[n-1]>thresholdScore)
    {
        // applied unitary method to calculate duration for the required threshold score
        float newval = float(duration[n-1]/damageScore[n-1] )* thresholdScore; 
        
        result = min(newval,Knapsack(damageScore,duration,thresholdScore,n-1));
        cout<<"val returned from third if "<<result<<endl;
        return(result);
    }
    
    return 0;
}

int main()
{
    
    float duration[] = {120,100000};
    float damageScore[] = {60,40};
    float thresholdScore = 50;
    int n = sizeof(damageScore)/sizeof(damageScore[0]);
    float minDuration;
    
    minDuration = Knapsack(damageScore,duration,thresholdScore,n);
    cout<<minDuration;
}

// Time Complexity is O(2^n)
// Space Complexity is O(1)