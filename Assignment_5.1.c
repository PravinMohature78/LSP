#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char Fname[20];
    sobj.Rollno = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 25;

    printf("Enter the full name : \n");
    scanf("%s", Fname);
    strcpy(sobj.Sname,Fname);


    printf("Roll no. : %d \n",sobj.Rollno);
    printf("Name : %s \n",sobj.Sname);
    printf("Marks. : %f \n",sobj.Marks);
    printf("Age : %d \n",sobj.Age);

    return 0;
    
}