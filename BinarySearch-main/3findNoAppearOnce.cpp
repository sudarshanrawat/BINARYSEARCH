/*input=[1,1,2,3,3,4,4,8,8]
output=2

1st solution
linearly iterate and and XOR(^) all the no. onluy 2 will remain
tym comp=On,O(1);

2nd binary search;
break point=where all the left element twice and right start with single element

[1,1    |  ,2,4,4,8,8]
	breakpoint


	*/

#include<bits/stdc++.h>
using namespace std;
int singleNonDuplicate(vector<int> a)
	{
		int low=0,high=a.size()-2;  // second last index from zero

		while(low <= high)
		{
			int mid= (low+high)/2;//divided by 2

			if(a[mid]==a[mid^1])//(XOR property)
			{
				low=mid+1;
			}
			else
			{
				high=mid-1;
			}
		}
		return a[low];
	}
int main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];

	int b=singleNonDuplicate(a);
	cout<<b;
}



/*low=0,high=n.size()-2;
if(low<=high)
	mid=low+high/2;
	if(n[mid]==n[mid^1])
		low=mid+1;
	else
		high=mid-1;*/
