#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10
void reset()
{
    printf("\033[0m");   //sets the text to default colour
}
void red()
{
    printf("\033[1;31m"); //sets the text colour to red colour
}
void yellow()
{
    printf("\033[1;33m"); //sets the text colour to yellow colour
}
void green()
{
    printf("\033[0;32m"); //sets the text colour to green
}
struct node //struct for main list
{
    int data;
    int roln;
    struct node *next1;
};
float upmark;
struct node *head1;
struct Student
{
    int rollno;
    char name[20];
    char class[30];
    char tutorname[20];
    char address[70];
    char phone[11];
    float Marks;
    float percentage;
    char grade;
    char bgrp[3];
    char speciality[50];
};
struct nod //struct for list (rank list)
{
    struct Student d1;
    struct nod *next;
} * head;

struct Student stack[MAX];
int Top = -1;

void insert(struct Student s1) //function to insert data into list
{

    struct nod *student = (struct nod *)malloc(sizeof(struct nod));
    student->d1 = s1;
    if (head == NULL)
    {
        head = student;
    }
    else
    {
        student->next = head;
        head = student;
    }
}
void push(struct Student data1)   //function to push the data into stack
{
    if (Top == MAX-1)
    {
        printf("\nSTACK IS FULL\n");
    }
    else
    {
        Top++;
        stack[Top] = data1;
    }
    return;
}
struct Student pop()        // poped data is returned 
{
    return stack[Top--];
}
void undo()                 // function to insert the poped data into stack
{
    if (Top == -1)
    {
        printf("STACK IS EMPTY\n");
    }
    else
    {
        struct Student temp = pop();
        insert(temp);
    }
}
void addNode(float data, int rol) //insert roll no and marks in list2
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->roln = rol;
    newNode->next1 = NULL;

    if (head1 == NULL)
    {
        head1 = newNode; //new node is added as head if null
    }
    else
    {
        newNode->next1 = head1;
        head1 = newNode;
    }
}

void gradecalculation(float percent)
{
    if (percent >= 90 && percent <= 100)
        printf("GRADE \t    : O\n");
    if (percent >= 80 && percent < 90)
        printf("GRADE \t    : A\n");
    if (percent >= 70 && percent < 80)
        printf("GRADE \t    : B\n");
    if (percent >= 60 && percent < 70)
        printf("GRADE \t    : C\n");
    if (percent >= 50 && percent < 60)
        printf("GRADE \t    : D\n");
    if (percent < 50)
        printf("GRADE \t    : E\n");
}
void create() //function to get the data from the user
{
    struct Student s1;
    int check = 0;
    struct nod *t;
    t = head;
    printf("ENTER ROLL NUMBER        : ");
    scanf("%d", &s1.rollno);
    while (t != NULL)
    {
        if (t->d1.rollno == s1.rollno)
            check++;
        t = t->next;
    }
    if (check == 0)
    {
        fflush(stdin);
        printf("ENTER NAME               : ");
        scanf("%[^\n]s", s1.name);
        fflush(stdin);
        printf("ENTER CLASS              :");
        scanf("%[^\n]s", s1.class);
        printf("ENTER PHONE NUMBER       : ");
        scanf("%s", s1.phone);
        while ((strlen(s1.phone) != 10))
        {
            red();
            printf("ENTER VALID PHONE NUMBER: ");
            reset();
            scanf("%s", s1.phone);
        }
        printf("ENTER TOTAL MARKS        :");
        scanf("%f", &s1.Marks);
        while (s1.Marks <= 0 || s1.Marks > 500)
        {
            red();
            printf("\nYOUR MARK IS INVALID\n ENTER VALID MARKS(1 to 500):");
            reset();
            scanf("%f", &s1.Marks);
        }
        s1.percentage = ((s1.Marks / 500) * 100);
        fflush(stdin);
        printf("ENTER TUTOR NAME         :");
        scanf("%[^\n]s", s1.tutorname);
        fflush(stdin);
        printf("ENTER THE ADDRESS        :");
        scanf("%[^\n]s", s1.address);
        printf("ENTER BLOOD GROUP        :");
        scanf("%s", s1.bgrp);
        fflush(stdin);
        printf("ENTER SPECIALITY (IF HAS):");
        scanf("%[^\n]s", s1.speciality);
        insert(s1);
        addNode(s1.Marks, s1.rollno); //adding marks and roll no to rank list
    }
    else
    {
        red();
        printf("THIS ROLL NUMBER ALREADY EXIST!! ?");
        reset();
    }
}

void search(int rollno) //function to search the record
{
    struct nod *temp = head;
    while (temp != NULL)
    {
        if (temp->d1.rollno == rollno)
        {
            printf("\nRECORD WITH ROLL NUMBER %d FOUND ? \n", rollno);
            printf("\n------------------------------------------------\n");
            printf("ROLL NUMBER : %d\n", temp->d1.rollno);
            printf("NAME        : %s\n", temp->d1.name);
            printf("CLASS       : %s\n", temp->d1.class);
            printf("PHONE NUMBER: %s\n", temp->d1.phone);
            printf("PERCENTAGE  : %0.4f\n", temp->d1.percentage);
            printf("TOTAL MARKS : %0.4f\n", temp->d1.Marks);
            printf("TUTOR NAME  : %s\n", temp->d1.tutorname);
            printf("ADDRESS     : %s\n", temp->d1.address);
            gradecalculation(temp->d1.percentage);
            printf("BLOOD GROUP : %s\n", temp->d1.bgrp);
            printf("SPECIALITY  : %s\n", temp->d1.speciality);
            printf("\n------------------------------------------------\n");
            return;
        }
        temp = temp->next;
    }
    printf("\n------------------------------------------------\n");
    red();
    printf("\n\nSTUDENT WITH ROLL NUMBER %d NOT FOUND!!! ?\n", rollno);
    reset();
    printf("\n------------------------------------------------\n");
}
void update(int rollno) //function to modify the student record
{

    struct nod *temp = head;
    while (temp != NULL)
    {

        if (temp->d1.rollno == rollno)
        {
            printf("\n---------------------------------------\n");
            green();
            printf("\nRECORD WITH ROLL NUMBER %d FOUND \n", rollno);
            reset();
            fflush(stdin);
            printf("ENTER NEW NAME           : ");
            scanf("%[^\n]s", temp->d1.name);
            fflush(stdin);
            printf("ENTER NEW CLASS NAME     : ");
            scanf("%[^\n]s", temp->d1.class);
            printf("ENTER NEW PHONE NUMBER   : ");
            fflush(stdin);
            scanf("%s", temp->d1.phone);
            printf("ENTER NEW MARKS          :");
            scanf("%f", &temp->d1.Marks);
            while (temp->d1.Marks <= 0 || temp->d1.Marks > 500)
            {
                red();
                printf("\nYOUR MARK IS INVALID\n ENTER VALID MARKS(1 to 100):");
                reset();
                scanf("%f", &temp->d1.Marks);
            }
            temp->d1.percentage = ((temp->d1.Marks / 500) * 100);
            upmark = temp->d1.Marks;
            fflush(stdin);
            printf("ENTER NEW TUTOR NAME     :");
            scanf("%[^\n]s", temp->d1.tutorname);
            fflush(stdin);
            printf("ENTER NEW ADDRESS        :");
            scanf("%[^\n]s", temp->d1.address);
            fflush(stdin);
            printf("ENTER NEW BLOOD GROUP    :");
            scanf("%s", temp->d1.bgrp);
            fflush(stdin);
            printf("ENTER SPECIALITY (IF HAS):");
            scanf("%[^\n]s", temp->d1.speciality);
            green();
            printf("UPDATION IS SUCCESSFULL!!! ?\n");
            reset();
            printf("\n---------------------------------------\n");
            return;
        }
        temp = temp->next;
    }
    printf("\n------------------------------------------------\n");
    red();
    printf("\nSTUDENT WITH ROLL NUMBER %d NOT FOUND!!! ?\n", rollno);
    reset();
    printf("\n------------------------------------------------\n");
}
void delmarks(int rollno) //function to delete the marks in list
{
    struct node *t1 = head1;
    struct node *t2 = head1;
    while (t1 != NULL)
    {
        if (t1->roln == rollno)
        {
            if (t1 == t2)
            {
                head1 = head1->next1;
                free(t1);
            }
            else
            {
                t2->next1 = t1->next1;
                free(t1);
            }
            return;
        }
        t2 = t1;
        t1 = t1->next1;
    }
}
void Delete(int rollno) //function to delete that paticular record
{
    struct nod *temp1 = head;
    struct nod *temp2 = head;
    int ch;
    while (temp1 != NULL)
    {

        if (temp1->d1.rollno == rollno)
        {
            printf("\n------------------------------------------------\n");
            printf("\nRECORD WITH ROLL NUMBER %d FOUND ? \n", rollno);
            if (temp1 == temp2)
            {
                head = head->next;
                push(temp1->d1);
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                push(temp1->d1);
                free(temp1);
            }
            green();
            printf("\nRECORD DELETED SUCCESSFULLY !!! ?\n");
            reset();
            printf("\n------------------------------------------------\n");
            printf("\nDO YOU WANT TO UNDO THIS DELETION (YES->1 AND NO->0):");
            scanf("%d", &ch);
            if(ch==1){
                undo();
            }
            else {
                delmarks(rollno);
            }
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    printf("\n------------------------------------------------\n");
    red();
    printf("STUDENT WITH ROLL NUMBER %d NOT FOUND!!! ?\n", rollno);
    reset();
    printf("\n------------------------------------------------\n");
}
void display() //display all records in list
{
    struct nod *temp = head;
    while (temp != NULL)
    {
        printf("\n------------------------------------------------\n");
        printf("ROLL NUMBER : %d\n", temp->d1.rollno);
        printf("NAME        : %s\n", temp->d1.name);
        printf("CLASS       : %s\n", temp->d1.class);
        printf("PHONE NUMBER: %s\n", temp->d1.phone);
        printf("PERCENTAGE  : %0.4f\n", temp->d1.percentage);
        printf("TOTAL MARKS : %0.4f\n", temp->d1.Marks);
        printf("TUTOR NAME  : %s\n", temp->d1.tutorname);
        printf("ADDRESS     : %s\n", temp->d1.address);
        gradecalculation(temp->d1.percentage);
        printf("BLOOD GROUP : %s\n", temp->d1.bgrp);
        printf("SPECIALITY  : %s\n", temp->d1.speciality);
        printf("\n------------------------------------------------\n");
        temp = temp->next;
    }
    if (head == NULL)
    {
        printf("\n------------------------------------------------\n");
        red();
        printf("\nTHERE ARE NO RECORDS IN THE DATABASE!! ?");
        reset();
        printf("\n------------------------------------------------\n");
    }
}
void sortList() // sorting the list
{
    struct node *current = head1, *index = NULL;
    int temp, temprol;
    if (head1 == NULL) //if list is empty
    {
        return;
    }
    else
    {
        while (current != NULL)
        {
            index = current->next1; //points to second element

            while (index != NULL)
            {
                if (current->data < index->data)
                {
                    temp = current->data;      //swapping the adjacent element if current is lesser
                    temprol = current->roln;
                    current->data = index->data;
                    current->roln = index->roln;
                    index->data = temp;
                    index->roln = temprol;
                }
                index = index->next1;
            }
            current = current->next1;
        }
    }
}
void dispmarks() //displays only 10 students who secured rank from 1 to 10
{
    int count = 0;
    struct node *current = head1;
    if (head1 == NULL)
    {
        red();
        printf("THE LIST IS EMPTY \n");
        reset();
        return;
    }
    printf("\n----------------------\n");
    yellow();
    printf("RANK\tROLLNO\tMARKS");
    reset();
    printf("\n----------------------\n");
    while (current != NULL)
    {
        printf("\n%d", count + 1);
        printf("       %d\t", current->roln);
        printf("%d ", current->data);
        printf("\n");
        current = current->next1;
        count++;
        if (count >= 10)
            break;
    }
    printf("\n");
}

void updatemarks(int rollno) //update the marks in list
{
    struct node *temp = head1;
    while (temp != NULL)
    {

        if (temp->roln == rollno)
        {
            temp->data = upmark;
            return;
        }
        temp = temp->next1;
    }
}

void addrank() //function to copy the marks and roll no from main list to rank list
{
    struct nod *temp = head;
    while (temp != NULL)
    {
        addNode(temp->d1.Marks, temp->d1.rollno);
        temp = temp->next;
    }
}
void read_binary(FILE *f1) // reading the data from file and inserting into the list
{
    struct Student s;
    head = NULL;
    while (fread(&s, sizeof(s), 1, f1))
    {
        insert(s);
    }
}
void write_binary(FILE *f1) //function to copy the data in list to file
{
    struct Student s;
    struct nod *temp;
    temp = head;
    while (temp != NULL)
    {
        s = temp->d1;
        fwrite(&s, sizeof(s), 1, f1);
        temp = temp->next;
    }
}
void writefile()
{
    FILE *f1;
    f1 = fopen("stud.dat", "wb");
    write_binary(f1);
    fclose(f1);
}
void bldgrp() // function to find the student record having same blood group
{
    int check = 0;
    char bg[3];
    printf("ENTER THE BLOOD GROUP: ");
    fflush(stdin);
    scanf("%[^\n]s", bg);
    struct nod *temp = head;
    while (temp != NULL)
    {
        if (strcmp(temp->d1.bgrp, bg) == 0)
        {
            printf("\n---------------------------------\n");
            printf("ROLL NUMBER : %d\n", temp->d1.rollno);
            printf("NAME        : %s\n", temp->d1.name);
            printf("CLASS       : %s\n", temp->d1.class);
            printf("PHONE NUMBER: %s\n", temp->d1.phone);
            printf("\n---------------------------------\n");
            check++;
        }
        temp = temp->next;
    }
    if (check == 0)
    {
        printf("\n------------------------------------------------\n");
        red();
        printf("\nSTUDENT WITH BLOOD GROUP [ %s ] NOT FOUND !!! ?\n", bg);
        reset();
        printf("\n------------------------------------------------\n");
    }
}
int login()
{
    char username[15];
    char password[12];
    printf("\n---------------------------------------------------------------\n");
    printf("\n\n\t\t\t *** LOGIN PAGE ***");
    printf("\n\nENTER YOUR USER NAME:");
    scanf("%s", username);
    printf("\nENTER YOUR PASSWORD:");
    scanf("%s", password);
    printf("\n---------------------------------------------------------------\n");
    if (strcmp(username, "admin") == 0)
    {
        if (strcmp(password, "cit123") == 0)
        {

            printf("\n\t\t\tLOGIN SUCCESSFULL ?\n");

            return 1;
        }
        else
        {
            printf("\n\t\t\tWRONG PASSWORD  ?\n\n");

            return 0;
        }
    }
    else
    {
        printf("\n\t\t\tUSER NAME DOSE NOT EXIST ?\n\n");
        return 0;
    }
}
int main()
{
    head = NULL;
    int choice;
    int rollno, confirm;
    FILE *f1;
    f1 = fopen("stud.dat", "rb");
    read_binary(f1); //reads the record in file and insert into list
    fclose(f1);
    addrank(); //adds the marks and roll number into rank list (for data in file)
    confirm = login();
    if (confirm == 1)
    {

        do
        {
            system("pause");
			system("cls");
            printf("\n------------------------------------------------------------------------------------------------\n");
            yellow();
            printf("\n\n\t\t\t\t******* ?? STUDENT DATABASE ?? *******");
            reset();
            printf("\n------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t1. ADD DETAILS ??\n\n\t2. SEARCH A RECORD ??\n\n\t3. DELETE A RECORD ??\n\n\t4. MODIFY A RECORD ??\n\n\t5. DISPLAY ALL THE RECORDS ??\n\n\t6. STUDENT RANK LIST ??\n\n\t7. SEARCH FOR BLOOD GROUP ??\n\n\t0. EXIT ??");
            printf("\n------------------------------------------------\n");
            printf("\n\nENTER CHOICE: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                create();
                break;
            case 2:
                printf("\nENTER ROLL NUMBER TO SEARCH: ");
                scanf("%d", &rollno);
                search(rollno);
                break;
            case 3:
                printf("\nENTER ROLL NUMBER TO DELETE: ");
                scanf("%d", &rollno);
                Delete(rollno);
                break;
            case 4:
                printf("\nENTER ROLL NUMBER TO UPDATE: ");
                scanf("%d", &rollno);
                update(rollno);
                updatemarks(rollno);
                break;
            case 5:
                printf("\n------------------------------------------------\n");
                yellow();
                printf("\n\t      ** ALL DETAILS **\n");
                reset();
                display();
                break;
            case 6:
                sortList();
                printf("\nTHE FOLLOWING STUDENTS ARE SELECTED FOR THE COMPETITION\n\n");
                dispmarks();
                break;
            case 7:
                bldgrp();
                break;
            case 0:
                writefile(); //before exit copying the records in list to file
                exit(0);
                break;
            default:
                red();
                printf("\nINVALID CHOICE!!");
                reset();
            }
        } while (choice != 0);
    }
    return 0;
}
