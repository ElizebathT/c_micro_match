#include<stdio.h>
#include<stdlib.h>
struct node
{
    int jersey;
    char playername[30];
    char designation[30];
    struct node *next;
};
struct node *head = NULL;
struct node *newnode, *temp;
int count1=0;

struct game
{
    int matchno;
    char matchname[30];
    char matchplace[30];
    char level[30];
    struct game *next1;
};
struct game *head1=NULL;
struct game *temp1,*ptr,*newnode1;

void add_match()
{
    newnode1=(struct game*)malloc(sizeof(struct game));
    printf("\n\t\t Enter match number: ");
    scanf("%d",&newnode1->matchno);
    printf("\n\t\tEnter match name: ");
    scanf("%s",&newnode1->matchname);
    printf("\n\t\t Enter match place: ");
    scanf("%s",&newnode1->matchplace);
    printf("\n\t\t Enter match level: ");
    scanf("%s",&newnode1->level);
    newnode1->next1=NULL;
        if(head1= NULL)
        {
            head1=newnode1;
        }
        else
        {
            temp1=head1;
            while(temp1->next1!=NULL)
            {
                temp1=temp1->next1;
            }
             temp1->next1 =newnode1;
        }
}
void delete_match()
{

    int matchnum;
    printf("\n\t Enter the match number to be deleted: ");
    scanf("%d",&matchnum);
    if(head1->matchno==matchnum)
    {
        struct game*temp2;
        temp2 = head1;
        head1 = head1->next1;
        free(temp2);
    }
    else
    {
        struct game*ptr1=NULL;
        struct game*prev1=NULL;
        struct game*currentnode=NULL;
        prev1=head1;
        currentnode=head1;
        while(currentnode->matchno!=matchnum)
        {
            prev1=currentnode;
            currentnode=currentnode->next1;
        }
        prev1->next1=currentnode->next1;
        currentnode->next1=NULL;
        free(currentnode);
        printf("RECORD OF ",currentnode->matchname);
        printf(" REMOVED ");

    }
}
void search_match()
{
    int match;
    struct game *j;
    printf("\n\t\t Enter match number to be searched:");
    scanf("%d",&match);
    j=head1;
    while(j!=NULL)
     {
        if(j->matchno==match)
        {
             printf("\n\t Match Number\t Match Name\t Match Place\t Level\t");
             printf("\n\t :::::::::::::\t:::::::::\t ::::::::::\t::::::::::\t\n");
             printf("\t\t");
            printf("%d\n",j->matchno);
            printf("%s\n",j->matchname);
            printf("%s\n",j->matchplace);
            printf("%s\n",j->level);
         break;
        }
         j=j->next1;
    }
    if(j==NULL)
    {
          printf("\n\t\t Match not conducted!!");
    }

}
void display_match_details()
{
    struct game *ptr;
    ptr=head1;
    if(head1==NULL)
         printf("\n\t\t NO MATCH CONDUCTED!!");
    else
    {
         printf("\n\t Match Number\t Match Name\t Match Place\t Level");
        printf("\n\t::::::::\t ::::::::\t ::::::::::\t::::::::::\n");

        while(ptr!=NULL)
        {
            printf("%d\n",ptr->matchno);
            printf("%s\n",ptr->matchname);
            printf("%s\n",ptr->matchplace);
            printf("%s\n",ptr->level);
            ptr=ptr->next1;
        }
       printf("\n\t****************");
    }
}
void create_team()
{
            newnode=(struct node*)malloc(sizeof(struct node));

    if(count1>11)
    {
        printf("\n\t\t TEAM FULL");
    }
    else
    {
        count1++;
         printf("\n\t\t Enter Jersey Number: ");
        scanf("%d",&newnode->jersey);
         printf("\n\t\t Enter Player Name: ");
        scanf("%s",&newnode->playername);
         printf("\n\t\t Enter designation:  ");
        scanf("%s",&newnode->designation);
        newnode->next=NULL;
        if (head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp=temp->next;
            }
             temp->next=newnode;
        }
    }
}
void search_members()
{
    int player;
    struct node *i;
    printf("\n\t\t Enter jersey number to be searched:");
    scanf("%d",&player);
    i=head;
    while(i!=NULL)
     {
        if(i->jersey==player)
        {
            printf("\n\t Jersey Number\t Player Name\t Player Designation\t ");
             printf("\n\t::::::::::\t:::::::::\t:::::::::::::::::::::\n");
             printf("\t\t");
             printf("%d%\t",i->jersey);
            printf("%s%\t\t",i->playername);
            printf("%s%\t\t\t",i->designation);
         break;
        }
         i=i->next;
    }
    if(i==NULL)
    {
         printf("\n\t\t Player not found");
    }
}

void display_team_details()
{
    struct  node *newnode;
    newnode=head;
    if(head==NULL)
        printf("\n\t\t TEAM EMPTY!!\n");
    else
    {
        printf("\n\t Jersey Number\t Player Name\t\t Player Designation\t ");
        printf("\n\t::::::::::::\t::::::::::::\t::::::::::::::::::::\n");
        while (newnode != NULL)
        {
            printf("\t\t");
            printf("%d\t\t",newnode->jersey);
             printf("%s\t\t\t",newnode->playername);
             printf("%s\t\t\t",newnode->designation);
            newnode=newnode->next;
        }
    }
}

void delete_team()
{
    struct node *ptr=NULL;
    struct node *prev=NULL;
    struct node *currentnode=NULL;
    int jerseyno;
    printf("\n\t Enter the jersey number of the member to be deleted: ");
    scanf("%d",&jerseyno);
    if(head->jersey==jerseyno)
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("\t\tRECORD OF ",currentnode->playername);
        free(currentnode);
        printf("REMOVED ");
    }
    else
    {
        prev=head;
        currentnode=head;
        while(currentnode->jersey!=jerseyno)
        {
            prev=currentnode;
            currentnode=currentnode->next;
        }
        prev->next=currentnode->next;
        currentnode->next=NULL;
        printf("\t\tRECORD OF ",currentnode->playername);
        free(currentnode);
        printf(" REMOVED ");
    }
}
int main()
{
    printf("\n\n\t\t\t\t\tFOOTBALL CLUB\t\t\n");
    printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
    int choice,constant,n,op1,op2;
    do
    {
        printf("\n\n\n\t\t [1] MATCH DETAILS\t\t [2] TEAM DETAILS\n\n");
       printf("\n\n\t ENTER YOUR CHOICE:");
        scanf("%d",&choice);
        printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
        switch(choice)
        {
            case 1:
            printf("\n\n\t\t 1) ENTER MATCH DETAILS\n\n\t\t 2) DELETE MATCH DETAILS\n\n\t\t 3) SEARCH MATCH DETAILS\n\n\t\t 4) SHOW MATCH DETAILS\n\n");
                int op;
                printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
                printf("\n\n\t ENTER YOUR CHOICE:");
                scanf("%d",&op);
                printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
                switch(op)
                {
                    case 1:
                        printf("\n\t\t\t\t ADD MATCH DETAILS\t\t");
                        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::");
                        add_match();
                        break;
                    case 2:
                        printf("\n\t\t\t\t REMOVE MEMBERSHIP\t\t");
                        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::");
                        delete_match();
                        break;
                    case 3:
                        printf("\n\t\t\t\t SEARCH MATCH DETAILS\t\t");
                        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::");
                        search_match();
                        break;
                    case 4:
                        printf("\n\t\t\t\t SHOW MATCH DETAILS\t\t");
                        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::");
                        display_match_details();
                        break;
                    default:printf("\n\t\t INVALID ");
                }
                break;

            case 2:
                printf("\n\n\t\t 1) EDIT TEAM DETAILS\n\n\t\t 2) SHOW TEAM DETAILS\n\n\t\t 3) SEARCH TEAM MEMBERS\n\n");
                printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                printf("\n\n\t ENTER YOUR CHOICE:");
                scanf("%d",&op1);
                printf("\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                switch(op1)
                {
                    case 1:
                        printf("\n\n\t\t ADD TEAM MEMBERS");
                        printf("\n\n\t\t DELETE TEAM MEMBERS");
                        printf("\n\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                        printf("\n\n\t ENTER YOUR CHOICE:");
                        int op2;
                        scanf("%d",&op2);
                        switch(op2)
                        {
                            case 1:
                                printf("\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::");
                                create_team();
                                printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                                break;
                            case 2:
                                printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                                printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                                delete_team();
                                break;
                            default:printf("\n\t\t INVALID CHOICE!!");
                        }
                        break;

                    case 2:
                        printf("\n\t:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                        display_team_details();
                            break;
                    case 3:
                        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
                         search_members();
                            break;
                    default:printf("\n\t\t INVALID CHOICE!!");
                }
        }
        printf("\n\t::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
        printf("\n\t DO YOU WANT TO CONTINUE?(1/0): ");
        scanf("%d",&constant);
    }
    while(constant!=0);
}
