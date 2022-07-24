/*
num1=[1,3] num2=[2]
output=2.00000
merge [1,3,2]..................and median is 2..


ques   num1=1,3,4,7,10,12
		nu2=2 3 6 15
		sort the num=[1,2,3,4,6,710,12,15]


1st=merge method O(n1+n2) sae space

2nd=take a count variable and simply find the required elements and store them
and take median out of them......

0000 0000 0000 

*/

// #include<bits/stdc++.h>
// using namespace std;
// int FindMedian(vector<int> &a,vector<int> &b)
// {
// 	if(b.size()<a.size()) return FindMedian(b,a);//we wanted a smaller than b
// 	int s1=a.size();
// 	int s2=b.size();

// 	int l=0,h=s1;
// 	//binary search
// 	while(l<=h)
// 	{
// 		int cut1=(l+h)/2;
// 		int cut2=((s1+s2+1)/2)-cut1;

// 		int l1=(cut1 == 0) ? INT_MIN : a[cut1-1];
// 		int l2=(cut2 == 0) ? INT_MIN : b[cut2-1];

// 		int r1=(cut1 == s1) ? INT_MAX : a[cut1];
// 		int r2=(cut2 == s2) ? INT_MAX : b[cut2];

// 		if((l1 <= r2) && (l2<=r1))
// 		{
// 			if((s1+s2)%2 == 0)
// 				return max(l1,l2);
// 			else
// 				return(max(l1,l2)+min(r1,r2))/2.0;
			
				
// 		}
// 		else if(l1>r2)
// 		{
// 			h=cut1-1;
// 		}else
// 		{
// 			l=cut1+1;
// 		}
		
// 	}
// 	return 0.0;
// }
// int main()
// {
// 	int n,t;
// 	cin>>n>>t;
// 	vector<int>a(n);
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>a[i];
// 	}
// 	vector<int>b(t);
// 	for(int i=0;i<t;i++)
// 	{
// 		cin>>b[i];
// 	}
// 	int c=FindMedian(a,b);
// 	cout<<c;
// }

#include<bits/stdc++.h>
using namespace std;

int median(int nums1[],int nums2[],int m,int n) {
    if(m>n)
        return median(nums2,nums1,n,m);//ensuring that binary search happens on minimum size array
        
    int low=0,high=m;
    while(low<=high) {
        int cut1 = (low+high)>>1;
        int cut2 = ((m+n)+1)/2 - cut1;
        
        int l1 = cut1 == 0 ? INT_MIN:nums1[cut1-1];
        int l2 = cut2 == 0 ? INT_MIN:nums2[cut2-1];
        int r1 = cut1 == m ? INT_MAX:nums1[cut1];
        int r2 = cut2 == n ? INT_MAX:nums2[cut2];
        
        if(l1<=r2 && l2<=r1) {
            if((m+n)%2 != 0)
                return max(l1,l2);
            else 
                return (max(l1,l2)+min(r1,r2))/2.0;
        }
        else if(l1>r2) high = cut1-1;
        else low = cut1+1;
    }
    return 0.0;
}

int main() {
    int nums1[] = {1,4,7,10,12};
    int nums2[] = {2,3,6,15};
    int m = sizeof(nums1)/sizeof(nums1[0]);
    int n = sizeof(nums2)/sizeof(nums2[0]);
    cout<<"The Median of two sorted arrays is :"<<fixed<<setprecision(5)
    <<median(nums1,nums2,m,n);
    return 0;
}