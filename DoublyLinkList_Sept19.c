//  About all the operation related to Doubly link list 

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *pre, *next;

};

struct node *start,*temp,*pre,*newnode,*end;

struct node * createNode(int data){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    return newnode;
}

int fstCk(int data){
    if(start == NULL){
        newnode = createNode(data);
        start = newnode;
        return 1;
    }else {
        return 0;
        };
}

struct node * endNode(){
    temp = start;
    while(temp->next != NULL){
        temp = temp->next;
    }
    end = temp;

    return end;
}

struct node * search(int data){
    temp = start;
    do{
        // printf("%d ,",temp->data);
        if(temp->data == data){
            // printf("The data is present\n");
                return temp;
                break;
            }
            temp = temp->next;
        }while (temp!= NULL);
        return 0;
}

void primaryTraver(){
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

void prevTraver(){
    if(start == NULL){
        printf("No data to display\n");
    }else{
        temp = endNode();
        while (temp->pre!=NULL)
        {
            printf("%d ,",temp->data);
            temp = temp->pre;
        }
        printf("%d",temp->data);
        printf("\n");        
    }
}

int insertion(int data){
    if(fstCk(data)){
        printf("Since their was no data thus Link List has been initiated and data added to the first node:: ,,, .\n");

    }else{
        printf("Make you decission that where you wanna add \n1 -- at start\n2 -- at end\n3 -- at a  specific point\nmake your choice::");
        int insOpt;
        scanf("%d",&insOpt);
        
        switch (insOpt )
        {
        case 1:
            printf("Performing insertion at the start\n");
            newnode = createNode(data);
            
            start->pre = newnode;
            newnode->next = start;

            start = newnode;

            break;
        
        case 2:
            printf("Performing insertion at the end\n");
            newnode =  createNode(data);

            end = endNode();
            newnode->pre = end;
            end->next = newnode;

            break;

        case 3:
            printf("Inserting at a specified point .. \n");
            printf("Note If that value will not be present their then it will be inserted at the end! \n");

            printf("1 -- for before a value\n2 -- for after a value\ngive input::");
            int switIn,val;
            scanf("%d",&switIn);
            switch (switIn)
            {
            case 1:
                printf("Enter value before which data should be entered :: ");
                scanf("%d",&val);

                newnode = createNode(data);
                temp = start;
                while (temp->next!= NULL){
                    // printf("%d ,",temp->data);
                    if(temp->data == val){
                        break;
                    }

                    temp = temp->next;
                }

                newnode->pre = temp;
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            case 2:
                printf("Enter data after which data should be entered :: ");
                scanf("%d",&val);
                
                newnode = createNode(data);
                temp = start;
                while (temp->next!= NULL){
                    // printf("%d ,",temp->data);
                    if((temp->next)->data == val){
                        break;
                    }
                    temp = temp->next;
                }

                newnode->pre = temp;
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            default:
                break;
            }
        
        default:
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
            start->next->pre = NULL;
            start = start->next;
            break;
        
        case 2:
            temp = endNode();
            temp = temp->pre;
            temp->next = NULL;
            break;

        case 3:
            int data;
            printf("Enter the data to be deleted :: ");
            scanf("%d",&data);

            temp = search(data);
            if(search(data)){
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;

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
    
    int choose,TrvChoose;
    
    int data;

    do{
        printf("\nEnter the value:: 1 - insertion\t2 - Deletion\t3 - traversal\t4 - search\t5 - exit\nEnter you choice :: ");
        scanf("%d",&choose);
        printf("\n");
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
            if(start == NULL){
                printf("No Data to Display\n");
            }else{
                printf("Do you want to get it\n1 -- right to left sequence\n2 -- left to right sequence\nEnter you choice :: ");
                scanf("%d",&TrvChoose);
                printf("Getting data ... .. .\n");
                switch (TrvChoose)
                {
                case 1:
                    printf("\n");
                    primaryTraver();
                    printf("\n");
                    break;
                case 2:
                    printf("\n");
                    prevTraver();
                    printf("\n");
                default:
                    printf("Enter a valid choice \n");
                    break;}
            }
            break;
        
        case 4:
            printf("Enter data for searching :: ");
            scanf("%d",&data);
            temp = search(data);
            if(temp){
                printf("The data is present.. .\n");
                if(temp->pre != NULL && temp->next != NULL){
                    printf("It is the only data present in the linkList");
                    }else{    
                        if(temp->pre != NULL){
                        printf("After : %d \n", temp->pre->data);
                    }else{
                        printf("at 1st position\n");
                    }
                    if(temp->next != NULL){
                        printf("Before : %d \n",temp->next->data);
                    }else{
                        printf("at the last position\n");
                    }
                }
                // printf("Before : %d  and After : %d \n",temp->next->data,temp->pre->data);
            }else{
                printf("Data not Present !\n");
            }
            break;
            
        default:
            break;
        }
        
    }while(choose !=5);
}