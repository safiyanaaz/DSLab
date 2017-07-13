#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int stack[MAX_SIZE],top=-1;


int isFULL()
{
	//returns 1 if stack is full else returns -1
	if (top==1)
{
	return 1;
}
else 
{
	return -1;
}
}
	

int isEmpty()
{
	//returns 1 if stack is full else returns -1
}
if (top==-1)
{
	return -1;
}
else 
{
	return 1;
}

int peek()
{
	//return element at the top of the stack
	return stack[top]
}
void push (int e){
	//inserts an element into stack
	if (!isFull)
	{
		top++;
		stack[top]=e;
		printf("inserted sucessfully");
	}
	else
	{
		printf("stack overflow");
	
}

void pop (int e){
	//remove an element from st
	int d;
	if (!isEmpty)
	{
		d=stack[top];
       top--;		
       printf("element d is sucessfully deleted");
   }
   else
   {
	   printf("stack underflow");
   }
}
int main(){
	int choice,e;
	do
	{
		display menu 1.peek 2.push 3.pop 4.exit
		printf("enter your choice");
		take input in choice variable
		switch(choice){
			case 1:
			//call peek fnctn
			break;
			till
			case 4:
			//exit
			return 0;
			
	}while(1);
	return=0;
	
