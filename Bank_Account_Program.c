
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Bank_Account_main.C>
typedef struct Account {
	unsigned char Full_Name[100];
	unsigned char status[100];
	unsigned char Address[200];
    unsigned char phone[20];
	unsigned char National_ID[16];
	unsigned int Age;
	unsigned char Guardian[50];
	unsigned long int National_ID;
	unsigned long int password;
	unsigned long int Guardian_National_ID;
	unsigned long int Bank_Account_ID;
	unsigned long int Tran_Bank_Account_ID;
	float Balance;
	float Money;
};
void Create_Account(void);	
void Open_Existing_Account(void);
void Get_Cash();
void Deposit_in_Account();
void Change_Account_Status();
void Change_Account_Password();
void Make_Transaction();
void Return_to_main_menu();

void Create_Account(Void){
	// asked to enter the following parameters
	// 1- Full Name
	// 2- Full Address
	// 3- Age 
	// 4- National ID
	// 5- Guardian National ID 
	// 6- Balance
	
	FILE *FileOne = fopen("user.bin", "ab+");
    if (FileOne == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
	Account user;
			system("cls");
			printf("\nEnter your Full Name ");
			scanf("%s",user.Full_Name);
				
			printf("\n Creat your password ");
			scanf("%s",user.password );
			
			printf("\nEnter your Age ");
			scanf("%s",user.Age);
			
			if (usr.age<21){
			printf("\nEnter your Guardian National ID ");
			scanf("%s",user.Guardian_National_ID);
			}
			
			printf("\nEnter your Address ");
			scanf("%s",user.Address);

			printf("\nEnter your National ID ");
			scanf("%s",user.National_ID);

			printf("\nEnter your Balance ");
			scanf("%f",user.Balance);
	fwrite(&user, sizeof(user), 1, FileOne);
	if(fwrite != 0){
            printf("\n\nAccount succesfully ");
        }else {
            printf("\n\nSomething went wrong please try again");
        }
    fclose(FileOne);
}
//__________________________________________________
void Open_Existing_Account(void){
	//Existing Account
		//1- Make Transaction
		//2- Get Cash
		//3- Deposit in Account
		//4- Change Account Status
		//5- Return to main menu
		
		int opt_4;
		system("cls");
			printf("\nWhat do you want to do?");
			printf("\n\n1.Make Transaction");
			printf("\n2.Get Cash");
			printf("\n3.Deposit in Account");
			printf("\n4.Change Account Status");
			printf("\n5.Return to main menu");
			printf("\n\nYour choice:\t");
			scanf("%d",&opt_4);
		switch(opt_4)
		{
			case 1:Make_Transaction();
			break;
			case 2:Get_Cash();
			break;
			case 3:Deposit_in_Account();
			break;
			case 4:Change_Account_Status();
			break;
			case 5:Return_to_main_menu();
			break;
			default:
			break;
		}
	else{
		printf("incorrect Choice\n");
}
}
//________________________________________________________________________
Make_Transaction(){
	FILE *FileOne = fopen("user.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
	
	Account user,tempInformation;
    int flag = 0;
    if (FileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }
    system("cls");
    printf("\t\t\t\t====== Make Transaction======\n");
    printf("\n\t\t\tEnter Bank Account ID: ");
    scanf("%s" ,tempInformation.Bank_Account_ID);
	printf("\n\t\t\tEnter Bank Account ID You Want to Transfer To: ");
    scanf("%s" ,tempInformation.Tran_Bank_Account_ID);	
	while (fread(&user, sizeof(user), 1, FileOne) == 1)
    {
        if (strcmp(user.Bank_Account_ID, tempInformation.Bank_Account_ID) == 0)
        {
            flag++;
            {
                printf("\n\t\t\tCurrent Balance:$ %.2f", user.Balance);
                printf("\n\t\t\tEnter the amount you want to Transfer:$ ");
                scanf("%f", &tempInformation.Money);
                if (user.Balance < tempInformation.Money)
                {
                    printf("\n\n\t\t\tUnsufficient Balance To Transfer!\n\n");
                    fwrite(&user, sizeof(user), 1, temp);
                }
                else
                {
                    user.Balance -= tempInformation.Money;
                    printf("\n\t\t\tCurrent Balance after Transfer:$ %.2f", user.Balance);

                    fwrite(&user, sizeof(user), 1, temp);
                    printf("\n\n\t\t\tTransfer Money successfully!\n\n");
                }

        }
        else
        {
            fwrite(&user, sizeof(user), 1, temp);
        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(	FileOne);
    fclose(temp);

    remove("user.bin");
    rename("temp.bin", "user.bin");
	}

//__________________________________________________________________________
Deposit_in_Account(){
    FILE *FileOne = fopen("user.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");
	
	Account user,tempInformation;
    int flag = 0;

    if (FileOne == NULL || temp == NULL)
    {
        printf("\n\t\t\tError !\n");
    }

    system("cls");
    printf("\t\t\t\t====== Deposit in Account======\n");
    printf("\n\t\t\tEnter Bank Account ID: ");
    scanf("%s" ,tempInformation.Bank_Account_ID);

    while (fread(&user, sizeof(user), 1, FileOne) == 1)
    {
        if (strcmp(user.Bank_Account_ID, tempInformation.Bank_Account_ID) == 0)
        {
            flag++;
                printf("\n\t\t\tCurrent Balance:$ %.2f",user.Balance);
                printf("\n\t\t\tEnter the amount you want to deposit:$ ");
                scanf("%f", &tempInformation.Balance);
                user.Balance += tempInformation.Balance;
                printf("\n\t\t\tCurrent Balance after Deposit:$ %.2f", user.accountBalance);
				
                fwrite(&user, sizeof(user), 1, temp);
                printf("\n\n\t\t\tDeposited successfully!\n\n");
            }
            else{
				printf("\n\n\t\t\tDeposited not successfully!\n\n");
			}
			 if (flag == 0)
			{
			printf("\n\t\t\tAccount is not found");
			}

			fclose(	FileOne);
			fclose(temp);

			remove("user.bin");
			rename("temp.bin", "user.bin");
			}
			}
//_________________________________________________________________________
	Get_Cash(){
				
	FILE *FileOne = fopen("user.bin", "rb");
	FILE *temp = fopen("temp.bin", "wb");
	system("cls");
	printf("\t\t\t\t====== Deposit in Account======\n");
	printf("\n\t\t\tEnter Bank Account ID: ");
	scanf("%s" ,tempInformation.Bank_Account_ID);

    while (fread(&user, sizeof(user), 1, FileOne) == 1)
    {
        if (strcmp(user.Bank_Account_ID, tempInformation.Bank_Account_ID) == 0)
        {
            flag++;
	
			Account user,tempInformation;
			int flag = 0;
            {
                printf("\n\t\t\tCurrent Balance:$ %.2f", user.Balance);
                printf("\n\t\t\tEnter the amount you want to Get:$ ");
                scanf("%f", &tempInformation.Balance);
                if (user.Balance < tempInformation.Balance)
                {
                    printf("\n\n\t\t\tUnsufficient Balance!\n\n");
                    fwrite(&user, sizeof(user), 1, temp);
                }
                else
                {
                    user.Balance -= tempInformation.Balance;
                    printf("\n\t\t\tCurrent Balance after Withdraw:$ %.2f", user.Balance);

                    fwrite(&user, sizeof(user), 1, temp);
                    printf("\n\n\t\t\tGet Money successfully!\n\n");
                }
            }
        }
        else
        {
            fwrite(&user, sizeof(user), 1, temp);
        }
    }
    if (flag == 0)
    {
        printf("\n\t\t\tAccount is not found");
    }

    fclose(	FileOne);
    fclose(temp);

    remove("user.bin");
    rename("temp.bin", "user.bin");
	}
//____________________________________________________________
void Change_Account_Status(){
	FILE *FileOne = fopen("user.bin", "wb");
    int choice_1;
	system("cls");
	printf("\t\t\t\t====== Account Status======\n");
	printf("\n\t\t\tEnter Bank Account ID: ");
	scanf("%s" ,user.Bank_Account_ID);
	printf("\n\t\t\t Enter the Bank Account Status you want for: ");
			printf("\n\n1.Set Account to Active State");
			printf("\n2.Set Account to Restricted State");
			printf("\n3.Set Account to Closed");
			printf("\n\nYour choice:\t");
			scanf("%d",&choice_1);
			switch(choice_1)
		{
			case 1:printf("\n Your Account to In Active State");
			break;
			case 2:printf("\n Your Account to In Restricted State");
			break;
			case 3:printf("Your Account Closed");
			break;
			default:
			break;
		}
}
//_________________________________________________________________
void Change_Account_Password();{
	void passwordGenerator()
{
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

void Return_to_main_menu(){
	return;
}
