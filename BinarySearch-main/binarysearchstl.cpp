//1.if x is present or not
//a[]={4,5,7,9}

//.......................binary_search()................... is an stl fucition

//bool res=binary_search(a,a+n,3) false

/*2...................lower_bound function:..........................

a[]={1,4,6,8,9,9}

int ind=lower_bound(a,a+n,4)-a(first iterator);     returns 1(iterator) previos
int ind=lower_bound(a.begin(),a.end(),x)-a.begin();



/*2...................upper_bound function:..........................

a[]={1,4,6,8,9,9}

int ind=upper_bound(a,a+n,4)-a(first iterator);     returns 1(iterator) previos
int ind=upper_bound(a.begin(),a.end(),x)-a.begin();

int ind=lower_bound(a.begin(),a.end(),x)-a.begin();



*/
//.....................to find the if any no. exist in given array or not........
// #include<bits/stdc++.h>
// using namespace std ;
// int main()
// {
// 	int n,x;
// 	cin>>n;
// 	int a[n];
// 	for(int i=0;i<n;i++)
// 		{cin>>a[i];}
// 	cin>>x;
// 	int ind=lower_bound(a,a+n,x)-a;  //ind=index

// 	(a[ind]==x)?cout<<ind : cout<<"-1";
// }

#include<bits/stdc++.h>
using namespace std ;
int main()
{
	int n,x;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		{cin>>a[i];}
	cin>>x;
	int ind=upper_bound(a,a+n,x)-a;  //ind=index

	if(ind<n) cout<<a[ind]; else cout<<-1;
}