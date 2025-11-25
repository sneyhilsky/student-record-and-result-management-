#include <stdio.h>
#include <string.h>
//structure declaration

struct Student{
    int SAP_ID;
    char Roll_no[20];
    char Name[50];
    char Phone_no[11];
    char Email_ID[50];
    int Year[4];
    int Semester[8];
    float SGPA[8];
    float CGPA;

}records[50],temp[1];
int counter=5;
int n;
int m=0;
//function declaration
int ADDITION(int count, struct Student records[],int n);

int DELETION(int count, struct Student records[]);

int DISPLAY(int counter, struct Student records[],int m,struct Student temp[]);

float Calculation(int counter, struct Student records[], int xy, int i);

int Calcu_year(int counter, struct Student records[], int xy);

int Menu();

void clear_buffer();

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


//ADDITION FUNCTION

int ADDITION(int count, struct Student records[],int n)
{
    char trash;
    int xy;
    count=count-n;
    int h=count + n;

    for (int i=count;i<h;i++)
    {
        printf("enter records of student no. %d (SAP ID )\n",i+1);
        scanf("%d",&records[i].SAP_ID);
        printf("enter records of student no. %d (Roll no. )\n",i+1);
        scanf("%s",records[i].Roll_no); 
        clear_buffer();  
        printf("enter records of student no. %d (Name)\n",i+1);
        fgets(records[i].Name,sizeof(records[i].Name), stdin);
        clear_buffer(); 
        printf("enter records of student no. %d (Phone no.)\n",i+1);
        scanf("%s",records[i].Phone_no);
        clear_buffer(); 
        printf("enter records of student no. %d (Email)\n",i+1);
        fgets(records[i].Email_ID,sizeof(records[i].Email_ID), stdin);
        clear_buffer(); 
        printf("Enter current year of student");
        scanf("%d",&xy);
        for(int j=0;j<xy;j++)
        {
            records[i].Year[j]=j+1;
            records[i].Semester[j]=j+1;
        }
        for(int k=0;k<2*xy;k++)
        {
            printf("enter SGPA for semester %d ",k+1);
            scanf("%f",&records[i].SGPA[k]);
        }
        records[i].CGPA=Calculation(counter, records, xy, i);
    }

    printf("\n");
    printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nCGPA: %.2f",
    records[5].SAP_ID,
    records[5].Roll_no,
    records[5].Name,
    records[5].Phone_no,
    records[5].Email_ID,
    records[5].Year[0],
    records[5].Semester[0],
    records[5].SGPA[0],
    records[5].Semester[1],
    records[5].SGPA[1],
    records[5].Year[1],
    records[5].Semester[2],
    records[5].SGPA[2],
    records[5].Semester[3],
    records[5].SGPA[3],
    records[5].Year[2],
    records[5].Semester[4],
    records[5].SGPA[4],
    records[5].Semester[5],
    records[5].SGPA[5],
    records[5].Year[3],
    records[5].Semester[6],
    records[5].SGPA[6],
    records[5].Semester[7],
    records[5].SGPA[7],
    records[5].CGPA);

    records[h].SAP_ID = 0; 
	strcpy(records[h].Roll_no, ""); 
	strcpy(records[h].Name, ""); 
	strcpy(records[h].Phone_no, ""); 
	strcpy(records[h].Email_ID, ""); 

	records[h].Year[0] = 0; 	
	records[h].Semester[0] = 0;
	records[h].SGPA[0] = 0.0; 

	records[h].Semester[1] = 0;
	records[h].SGPA[1] = 0.0;

	records[h].Year[1] = 0; 	 	
	records[h].Semester[2] = 0;
	records[h].SGPA[2] = 0.0;

	records[h].Semester[3] = 0;
	records[h].SGPA[3] = 0.0;

	records[h].Year[2] = 0; 	
	records[h].Semester[4] = 0;
	records[h].SGPA[4] = 0.0;

	records[h].Semester[5] = 0;
	records[h].SGPA[5] = 0.0;

	records[h].Year[3] = 0; 	 	
	records[h].Semester[6] = 0;
	records[h].SGPA[6] = 0.0;
		 	
	records[h].Semester[7] = 0;
	records[h].SGPA[7] = 0.0;
    printf("Thank you, Now returning to the menu.\n");
    printf("\n");
    Menu();

    
}

// DELETION FUNCTION

int DELETION(int count, struct Student records[])
{
    count=count+1;
    int D=0;
    int SAPID;
    printf("Enter the SAP ID of student whose records you want to delete. ");
    scanf("%d",&SAPID);
    for(int i=0;i<count;i++)
    {
        if(SAPID==records[i].SAP_ID)
        {
            D=i;
        }
    }
    for(D;D<count;D++)
    {
        memmove(&records[D], &records[D + 1], sizeof(struct Student));
    }
    printf("\n");
    printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\n", 
    records[5].SAP_ID,
    records[5].Roll_no,
    records[5].Name,
    records[5].Phone_no,
    records[5].Email_ID,
    records[5].Year[1],
    records[5].Semester[1],
    records[5].SGPA[2]);
    printf("Thank you, Now returning to the menu.\n");
    printf("\n");

    Menu();
}

//DISPLAY FUNCTION

int DISPLAY(int counter, struct Student records[],int m,struct Student temp[])
{
    int value;
    int choice1,choice2,choice3;

    if (m==0)
    {
        while(1)
        {
            printf("How do you want to sort the records: -\n"
                    "(1)In ascending order of their Name\n"
                    "(2)In ascending order of their SAP ID\n");
            scanf("%d",&choice1);
            if (choice1==1)
            {
                for (int i=0;i<counter-1;i++)
                {
                    for (int j=0;j<counter-i-1;j++)
                    {
                        value=strcmp(records[j].Name,records[j+1].Name);
                        if(value>0)
                        {
                            temp[1]=records[j];
                            memmove(&records[j], &records[j + 1], sizeof(struct Student));
                            memmove(&records[j + 1], &temp[1], sizeof(struct Student));

                        }
                    }
                }
                for(int h=0;h<counter;h++)
                {   
                    printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n",
                    records[h].SAP_ID,
                    records[h].Roll_no,
                    records[h].Name,
                    records[h].Phone_no,
                    records[h].Email_ID,
                    records[h].Year[0],
                    records[h].Semester[0],
                    records[h].SGPA[0],
                    records[h].Semester[1],
                    records[h].SGPA[1],
                    records[h].Year[1],
                    records[h].Semester[2],
                    records[h].SGPA[2],
                    records[h].Semester[3],
                    records[h].SGPA[3],
                    records[h].Year[2],
                    records[h].Semester[4],
                    records[h].SGPA[4],
                    records[h].Semester[5],
                    records[h].SGPA[5],
                    records[h].Year[3],
                    records[h].Semester[6],
                    records[h].SGPA[6],
                    records[h].Semester[7],
                    records[h].SGPA[7]);
                }
            }
            else if (choice1==2)
            {
                for (int i=0;i<counter-1;i++)
                {
                    for (int j=0;j<counter-i-1;j++)
                    {
                        if(records[j].SAP_ID>records[j+1].SAP_ID)
                        {
                            temp[1]=records[j];
                            memmove(&records[j], &records[j + 1], sizeof(struct Student));
                            memmove(&records[j + 1], &temp[1], sizeof(struct Student));
                            
                        }
                        
                    }
                }
                for(int h=0;h<counter;h++)
                {   
                    printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n",
                    records[h].SAP_ID,
                    records[h].Roll_no,
                    records[h].Name,
                    records[h].Phone_no,
                    records[h].Email_ID,
                    records[h].Year[0],
                    records[h].Semester[0],
                    records[h].SGPA[0],
                    records[h].Semester[1],
                    records[h].SGPA[1],
                    records[h].Year[1],
                    records[h].Semester[2],
                    records[h].SGPA[2],
                    records[h].Semester[3],
                    records[h].SGPA[3],
                    records[h].Year[2],
                    records[h].Semester[4],
                    records[h].SGPA[4],
                    records[h].Semester[5],
                    records[h].SGPA[5],
                    records[h].Year[3],
                    records[h].Semester[6],
                    records[h].SGPA[6],
                    records[h].Semester[7],
                    records[h].SGPA[7]);
                }
            }
                

        }
    }
    else if (m!=0)
    {
        for (int i=0;i<counter;i++)
        {
            if(records[i].SAP_ID==m)
            {
  
                printf("SAP ID: %d \nRoll no.: %s \nName: %s\nPhone no: %s\nEmail ID: %s\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n\nYear: %d\nSemester: %d\nSGPA: %.2f\nSemester: %d\nSGPA: %.2f\n",
                records[i].SAP_ID,
                records[i].Roll_no,
                records[i].Name,
                records[i].Phone_no,
                records[i].Email_ID,
                records[i].Year[0],
                records[i].Semester[0],
                records[i].SGPA[0],
                records[i].Semester[1],
                records[i].SGPA[1],
                records[i].Year[1],
                records[i].Semester[2],
                records[i].SGPA[2],
                records[i].Semester[3],
                records[i].SGPA[3],
                records[i].Year[2],
                records[i].Semester[4],
                records[i].SGPA[4],
                records[i].Semester[5],
                records[i].SGPA[5],
                records[i].Year[3],
                records[i].Semester[6],
                records[i].SGPA[6],
                records[i].Semester[7],
                records[i].SGPA[7]);
                
            }
        }
    }

}

float Calculation(int counter, struct Student records[], int xy, int i)
{
    float sgpa=0.0,cgpa;
    if(xy==1)
    {
        sgpa=records[i].SGPA[0]+records[i].SGPA[1];
        cgpa=sgpa/2;
    }
    else if(xy==2)
    {
        sgpa=records[i].SGPA[0]+records[i].SGPA[1]+records[i].SGPA[2]+records[i].SGPA[3];
        cgpa=sgpa/4;
    }
    else if(xy==3)
    {
        sgpa=records[i].SGPA[0]+records[i].SGPA[1]+records[i].SGPA[2]+records[i].SGPA[3]+records[i].SGPA[4]+records[i].SGPA[5];
        cgpa=sgpa/6;
    }
    else if(xy==4)
    {
        sgpa=records[i].SGPA[0]+records[i].SGPA[1]+records[i].SGPA[2]+records[i].SGPA[3]+records[i].SGPA[4]+records[i].SGPA[5]+records[i].SGPA[6]+records[i].SGPA[7];
        cgpa=sgpa/8;
    }
    return cgpa; 
}

int Calcu_year(int counter, struct Student records[], int xy)
{
    int count=0;
    int i=0,j=0;
    float sum=0,avg;
    for(i;i<counter;i++)
    {
        if(records[i].Year[xy-1]==xy)
        {
            sum=sum+records[i].CGPA;
            j++;
        }
    }
    avg=sum/j;
    printf("The average CGPA of all students of year %d is %f",xy,avg);
}
//Body of the menu function

int Menu()
{
    int choice,choice2;
    while(1)
        {
            printf("(1)To Perform Operations Related to Addition or Deletion of New Records.\n"
                    "(2)To Display CGPA average of all students of a particular year.\n"
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
                            "(3)if you want to return to the previous menu\n"
                            "enter your choice\n");
                    scanf("%d",&choice2);
                    if (choice2==1)
                    {
                        printf("enter no. of records you want to add");
                        scanf("%d",&n);
                        counter=counter+n;
                        ADDITION(counter, records,n);
                        
                    }
                    else if (choice2==2)
                    {
                        counter=counter-1;
                        DELETION(counter, records);
                        
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
                printf("enter the year for which you want CGPA Average");
                scanf("%d",&n);
                Calcu_year(counter, records, n);
                printf("\nThank you for using it.!\n");
                break;
            }
            else if (choice==3)
            {
                while(1)
                {
                    printf("Which Type of Operation related to Displaying of Records you want to perform: -\n"
                            "(1)Display all records present.\n"
                            "(2)Display record of a particualr student\n"
                            "(3)if you want to return to the previous menu\n"
                            "enter your choice\n");

                    scanf("%d",&choice2);
                    if (choice2==1)
                    {
                        DISPLAY(counter, records, m, temp);
                        

                    }
                    else if (choice2==2)
                    {
                        printf("enter SAP ID of the student\n");
                        scanf("%d",&m);
                        DISPLAY(counter, records, m, temp);

                    }
                    else if (choice2==3)
                    {
                        break;
                    }
                    
                    else
                    {
                    printf("Please enter a valid option\n");
                    continue;
                    }

                }
                
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
    int xy=0,i=0;
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
	records[0].Year[0] = 1;
	records[0].Semester[0] = 1;
	records[0].SGPA[0] = 7.4;
    records[0].Semester[1] = 2;
	records[0].SGPA[1] = 8.4;
    xy=1;
    i=0;
    records[0].CGPA=Calculation(counter, records, xy, i);
	
	// --- RECORD 2 ---
	records[1].SAP_ID = 601135709; 
	strcpy(records[1].Roll_no, "26021500302"); 
	strcpy(records[1].Name, "Aarav Sharma");
	strcpy(records[1].Phone_no, "9912345678"); 
	strcpy(records[1].Email_ID, "aarav.s@uni.in");
	records[1].Year[0]=1;
    records[1].Year[1]=2;
	records[1].Semester[0]=1;
    records[1].Semester[1]=2;
	records[1].SGPA[0]= 8.1;
    records[1].SGPA[1]= 7.1;	
    xy=1;
    i=1;
    records[1].CGPA=Calculation(counter, records, xy, i);
	// --- RECORD 3 ---
    records[2].SAP_ID = 589001234; 
	strcpy(records[2].Roll_no, "24050110411"); 
	strcpy(records[2].Name, "Priya Kulkarni");
	strcpy(records[2].Phone_no, "7089012345"); 
	strcpy(records[2].Email_ID, "priya.k@mail.org");

	records[2].Year[0] = 1; 	
	records[2].Semester[0] = 1;
	records[2].SGPA[0] = 8.5;

		
	records[2].Semester[1] = 2;
	records[2].SGPA[1] = 8.8;

	records[2].Year[1] = 2; 	 	
	records[2].Semester[2] = 3;
	records[2].SGPA[2] = 9.0;

		
	records[2].Semester[3] = 4;
	records[2].SGPA[3] = 9.1;

	records[2].Year[2] = 3; 	
	records[2].Semester[4] = 5;
	records[2].SGPA[4] = 9.2;

		 	
	records[2].Semester[5] = 6;
	records[2].SGPA[5] = 9.4;

	records[2].Year[3] = 4; 	 	
	records[2].Semester[6] = 7;
	records[2].SGPA[6] = 9.2;
	 	
	records[2].Semester[7] = 8;
	records[2].SGPA[7] = 8.2;
    xy=4;
    i=2;
    records[2].CGPA=Calculation(counter, records, xy, i);
	
    // --- RECORD 4 (records[3]) ---
    records[3].SAP_ID = 610543210; 
	strcpy(records[3].Roll_no, "27001000507"); 
	strcpy(records[3].Name, "Vishal Singh");
	strcpy(records[3].Phone_no, "8055678901"); 
	strcpy(records[3].Email_ID, "v.singh@campus.edu");

	records[3].Year[0] = 1; 	
	records[3].Semester[0] = 1;
	records[3].SGPA[0] = 7.5; 	

		
	records[3].Semester[1] = 2;
	records[3].SGPA[1] = 7.8; 	

	records[3].Year[1] = 2; 	 	
	records[3].Semester[2] = 3;
	records[3].SGPA[2] = 8.0; 	

		
	records[3].Semester[3] = 4;
	records[3].SGPA[3] = 7.2; 	

	records[3].Year[2] = 3; 	
	records[3].Semester[4] = 5;
	records[3].SGPA[4] = 6.9; 	

		 	
	records[3].Semester[5] = 6;
	records[3].SGPA[5] = 7.1;
    xy=3;
    i=3;
    records[3].CGPA=Calculation(counter, records, xy, i);
	
	// --- RECORD 5 ---
    records[4].SAP_ID = 599876543; 
	strcpy(records[4].Roll_no, "25032000620"); 
	strcpy(records[4].Name, "Zoya Ansari");
	strcpy(records[4].Phone_no, "9321098765"); 
	strcpy(records[4].Email_ID, "zoya.a@xyz.com");

	records[4].Year[0] = 1;
	records[4].Semester[0] = 1;
	records[4].SGPA[0] = 7.95;

	
	records[4].Semester[1] = 2;
	records[4].SGPA[1] = 7.5;
    xy=1;
    i=4;
    records[4].CGPA=Calculation(counter, records, xy, i);
    Menu();
    return 0;

    
}
