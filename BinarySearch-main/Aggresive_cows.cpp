/*

AGGRESSIVE COW

n=5               largest min distance 
a[]=[1,2,4,8,9] cows=3         ****SORT THE ARRAY***

place three cows in these stalls 

min distance b/w cows should be as large as possible

1st=brute force
linearly strt from 1 till the max distace is found i.e.
1  2  3  (after 4 distance is not possible)

2 for loops 

2nd: BINARY SEARCH

search space b/w [1,8] as 8 in max differ b/w cows


[1       4      8]   
low     mid    high    **here min distace is 4** not possible 5 6 7
                         same case

[1       2        4] **here min distace is 2** possible as we want
low	    mid      high      largest movwe to mid+1

[3        3        3]   **here min distance is 3** possible
low      mid     high


low crossed high break BINARY SEARCH

*/

// #include<bits/stdc++.h>
// using namespace std;
// bool canplace(int mid,int a[],int n,int k)
// {
// 	int cord=a[0],cnt=1;
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(a[i]-cord>=mid)
// 		{
// 			cnt++;
// 			cord=a[i];
// 		}

// 	}	if(k<=cnt)
// 			return true;
// 		return false;
	
// }
// int distcow(int a[],int m,int k)
// {
// 	int low=1,high=(a[m-1]-a[0]),res=0;;
// 	while(low<=high)
// 	{
// 		int mid=(low+high)/2;

// 		if(canplace(mid,a,m,k)==true)
// 		{
			
// 			low=mid+1;
// 		}else{
// 			high=mid-1;
// 		}
// 	}
// }
// int main()
// {
// 	int n=5;
// 	int a[]={1,2,8,4,9};
// 	sort(a,a+n);
// 	int k=3;

// 	int =distcow(a,n,k);
//	cout<<high;
// }


#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int cows, int minDist) {
    int cntCows = 1;
    int lastPlacedCow = a[0];
    for (int i = 1; i < n; i++) {
    if (a[i] - lastPlacedCow >= minDist) {
        cntCows++;
        lastPlacedCow = a[i];
        }
    }
      if (cntCows >= cows) return true;
      return false;
    }


    int main() {
      int n = 5, cows = 3;
      int a[]={1,2,7,4,14};
      sort(a, a + n);

      int low = 1, high = a[n - 1] - a[0];

      while (low <= high) {
        int mid = (low + high) >> 1;

        if (isPossible(a, n, cows, mid)) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
      cout << "The largest minimum distance is " <<high << endl;

      return 0;
      }