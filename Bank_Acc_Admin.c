# include <stdio.h>
# include <string.h>
#include "STD_Types.h"
#include "Bank_ACC_Admin.h"
#include "Bank_ACC_Client.h"
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_ACC_Admin.h"
#include "Bank_ACC_Client.h"
#include "STD_Types.h"
#include<windows.h>


// Creating a structure to store data of the user
typedef struct Account {
	u8 Full_Name[300];
	u16 status[100];
	u32 Address[300];
    u16 phone[20];
	u8 Age ;
	u16 Guardian[50];
	u16 National_ID [100];
	u8 Account_ID;
	u16 password [100];
	u64 Guardian_National_ID[15];
	u64 Bank_Account_ID[15];
	u8 State[4];
	f32 Balance;
}; Account;

//Admin Window
Admin_Window(){
    int opt_1;
	printf("\nWhat do you want to do?");
    printf("\n\n1.Create New Account");
    printf("\n2.Open Existing Account");
    printf("\n3.Exit System");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt_1);
	switch(opt_1){
		case 1:
			Create_Account();

			break;

		case 2:
			Open_Existing_Account();

			break;

		case 3:
			printf("\n*****Thank You For Using Our System*****");

			Exit(1);
		default:
			printf("\nEnter the correct choice!!!");
	}

	return 0;
}

Make_Transaction(){
	f32 Transfer_Amount;
	u8  ACC_Transfer_ID[20];
	struct Account user;


	printf("enter the account ID you want to transfer to:\n");
		scanf(" %[^\n]",&ACC_Transfer_ID);


		printf("Enter the Amount of Money you want to Transfer\n");
		scanf("%d",&Transfer_Amount);

		if(Transfer_Amount < user.Balance){

		user.Balance=user.Balance - Transfer_Amount;

		printf("%d\n\n\n ",user.Balance);
		}
		else
		{
			printf("The balance is not enough to complete the transaction\n");
		}
}

Create_Account(){
// asked to enter the following parameters
// 1- Full Name
// 2- Full Address
// 3- Age
// 4- National ID
// 5- Guardian National ID
// 6- Balance
struct Account user;

 FILE *FileOne = fopen("user.txt", "ab+");
    if (FileOne == 0)
    {
        printf("\n\t\t\tError !\n");
    }
			system("cls");
       printf("\n\n!!!!!CREATE ACCOUNT!!!!!");
			printf("\n\n Enter your Full Name ");
			scanf("%s",user.Full_Name);
			_flushall();

			printf("\n Creat your password ");
			scanf("%s",user.password );
			_flushall();

			printf("\n Creat Account ID ");
			scanf("%d",&user.Account_ID );
			_flushall();


			printf("\nEnter your Age ");
			scanf("%d",&user.Age);
			_flushall();

			if (user.Age<21){
			printf("\nEnter your Guardian National ID ");
			scanf("%s",user.Guardian_National_ID);
			_flushall();

			if (user.Guardian_National_ID[14]=! '\0'){
			printf("\n UNcorrect ID Pleas Try Again ");
			scanf("%s",user.Guardian_National_ID);
			_flushall();
			}
			}
          if (user.Age>=21) {

			printf("\nEnter your National ID ");
			scanf("%s",user.National_ID);
			_flushall();

			if (user.National_ID[14]=! '\0'){
			printf("\n UNcorrect ID Pleas Try Again ");
			scanf("%s",user.National_ID);
			_flushall();
			}

          }


			printf("\nEnter your Address ");
			scanf("%s",user.Address);
			_flushall();

			printf("\nEnter your Balance ");
			scanf("%f",&user.Balance);
			_flushall();

    fwrite(user.password , sizeof(user.password ), 1,FileOne);
    fwrite(user.Full_Name, sizeof(user.Full_Name), 1,FileOne);
    fwrite(user.Address, sizeof(user.Address), 1,FileOne);
    fwrite(user.National_ID, sizeof(user.National_ID), 1,FileOne);
    fwrite(&user.Age, sizeof(user.Age), 1,FileOne);

    if (user.Age < 21)
    {
    fwrite(user.Guardian_National_ID, sizeof(user.Guardian_National_ID), 1,FileOne);
    }
    fwrite(user.Account_ID, sizeof(user.Account_ID), 1,FileOne);
    fwrite(&user.Balance, sizeof(user.Balance), 1,FileOne);
	if(fwrite != 0){
            printf("\n\nAccount succesfully ");
        }else {
            printf("\n\nSomething went wrong please try again");
        }
	printf("\n\n\t\t\tEnter any keys to continue.......");
	fclose(FileOne);
}

Open_Existing_Account(){
    //Existing Account
		//1- Make Transaction
		//2- Get Cash
		//3- Deposit in Account
		//4- Change Account Status
		//5- Return to main menu

		int opt_3;
		system("cls");

			printf("\nWhat do you want to do?");

			printf("\n\n1.Make Transaction");
			printf("\n2.Get Cash");
			printf("\n3.Deposit in Account");
			printf("\n4.Change Account Status");
			printf("\n5.Return to main menu");
			printf("\n\nYour choice:\t");

			scanf("%d",&opt_3);
		switch(opt_3)
		{
			case 1:Make_Transaction();
			break;
			case 2:Get_Cash();
			break;
			case 3:Deposit_in_Account();
			break;
			case 4:Change_Account_Status();
			break;
			case 5:
			printf("\n*****Thank You For Using Our System*****");

			Exit(1);
		default:
			printf("\nEnter the correct choice!!!");
	}

	return 0;
}

Deposit_in_Account(){
int acc_id;
f32 deposit;
struct Account user;
struct Account tempInformation;
printf("\t\t\t\t====== Deposit in Account======\n");
printf("\t\t Enter The Account ID of the Account \n\t\t You Would Like To Deposit To : ");
scanf("%d", &acc_id);
_flushall();

FILE *FileOne = fopen("user.txt", "r");
FILE *FileNew = fopen("NewInformation.txt", "w");

  fscanf(FileOne, "Account ID : %d", user.Account_ID);
  fscanf(FileOne, "Account USER Name : %s", user.Full_Name);
  fscanf(FileOne, "Balance : %f",&user.Balance);

    if (acc_id == user.Account_ID)
    {
        printf("\n\t\t Enter The Amount You Would Like To Deposit : ");
        scanf("%f", &deposit);
        _flushall();

        user.Balance =user.Balance + deposit ;
        fprintf(FileNew, "\n Account ID: %d \n FULL Name : %s \n Balance : %f", user.Account_ID,user.Full_Name,user.Balance);

        fclose(FileNew);
        fclose(FileOne);
        remove("user.txt");
        rename("NewInformation.txt", "user.txt");
    }

    if(acc_id != user.Account_ID)
    {
        printf("\t\t Account ID Doesn't Exist\n");
        fclose(FileOne);
        fclose(FileNew);
}        remove("NewInformation.txt");
}

Exit(){
    ExitProcess;
}

Get_Cash(){
int acc_id;
f32 Cash;
struct Account user;
struct Account tempInformation;

printf("\t\t\t\t====== Get Cash From Account======\n");
printf("\t\t Enter The Account ID of the Account \n\t\t You Would Like To Get from : ");
scanf("%d", &acc_id);
_flushall();

FILE *FileOne = fopen("user.txt", "r");
FILE *FileNew = fopen("NewInformation.txt", "w");

  fscanf(FileOne, "Account ID : %d", user.Account_ID);
  _flushall();

  fscanf(FileOne, "Account USER Name : %s", user.Full_Name);
  _flushall();

  fscanf(FileOne, "Balance : %f",&user.Balance);
 _flushall();

    if (acc_id == user.Account_ID)
    {
        printf("\n\t\t Enter The Amount You Would Like To Get : ");
        scanf("%f", &Cash);
        _flushall();

        if(Cash > user.Balance){
                printf("\n\n\t\t\t Unsufficient Balance!\n\n");
        }
        else{
        user.Balance = user.Balance - Cash ;
        fprintf(FileNew, "\n Account ID: %d \n FULL Name : %s \n Balance : %f", user.Account_ID,user.Full_Name,user.Balance);
        _flushall();
        fclose(FileNew);
        fclose(FileOne);
        remove("user.txt");
        rename("NewInformation.txt", "user.txt");
    }

    if(acc_id != user.Account_ID)
    {
        printf("\t\t Account ID Doesn't Exist\n");
        fclose(FileOne);
        fclose(FileNew);
}       remove("NewInformation.txt");
}
}

Change_Account_Status(){
    FILE *FileOne = fopen("user.txt", "wb");
    struct Account user;
    int choice_1;

	system("cls");

	printf("\t\t\t\t====== Account Status======\n");

	printf("\n\t\t\tEnter Bank Account ID: ");
	scanf("%d",&user.Account_ID );
	_flushall();


	printf("\n\t\t\t Enter the Bank Account Status you want for: ");
			printf("\n\n1.Set Account to Active State");
			printf("\n2.Set Account to Restricted State");
			printf("\n3.Set Account to Closed");
			printf("\n\nYour choice:\t");
			scanf("%d",&choice_1);
			_flushall();

			switch(choice_1)
		{
			case 1:printf("\n Your Account to In Active State");
                 fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			case 2:printf("\n Your Account to In Restricted State");
                fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			case 3:printf("Your Account Closed");
			fwrite(user.State, sizeof(user.State), 1,FileOne);
			break;
			default:
			break;
		}
}
