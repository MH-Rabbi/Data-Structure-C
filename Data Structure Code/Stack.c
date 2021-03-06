#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack
{
    int data;
    struct stack *next;
 
}*top;
int size=0;
void push(int element);
int pop();
void display();
void maxmin();
void find();
int main()
{
    int choice, data;
    while(1)
   {
 
    printf("--------------------------------------------\n");
    printf("choose what do you want:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. display\n");
    printf("4. size\n");
    printf("5. Maximum & minimum\n");
    printf("6. Find Item\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Input data to push into stack: ");
        scanf("%d",&data);
        push(data);
        break;
    case 2:
        data=pop();
        if(data!=INT_MIN)
            printf("Popped data is : %d",data);
 
        break;
    case 3:
        display();
        break;
    case 4:
        printf("stack size is : %d",size);
        break;
    case 5:
        maxmin();
        break;
    case 6:
        find();
        break;
 
    }
    printf("\n\n");
   }
return 0;
}
void push(int element)
{
    struct stack *temp;
    temp=(struct stack*)malloc(sizeof(struct stack));
    temp->data=element;
    temp->next=top;
    top=temp;
    printf("Pushed data is: %d\n",temp->data);
    size++;
}
int pop()
{
    int data=0;
    struct stack *temp;
    if(size<= 0 || !top)
    {
        printf("Stack is Empty");
        return INT_MIN;
    }
 
    temp=top;
    data=top->data;
    top=top->next;
    free(temp);
    size--;
    return data;
 
}
void display()
{
    struct stack *temp;
    temp=top;
    printf("Stack data are:\n");
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
void maxmin()
{
    struct stack *temp;
    temp=top;
    int max,min;
    max=temp->data;
    min=temp->data;
 
    while(temp!=NULL)
    {
        if(temp->data>max)
        {
            max=temp->data;
        }
        if(temp->data<min)
        {
            min=temp->data;
        }
        temp=temp->next;
    }
    printf("Maximum element is : %d\n",max);
    printf("Minimum element is : %d\n",min);
}
void find()
{
    struct stack *temp;
    int num,i,Item;
    i=0;
    temp=top;
    printf("Enter a number to find: ");
    scanf("%d",&num);
    while(temp!=NULL)
    {
        if(temp->data==num)
           {
            i++;
            Item=temp->data;
           }
 
        temp=temp->next;
    }
   printf("Item Found %d times: %d\n",i,Item);
}