#include <stdio.h>
#include <stdlib.h>

struct node{
    int key;
    int val;
    struct node *next;
};

struct table{
    int size;
    struct node **list;
};

struct table *createTable(int size);

int hashCode(struct table *t,int key);

void insert(struct table *t,int key,int val);

int lookup(struct table *t,int key);


int main(int argc,char* argv[])
{
    int input1[] = {1,1,1,2,3,4,5};
    int input2[] = {1,1,2,2,3,3,3,3,3,3,3,3,3,3,3,3,4,4,5,5,6,6,7};


    


}

struct table *createTable(int size)
{
    struct table *t = (struct table*)malloc(sizeof(struct table));
    t->size = size;
    t->list = (struct node**)malloc(sizeof(struct node*)*size);
    int i;
    for(i=0;i<size;i++)
        t->list[i] = NULL;
    return t;
}

int hashCode(struct table *t,int key)
{
    if(key<0)
        return -(key%t->size);
    return key%t->size;
}

void insert(struct table *t,int key,int val)
{
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            temp->val = val;
            return;
        }
        temp = temp->next;
    }
    newNode->key = key;
    newNode->val = val;
    newNode->next = list;
    t->list[pos] = newNode;
}

int lookup(struct table *t,int key)
{
    if(key < 0)
    {
    
    }
    int pos = hashCode(t,key);
    struct node *list = t->list[pos];
    struct node *temp = list;
    while(temp){
        if(temp->key==key){
            return temp->val;
        }
        temp = temp->next;
    }
    return -1;
}

