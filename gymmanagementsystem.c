#include <stdio.h>
#include <stdlib.h>
struct member
{
    int id, id1, age;
    char Name[50], lastname[50], Address[50];
    char phonenum[15] ,weight[10];
};
int addmember() // taking inputs
{
    FILE *fptr;
    struct member m;
    int n;
    printf("Enter the number of member you want to add :");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        fptr = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt", "a+");
        printf("ID :");
        scanf("%d", &m.id);
        printf("Name :");
        scanf("%s", m.Name);
        printf("Last Name :");
        scanf("%s", m.lastname);
        printf("Age :");
        scanf("%d", &m.age);
        printf("Address :");
        scanf("%s", m.Address);
        printf("Contact number :");
        scanf("%s", m.phonenum);
        printf("Weight :");
        scanf("%s", m.weight);
        fprintf(fptr, "%d %s %s %d %s %s %s\n",m.id, m.Name, m.lastname, m.age, m.Address, m.phonenum, m.weight);
        fclose(fptr);
    }
}
void displaymember()
{
    FILE *fptr = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt", "r");
    printf("  ID \t\t\t  Name \t\t\tAge \t\t\t Address \t\t\t Phone_number \t\t\t Weight \t\t\t\n");
    struct member m;
    printf("|---------------------------------------------------------------------------------------------------------------------------------------------------|\n\n");
    while(fscanf(fptr, "%d %s %s %d %s %s %s\n",&m.id, m.Name, m.lastname, &m.age, m.Address, m.phonenum, m.weight) != EOF)
    {
        printf("  %d \t\t     %s %s\t\t%d\t\t\t %s  \t\t\t %s \t\t         %s \t\t\n", m.id, m.Name, m.lastname, m.age, m.Address, m.phonenum, m.weight);
    }
    fclose(fptr);
    // C:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling
}
void editmember()
{
    struct member m;
    int choice;
    printf("Enter id you want to update");
    scanf("%d", m.id1);
    FILE *fptr = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt", "r");
    FILE *fptr1 = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt", "w");
    while (fscanf(fptr, "%d %s %s %d %s %s %s\n",m.id, m.Name, m.lastname, m.age, m.Address, m.phonenum, m.weight) != EOF)
    {
        if (m.id = m.id1)
        {
            printf("what do you wanna update\n");
            printf("\n1. Name\n");
            printf("\n2. Last_Name\n");
            printf("\n3. age\n");
            printf("\n4. Address\n");
            printf("\n5. Phone Number\n");
            printf("\n6. Weight\n");
            printf("\n7. Exit\n");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter New Name :");
                scanf("%s", m.Name);
                break;
            case 2:
                printf("Enter New Last_Name :");
                break;
            case 3:
                printf("Enter New Last_Name :");
                break;
            case 4:
                printf("Enter New Last_Name :");
                break;
            case 5:
                printf("Enter New Last_Name :");
                break;
            case 6:
                printf("Enter New Last_Name :");
                break;
            case 7:

                break;

            default:
                break;
            }
        }
    }
}
void deletmember()
{
    int id;
    struct member m;
    printf("Enter id you want to delet :");
    scanf("%d",&id);
    FILE *fptr = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt", "a+");
    FILE *fptr1 = fopen("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\temp.txt", "w");
    while (fscanf(fptr, "%d %s %s %d %s %s %s\n",m.id, m.Name, m.lastname, m.age, m.Address, m.phonenum, m.weight)!= EOF)
    {
        if(id != m.id)
        {
            fprintf(fptr, "%d %s %s %d %s %s %s\n",m.id, m.Name, m.lastname, m.age, m.Address, m.phonenum, m.weight);
        }
    }
    fclose(fptr);
    fclose(fptr1);
    remove("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt");
    rename("c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\temp.txt","c:\\Users\\User\\OneDrive\\Desktop\\loops\\file_handling\\new1.txt");
    
}
void searchmember()
{
    printf("In progress......");
}
void homepage() // first page
{
    int menu, id;
    printf("\t\t\t  \"GYM MANAGEMENT SYSTEM\"\n\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  1: Add Member\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  2: Display Member\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  3: Edit Member\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  4: Delet Member\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  5: Search Member\n");
    printf("\t\t\t|------------------------|\n");
    printf("\t\t\t  6: Exit\n");
    printf("\t\t\t|------------------------|\n");
    printf("\n Enter the number: ");
    scanf("%d", &menu);
    char Name[20], Address[20];
    int Number;
    switch (menu)
    {
    case 1: // add member
        addmember();
        break;
    case 2: // display member
        displaymember();
        break;
    case 3: //   edit member
       // editmember();
       printf("In progress......");
        break;
    case 4: // delet applicant
       // deletmember();
        printf("In progress......");
        break;
    case 5: // search member's info
        searchmember();
        printf("In progress......");
        break;
    case 6:
        exit(1);
        break;

    default:
        printf("Entered wrong number");
        break;
    }
}
int main()
{
    homepage();
    return 0;
}