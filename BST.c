  //Program to implement Binary Search Tree.
  //Learner:SHAIKH SAFIYA NAAZ ABDUL HAKEEM.
  //Created on:21 SEPTEMBER.

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
 }
 void searchnode(node **x,node **root,node **parent,int num,int *f)
 {
	 node*temp;
	 temp=root;
	 if(temp==NULL)
	    return;

	    while(temp!=NULL)
	    {
			 if(temp->data==num)
	  {
		  *f=1;
		  *x=temp;
		  return;
	    }
	       *parent=temp;
			if(num>temp->data)
			   temp=temp->right;
			else
			   temp=temp->left;
		 }

 }
 void delete (node **r,int num)
{
	node *temp,*parent,*x,*xsucc;
	int f=0;
	parent=NULL;x=NULL,xsucc=NULL;
    temp=*r;
    searchnode(&x,temp,&parent,num,&f);
    if(f==0)
    {
		printf("\nTHE ELEMENT %D IS NOT FOUND",num);
		return;
	}
	//x has no child
	if(x->left==NULL && x->right==NULL)
	{
		if(x->data > parent->data)
		     parent->right==NULL;
		 else
		     parent->left==NULL;
		  free(x);
	 }
	 //x has left child
	 else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data > parent->data)
		     parent->right==x->left;
		 else
		     parent->left==x->left;
    }
    //x has right child
    else if(x->left==NULL && x->right!=NULL)
	{
		if(x->data > parent->data)
		     parent->right==x->right;
		 else
		     parent->left==x->right;
	}
    //x has two children
    else if (x->left!=NULL && x->right!=NULL)
    {
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
		  xsucc=xsucc->left;
	    }
	    if(xsucc->data > parent->data)
	      parent->right=NULL;
	    else
	     parent->left==NULL;
		  x->data=xsucc->data;
		  parent->left==NULL;
		  x=xsucc;
		  
    }
    free(x);
	}
		

 
 int search (node *q,int key)
{
	if (q==NULL)
	return -1;
	else
	{
		if(q->data==key)
		return 1;
			else
			{
				if (key>q->data)
			{
				search(q->right,key);
			}
			else
			{
				search(q->left,key);
			}
		}
  }
 }
			

void insert ( node **r,int num)
{
	node *temp,*ptr;
	temp=*r; 
	if (temp==NULL)
	{
		ptr=(node*)malloc(sizeof(node));
	             ptr->data=num;
	             ptr->left=NULL;
            	ptr->right=NULL;
				temp->right=ptr;
	            *r=ptr;
	 }
	else
	{
		if(num>temp->data)
		{
			insert(&temp->right,num);
		}
			else
			{
				insert(&temp->left,num);
				}
			}
}



int main()
{
	node *root;
	root=NULL;
	insert(&root,20);
	insert(&root,15);
	insert (&root,13);
	insert(&root,17);
	insert(&root,16);
	insert (&root,19);
	insert(&root,18);
	insert(&root,25);
	traverseinorder(root);
	if(search(root,7)==1)
		printf("\n%d is present in thetree",7);
		else
		printf("number not found");
	delete(&root,19);
	traverseinorder(root);
	return 0;
}
	
	

