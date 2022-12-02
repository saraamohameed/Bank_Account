#include <stdio.h>
#include <stdlib.h>
#include <Bank_Account_Program.c>
#include <string.h>
	

void Create_Account(void);	
void Open_Existing_Account(void);
void Get_Cash(int Required_Money_to_Get);
void Deposit_in_Account(int Required_Money_to_put);
void Change_Account_Status(int Account_ID);
void Change_Account_Password(int Old_pw,int New_pw,int Acount_ID);
void Make_Transaction();
void Return_to_main_menu();
  int main()
{
	int opt,opt_1,opt_2;
    
	printf("\nWhat do you want ?");
	printf("\n\n1. Admin Window");
	printf("\n2. Client Window");
	printf("\n\nYour choice:\t");
	scanf("%d",&opt);
	
//_______________________________________________
	//Admin Window opt=1
    if(opt == 1){
		printf("\nWhat do you want to do?");
		printf("\n\n1.Create New Account");
		printf("\n2.Open Existing Account");
		printf("\n3.Exit System");
		printf("\n\nYour choice:\t");
		scanf("%d",&opt_1);
		switch(opt_1)
		{
			case 1:Create_Account();
			break;
			case 2:Open_Existing_Account();
			break;
			case 3:Exit_System();
			break;
			default:
			break;
		}
	}else{
		printf("incorrect Choice\n");
}

//____________________________________________________________
	//Client Window opt=2
    else if(opt == 2){
		Open_Existing_Account(opt_2);
		printf("\nWhat do you want to do?");
		printf("\n\n1.Make Transaction");
		printf("\n2.Change Account Password");
		printf("\n3.Get Cash");
		printf("\n4.Deposit in Account");
		printf("\n5.Return to main menu");
		printf("\n\nYour choice:\t");
		scanf("%d",&opt_2);
		switch(opt_2)
		{
			case 1:Make_Transaction();
			break;
			case 2:Change_Account_Password();
			break;
			case 3:Get_Cash();
			break;
			case 4:Deposit_in_Account();
			break;
			case 5:Return_to_main_menu();
			break;
			default:
			break;
		}
	}else{
		printf("incorrect Choice\n");
}
}