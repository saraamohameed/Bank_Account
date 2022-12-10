
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_ACC_Admin.h"
#include "Bank_ACC_Client.h"
#include "STD_Types.h"
#include<windows.h>

//Client Window
// Creating a structure to store data of the user
typedef struct Account {
	u8 Full_Name[300];
	u16 status[100];
	u32 Address[300];
    u16 phone[20];
	u8 Age ;
	u16 Guardian[50];
	u16 National_ID [100];
	u16 password [100];
	u64 Guardian_National_ID[15];
	u64 Bank_Account_ID[15];
	f32 Balance;
}; Account;
// Structure to keep track of amount transfer

Client_Window(){

    int opt_2;
    printf("\nWhat do you want to do?");
    printf("\n\n1.Make Transaction");
    printf("\n2.Change Account Password");
    printf("\n3.Get Cash");
    printf("\n4.Deposit in Account");
    printf("\n5.Return to main menu");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt_2);
	switch(opt_2){
		case 1:
			Make_Transaction();
        break;

		case 2:
			Change_Account_Password();
        break;

		case 3:
			Get_Cash();
        break;
		case 4:
			Deposit_in_Account();
        break;
		case 5:
			printf("\n*****Thank You For Using Our System*****");
			Exit(1);

		default:
			printf("\nEnter the correct choice!!!");
	}

	return 0;
}


Change_Account_Password(){
     char storePassword[50], oldPassword[50], newPassword[50];

    FILE *passwordFile = fopen("password.bin", "rb");
    FILE *tempFile = fopen("tempPassword.bin", "wb");

    if (passwordFile == NULL)
    {
        printf("\n\t\t\tPlease enter new password : ");
        scanf("%s",newPassword);
        fprintf(tempFile, "%s", newPassword);
        printf("\n\t\t\tNew Password has been created successfully.");
    }
    else
    {
        fscanf(passwordFile, "%s", storePassword);
        printf("\n\t\t\tPlease enter old password : ");
        scanf("%s",oldPassword);
        if (strcmp(storePassword, oldPassword) == 0)
        {
            printf("\n\t\t\tPlease enter new password : ");
            scanf("%s",newPassword);
            fprintf(tempFile, "%s", newPassword);
            printf("\n\t\t\tNew Password has been created successfully.");
        }
        else
        {
            fprintf(tempFile, "%s", storePassword);
            printf("\n\t\t\tWrong Password ! PLease Try Later.... ");
        }
    }

    fclose(passwordFile);
    fclose(tempFile);

    remove("password.bin");
    rename("tempPassword.bin", "password.bin");

}




