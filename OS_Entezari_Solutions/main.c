#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node
{
    char *name;
    long value;
    int index;
    struct Node *next;
};


  
void swap(struct Node *a, struct Node *b); 

int specification_delete(struct Node ** head, long value , char* name);



void Add(struct Node **head ,char name[], long value, int index)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->index = index;
    new_node->value = value;
    new_node->name = (char *)malloc(sizeof(char *));
    new_node->next = *head;
    strcpy(new_node->name, name);
    *head = new_node;
}

void PrintList(struct Node **head)
{
    struct Node *ptr = *head;
    printf("\n[ ");
    while (ptr != NULL)
    {
        printf("(%ld,%d,%s),", ptr->value, ptr->index, ptr->name);
        ptr = ptr->next;
    }
    printf(" ]");
}

void sort(struct Node **h)
{
    int i,j,a;

    struct Node *temp1;
    struct Node *temp2;

    for(temp1 = *h ; temp1!=NULL ; temp1=temp1->next)
      {
        for(temp2 = temp1->next ; temp2!=NULL ; temp2=temp2->next)
          { 
            if(temp2->value < temp1->value)
              {
                a = temp1->value;
                temp1->value = temp2->value;
                temp2->value = a;
              }
           }
       }
}


int main(){

    struct Node *start = NULL;
    
    Add(&start , "Ahmad" , 13, 0);
    Add(&start , "Ali"   , 10 , 1);
    Add(&start , "Reza" , 20 , 2);
    Add(&start , "AhmadReza" , 80 , 3);
    Add(&start , "Mahdi" , 110 , 4);
    Add(&start , "Melika" , 94 , 5);
    Add(&start , "Asghar" , 1, 6);

    sort(&start);
    PrintList(&start);
    printf("\n");


    printf("Removing \n");
    //printf("%d\n", specification_delete(start));
    specification_delete(&start , 13 , "Ahmad");
    PrintList(&start);
 
/*    printf("%s", "\n");*/ 
    return 0; 
}





int specification_delete(struct Node ** head, long value , char* name) {

    int result = -1;
    struct Node * current = *head;
    struct Node * temp_node = NULL;
    struct Node * now = *head;

    int counter = 0 , counter_x = 0; 

    while(current->next != NULL)
        counter++;

    printf("current :%ld \n" , current->value);


    while(true) 
    {
        counter_x++;

        if (current->next == NULL)
            return -1;
        

        if(current->value == value /*&& current->name == name*/)
        {
            printf("Hello Mamad !!!\n");

            

            for (int i = 0; i < counter_x - 1; ++i)
            {
                Add(&temp_node , now->name , now->value , now->index);
                now = now->next;
            }
            break;
        }

        current = current->next;
            
    }


    for (int i = counter_x; i < counter; ++i)
    {
        Add(&temp_node , current->name , current->value , current->index);
        current = current->next;
    }

    


    printf("Removed Node : \n");
    PrintList(&temp_node);
    printf("\n");

    return result;


}




