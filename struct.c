//This code is for structures
//Rudraksh Charhate
//I division

#include<stdio.h>

typedef struct student {

        int roll;
        float per;
        char name[30];
}std;

int main() {

    int n;
    printf("Enter number of students : ");
    scanf("%d", &n);

    std stud[n];

    for(int i = 0;i < n;i++) {

       printf("Enter the roll no. of student %d : ", i+1);
       scanf("%d", &stud[i].roll);
       printf("Enter the name of student %d : ", i+1);
       scanf("%s", stud[i].name);
       printf("Enter the percentage of student %d : ", i+1);
       scanf("%f", &stud[i].per);
    }
    for(int i = 1;i < n;i++) {

       std key = stud[i];
       int j = i-1;
       while(j >= 0 && stud[j].per < key.per) {

            stud[j+1] = stud[j];
            j--;
       }
       stud[j+1] = key;
    }
    for(int i = 0;i < n;i++) {

       printf("Roll number: %d | Name: %s | Percentage: %f", stud[i].roll, stud[i].name, stud[i].per);
       printf("\n");
    }
    int r;
    printf("Roll no. you want to find : ");
    scanf("%d", &r);
    int check = 1;
    for(int i = 0;i < n;i++) {

       if(stud[i].roll == r) {
         printf("Roll number: %d | Name: %s | Percentage: %f", stud[i].roll, stud[i].name, stud[i].per);
         check = 0;
         break;
       }

    }
    if(check == 1)
        printf("Roll number not found\n");
return 0;
}



