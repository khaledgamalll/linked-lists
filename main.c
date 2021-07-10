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
int main()
{
printf("---------welcome to the linkedist assignment----------");
    return 0;

}
