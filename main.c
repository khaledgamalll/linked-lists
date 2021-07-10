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


//Start a program to store the data of students in an array.
//takes the pointer to the structure as input, a (op)to choose(1:insertion with actual values,2:random values).
void arr_start(struct student_data *a, int op);

//insert a new student (new_student) at a specific index (ind) in an array (a)
//Updates the global variables n and fld_elemnts.
//ind must be a valid value (0<=ind<=fld_elemnts)
void insertarr_ind(int ind, struct student_data *ptr, struct student_data new_student, int op);


void minue();

int main()
{  printf("---------welcome to the linkedist assignment----------");
    while(1)
        minue();
    return 0;
}
void minue()
{
    fld_elemnts = 0; //number of filled elements in the array
    n = 0;          //Number of allocated places for the array
    n_l = 0;       //Number of nodes in the linked list.
    head = NULL;  //Initialize the head and the tail pointers
    tail = NULL;
    int choice, op = 0,ind; //variables for storing the choice,index and whether to start with random variables or not.
    char y;     //variable to deside whether to continue inserting or not.
    struct student_data*a; //pointer for array.
    struct student_data temp; //structure to store date befor insertion.
    printf("1:array\n2:linkedlist\n\n>>");
    scanf("%d", &choice);
    switch (choice)  //start insertion on choice (1: array, 2:liked list).
    {
    case 1:
        printf("insert the number of elements in the array>>");
        scanf("%d", &n);
        printf("the size of a single node: %d bytes\n",sizeof(struct student_data));
        printf("the size of all nodes: %d bytes\n\n",n*sizeof(struct student_data));
        //allocate space for the array in the heap.
        struct student_data *a = (struct student_data *)calloc(n , sizeof(struct student_data));
        do
        {
            if (op == 0)//initial excution.
            {
                printf("1:actual array values\n2:randomized values\n\n>>");
                scanf("%d", &op);
            }
            arr_start(a, op);//insert in array.
            if (op == 2)
                break;
            printf("continue?(y,n)>>");//continue inserting.
            scanf("%c", &y);
        } while (y != 'n');
        break;
    case 2:
        do
        {
            if (op == 0) //initial insertion.
            {
                printf("1:actual array values\n2:randomized values\n\n>>");
                scanf("%d", &op);
            }
            if (op == 2)//random values for nodes.
            {
                printf("insert the number of elements in the list>>");
                scanf("%d", &ind);
                printf("the size of a single node: %d bytes\n",sizeof(struct student));
                printf("the size of all nodes: %d bytes\n\n",ind*sizeof(struct student));
                for (int i = 0; i < ind; i++)//Create a linked list with random values for each node.
                {
                    struct student *s = (struct student *)malloc(sizeof(struct student));
                    insertind(0, s);//insert the node to the linked list.
                }
            }
            linked_start(op);//start insertion.
            if (op == 2)
                break;
            printf("continue?(y,n)>>");//Continue insertion.
            scanf("%c", &y);
        } while (y != 'n');
        break;
    }
}

void arr_start(struct student_data *a, int op)
{
    int ind;//index of insertion.
    if(op==2) //insertion with randomized values.
        fld_elemnts = n;
    printf("number of elements in the array: %d\n\ninsert the index you want to add>>", fld_elemnts);
    scanf("%d", &ind);//storing the index of insertion.
    if (ind > fld_elemnts)//index greater than the number of filled nodes in the array.
    {
        printf("wrong index!\n\n");
        return;
    }
    getchar();//dequeue the input buffer.
    struct student_data std;//temp structure.
    fillnode(&std);//filling the temp structure to store it in the array.
    clock_t clocks = clock();
    insertarr_ind(ind, a, std, op);//insert node in the array.
    clocks = clock() - clocks;
        for (int u = 0; u < fld_elemnts; u++){//display the array.
            printf("%d:",u);
            dispnode(a + u);
        }
    printf("time for excuting is: %.12lf sec\n\n", (double)clocks / CLOCKS_PER_SEC);
}
void insertarr_ind(int ind, struct student_data * ptr, struct student_data new_student, int op)
{
    if (fld_elemnts == n)
    {                                                                               //If the array is full
        n++;                                                                        //increment the number of places.
        ptr = (struct student_data *)realloc(ptr, n * sizeof(struct student_data)); //add an block to the array.
    }
    printf("%d\n",fld_elemnts);
    for (int i = fld_elemnts; i > ind; i--) //Moving each element to the next index.
        *(ptr + i) = *(ptr + i - 1);
    *(ptr + ind) = new_student; //filling the data of the first element with the data of the new student.
    fld_elemnts++;              //Updating the global variable(filled elements in the array).
}

