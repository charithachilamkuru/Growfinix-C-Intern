#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Enquiry {
    int id;
    char name[50];
    char destination[50];
    char date[20];
};

typedef struct Enquiry Enquiry;


void addEnquiry() {
    FILE *fp = fopen("enquiry.dat", "ab");
    Enquiry e;

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("\nEnter ID: ");
    scanf("%d", &e.id);

    printf("Enter Name: ");
    scanf(" %[^\n]", e.name);

    printf("Enter Destination: ");
    scanf(" %[^\n]", e.destination);

    printf("Enter Date: ");
    scanf(" %[^\n]", e.date);

    fwrite(&e, sizeof(Enquiry), 1, fp);
    fclose(fp);

    printf("? Enquiry Added Successfully!\n");
}


void viewEnquiries() {
    FILE *fp = fopen("enquiry.dat", "rb");
    Enquiry e;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- All Enquiries ---\n");

    while (fread(&e, sizeof(Enquiry), 1, fp)) {
        printf("\nID: %d\nName: %s\nDestination: %s\nDate: %s\n",
               e.id, e.name, e.destination, e.date);
    }

    fclose(fp);
}


void searchEnquiry() {
    FILE *fp = fopen("enquiry.dat", "rb");
    Enquiry e;
    int id, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Enquiry), 1, fp)) {
        if (e.id == id) {
            printf("\n? Found!\n");
            printf("Name: %s\nDestination: %s\nDate: %s\n",
                   e.name, e.destination, e.date);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("? Record not found!\n");

    fclose(fp);
}


void updateEnquiry() {
    FILE *fp = fopen("enquiry.dat", "rb+");
    Enquiry e;
    int id, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter ID to update: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Enquiry), 1, fp)) {
        if (e.id == id) {
            printf("Enter new Name: ");
            scanf(" %[^\n]", e.name);

            printf("Enter new Destination: ");
            scanf(" %[^\n]", e.destination);

            printf("Enter new Date: ");
            scanf(" %[^\n]", e.date);

            fseek(fp, -sizeof(Enquiry), SEEK_CUR);
            fwrite(&e, sizeof(Enquiry), 1, fp);

            printf("? Updated Successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("? Record not found!\n");

    fclose(fp);
}


void deleteEnquiry() {
    FILE *fp = fopen("enquiry.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    Enquiry e;
    int id, found = 0;

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter ID to delete: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(Enquiry), 1, fp)) {
        if (e.id != id) {
            fwrite(&e, sizeof(Enquiry), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("enquiry.dat");
    rename("temp.dat", "enquiry.dat");

    if (found)
        printf("? Deleted Successfully!\n");
    else
        printf("? Record not found!\n");
}


int main() {
    int choice;

    while (1) {
        printf("\n====== Tour Enquiry Manager ======\n");
        printf("1. Add Enquiry\n");
        printf("2. View Enquiries\n");
        printf("3. Search Enquiry\n");
        printf("4. Update Enquiry\n");
        printf("5. Delete Enquiry\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEnquiry(); break;
            case 2: viewEnquiries(); break;
            case 3: searchEnquiry(); break;
            case 4: updateEnquiry(); break;
            case 5: deleteEnquiry(); break;
            case 6: exit(0);
            default: printf("? Invalid choice!\n");
        }
    }

    return 0;
}
