/*Description:Implementation of Binary search.
 * learner:Shaikh Safiya Naaz Abdul Hakeem.*/
#include<stdio.h>
#include<stdlib.h>
#define Max 100
int binary_search(int a[],int n,int x)
{
	int mid=n/2;
	int high=n-1,low=0;
	while(high>=low)
	{
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			low=mid+1;
		else
			high=mid-1;
	mid=(low+high)/2;
	}
	return -1;
}
 int main()
 {
	 int a[Max],x,n,i,search;
	 printf("enter no of elements in the array");
	 scanf("%d",&n);
	 printf("enter the elements in order in the array");
	 for(i=0;i<n;i++)
	 {
	 scanf("%d",&a[i]);
     }
     printf("enter the number to be search in the given array");
     scanf("%d",&x);
     search=binary_search(a,n,x);
     if (search!=-1)
		printf("element sucessfully found %d and the position is %d",x,search);
     else
		printf("number not found");
   return 0;
 }
 
/* enter no of elements in the array8
enter the elements in order in the array6
7
8
9
10
11
12
13
enter the number to be search in the given array12
element sucessfully found 12 and the position is 6

------------------
(program exited with code: 0)
Press return to continue*/

	  
