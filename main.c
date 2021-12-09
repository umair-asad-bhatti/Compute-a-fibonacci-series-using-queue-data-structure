//programe to compute the fibonnaci series using data structure
#include<stdio.h>
#include<stdlib.h>

//defination of linked list
struct node{

    int value;
    struct node * next;

};
int count=0;
struct node* header;

//function prototypes
void insert(struct node** ptr,int value);
void display(struct node** ptr);
void Compute_Finonnaci();


//start of main function
int main()
{

    Compute_Finonnaci();
    printf("\n");
    
    system("pause");
    return 0;
}

//function definations

void insert(struct node** ptr,int value)
{

    struct node* temp=(struct node*)malloc(sizeof(struct node));

    if(count==0)
    {
        temp->value=value;
        temp->next=NULL;
        *ptr=temp;//head will point to first node
        count++;
    }
    else
    {
        struct node* p=*ptr;//assigning the address of head in p
        while(p->next!=NULL)
        {
            p=p->next;
        }

        p->next=temp;
        temp->value=value;
        temp->next=NULL;
        count++;
    }

}
void display(struct node** ptr)
{

   struct node* temp=*ptr;//assigning the address of head in temp
   while(temp->next!=NULL)
   {
       printf("%d",temp->value);
       temp=temp->next;

   }
    printf("%d",temp->value);

}

void Compute_Finonnaci()
{

    int upper_bound;
    int a=0;
    int b=1;
    int sum;
    puts("Enter the upper bounds\n");
    scanf("%d",&upper_bound);
    puts("The fibonnaci series is :");
    insert(&header,a);
    insert(&header,b);
    while(sum<=upper_bound)
    {
        sum=a+b;
        if(sum<=upper_bound)
        {
           insert(&header,sum);
        }
            a=b;
            b=sum;
    }

    display(&header);
}
