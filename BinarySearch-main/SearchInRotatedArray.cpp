/*
input=[4,5,6,0,1,2] target=0  ...RoTATED ARRAY
output=4;

1st=linear search tym===O(n),O(1);



1st-;linera search..from index 1 to target index O(n),O(1);
2nd-;binary search

divide in half (by binary search)
then compare ................loe(1st elemet) <mid
if true mid=mid+1............;else mid-1;
if mid+1...........eleminate left side
binary search on remaining
same againa dn again .......by comparing target == mid;


*/

#include<bits/stdc++.h>
using namespace std;
int FindTargetIndex(vector<int>a,int target)
{
	int l=0,h=a.size();
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(a[mid]==target)
			return mid;

//for left side
		if(a[l]<= a[mid])
		{
			if((a[l] <= target) && (target<=a[mid]))
			{
				h=mid-1;}
			else
			{
				l=mid+1;
			}
		}
//FOR RIGHT SIDE
		else
		{
			if((a[l] <= target) && (target<=a[h]))
			{
				h=mid+1;}
			else
			{
				l=mid-1;
			}
		}
	}
	return -1;
}
int main()
{
	int n,t;
	cin>>n>>t;
	vector<int>a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	int b=FindTargetIndex(a,t);
	cout<<b;
}



