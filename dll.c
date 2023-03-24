#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next,*prev;
};
struct node* root=NULL;

void insert(){
    struct node*temp,*p;
    int d;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &d);
    temp->data=d;
    temp->prev=NULL;
    temp->next=NULL;
    if(root==NULL){
        root=temp;
    }
    else{
        p=root;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
        temp->prev=p;
    }
}


void display(){  
    struct node* p;  
    p=root;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
int length(){
    int count;
    struct node* p;  
    p=root;
    while(p!=NULL){ 
    count++;
    p=p->next;
    }
    return count;
}

void pinsert(){
    int pos,len=length();
     printf("\nEnter the position to insert: ");
        scanf("%d", &pos);
        if(len<pos)
        printf("\nEntered Position is exicides size of DLL");
else{ 
    struct node*temp,*p;
    int d,i=0;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert: ");
    scanf("%d", &d);
    temp->data=d;
    temp->prev=NULL;
    temp->next=NULL;
    p=root;
    if (pos == 1) { // insert at the beginning
            temp->next = root;
            root->prev = temp;
            root = temp;
        }
        else { // insert at other positions
            while (i < pos) {
                p = p->next;
                i++;
            }
            temp->next = p->next;
            p->next->prev = temp;
            temp->prev = p;
            p->next = temp;
        }
}
}

int main() {
    int ch;
    while (1) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
        pinsert();
        break;
        case 4:
            exit(0);
        default: 
            printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}
