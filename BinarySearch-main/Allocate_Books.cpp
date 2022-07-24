/*

arr[]={12,34,67,90}
n==4(no. of boooks)    studets=2

CONDITION:     1 A book will be allocated to one student
			   2 each student must get min of 1 book
			   3 allotment should be in contagous order


1st=RECURSION-by partition
2nd=BINARY SOLn......take low as the min no. of pages
					 take high as the total no. of pages provided

		[12                    107                      203]
		low			 		   mid				high(  total no. og pages)

SINCE:we can not allocate 2 students because of given barries 
therefore we will increase our barrier in order to allocate books to 2 student

		[108                  155                   203]     res=155
		low                   mid                   high

HERE we can allocate books to 2 STUDENTS easily  

SINCE we want the minimal thats why THEREFORE right side get eliminated

		[108               131                154]        res=131
		low                mid                high

same as above ...again we want minimal  THEREFORE right side get eliminated

		[108             118       130]              res=118
		low				mid			high			 {res=113}

same process till end

*/

#include<bits/stdc++.h>
using namespace std;
bool studs(int barrier,int k,int a[],int n)
{
	int allstud=1,pages=0;
	for(int i=0;i<n;i++)
	{
		if(barrier<a[i]) return false;
		if(pages+a[i]>barrier)
		{
			allstud+=1;
			pages+=a[i];
		}else
		{
			pages+=a[i];
		}
	}
		if(allstud>k)
			return false;
		else return true;
	

}
int Allbook(int a[],int m,int k)
{
	int l=0,res=-1,h=0;
	for(int i=0;i<m;i++)
	{ 
		h+=a[i];
	}
	while(l<=h)
	{
		int mid=(l+h)/2;
		if(studs(mid,k,a,m)==true)
		{
			res=mid;
			h=mid-1;
		}else{
			l=mid+1;
		}
	}
	
}
int main()
{
	int a[]={12,34,67,90,113,160};
	int m=sizeof(a)/sizeof(a[0]);
	int k=4; //no of students;
	cout<<"Allocated Books to student are :"<<Allbook(a,m,k);

}


