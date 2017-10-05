  /*Program to HASHING..
  *Learner:SHAIKH SAFIYA NAAZ ABDUL HAKEEM.
  * Created on:5 october*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 5

int hash(int k)
{
	return k%MAX;
}
int linear_probe(int h)
{
	return ++h%MAX;
}
int double_hash(int h,int i)
{
	return (h+i*linear_probe(h))%MAX;
}
int quadratic_probe(int h,int i)
{
	return (int)(h+pow(i,2))%MAX;
}
void display(int a[])
{
	int i;
	printf("\n THE ELEMRNTS OF AN ARRAY ARE\n");
	for(i=0;i<MAX;i++)
	{
		printf("%d\t",a[i]);
	}
}
int main()
{
	int a[MAX],i,h,e,count,c;
	for (i=0;i<MAX;i++)
		a[i]=-1;
	do
	{
		count=0;
		printf("\nENTER THE NUMBER TO BE STORED");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1)
		{
			a[h]=e;
			display(a);
		}
		else
		{
			while(count<MAX)
			{	count++;
				printf("\ncollision occured at %d\n",h);
				printf("Enter your choice of resolution\n");
				printf("1.linear probe\n2.quadratic probe\n3.double hash\n");
				scanf("%d",&c);
				switch(c)
				{
					case 1:
						h=linear_probe(h);
						break;
					case 2:
						h=quadratic_probe(h,count);
						break;
					case 3:
						h=double_hash(h,count);
						break;
					default:
						printf("\nINVALID CHOICE");
						count--;
						break;
			    }
			if(a[h]==-1)
			{
				a[h]=e;
				display(a);
				break;
		    }
	    }
      }
			if(count==MAX)
		{
			printf("\nARRAY IS FULL OR COLLISION RESOLUTION IS NOT SUCESSFULL");
			return 0;
		}
	}while(1);
}
/*ENTER THE NUMBER TO BE STORED10

 THE ELEMRNTS OF AN ARRAY ARE
10	-1	-1	-1	-1	
ENTER THE NUMBER TO BE STORED12

 THE ELEMRNTS OF AN ARRAY ARE
10	-1	12	-1	-1	
ENTER THE NUMBER TO BE STORED12

collision occured at 2
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
 THE ELEMRNTS OF AN ARRAY ARE
10	-1	12	12	-1	
ENTER THE NUMBER TO BE STORED10
collision occured at 0
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
2
 THE ELEMRNTS OF AN ARRAY ARE
10	10	12	12	-1	
ENTER THE NUMBER TO BE STORED10
collision occured at 0
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
3
collision occured at 1
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
3
collision occured at 0
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
3
collision occured at 3
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
3
 THE ELEMRNTS OF AN ARRAY ARE
10	10	12	12	10	
ENTER THE NUMBER TO BE STORED15
collision occured at 0
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
collision occured at 1
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
collision occured at 2
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
collision occured at 3
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
collision occured at 4
Enter your choice of resolution
1.linear probe
2.quadratic probe
3.double hash
1
ARRAY IS FULL OR COLLISION RESOLUTION IS NOT SUCESSFULL

------------------
(program exited with code: 0)
Press return to continue*/


                                                                               
