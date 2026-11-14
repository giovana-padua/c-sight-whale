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
    struct WHALE whales[MAX];
    int code_specie;
    char local[50];
    char activity[50];
    
    printf("Whale %i", 0);
    
    printf("\nWhat specie are?\n1. Blue\n2. Humpback\n3. Sperm\nSpecie code: ");
    scanf("%i", &code_specie);
    switch(code_specie) {
        case 1:
            strcpy(whales[0].specie, "Blue");
            break;
        case 2:
            strcpy(whales[0].specie, "Humpback");
            break;
        case 3:
            strcpy(whales[0].specie, "Sperm");
            break;
        default:
            strcpy(whales[0].specie, "Other");
            break;
    }
    
    sprintf(whales[0].id, "%i%i", code_specie, 0);
    
    //printf("%s\n", whales[0].id);
    //printf("%s", whales[whales_number].specie);
    
    printf("\nWhere have you saw?: ");
    scanf("%s", local);
    
    printf("\nWhat the whale was doing? Example: breathing, eating, attacking: ");
    scanf("%s", activity);
    
    //regiterSight(1, whales[0], local, activity);
    
    pointer = fopen("whales.txt", "wt");
    fprintf(pointer, "Number of whales sighted: %i\n", 1);
    
    if (pointer == NULL) {
        fprintf(pointer, "Error: Null");
    }
    else {
        fprintf(pointer, "%s - %s\nSighted in %s when was %s\n", whales[0].id, whales[0].specie, local, activity);
    }
    fclose(pointer);
}
