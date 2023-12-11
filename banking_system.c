#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
};
void changePassword(struct user *user, char *password) {
    FILE *user_records_file;
    char temp_filename[50];
    sprintf(temp_filename, "temp_%s", "user_records.txt");
    FILE *temp_file = fopen(temp_filename, "w");

    if (temp_file != NULL) {
        user_records_file = fopen("user_records.txt", "r");

        if (user_records_file != NULL) {
            char line[100];
            while (fgets(line, sizeof(line), user_records_file) != NULL) {
                char ac[50], stored_phone[50], stored_password[50];
                if (sscanf(line, "Account: %s, Phone: %s, Password: %s", ac, stored_phone, stored_password) == 3) {
                    if (strcmp(user->phone, stored_phone) == 0) {
                        fprintf(temp_file, "Account: %s, Phone: %s, Password: %s\n", ac, stored_phone, password);
                    } else {
                        fprintf(temp_file, "%s", line);
                    }
                }
            }

            fclose(user_records_file);
            fclose(temp_file);

            remove("user_records.txt");
            rename(temp_filename, "user_records.txt");
        }
    }
}

int main(){
    struct user user, usr;
    char filename[50], phone[50], password[50], phone2[50];
    FILE *fp, *fptr, *user_records_file;
    int opt, choice;
    int amount;
    char cont = 'y';

    printf("\nWhat do you want to do?");
    printf("\n\n1.Register your account");
    printf("\n2.Login to your account");

    printf("\n\nPlease enter your choice:\t");
    scanf("%d", &opt);

    if(opt == 1){
        system("clear");
        printf("\nEnter your account number:\t");
        scanf("%s", user.ac);
        printf("Enter your phone number:\t");
        scanf("%s", user.phone);
        printf("Enter your new password:\t");
        scanf("%s", user.password);
        user.balance = 0;

        stpcpy(filename, user.phone);
        fp = fopen(strcat(filename, ".dat"), "w");
        fwrite(&user, sizeof(user), 1, fp);

        // Record the new user in the user_records.txt file
        user_records_file = fopen("user_records.txt", "a");
        fprintf(user_records_file, "Account: %s, Phone: %s, Password: %s\n", user.ac, user.phone, user.password);
        fclose(user_records_file);

        if(fwrite != 0){
            printf("Successfully registered");
        }
    }
    else if(opt == 2){
        system("clear");
        printf("\nPhone No.:\t");
        scanf("%s", phone);
        printf("Password:\t");
        scanf("%s", password);
        fp = fopen(strcat(phone, ".dat"), "r");

        if(fp == NULL) {
            printf("Account number not registered");
        } else {
            fread(&user, sizeof(struct user), 1, fp);
            fclose(fp);

            if(!strcmp(password, user.password)){
                while(cont == 'y'){
                    system("clear");
                    printf("\n\tWelcome %s", user.phone);
                    printf("\nPress 1 for balance inquiry");
                    printf("\nPress 2 for adding fund");
                    printf("\nPress 3 for cash withdraw");
                    printf("\nPress 4 for online transfer");
                    printf("\nPress 5 for changing password");
                    printf("\nPress 6 to display all registered users\n\n");

                    scanf("%d", &choice);

                    switch(choice){
                        case 1:
                            printf("Your current balance is Rs. %.2f", user.balance);
                            break;

                        case 2:
                            system("clear");
						printf("Enter amount to be added:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(struct user),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amount);
						fclose(fp);
						
                            // ... (existing code)
                        break;

                        case 3:
                            system("clear");
						    printf("Enter withdrawl amount:\t");
						    scanf("%d",&amount);
						    if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						    else if(amount>user.balance) printf("\nSorry insufficeint balance");
						    else {
							user.balance -= amount;
						    fp = fopen(phone,"w");
						    fwrite(&user,sizeof(struct user),1,fp);
						    if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						    fclose(fp);
						    }
						    break;
					
                            

                        case 4:
                            printf("Please enter the phone number to trasnfer balance:\t");
						    scanf("%s",phone);
						    printf("Enter the amount to transfer:\t");
						    scanf("%d",&amount);
						    if(amount > user.balance) printf("\nSorry insufficent balance");
						    else {
							    fptr = fopen(strcat(phone,".dat"),"r");
							    if(fptr==NULL) printf("Sorry number is not registered");
							    else {
								    fread(&usr,sizeof(struct user),1,fptr);
								    fclose(fptr);
							
								    usr.balance += amount;
								
								    fptr = fopen(phone,"w");
								    fwrite(&usr,sizeof(struct user),1,fptr);
								    if(fwrite != 0){
								    // 	printf("ACcount:%s",usr.ac);
								    // printf("\npassword%s",usr.password);
								    // printf("\nphone%s",usr.phone);
								    // printf("\nbalance%f",usr.balance);
									    printf("Your trasfer is completed. You have trasnfered Rs.%d to %s",amount,usr.phone);
									    fclose(fptr);
									    user.balance -= amount;
									    strcpy(filename,user.phone);
									    fp = fopen(strcat(filename,".dat"),"w");
									    fwrite(&user,sizeof(struct user),1,fp);
									    fclose(fp);
								    }
							    }
						    }
						    break;
                        
                            
                            

                        case 5:
                            printf("\n\nPlease enter your old password:\t");
                        scanf("%s", password);
                        if (!strcmp(password, user.password)) {
                            printf("\n\nPlease enter your new password:\t");
                            scanf("%s", password);
                            strcpy(user.password, password);
                            changePassword(&user, password);
                            printf("\nPassword successfully changed");
                        } else {
                            printf("\nSorry, your password is wrong");
                        }
                        break;

                        case 6:
                            fp = fopen("user_records.txt", "r");
                            if (fp == NULL) {
                                printf("No registered users found.");
                            } else {
                                printf("\nRegistered Users :\n");
                                char line[100];
                                while (fgets(line, sizeof(line), fp) != NULL) {
                                    printf("%s", line);
                                }
                                fclose(fp);
                            }
                            break;
                        default:
                            break;
                    }

                    printf("\n\nDo you want to continue?[y/n]:\t");
                    scanf("%s", &cont);
                }
            }
            else {
                printf("Invalid password");
            }
        }
        printf("\n\n***Thank you for banking with ADV. bank***\n\n");
    }

    return 0;
}
