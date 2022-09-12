#include <stdio.h> 
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node *start,*temp,*pre,*newnode;



int fstCk(int data){
    if(start == NULL){
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = data;
        start = newnode;
        return 1;
    }else return 0;
}

void traver(){
    if(start == NULL){
        printf("No data to display\n");
    }else{
        temp = start;
        while (temp->next!= NULL)
        {
            printf("%d ,",temp->data);
            temp = temp->next;
        }
        printf("%d \n",temp->data);
        
    }
}

int search(int data){
    temp = start;
    do{
        // printf("%d ,",temp->data);
        if(temp->data == data){
            // printf("The data is present\n");
                return 1;
                break;
            }
            temp = temp->next;
        }while (temp!= NULL);
        return 0;
}


void insertion(int data){
    if(fstCk(data)){
        printf("Since their was no data thus entered at the begning\n");
    }else{
        printf("Enter the values at::\n1 -- Start\n2 -- end\n3 -- after a value\n4 -- before a value\n");
        int option;
        printf("Choose the value :: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("Performing insertion at the 1st place\n");
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = start;
            start = newnode;

            break;
        
        case 2:
            printf("inserting at the end\n");
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;


            temp = start;
            while (temp->next!= NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            break;
        case 3:
            printf("Note If that value will not be present their then it will be inserted at the end! \n");
            int val;
            printf("Enter the value after which it has to be inserted\nValue :: ");
            scanf("%d",&val);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;


            temp = start;
            while (temp->next!= NULL){
                // printf("%d ,",temp->data);
                if(temp->data == val){
                    break;
                }
                temp = temp->next;
            }

            newnode->next = temp->next;
            temp->next = newnode;
            break;
        
        case 4:
            printf("Note If that value will not be present their then it will be inserted at the end! \n");
            int val2;
            printf("Enter the value before which it has to be inserted\nValue :: ");
            scanf("%d",&val2);

            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->data = data;


            temp = start;
            while (temp->next!= NULL){
                // printf("%d ,",temp->data);
                if((temp->next)->data == val2){
                    break;
                }
                temp = temp->next;
            }

            newnode->next = temp->next;
            temp->next = newnode;
            break;

        default:
            printf("Choose some appropriate value::\n");
            break;
        }
    }
}

void deletion(){
    if(start == NULL){
        printf("Data Underflow.. . thus nothing to delete  // \n");

    }else{
        printf("Enter the values at::\n1 -- Start\n2 -- end\n3 -- to a specific value\n");
        int option;
        printf("Choose the value :: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            start = start->next;
            break;
        
        case 2:
            temp = start;
            while (temp->next!= NULL){
                
            }
            break;

        case 3:
            int data;
            printf("Enter the data to be deleted :: ");
            scanf("%d",&data);

            if(search(data)){
            temp = start;
            while (temp->next!= NULL){
                // printf("%d ,",temp->data);
                if((temp->next)->data == data){
                    break;
                }
                temp = temp->next;
            }
            temp->next = (temp->next)->next;

            printf("data deleted");
  
            }else{
                printf("DATA not found!");
            }
            break;
        
        default:
            break;
        }

    }
}




int main(){
    printf("Enter the value::\n1 -- to perform the insertion\n2 -- for Deletion\n3 -- to traverse\n4 -- to search\n5 -- exit\nEnter you choice :: ");
    int choose;
    scanf("%d",&choose);
    int data;

    do{

        switch (choose)
        {
        case 1:
            
            printf("Enter the data::");
            scanf("%d",&data);
            insertion(data);
            break;

        case 2:
            // printf("Comming soon .. .. .\n");
            deletion();
            break;

        case 3:
            printf("Getting data ... .. .\n");
            traver();
            break;
        
        case 4:
            printf("Enter data for searching :: ");
            scanf("%d",&data);
            if(search(data)){
                printf("The data is present.. .\n");
            }else{
                printf("Data not Present !\n");
            }
            break;
            
        default:
            break;
        }
        printf("\nEnter you choices again :: ");
        scanf("%d",&choose);
    }while(choose !=5);
}
