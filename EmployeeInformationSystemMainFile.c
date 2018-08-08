// ******************** Employee information Management System ********************  //
// implementing Stack by ptred List ... //

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define p printf
#define s scanf

typedef struct node
{	// In each Node these informations will be stored //
	char *eid;			// Emp id
	char *address;      // Emp Address
	double *salary;		// Emp Salary
	double *phone;		// Emp Cell Phone Number
	char *dept;			// Emp department

	struct node *ptr;	// This is to Connect One Node with Another
}emp;// A new User Data Type "emp"

emp *top = NULL;

// ****************************************************** Insert function() ************************************************ //
int insertData(emp *e)
{
    // Before storing Data Allocate the memory to the pointers //
    e->eid = malloc(sizeof(char)*10);
    e->address = malloc(sizeof(char)*255);
    e->dept = malloc(sizeof(char)*15);
    e->phone = malloc(11);
    e->salary = malloc(10);

    if( e->eid && e->dept && e->phone && e->salary && e->address)
    {
        printf("\nEnter Emp Id     : ");
        fflush( stdin );
        scanf("%10s",e->eid);
    //	scanf("%Size4eids",e->eid);

        printf("\nEnter Emp Address: ");
        fflush( stdin );
        scanf("%255s",e->address);
    //    scanf("%Size4addresss",e->address);

        printf("\nEnter Emp dept   : ");
        fflush( stdin );
    //    scanf("%Size4depts",e->dept);
        scanf("%25s",e->dept);

        printf("\nEnter Emp PhoneNo: ");
        fflush( stdin );
    //	scanf("%Size4phones",e->phone);
        scanf("%11s",e->phone);

        printf("\nEnter Emp Salary : ");
        fflush( stdin );
        scanf("%10s",e->salary);


    }

	//scanf("%Size4salarys",e->salary);
	return 1;
}


// ****************************************************** Showdata() Function ************************************************ //



// ****************************************************** Print() Function *************************************************** //
int  printData( emp * t)
{
	int k=0,i;
	if( t == NULL )
	{
		printf("\n************************** Stack is Empty *****************************\n");
		return k;
	}
	else
	{
		while( t != NULL )
		{
			printf("\n************************** Employee %d ***************************\n",++k);
			printf("\nEmp Id        : ");
			puts(t->eid);

			printf("\nEmp Address   : ");
			puts(t->address);

			printf("\nEmp Salary    : ");
			puts(t->salary);

			printf("\nEmp Phone No. : ");
			puts(t->phone);

			printf("\nEmp Department: ")			;
			puts(t->dept );

			t = t->ptr;
		}
	}
}

// ****************************************************** Main() Function ************************************************ //

int main()
{
	int choice;

	printf("\n*******************************************************************\n");
	printf("+++++++++++++++++++ Hello! Welcome To +++++++++++++++++++++++++++++");
	printf("\n++++++++++++++++ Shubh Software Services ++++++++++++++++++++++++++");
	printf("\n+++++++++++ For Store Emp Infomations as Stack ++++++++++++++++++++");
    printf("\n*******************************************************************\n");

	while(1)
	{
		printf("\n**************************** OPTIONS ******************************\n");
		printf("\n1) Insert an Employee Information .");
		printf("\n2) Delete an Employee Information .");
		printf("\n3) Print All Employee Informations .");
		printf("\n4) Exit\n");

		printf("\nEnter Your Choice : ");
		fflush(stdin);
		scanf("%d",&choice);

		switch( choice )
		{
			case 1:	// Insert() or say Push()
				{
					int returnVal = 0;
					emp *temp;		// temp 'll got a Dynamically created "emp" type  Var's address

					temp = (emp *)malloc((sizeof(emp)));
					returnVal = insertData( temp ); // calling to push //

					if(top == NULL)
					{
						top = temp;
						top->ptr = NULL;

						if( returnVal )
						{	printf("\n********** New Employee's Information Successfully Added ************\n ");   }
						else
						{	printf("\n********************** OOOPs !!! Something went Wrong... Try Again plz. **********************\n ");	}

					}
					else
					{
						temp ->ptr = top;
						top = temp;
						if( returnVal )
						{	printf("\n********** New Employee's Information Successfully Pushed ************\n ");	}
						else
						{	printf("\n********************** OOOPs !!! Something went Wrong... Try Again plz. **********************\n ");	}

					}

					break;
				} 	// case 1 closed
			case 2:	// Delete() or say pop()
				{
				    emp *temp = top;
					if(top == NULL)
                    {
                         printf("\n************************* Stack is Empty *************************\n\n");
                         getch();
                         break;
                    }
                    else
                    {
                        top = top->ptr;
                        printf("\n************************ Top Emp info Popped **********************\n");
                        printData(temp);
                    }
					break;
				}	// case 2 closed
			case 3:	// Print()
				{
					double totalEmp = 0;
					emp *e = top;  // top is assigned to *e
					if(top == NULL)
                    {
                         printf("\n************************* Stack is Empty *************************\n\n");
                         getch();
                         break;
                    }

					while( e != NULL )
                    {
                         printf("\n************************** Employee %.0lf ****************************\n", ++totalEmp);
                         printf("\nEmp Id     : %s",e->eid);
                         printf("\nEmp Address: %s",e->address);
                         printf("\nEmp Dept   : %s",e->dept);
                         printf("\nEmp PhoneNo: %s",e->phone);
                         printf("\nEmp Salary : %s",e->salary);
                         printf("\n********************************************************************\n\n");
                         e = e->ptr;
                    }
					break;
				} 	// case 3 closed
			case 4:	// Exit()
				{
                    printf("\nAre you sure to exit : press 1 -> Yes   Or   press 0 -> No : ");
                    fflush(stdin);
                    scanf("%d",&choice);
                    if(choice == 1)
                    {
                        exit(1);
                    }
                    else if(!choice)
                    {
                        break;
                    }
                    else{ printf("\n************************* Warning!!! Invalid Option .**********************");
                        getch();
                        break;
                    }

				}	// case 4 closed
			default:// Default
				{
				    printf("\n************************* Warning!!! Invalid Option .**********************");
                    getch();
                    break;
				} 	// Default closed

		} // switch closed

	}	// while closed

	return 1;
}










