#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char id [50];
    char name[100];
    int quantity;
    double price;
} Item;

int main() {
    Item inventory [100];
    int count = 0;
    char input[256];

    while (scanf("%s", input) != EOF) {
        if (strcmp(input, "---") == 0) {
            break;
        }

        char *command = strtok (input, "#");

        if (strcmp(command, "receive") == 0) {
            char *id = strtok(NULL, "#");
            char *name = strtok(NULL, "#");
            char *qty_str = strtok(NULL, "#");
            char *price_str = strtok(NULL, "#");
            
            if (id && name && qty_str && price_str) {
                int exists = 0;
                for (int i = 0; i < count; i++) {
                    if (strcmp(inventory[i].id, id) == 0 ) {
                        exists = 1;
                        break;
                    }
                }
                if (!exists) {
                    strcpy(inventory[count].id, id);
                    strcpy(inventory[count].name, name);
                    inventory[count].quantity = atoi(qty_str);
                    inventory[count].price = atof(price_str);
                    count++;
                }
            }
        } else if (strcmp(command, "report") == 0) {
            for (int i = 0; i < count; i++) {
                printf("%s|%s|%d|%1.f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            }
        }
    }

    return 0;
}