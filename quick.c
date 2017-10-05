/*Description:Implementation of Quick sort.
 * learner:Shaikh Safiya Naaz Abdul Hakeem.*/
 
#include<stdio.h>
#include<stdlib.h>
#define Max 100
int split(int arr[],int lower,int upper)
{
	int temp;
	int pivot=lower;
	int a=pivot+1,b=upper;
	while(b>=a)
	{
		while(arr[a]<arr[pivot])
			a++;
		while(arr[b]>arr[pivot])
			b--;
		if (b>a)
		{
			temp=arr[a];
			arr[a]=arr[b];
			arr[b]=temp;
		}
	}
	temp=arr[b];
	arr[b]=arr[pivot];
	arr[pivot]=temp;
return b;
}
void Quick_sort(int arr[],int lower,int upper)
{
	int i;
	if(upper>lower)
	{
	i=split(arr,lower,upper);
	Quick_sort(arr,lower,i-1);
	Quick_sort(arr,i+1,upper);
    }
}
 int main()
 {
	int arr[Max],n,i;
    printf("enter no of elements in the array");
	 scanf("%d",&n);
	 printf("enter the elements in order in the array");
	 for(i=0;i<n;i++)
	 {
	 scanf("%d",&arr[i]);
     } 
     Quick_sort(arr,0,n-1);
     printf("the sorted array is");
     for(i=0;i<n;i++)
     {
		 printf("%d\t",arr[i]);
	 }
	 return 0;
 }
 /*enter no of elements in the array5
enter the elements in order in the array8
9
7
2
6
the sorted array is2	6	7	8	9	
------------------
(program exited with code: 0)
Press return to continue*/




	 
