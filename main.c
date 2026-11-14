#include <stdio.h>
#include <string.h>

#define MAX 10
FILE *pointer;

struct WHALE
{
    char id[10];
    char specie[50];
};

void regiterSight(int total, struct WHALE animal, char local, char activity) {
    if (pointer == NULL) {
        pointer = fopen("whales.txt", "wt");
        fprintf(pointer, "Number of whales sighted: %i\n%i - %s\nSighted in %s during your %s time", total, animal.id, animal.specie, local, activity);
    }
    else {
        pointer = fopen("whales.txt", "a");
        fprintf(pointer, "Number of whales sighted: %i\n%i - %s\nSighted in %s during your %s time", total, animal.id, animal.specie, local, activity);
    }
    fclose(pointer);
}

int main()
{
    int option = 1, whales_number = 0;
    struct WHALE whales[MAX];
    int code_specie;
    char local;
    char activity;
    char report;
    
    while (option != 0) {
        printf("- Saw a whale -\nWhales observation System\n1. Register a whale\n2. Show all whales\n0. Exit\nOption: ");
        scanf("%i", &option);

        if (option == 1)
        {
            printf("Whale %i", whales_number);
            
            printf("\nWhat specie are?\n1. Blue\n2. Humpback\n3. Sperm\nSpecie code: ");
            scanf("%i", &code_specie);
            switch(code_specie) {
                case 1:
                    strcpy(whales[whales_number].specie, "Blue");
                    break;
                case 2:
                    strcpy(whales[whales_number].specie, "Humpback");
                    break;
                case 3:
                    strcpy(whales[whales_number].specie, "Sperm");
                    break;
                default:
                    strcpy(whales[whales_number].specie, "Other");
                    break;
            }
            
            sprintf(whales[whales_number].id, "%i%i", code_specie, whales_number);
            
            printf("%s\n", whales[whales_number].id);
            printf("%s", whales[whales_number].specie);
            
            printf("\nWhere have you saw?: ");
            scanf("%s", &local);
            
            printf("\nWhat the whale was doing? Example: breathing, eating, attacking: ");
            scanf("%s", &activity);
            
            regiterSight(whales_number, whales[whales_number], local, activity);
        }
        else if (option == 2)
        {
            pointer = fopen("file.txt", "rt");
            if (pointer == NULL) {
                printf("Nothing registered :(");
            }
            else {
                fscanf(pointer, "%[^\n]", &report);
                printf("%s", report);
            }
        }
    }
}
