/* if n is given as 4 
we hav to find second root of 4 i.e. 2
if n=4 and m=15
4root 15 = 1.967...(4th root of 15) 5 place points


Q1. n=3,m=27
	(trim our search space)search space[1....4.25]...not here....7.5]....not here....14].....not here......27]  
				            mid=1+7.5/2=4.25 ////mid=1+14/2=7.5  ////mid=(1+27)/2=14
				        high-low>10^-6;

	linearly increases as we go from 1 to 2 to 3 to.....

*/

#include<bits/stdc++.h>
using namespace std;

double multiply(double number,int n)
{
	double ans=1.0;
	for(int i=1;i<=n;i++){
		ans = ans * number;
	}
	return ans;
}

getnode(double n,int m)
{
	double low=1,high=m,diff=1e-6; //1e=n ki power-6
	while((high-low)>diff)
	{
		double mid=(low+high)/2.0;
			if(multiply(mid,n)<m)
			{
				low=mid;
			}else
			{
				high=mid;
			}
	}
	cout<<low <<" "<<high<< endl;

	cout<< pow(m, (double)(1.0/(double)n));
}
int main()
{
	int n,m;
	cin>>n>>m;
	getnode(n,m);
}
