#include <stdio.h>
#include <string.h>

struct student {
    int roll_no;
    char name[25];
    char fname[25];
    int age;
    float marks;
};

void AddStudent(){
    FILE *fp;
    struct student s;

    fp = fopen("data/student.dat","ab+");
    if (fp == NULL){
        printf("File could not be opened.");
        return;
    }

    printf("\nEnter Roll no:");
    scanf("%d",&s.roll_no);
    getchar();

    printf("Enter Student Name:");
    fgets(s.name,sizeof(s.name),stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Fathers Name:");
    fgets(s.fname,sizeof(s.fname),stdin);
    s.fname[strcspn(s.fname, "\n")] = 0; 

    printf("Enter Age:");
    scanf("%d",&s.age);
    getchar();

    printf("Enter Marks:");
    scanf("%f",&s.marks);
    getchar();

    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);

    printf("Studend Added Sucessfully\n");
}

void SearchStudent(){
    FILE *fp;
    struct student s;
    int roll,found=0;

    fp = fopen("data/student.dat","rb");
    if (fp == NULL){
        printf("File could not be opened.");
        return;
    }

    printf("Enter Roll No to Search:");
    scanf("%d",&roll);
    getchar();

    while (fread(&s,sizeof(s),1,fp)){
        if (s.roll_no == roll){
            printf("\nRoll No: %d\n",s.roll_no);
            printf("Name: %s\n",s.name);
            printf("Father's Name: %s\n",s.fname);
            printf("Age: %d\n",s.age);
            printf("Marks: %.2f\n",s.marks);
            found = 1;
        }
    }
    fclose(fp);

    if (!found){
        printf("Student Not Found\n");
    }
}

void DisplayStudent(){
    FILE *fp;
    struct student s;
    int roll,found=0;

    fp = fopen("data/student.dat","rb");
    if (fp == NULL){
        printf("File could not be opened.");
        return;
    }
    
    printf("\n---------------------------------------------------------------------------\n");
    printf("%-6s %-25s %-25s %-5s %-6s","Roll No","Student Name","Father's Name","Age","Marks");
    printf("\n---------------------------------------------------------------------------\n");

    while (fread(&s,sizeof(s),1,fp)){
        printf("%-6d %-25s %-25s %-5d %-6.2f",
            s.roll_no,
            s.name,
            s.fname,
            s.age,
            s.marks
        );
        found = 1;
    }
    fclose(fp);
    if (!found){
        printf("No Student to Display");
    }
    printf("\n---------------------------------------------------------------------------\n");
}

void UpdateStudent(){
    FILE *fp,*temp;
    struct student s;
    int roll,found = 0;

    fp = fopen("data/student.dat","rb");
    temp = fopen("data/temp.dat","wb");
    if (fp == NULL || temp == NULL){
        printf("File could not be opened");
        return;
    }

    printf("Enter Roll No to be Updated: ");
    scanf("%d",&roll);
    getchar();

    while (fread(&s,sizeof(s),1,fp)){
        if (s.roll_no == roll){
            printf("Enter Student Name:");
            fgets(s.name,sizeof(s.name),stdin);
            s.name[strcspn(s.name, "\n")] = 0;

            printf("Enter Fathers Name:");
            fgets(s.fname,sizeof(s.fname),stdin);
            s.fname[strcspn(s.fname, "\n")] = 0; 

            printf("Enter Age:");
            scanf("%d",&s.age);
            getchar();

            printf("Enter Marks:");
            scanf("%f",&s.marks);
            getchar();

            found = 1;
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("data/student.dat");
    rename("data/temp.dat","data/student.dat");
    
    if(!found){
        printf("No data found");
    }
    else{
        printf("Data updated Successfully");
    }
}

void DeleateStudent(){
    FILE *fp,*temp;
    struct student s;
    int roll,found = 0;

    fp = fopen("data/student.dat","rb");
    temp = fopen("data/temp.dat","wb");
    if (fp == NULL || temp == NULL){
        printf("File could not be opened");
        return;
    }

    printf("Enter Roll No to be Deleted: ");
    scanf("%d",&roll);
    getchar();

    while (fread(&s,sizeof(s),1,fp)){
        if (s.roll_no == roll){
            found = 1;
            continue;
        }
        fwrite(&s,sizeof(s),1,temp);
    }
    fclose(fp);
    fclose(temp);
    remove("data/student.dat");
    rename("data/temp.dat","data/student.dat");
    
    if(!found){
        printf("No data found");
    }
    else{
        printf("Data Deleted Successfully");
    }
}

int main(){
    int n;
    do{
        printf("\n-----------STUDENT MANAGEMENT SYSTEM--------------\n");
        printf("1.Add New Student\n");
        printf("2.Search a Student\n");
        printf("3.Display All Students\n");
        printf("4.Update a Student\n");
        printf("5.Delete a Student\n");
        printf("6.Exit\n");
        printf("Enter Your Choice:");
        scanf("%d",&n);
        getchar();
        switch (n)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            SearchStudent();
            break;
        case 3:
            DisplayStudent();
            break;
        case 4:
            UpdateStudent();
            break;
        case 5:
            DeleateStudent();
            break;
        case 6:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }
    }while (n != 6);
    
}