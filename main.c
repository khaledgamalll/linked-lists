#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct student_data
{ //Structure for array.
    int ID;
    int date[3];
    int score;
    char name[50];
};
struct student
{ //Linked list node.
    struct student_data d;
    struct student *next;
};
struct student *head = NULL;  //Head pointer.
struct student *tail = NULL;  //Taail pointer.
unsigned int fld_elemnts = 0; //number of filled elements in the array
unsigned int n = 0;           //Number of allocated places for the array
unsigned int n_l = 0;         //Number of nodes in the linked list.
//prototypes.

//Fills the data of a single student(node) in the linked list
void fillnode(struct student_data *node);

//Displays the content of a node in the list
void dispnode(struct student_data *ptr);

//Displays the list of students(nodes) stored.
void displist();

//Inserts a new_student in the array with a specific index
//returns 1 in succesful insertion otherwise 0.
//ind must be a valid value (0<=ind<=fld_elemnts)
int insertind(int ind, struct student *std);


void linked_start(int op);


int main()
{
    printf("------------------WELCOME TO LINKED LISTS ASSIGNMENTS---------------");
    while(1)
        minue();
    return 0;
}

void linked_start(int op)
{
    int ind;//index of insertion.
    struct student *std = (struct student *)malloc(sizeof(struct student)); //Temp structure.
    printf("number of nodes in the list: %d\n\ninsert the index you want to add>>", n_l);
    scanf("%d", &ind);//store index of insertion.
    getchar();//dequeue buffer.
    if (ind > n_l)//if index is bigger than the number of elements in the list.
    {
        printf("\nInvalid index, try again!\n");
        return;
    }
    fillnode(&std->d);//fill the node to be inserted.
    clock_t clocks = clock(); //store number of clocks now.
    insertind(ind, std);
    clocks = clock() - clocks;//number of clocks taken by the processor for insertion.
    displist();//print list.
    printf("time for excuting is: %.12lf sec\n\n", (double)clocks / CLOCKS_PER_SEC);//print the excution time.
}


int insertind(int ind, struct student *std)
{
    if (ind == 0 || n_l == 0)
    { //begining of the list or empty list
        if (tail == NULL)
            tail = std;
        std->next = head;
        head = std;
        n_l++;
    }
    else if (ind == n_l)
    { //adding to the tail of the list.
        std->next = NULL;
        tail->next = std;
        tail = std;
        n_l++;
    }
    //else if (ind > n_l) //invalid index, bigger than number of elements in the list.
    //  return 0;
    else
    { //middel of the list
        struct student *current = head;//temp structure.
        int i = 0;//iterator
        while (current != tail)//loop till end of list.
        {
            if (i == ind - 1)//node before the specified index.
            {
                std->next = current->next;
                current->next = std;
                n_l++;
                break;
            }
            current = current->next;
            i++;
        }
    }
    return 1;
}
void displist()
{
    int i = 0;//iterator.
    struct student *temp;//temp structure.
    temp = head;//start from the first node in the list.
    while (temp != NULL)
    {
        printf("%d:",i++);
        dispnode(&temp->d);
        temp = temp->next;
    }
}
void dispnode(struct student_data *ptr)
{
    printf("the name is : %s\t", ptr->name);
    printf("the ID is : %d  ", ptr->ID);
    printf("the last score is : %d  ", ptr->score);
    printf("the date of birth is : %d  %d  %d  \n\n", ptr->date[0], ptr->date[1], ptr->date[2]);
}
void fillnode(struct student_data *node)
{
    printf("filling the  Node in the list\n");
    printf("Enter the name :");
    gets(node->name); //store a string till a new line charcter entered.
    printf("Enter the ID :");
    scanf("%d", &(node->ID));
    printf("Enter the last score :");
    scanf("%d", &(node->score));
    printf("Enter the date of birth , 1st no.is year >>");
    scanf("%d", &(node->date[0]));
    printf("2nd is month>>");
    scanf("%d", &(node->date[1]));
    printf("third is day>>");
    scanf("%d", &(node->date[2]));
    getchar(); //ignore last charcter in the stream stdin.
}
