#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_ACC_Admin.h"
#include "Bank_ACC_Client.h"
#include "STD_Types.h"
#include<windows.h>

void Create_Account();
void Open_Existing_Account();
void Get_Cash();
void Deposit_in_Account();
void Change_Account_Status();
void Change_Account_Password();
void Make_Transaction();
void Admin_Window();
void Client_Window();
void Exit();

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
// Structure to keep track of amount transfer

int main()
{
    int choice;
	printf("Welcome to Bank System \n");
	printf("\nWhat do you want ?");
	printf("\n\n1. Admin Window");
	printf("\n2. Client Window");
	printf("\n3. Exit");
	printf("\n\nYour choice:\t");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			Admin_Window();
			break;

		case 2:
			Client_Window();
			break;

		case 3:
			printf("\n*****Thank You For Using Our System*****");
			exit(1);

		default:
			printf("\nEnter the correct choice!!!");
	}

	return 0;
}
