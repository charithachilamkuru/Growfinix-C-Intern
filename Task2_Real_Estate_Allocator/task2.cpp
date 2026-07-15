#include <stdio.h>
#include <stdlib.h>

struct Property {
    int id;
    float price;
    int sqft;
};

typedef struct Property Property;

int main() {
    Property *list = NULL;  
    int count = 0;
    int choice;

    while (1) {
        printf("\n==== Real Estate Manager ====\n");
        printf("1. Add Property\n");
        printf("2. View Properties\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            
            list = (Property *)realloc(list, (count + 1) * sizeof(Property));

            if (list == NULL) {
                printf("Memory allocation failed!\n");
                return 1;
            }

            printf("\nEnter Property ID: ");
            scanf("%d", &list[count].id);

            printf("Enter Price: ");
            scanf("%f", &list[count].price);

            printf("Enter Square Feet: ");
            scanf("%d", &list[count].sqft);

            count++;

            printf("? Property Added!\n");
        }

        else if (choice == 2) {
            if (count == 0) {
                printf("No properties available!\n");
            } else {
                printf("\n--- Property List ---\n");
                for (int i = 0; i < count; i++) {
                    printf("\nID: %d\nPrice: %.2f\nSqFt: %d\n",
                           list[i].id, list[i].price, list[i].sqft);
                }
            }
        }

        else if (choice == 3) {
            free(list);  
            printf("Memory freed. Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
