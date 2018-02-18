/*This program is a phone book. It takees a users information and stores it. They user is then offered
 * the option to write the contacts to a file, edit, find, add, delete, display the contacts currently added and exit the program.
 * Coded on Codelite
 * Windows 10
 * Adam Fegan and Khurram Farooq.
 * Some research from various sites such as stack overflow were used in the creation of this program
 * mainly for the structure and layout rather than the code.
 * 
 * The unique identifier in this program is the phone number because phone numbers are unique and names may not be.
 * For example the same last name for relatives and the same first name by chance. 
 * */

# include <stdio.h>
# include <conio.h>
# include <string.h>
# include <stdlib.h>
int f_menu(); //main menu
void f_add(); //add to list
void f_find(); //search from the list
void f_edit(); //edit the record
void f_delete(); //delete from the list
void f_display(); //display all
void f_record_contacts();

#define SIZE 30
#define MAX_RECORD 500


struct dnode 
{
    char name[SIZE];//character array for name
	char lname[SIZE];//character array for lastname
    char telephone[SIZE];//character array for phone number
    char email[SIZE];//character array for email
    struct dnode *next;
};

typedef struct dnode node;//using a typedef for the dnode
node *start, *temp;

void main()//main
{
	int choice;//variable for users menu choice
	start=(node *)malloc(sizeof(node));//dynamically allocating memory
	start=NULL;//assigning the start vairable as NULL
	
	//start do while to ensure that this section is run at least once
	do
    {
		choice=f_menu();//putting the users menu choice from the function into the choice variable
		switch(choice) //starting a switch case for the users menu choice
        {
			case 1: 
                f_add();//call add function
                break;//break
			case 2:
                f_find();//call find function
                break;//break
			case 3: 
                f_edit();//call edit function
                break;//break
			case 4: 
                f_delete();//call delete function
                break;//break
			case 5: 
                f_display();//call display function
                break;//break
			case 6:
				f_record_contacts();
				break;
        }//end switch
    }//end do while
    while(choice!=7); //while users choice is not an option in the switch or 7
}//end main

//menu function which allows the user t
int f_menu()
{
    int menu;

	//here is the menu that is displayed to user when the program begins, they are asked for their choice and it is
	//stored in the menu variable which is then returned and stored in the choice variable in main.
    printf("\n\nTELEPHONE DIRECTORY\n\n");
	printf("Please Choose an Option\n");
	printf("1. Add a Contact\n");
	printf("2. Find a Contact\n");
	printf("3. Edit a Contact\n");
	printf("4. Delete a Contact\n");
	printf("5. Display All Cntacts\n");
	printf("6. Record Cntacts\n");
	printf("7. Exit The Program\n\n");
	scanf("%d", &menu);
	return menu;
}//end menu
void f_add()
{
	node *ptr,*prev;
	temp=(node *)malloc(sizeof(node)); //using malloc for the temp variable
	
	//prompting the user for the contact details to add
	printf("First Name: ");
	scanf("%s", temp->name);
	printf("Last Name: ");
	scanf("%s", temp->lname);
	printf("Telephone: ");
	scanf("%s", temp->telephone);
	printf("Email: ");
	scanf("%s", temp->email);
	temp->next=NULL;

	if(start==NULL) //if start is NULLL
	{
		start=temp; //make start equal temp
	}
	else 
    {
        prev=ptr=start; //make ptr equal start and prev equal ptr.
        while(strcmp(temp->name,ptr->name)>0) 
        {
            prev=ptr;//make prev equal to ptr
            ptr= ptr->next;//ptr equal next ptr
            if (ptr == NULL) //if ptr equals NULL
			{
				break; //break
			}
        }
		if(ptr==prev) //if ptr is equivalent to prev
        {
			temp->next=start; //make next temp equal start
			start=temp;//make start equal temp
        }
		else if(ptr==NULL) //if ptr is NULL
		{
			prev->next=temp;//make next prev equal temp
			
		}
		else 
        {
			temp->next=ptr;//make temp equal ptr
			prev->next=temp;//and prev equal temp
		}//end inner else
	}//end else
}//end f_add

void f_find()
 {
	node *ptr;
	char str[SIZE];
	
	//checking if directory is empty
	if(start==NULL) 
    {
		printf("\nTelephone Directory is Empty\n");
        getch();
		return;
	}
	
	//prompting the user for the contact details to find
	printf("Telephone Number to Find: ");
	scanf("%s",str);
	
    ptr=start;//ptr equals start
    while(strcmp(ptr->telephone,str)!=0)
    {
        ptr= ptr->next; //make ptr equal next ptr
        if (ptr == NULL) //if ptr is NULL
			{
				break;
			}
    }
	if(ptr!=NULL)//if ptr is not NULL
    {
		//print the information
		printf("Name: %s\n",ptr->name);
		printf("Last Name: %s\n",ptr->lname);
		printf("Telephone: %s\n",ptr->telephone);
		printf("Email: %s\n",ptr->email);
	}
	else 
    {
		//print
		printf("No Matching Records Found!\n");
	}
    getch();
}//end f_find

void f_edit()
{
	node *ptr;
	char str[SIZE];
	if(start==NULL) //if start is NULL
    {
		printf("\nTelephone Directory is Empty\n");
        getch();
		return;
	}
	
	//prompting the user for the contact details to edit
	printf("Enter the Telephone Number of the contact to Edit: ");
	scanf("%s",str);
    ptr=start;//mak eptr = start

    while(strcmp(ptr->telephone,str)!=0)
    {
        ptr= ptr->next;//make ptr equal next ptr
        if (ptr == NULL) //if ptr is NULL
			{
				break;//break
			}
	}
        if(ptr!=NULL) //if ptr is not NULL
        {
			//prompt the user for the details they want entered
            printf("Original First Name is: %s, Please Enter New First Name\n", ptr->name);
            scanf("%s", ptr->name);
			printf("Original Last Name is: %s, Please Enter New Last Name\n", ptr->lname);
            scanf("%s", ptr->lname);
            printf("Original Telephone Number is: %s, Please Enter New Telephone Number\n", ptr->telephone);
            scanf("%s", ptr->telephone);
            printf("Original Email is: %s, Please Enter Email Address\n", ptr->email);
            scanf("%s", ptr->email);
            printf("Done");
        }
        else 
        {
            printf("No Matching Records Found!\n");
        }
        getch();//used to keep executable open
}//end f_edit

void f_delete()
 {
	node *ptr,*prev,*temp;
	char str[SIZE], yesno='n';

	if(start==NULL) //if ptr is NULL
    {
		printf("\nTelephone Directory is Empty\n");
        getch();//used to keep executable open
		return;
	}
	
	//prompting the user for the contact details to delete
	printf("Enter the telephone number of the Contact to Delete: ");
	scanf("%s",str);
	
    prev=ptr=start;//make ptr equal start and prev equal ptr
    while(strcmp(ptr->telephone,str)!=0)
    {
        prev=ptr;//make prev equal ptr
        ptr= ptr->next;//make ptr equal next ptr
		
        if(ptr == NULL) //if ptr is NULL
		{
			break; //break
		}
    }
	if(ptr!=NULL)//if ptr is not NULL
	{
		printf("\nWould you like to delete this record? [Y/N]: ");
		//yesno=getch();//using getchar to take the users yes or no input
        
		//print the info to the screen
		printf("\nFirst Name: %s\n",ptr->name);
		printf("Last Name: %s\n",ptr->lname);
		printf("Telephone: %s\n",ptr->telephone);
		printf("Email: %s\n",ptr->email);
        yesno=getch();//using getchar to take the users yes or no input
		
		if(yesno=='y' || yesno=='Y') //checking for upper and lower case
        {
			if (ptr==start) //if ptr is start
            {
				temp=start->next; //make temp = next start
				free(start);//free the  variable start
				start=temp;//make start equal temp
			}
			else 
            {
				temp=ptr->next;//make temp equal next ptr
				free(ptr);//free the variable ptr
				prev->next=temp;//make next prev equal temp
			}
			//prompt that the deletion was successful
			printf("\nRecord Deletion Successful");
		}
		else
		{
			//prompt that the deletion was not successful 
			printf("\n\nRecord Not Deleted");
			
		}
	}
	else 
    {
		//prompt that there was no records found
		printf("\nNo Matching Records Found!");
	}
    getch();//keep the executable window open
}//edn f_delete

void f_display()
{
	node *ptr;
	if(start==NULL) //if start is NULL
    {
		//prompt that the directory is empty
		printf("\nTelephone Directory is Empty\n");
        getch();
		return;
	}
	
	//loop that displays the contact details enter until all contacts are displayed.
	for(ptr=start; ptr!=NULL; ptr=ptr->next)
    {
		printf("\nFirst Name: %s", ptr->name);
		printf("\nLast Name: %s",ptr->lname);
		printf("\nTelephone:%s", ptr->telephone);
		printf("\nEmail: %s", ptr->email);
		printf("\n\n");
    }
    getch();
}//end f_display

void f_record_contacts()
{
	int i;
	node *ptr;
    FILE *fp; 
	
    //writing the records to a file if it can be opened
    if( (fp = fopen("phonebook.txt", "w")) == NULL)
    {
		//prompt that the file writing failed
        printf("Error Writing File.");
    }
    else
    {
		//print the records to the file
        for(ptr=start; ptr!=NULL; ptr=ptr->next)// as long as ptr equals start, ptr is not NULL and ptr equals next ptr.
        {
            fprintf(fp,"First Name: %s\n", ptr->name);
			fprintf(fp,"Last Name: %s\n", ptr->lname);
            fprintf(fp,"Telephone: %s\n", ptr->telephone);
            fprintf(fp,"Email: %s\n", ptr->email);
        }
    }
    fclose(fp);//close the file
            
}//end of f_record_contacts



