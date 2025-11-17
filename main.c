#include <stdio.h>
#include <string.h>
//structure declaration

struct Student{
    int SAP_ID;
    char Roll_no[20];
    char Name[50];
    char Phone_no[11];
    char Email_ID[50];
    int Year;
    int Semester;
    float SGPA;

}records[50];
int counter=5;
//function declaration
int ADDITION(int counter, struct Student records[]);

int DELETION(int counter, struct Student records[]);

int Menu();

void clear_buffer();

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//ADDITION FUNCTION

int ADDITION(int counter, struct Student records[])
{
    char trash;
    int n;
    printf("enter how many records you want to add");
    scanf("%d",&n);
    for (int i=counter;i<counter+n;i++)
    {
        printf("enter records of student no. %d (SAP ID )\n",i+1);
        scanf("%d",&records[i].SAP_ID);
        clear_buffer();
        printf("enter records of student no. %d (Roll no. )\n",i+1);
        scanf("%s",records[i].Roll_no);  
        clear_buffer();        
        printf("enter records of student no. %d (Name)\n",i+1);
        fgets(records[i].Name,sizeof(records[i].Name), stdin);
        printf("enter records of student no. %d (Phone no.)\n",i+1);
        scanf("%s",records[i].Phone_no);
        clear_buffer(); 
        printf("enter records of student no. %d (Email)\n",i+1);
        fgets(records[i].Email_ID,sizeof(records[i].Email_ID), stdin);
        printf("enter records of student no. %d (Year)\n",i+1);
        scanf("%d",&records[i].Year);
        printf("enter records of student no. %d (Semester)\n",i+1);
        scanf("%d",&records[i].Semester);
        printf("enter records of student no. %d (SGPA)\n",i+1);
        scanf("%f",&records[i].SGPA);                                       
    }
    printf("\n");
    printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\n", 
       records[5].SAP_ID,
       records[5].Roll_no,
       records[5].Name,
       records[5].Phone_no,
       records[5].Email_ID,
       records[5].Year,
       records[5].Semester,
       records[5].SGPA);
    printf("Thank you, Now returning to the menu.\n");
    printf("\n");
    Menu();
    return counter+n;                                    
    

}

// DELETION FUNCTION

int DELETION(int counter, struct Student records[])
{
    printf("hello this is also being worked on bye \n");
    Menu();
    return counter;
}

//Body of the menu function

int Menu()
{
    int choice,choice2;
    while(1)
        {
            printf("(1)To Perform Operations Related to Addition or Deletion of New Records.\n"
                    "(2)To Perform Operations Related to Calculations of Present Records.\n"
                    "(3)To Perform Operations Related to Displaying of Records.\n"
                    "enter your choice\n");
            scanf("%d",&choice);
            if (choice==1)
            {
                while(1)
                {
                    printf("Which type of addition command do you want to perform: -\n"
                            "(1)Add New Records with field such as SAP ID, ROll no, etc.\n"
                            "(2)Delete Records of a existing student.\n"
                            "enter your choice\n");
                    scanf("%d",&choice2);
                    if (choice2==1)
                    {
                        counter=ADDITION(counter, records);
                        printf("The number of records currently present in database is %d",counter);
                    }
                    else if (choice2==2)
                    {
                        counter=ADDITION(counter, records);
                    }
                    else    
                    {
                        printf("enter a valid option\n");
                        continue;
                    }
                }
            }
            else if (choice==2)
            {
                printf("Which type of Calculation Operation you want to perform: -\n"
                        "(1)Calculate CGPA till the year the student is in at present.\n"
                        "(2)Calculate CGPA average of all students of each year.\n"
                        "enter your choice\n");
            }
            else if (choice==3)
            {
                printf("Which Type of Operation related to Displaying of Records you want to perform: -"
                        "(1)Display all records present."
                        "(2)Display record of a particualr student"
                        "enter your choice\n");
            }
            else
            {
                printf("Please enter a valid option\n");
                continue;
            }
        }
    
}

//main body of function 

int main()
{
    char n;
    printf("=============================Welcome To Student Record and Management System=============================\n");
    printf("                                        Press enter to continue");
    scanf("%c",&n);
	
	// --- RECORD 1 ---
	records[0].SAP_ID = 590032818; 
	strcpy(records[0].Roll_no, "25010100281");
	strcpy(records[0].Name, "Sneyhil S K Yadav");
	strcpy(records[0].Phone_no, "8844391754");
	strcpy(records[0].Email_ID, "buh1g@gmail.com");
	records[0].Year = 1;
	records[0].Semester = 1;
	records[0].SGPA = 7.4;
	
	// --- RECORD 2 ---
	records[1].SAP_ID = 601135709; 
	strcpy(records[1].Roll_no, "26021500302"); 
	strcpy(records[1].Name, "Aarav Sharma");
	strcpy(records[1].Phone_no, "9912345678"); 
	strcpy(records[1].Email_ID, "aarav.s@uni.in");
	records[1].Year = 2;
	records[1].Semester = 3;
	records[1].SGPA = 8.1;
	
	// --- RECORD 3 ---
	records[2].SAP_ID = 589001234; 
	strcpy(records[2].Roll_no, "24050110411"); 
	strcpy(records[2].Name, "Priya Kulkarni");
	strcpy(records[2].Phone_no, "7089012345"); 
	strcpy(records[2].Email_ID, "priya.k@mail.org");
	records[2].Year = 4;
	records[2].Semester = 7;
	records[2].SGPA = 9.2;
	
	// --- RECORD 4 ---
	records[3].SAP_ID = 610543210; 
	strcpy(records[3].Roll_no, "27001000507"); 
	strcpy(records[3].Name, "Vishal Singh");
	strcpy(records[3].Phone_no, "8055678901"); 
	strcpy(records[3].Email_ID, "v.singh@campus.edu");
	records[3].Year = 3;
	records[3].Semester = 5;
	records[3].SGPA = 6.9;
	
	// --- RECORD 5 ---
	records[4].SAP_ID = 599876543; 
	strcpy(records[4].Roll_no, "25032000620"); 
	strcpy(records[4].Name, "Zoya Ansari");
	strcpy(records[4].Phone_no, "9321098765"); 
	strcpy(records[4].Email_ID, "zoya.a@xyz.com");
	records[4].Year = 1;
	records[4].Semester = 2;
	records[4].SGPA = 7.95;
    Menu();
    return 0;

    
}
