/*
PROGRAM DESCRIPTION: CA ASSIGNMENT 2: Program that will perform security authorisation based on access codes.
AUTHOR'S NAME: Khurram Farooq
DATE RECEIVED: 23rd Feburary 2017
DUE DATE: 12th March 2017
OS VERSION: Windows 10
COMPILER: Borland
*/

//Header Files
#include<stdio.h>
#include<stdlib.h>

//Symbolic Names
#define SIZE 4//Array to enter in elements of the code
#define CI 2//Array for counting number of times code was entered correctly and incorrectly

//Function Prototypes
void Enter_code(int*);//Function to save code as the default code, entered by user
void Encrypt_code(int*,int*,int*);//Function to encrypt the default code 
void Decrypt_code(int*);//Function to decrypt the previously encrypted code
void Correct_Incorrect_code(int*);//Function to display the number of times the code was enter correctly and incorrectly
void Exit_program(void);//Function to exit the program

int main()
{
    char option;
    int access_code[SIZE]={4,5,2,3};
    int newcode[SIZE];
    int corincor[CI]={0,0};

    do
    {
        //Displaying the Menu
        printf("\n");
        printf("Please select an option from the following menu:\n");
        printf("\n");
        printf("<<<<<<<<<<MENU>>>>>>>>>>");
        printf("\n");
        printf("Enter 1: to Enter code (Numbers entered must be 4 single digit integers) \n");
        printf("Enter 2: to Encrypt code and verify if correct (i.e If it matches authorised access code) \n");
        printf("Enter 3: to Decrypt code \n");
        printf("Enter 4: to Display the number of times the code was entered (i)Successfully (ii)Incorrectly \n");
        printf("Enter 5: to Exit Program \n");
        printf("\n");
        scanf("%c",&option);
        flushall();
        printf("\n");
        
        //User must select an option to continue
        if(option=='1')
        {
            //Calling function to enter the code and save as the default code
            Enter_code(newcode);
        }
        
        else if(option=='2')
        {
            //Calling function to encrypt the defualt code
            Encrypt_code(newcode, access_code, corincor);
        }
        else if(option=='3')
        {
            //Calling function to decrypt the default code
            Decrypt_code(newcode);
        }
        else if(option=='4')
        {
            //Calling function to display the number of times the code was entered right and wrong
            Correct_Incorrect_code(corincor);
        }
        
        else if(option=='5')
        {
            //Calling function to end the program
            Exit_program();
        }
        else//Error message if one of the five options are not selected
        {
            printf("\nYou have selected an invalid option/entry, please select a valid one\n");
        }
    }
    while(option!='5');//Carry out steps until option 5 is selected, to exit the program

    getchar();//Prevent window from closing
    return(0);
}

//Start of FUNCTION 1
//Implement function 1: Enter_code
void Enter_code(int *newcode)
{
    int i;//To allow elements to be entered into array

    printf("Enter your code, press enter after each digit\n");//Asking user ti enter the code
    
    for(i=0;i<SIZE;i++)//to store newcode as code
    {
        scanf("%d",&*(newcode+i));
        
    }
    printf("Your entered code is correct\n");
    getchar();
    //Prevent window from closing
}//End of FUNCTION 1

//Start of FUNCTION 2
//Implement function 2: Encrypt_code
void Encrypt_code(int *newcode, int *access_code, int *corincor)
{
    int tmparr[SIZE];//Temporary array tfor swapping the numbers
    int i;
    
    for(i=0;i<SIZE;i++)//For encrypting each element in array
    {
        *(tmparr+i)=*(newcode+i);
    }
    
    //Encrypting process as given in document: swaping the numbers 
    *(newcode+0)=*(tmparr+2);//Swapping the first and third elements
    *(newcode+2)=*(tmparr+0);//Swapping the third and first elements
    *(newcode+1)=*(tmparr+3);//Swapping the second and fourth elements
    *(newcode+3)=*(tmparr+1);//Swapping the fourth and second elements
    
    for(i=0;i<SIZE;i++)//Encryption process: adding 1 to each number after it is swaped
    {
        *(newcode+i)=*(newcode+i)+1;
    }
    
    for(i=0;i<SIZE;i++)//If any number has a value = 10, this changes it to 0
    {
        if (*(newcode+i)==10)
        {
            *(newcode+i)=0;
        }
    }
    
    //Checking if the encrypted code matches the default code
    if(*(newcode+0)==*(access_code+0) && *(newcode+1)==*(access_code+1) && *(newcode+2)==*(access_code+2) && *(newcode+3)==*(access_code+3))
    {
        printf("\nCorrect Code (code has been encrypted)\n");//Display this if default code has been entered correctly as encryption is correct
        *(corincor+0)=*(corincor+0)+1;
    }
    else
    {
        printf("\nError Code (code has already been encrypted OR Wrong code entered in option 1)\n");
        *(corincor+1)=*(corincor+1)+1;
    }
}//End of FUNCTION 2

//Start of FUNCTION 3
//Implement function 3: Decrypt_code
void Decrypt_code(int*newcode)
{
    int tmparr[SIZE];//Temporary array tfor swapping the numbers
    int i;
    
    //The decryption process, just reversing what was done to the code in the 2nd function
    for(i=0;i<SIZE;i++)
    {
        *(tmparr+i)=*(newcode+i);
    }
    
    for(i=0;i<SIZE;i++)
    {
        *(newcode+i)=*(newcode+i)-1;
    }
    
    for(i=0;i<SIZE;i++)//If any number has a value of -1, this changes it to 9
    {
        if(*(newcode+i)==-1)
        {
            *(newcode+i)=9;
        }
    }
    
    //Encrypting process as given in document: swaping the numbers
    *(newcode+0)=*(tmparr+2);//Swapping the first and the third numbers, aacording the decryption algorithm
    *(newcode+2)=*(tmparr+0);//Swapping the third and the first numbers, aacording the decryption algorithm
    *(newcode+1)=*(tmparr+3);//Swapping the second and the fourth numbers, according to decryption algorithm
    *(newcode+3)=*(tmparr+1);//Swapping the fourth and the second numbers, according to decryption algorithm
    printf("Code Decrypted\n");
}//End of FUNCTION 3

//Start of FUNCTION 4
//Implement function 4: Correct_Incorrect_code
void Correct_Incorrect_code(int *corincor)
{
    //Displaying the number of times code was entered (i) Successfully & (ii) Incorrectly
    printf("This is how many times your Code was entered correctly: %d time(s) \n", *(corincor+0));
    printf("This is how many times your Code was entered incorrectly: %d time(s) \n", *(corincor+1));
}//End of FUNCTION 4

//Start of FUNCTION 5
//Implement function 5: Exit_program
void Exit_program()
{
    printf("Program will now end, goodbye! (Press return to close this window)");
}//End of FUNCTION 5