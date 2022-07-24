/*
a1=2 3 6 7 9,,,,a2= 1 4 8 10    k=5(5th elementin the array)

after sorting:
1 2 3 4 6 7 8 9 10
output is "6"    {as it is the 5th element}

1st:linearly sort both the array taking ..[arr3].. then find the fifth element
2nd=similar as median by taking l1 and l2 and r2 and r2;



*/
// #include<bits/stdc++.h>
// using namespace std;
// int kelement(int a[],int b[],int n,int m,int k)
// {
// 	if(n>m)	
// 		return kelement(a,b,m,n, k);

// 	int l=max(0,k-m),h=min(k,n);
// 	while(l<=h)
// 	{
// 		int cut1=(l+h)/2;
// 		int cut2=k-cut1;
// 		int l1= cut1==0 ?INT_MIN:a[cut1-1];
// 		int l2= cut2==0 ?INT_MIN:a[cut2-1];
// 		int r1= cut1==m ?INT_MAX:a[cut1];
// 		int r2= cut2==n ?INT_MAX:b[cut1];

// 		if(l1<=r2 && l2<=r1)
// 		{
// 			return max(l1,l2);
// 		}else	if(l1>r2)
// 		{
// 			h=cut1-1;
// 		}else
// 		{
// 			l=cut1+1;
// 		}
// 	}
// 	return 1;

// } 
// int main()
// {
// 	int a[]={2,5,8,21,27,34};
// 	int b[]={4,6,9,10,16,19};
// 	int n=sizeof(a)/sizeof(a[0]);
// 	int m=sizeof(b)/sizeof(b[0]);
// 	int k=9;
// 	cout<<"position of kth element is :"<<kelement(a,b,m,n, k);

// }

#include<bits/stdc++.h>
using namespace std;
int kthelement(int arr1[], int arr2[], int m, int n, int k) {
    if(m > n) {
        return kthelement(arr2, arr1, n, m, k); 
    }
        
    int low = max(0,k-m), high = min(k,n);
        
    while(low <= high) {
        int cut1 = low +(high-low)/ 1; 
        int cut2 = k - cut1; 
        int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
        int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
        int r1 = cut1 == n ? INT_MAX : arr1[cut1]; 
        int r2 = cut2 == m ? INT_MAX : arr2[cut2]; 
            
        if(l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) {
            high = cut1 - 1;
        }
        else {
            low = cut1 + 1; 
        }
    }
    return 1; 
}
int main() {
    int array1[] = {2,3,6,7,9};
    int array2[] = {1,4,8,10};
    int m = sizeof(array1)/sizeof(array1[0]);
    int n = sizeof(array2)/sizeof(array2[0]);
    int k = 8;
    cout<<"The element at the kth position in the final sorted array is "
    <<kthelement(array1,array2,m,n,k);
    return 0;
    }