#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct account{
    char name[50];
    int acc_no;
    float balance;
};

void createaccount();
void displayaccount();
void depositmoney();
void withdrawmoney();

int main(){
    
    int choice;
    while(1){
        printf("\n===== BANKING SYSTEM =====\n");
        printf("1.CREATE ACCOUNT\n");
        printf("2.DISPLAY ACCOUNT\n");
        printf("3.DEPOSITE MONEY\n");
        printf("4.WITHDRAW MONEY\n");
        printf("5.EXIT\n");

        printf("ENTER YOUR CHOICE: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                createaccount();
                break;
            
            case 2:
                displayaccount();
                break;

            case 3:
                depositmoney();
                break;
            
            case 4:
                withdrawmoney();
                break;
            
            default:
                printf("INVALID CHOICE\n");
        }

    }
    return 0;
}

void createaccount(){
    FILE *fp;
    struct account a;
    fp=fopen("accounts.dat","ab");

    if(fp==NULL){
        printf("File Error\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d",&a.acc_no);

    getchar();

    printf("Enter Name: ");
    fgets(a.name,50,stdin);

    a.name[strcspn(a.name,"\n")]='\0';

    printf("Enter Initial Balance: ");
    scanf("%f",&a.balance);

    fwrite(&a,sizeof(a),1,fp);

    fclose(fp);

    printf("Account Created successfully\n");
}

void displayaccount(){
    FILE *fp;
    struct account a;
    fp=fopen("accounts.dat","rb");

    if(fp==NULL){
        printf("No Records found\n");
        return;
    }

    printf("\n=====ACCOUNT DETAILS=====\n");

    while(fread(&a,sizeof(a),1,fp)){
        printf("\nAccount Number: %d\n",a.acc_no);
        printf("Name            : %s\n",a.name);
        printf("Balance         : %.2f\n",a.balance);
    }
    fclose(fp);

}

void depositmoney(){
    FILE *fp;
    struct account a;
    int acc;
    float amount;
    int found=0;

    fp=fopen("accounts.dat","rb+");

    if(fp==NULL){
        printf("FILE ERROR\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%d",&acc);

    printf("Enter Deposit Account: ");
    scanf("%f",&amount);

    while(fread(&a,sizeof(a),1,fp)){
        if(a.acc_no==acc){
            a.balance+=amount;
            fseek(fp,-sizeof(a),SEEK_CUR);

            fwrite(&a,sizeof(a),1,fp);

            printf("MONEY DEPOSITED SUCCESSFULLY\n");
            printf("UPDATED BALANCE:%.2f\n",a.balance);

            found=1;
            break;
        }
    }
    if(found==0){
        printf("ACCOUNT NOT FOUND\n");
    }
    fclose(fp);
}

void withdrawmoney(){
    FILE *fp;
    struct account a;
    int acc;
    float amount;
    int found=0;

    fp=fopen("accounts.dat","rb+");

    if(fp==NULL){
        printf("FILE ERROR\n");return;
    }
    printf("\nENTER ACCOUNT NUMBER: ");
    scanf("%d",&acc);

    printf("ENTER WITHDRAW AMOUNT: ");
    scanf("%f",&amount);

    while(fread(&a,sizeof(a),1,fp)){
        if(a.acc_no==acc){
            if(amount>a.balance){
                printf("INSUFFICIENT BALANCE.\n");
            }else{
                a.balance-=amount;
                fseek(fp,-sizeof(a),SEEK_CUR);
                fwrite(&a,sizeof(a),1,fp);

                printf("MONEY WITHDRAWN SUCCESSFULLY\n");
                printf("REMAINING BALANCE:%.2f\n",a.balance);
            }
            found=1;
            break;
        }
    }
    if(found==0){
        printf("ACCOUNT NOT FOUND\n");
    }
    fclose(fp);
}