#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int dp[100][100];
string a,b;
void LCS()
{
    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=b.size()-1;j>=0;j--)
        {
            if(a[i]==b[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            }
            else dp[i][j]=max(dp[i][j+1],dp[i+1][j]);
        }
    }
}
int nu(int i,int j)
{
    if(i>=a.size()||j>=b.size())return 0;
    if(a[i]==b[j])return nu(i+1,j+1)+1;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j]=max(nu(i+1,j),nu(i,j+1));
}

void pr()
{
    int i=0,j=0;
    while(i<a.size()||j<b.size())
    {
        if(a[i]==b[j])
        {
         cout<<a[i];
            i++;
            j++;
            continue;
        }
        else if(dp[i][j]==dp[i][j+1])
        {
            j++;
        }
        else
        {
            i++;
        }

    }


}

int main()
{
    cin>>a>>b;
     LCS();
   cout<<dp[0][0]<<endl;
    pr();
  return 0;
}
