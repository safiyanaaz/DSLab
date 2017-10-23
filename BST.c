  /*Program to implement Binary Search Tree..
  *Learner:SHAIKH SAFIYA NAAZ ABDUL HAKEEM.
  * Created on:21 SEPTEMBER.*/
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
void searchnode(node **x,node *root,node **parent,int num,int *f)
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
		printf("\nTHE ELEMENT %d IS NOT FOUND",num);
		return;
	}
	//x has no child
	if(x->left==NULL && x->right==NULL)
	{
		if(x->data > parent->data)
		     parent->right=NULL;
		 else
		     parent->left=NULL;
		  free(x);
	 }
	 //x has left child
	 else if(x->left!=NULL && x->right==NULL)
	{
		if(x->data > parent->data)
		     parent->right=x->left;
		 else
		     parent->left=x->left;
    }
    //x has right child
    else if(x->left==NULL && x->right!=NULL)
	{
		if(x->data > parent->data)
		     parent->right=x->right;
		 else
		     parent->left=x->right;
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
	     parent->left=NULL;
		  x->data=xsucc->data;
		  parent->left=NULL;
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
				return search(q->right,key);
			}
			else
			{
				return search(q->left,key);
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
    int c,n,e,d,s,i;
	root=NULL;
	do
	{
		printf("ENETR\n1.INSERT\n2.DELETE\n3.SEARCH\n4.TRAVERSE INORDER\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("\nENTER HOW MANY NO YOU WANT TO INSERT\n");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					scanf("%d",&e);
					insert(&root,e);
				}
				break;
			case 2:
				printf("THE NO YOU WANT TO DELETE : ");
				scanf("%d",&d);
				delete(&root,d);
				break;
			case 3:
				printf("ENTER THE NO YOU WANT TO SEARCH : ");
				scanf("%d",&s);
				if(search(root,s)==1)
					printf("\n THE NUMBER %d IS PRESENT IN THE TREE\n",s);
				else
					printf("\n THE NUMBER %d IS IS NOT FOUND\n",s);
				break;
			case 4:
				traverse_inorder(root);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("INVALID CHOICE!!");
		}
	}while(1);
	return 0;
}

