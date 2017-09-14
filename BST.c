  //Program to implement Binary Search Tree.
  //Learner:SHAIKH SAFIYA NAAZ ABDUL HAKEEM.

#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
	int data;
	struct bst *left,*right;
}node;

void traverseinorder(node *q)
{
	if(q!=NULL)
	{
	traverseinorder(q->left);
	printf("%d\t",q->data);
	traverseinorder(q->right);
    }
 node* delete (node *q,int num)
{
	node *temp;
	temp=q;
	if(temp==NULL)
	{
		printf("\nthe given number is not found"):
		return;
	}
	else
	{
	if(temp->data==num)
	{
		if(temp->left==NULL&&temp->right==NULL)
		free(temp);
		
		return;
	}
		

 
 int search (node *r,int key)
{
	if (r==NULL)
	return -1;
	else
	{
		if(q->data==key)
		return 1;
			else
			{
				if (key>q->data)
			{
				search(r->right,key);
			}
			else
			{
				search(r->left,key);
			}
		}
  }
 }
			

node* insert (node *r,int num)
{
	node *temp,*ptr;
	temp=r; 
	if (temp==NULL)
	r=ptr;
	else
	{
		if(num>temp->data)
		{
			if(temp->right==NULL)
			{
				ptr=(node*)malloc(sizeof(node));
	             ptr->data=num;
	             ptr->left=NULL;
            	ptr->right=NULL;
				temp->right=ptr;
				return;
			}	
			else
			{
				temp=temp->right;
				insert(temp,num);
				}
			}
			else
			{
			if(temp->left==NULL)
			{
				ptr=(node*)malloc(sizeof(node));
	             ptr->data=num;
	             ptr->left=NULL;
            	ptr->right=NULL;
				temp->left=ptr;
				return;
			}	
			else
			{
				temp=temp->left;
				insert(temp,num);
				}
			}
	}
	return r;
}



int main()
{
	node *root;
	root=NULL;
	insert(root,5);
	insert(root,6);
	insert (root,7);
	traverseinorder(root);
	if(search(root,7)==1)
		printf("\n%d is present in thetree",7);
		else
		printf("number not found");
	return 0;
}
	
	

