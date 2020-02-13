
/*
Selina Winter <winterse@sheridan.desire2learn.com>
----------------------------------------------------------------------
 */

/* 
 * File:   main.c
 * Author: Selina Winter <winterse@sheridan.desire2learn.com>
 *
 * Created on July 13, 2019, 12:05 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FLUSH stdin=freopen(NULL,"r",stdin)
#define MAX_LEN 100
#define MAX 2

//struct node to hold the record values

struct node {
    char* name;
    char* address;
    char* fName;
    char* mName;
    char* phone;
    char* email;
    char sex;
    char* citNo;

    struct node *next;
} *stuDirect_t = NULL;

void menu(); //This function is used to display the main menu. 
void start(); //This function calls the menu function mentioned above.
void back(); //This function is used to go back to start.
void addrecord(); //It adds a new Phonebook record.
void listrecord(); //This function is used to view list of added records in file. 
void modifyrecord(); //This function is used to modify added records.
void deleterecord(); //It deletes record from file.
void searchrecord(); //It searches for added record by name.

int main() {

    start();
    return (0);
}

/**
 * This method displays the menu.
 */
void menu() {
    printf("\t\t\t**********WELCOME TO THE PHONEBOOK**********\n");
    printf("\t\t\t\t\tMENU\n");
    printf("\t\t\t1. Add New\t 2. List\t 3. Exit\n \t\t\t4. Modify\t 5. Search\t 6. Delete\n");
}

/**
 * This method starts the program and requests input from
 * the user on which operation they would like to do.
 */
void start() {

    menu();

    struct node* tmp = NULL;
    struct node** head = &stuDirect_t;
    int value;
    FLUSH;
    scanf("%d", &value);
    switch (value) {
        case 1:
            addrecord();
            break;
        case 2:
            listrecord();
            break;
        case 3:
            exit(0);
            break;
        case 4:
            modifyrecord();
            break;
        case 5:
            searchrecord();
            break;
        case 6:
            deleterecord();
            break;
    }
}

/**
 * This method asks the user to enter any keyboard
 * key and return back to the menu.
 */
void back() {
    printf("Enter any key\n");
    FLUSH;
    getchar();
    FLUSH;
    start();
}

/**
 * This function creates a new record for the 
 * list and adds that record to the linked
 * list.
 */
void addrecord() {
    printf("\n\n");

    char theName[MAX_LEN];
    char address[MAX_LEN];
    char fName[MAX_LEN];
    char mName[MAX_LEN];
    char phone[MAX_LEN];
    char sex;
    char email[MAX_LEN];
    char citNo[MAX_LEN];
    //Get user inputs
    FLUSH;
    printf("Enter name: ");
    fgets(theName, sizeof (theName), stdin);
    theName[strcspn(theName, "\n")] = 0;
    FLUSH;
    printf("Enter the address: ");
    fgets(address, sizeof (address), stdin);
    address[strcspn(address, "\n")] = 0;
    FLUSH;
    printf("Enter father name: ");
    fgets(fName, sizeof (fName), stdin);
    fName[strcspn(fName, "\n")] = 0;
    FLUSH;
    printf("Enter mother name: ");
    fgets(mName, sizeof (mName), stdin);
    mName[strcspn(mName, "\n")] = 0;
    FLUSH;
    printf("Enter phone no.: ");
    fgets(phone, sizeof (phone), stdin);
    phone[strcspn(phone, "\n")] = 0;
    FLUSH;
    printf("Enter sex: ");
    scanf(" %c", &sex);

    FLUSH;
    printf("Enter e-mail: ");
    fgets(email, sizeof (email), stdin);
    email[strcspn(email, "\n")] = 0;
    FLUSH;
    printf("Enter citizen no: ");
    fgets(citNo, sizeof (citNo), stdin);
    citNo[strcspn(citNo, "\n")] = 0;
    FLUSH;
    //allocate memory and copy the value to the memory of the heap
    struct node *newNode = NULL;
    newNode = (struct node*) malloc(sizeof (struct node));
    if (newNode == NULL) {
        printf("cannot allocate memory for node");
        exit(1);
    }

    newNode->name = (char*) calloc((strlen(theName) + 1), sizeof (char));
    if (newNode->name == NULL) {
        printf("Cannot allocate memory for a name.");
        exit(1);
    }
    strncpy(newNode->name, theName, sizeof (theName) + 1);
    newNode->address = (char*) calloc((strlen(address) + 1), sizeof (char));
    if (newNode->address == NULL) {
        printf("Cannot allocate memory for an address.");
        exit(1);
    }
    strncpy(newNode->address, address, sizeof (address) + 1);
    newNode->fName = (char*) calloc((strlen(fName) + 1), sizeof (char));
    if (newNode->fName == NULL) {
        printf("Cannot allocate memory for father's name.");
        exit(1);
    }
    strncpy(newNode->fName, fName, sizeof (fName) + 1);
    newNode->mName = (char*) calloc((strlen(mName) + 1), sizeof (char));
    if (newNode->mName == NULL) {
        printf("Cannot allocate memory for mother's name.");
        exit(1);
    }
    strncpy(newNode->mName, mName, sizeof (mName) + 1);
    newNode->phone = (char*) calloc((strlen(phone) + 1), sizeof (char));
    if (newNode->phone == NULL) {
        printf("Cannot allocate memory for phone.");
        exit(1);
    }
    strncpy(newNode->phone, phone, sizeof (phone) + 1);
    newNode->email = (char*) calloc((strlen(email) + 1), sizeof (char));
    if (newNode->email == NULL) {
        printf("Cannot allocate memory for email.");
        exit(1);
    }
    strncpy(newNode->email, email, sizeof (email) + 1);
    newNode->sex = sex;
    newNode->citNo = (char*) calloc((strlen(citNo) + 1), sizeof (char));
    if (newNode->citNo == NULL) {
        printf("Cannot allocate memory for citizen number.");
        exit(1);
    }
    strncpy(newNode->citNo, citNo, sizeof (citNo) + 1);

    //assign node to the list
    if (stuDirect_t == NULL) {
        newNode->next = NULL;

    } else {
        newNode->next = stuDirect_t;

    }
    stuDirect_t = newNode;

    printf("Record Saved.\n");

    back();
}

/**
 * This function lists every record in the linked
 * list.
 */
void listrecord() {
    if (stuDirect_t == NULL) {
        printf("List is already empty\n");
    } else {

        struct node *temp = stuDirect_t;
        //loop through the list and print the values
        while (temp != NULL) {
            printf("Name: %s\n "
                    "Address: %s\n "
                    "Father: %s\n "
                    "Mother: %s\n "
                    "Phone: %s\n "
                    "Email: %s\n "
                    "Sex: %c\n "
                    "Citizen No: %s\n\n", temp->name, temp->address, temp->fName, temp->mName, temp->phone, temp->email, temp->sex, temp->citNo);
            temp = temp->next;
        }
    }

    back();
}

/**
 * This function  asks for user input of a
 * particular record that the user wants to 
 * update and traverses the linked list
 * to find the record. Then the new values are
 * copied to the record.
 */
void modifyrecord() {

    printf("\n\n");

    char theName[MAX_LEN];
    char address[MAX_LEN];
    char fName[MAX_LEN];
    char mName[MAX_LEN];
    char phone[MAX_LEN];
    char sex;
    char email[MAX_LEN];
    char citNo[MAX_LEN];
    //retrieve user input
    FLUSH;
    printf("Please enter the name of the record: ");
    fgets(theName, sizeof (theName), stdin);
    theName[strcspn(theName, "\n")] = 0;
    FLUSH;

    //traverse the list

    if (stuDirect_t == NULL) {
        printf("The list is empty\n");
    } else {
        struct node** head = &stuDirect_t;
        struct node *temp = *head;
        if (strcmp(temp->name, theName) == 0) {
            if (temp != NULL) {
                printf("Name: %s\n Address: %s\n Father: %s\n Mother: %s\n Phone: %s\n Email: %s\n Sex: %c\n Citizen No: %s\n\n", temp->name, temp->address, temp->fName, temp->mName, temp->phone, temp->email, temp->sex, temp->citNo);
                printf("Please enter the new values for %s: \n\n", temp->name);
                FLUSH;
                //User inputs for new node values and copying string values
                printf("Enter the address: ");
                fgets(address, sizeof (address), stdin);
                address[strcspn(address, "\n")] = 0;
                FLUSH;
                strcpy(temp->address, address);
                printf("Enter father name: ");
                fgets(fName, sizeof (fName), stdin);
                fName[strcspn(fName, "\n")] = 0;
                FLUSH;
                strcpy(temp->fName, fName);
                printf("Enter mother name: ");
                fgets(mName, sizeof (mName), stdin);
                mName[strcspn(mName, "\n")] = 0;
                FLUSH;
                strcpy(temp->mName, mName);
                printf("Enter phone no.: ");
                fgets(phone, sizeof (phone), stdin);
                phone[strcspn(phone, "\n")] = 0;
                FLUSH;
                strcpy(temp->phone, phone);
                printf("Enter sex: ");
                scanf(" %c", &sex);
                FLUSH;
                temp->sex = sex;
                printf("Enter e-mail: ");
                fgets(email, sizeof (email), stdin);
                email[strcspn(email, "\n")] = 0;
                FLUSH;
                strcpy(temp->email, email);
                printf("Enter citizen no: ");
                fgets(citNo, sizeof (citNo), stdin);
                citNo[strcspn(citNo, "\n")] = 0;
                FLUSH;
                strcpy(temp->citNo, citNo);
            }
        } else if (strcmp(temp->name, theName) != 0) {
            while (strcmp(temp->name, theName) != 0) {
                temp = temp->next;
            }
            if (temp != NULL) {
                printf("Name: %s\n Address: %s\n Father: %s\n Mother: %s\n Phone: %s\n Email: %s\n Sex: %c\n Citizen No: %s\n\n", temp->name, temp->address, temp->fName, temp->mName, temp->phone, temp->email, temp->sex, temp->citNo);
                printf("Please enter the new values for %s: \n\n", temp->name);
                FLUSH;
                //user Inputs
                printf("Enter the address: ");
                fgets(address, sizeof (address), stdin);
                address[strcspn(address, "\n")] = 0;
                FLUSH;
                strcpy(temp->address, address);
                printf("Enter father name: ");
                fgets(fName, sizeof (fName), stdin);
                fName[strcspn(fName, "\n")] = 0;
                FLUSH;
                strcpy(temp->fName, fName);
                printf("Enter mother name: ");
                fgets(mName, sizeof (mName), stdin);
                mName[strcspn(mName, "\n")] = 0;
                FLUSH;
                strcpy(temp->mName, mName);
                printf("Enter phone no.: ");
                fgets(phone, sizeof (phone), stdin);
                phone[strcspn(phone, "\n")] = 0;
                FLUSH;
                strcpy(temp->phone, phone);
                printf("Enter sex: ");
                scanf(" %c", &sex);
                FLUSH;
                temp->sex = sex;
                printf("Enter e-mail: ");
                fgets(email, sizeof (email), stdin);
                email[strcspn(email, "\n")] = 0;
                FLUSH;
                strcpy(temp->email, email);
                printf("Enter citizen no: ");
                fgets(citNo, sizeof (citNo), stdin);
                citNo[strcspn(citNo, "\n")] = 0;
                FLUSH;
                strcpy(temp->citNo, citNo);
            }
        }
    }
    back();
}

/**
 * This function deletes the last inputed record.
 */
void deleterecord() {
    struct node** head = &stuDirect_t;
    printf("\n\n");

    FLUSH;

    //deleting the node
    if (*head == NULL) {
        printf("The list is already empty\n");
    } else {
        //the body is being deleted here
        struct node* current = *head;

        if (current != NULL) {

            printf("Deleted record: %s\n", current->name);

            struct node* toDelete = *head;

            if ((*head)->next == NULL) {

                free(*head);

                *head = NULL;
            } else {
                *head = (*head)->next;

                //freeing the elements
                free(toDelete->name);
                free(toDelete->address);
                free(toDelete->fName);
                free(toDelete->mName);
                free(toDelete->email);
                free(toDelete->phone);
                free(toDelete->citNo);
                free(toDelete);
            }
        }
    }
    back();
}

/**
 * This method requests user input and traverses the linked list
 * to find the record that the user is looking for.
 */
void searchrecord() {
    printf("\n\n");
    char theName[MAX_LEN];
    FLUSH;
    //request input
    printf("Please enter the name of the record: ");
    fgets(theName, sizeof (theName), stdin);
    theName[strcspn(theName, "\n")] = 0;
    FLUSH;
    //traverse the list
    if (stuDirect_t == NULL) {
        printf("The list is empty\n");
    } else {
        struct node *temp = stuDirect_t;
        while (temp != NULL) {
            if (strcmp(temp->name, theName) == 0) {
                printf("Name: %s\n Address: %s\n Father: %s\n Mother: %s\n Phone: %s\n Email: %s\n Sex: %c\n Citizen No: %s\n\n", temp->name, temp->address, temp->fName, temp->mName, temp->phone, temp->email, temp->sex, temp->citNo);
                break;
            }
            temp = temp->next;
        }
    }
    back();
}




