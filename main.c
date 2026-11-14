#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX 10

struct WHALE
{
    char id[10];
    char specie[50];
};

int main()
{
    // File
    FILE *pointer;
    const char *name_archive = "whales.txt";
    
    // Sight
    struct WHALE whales[MAX];
    int code_specie;
    char local[50];
    char activity[50];
    //..Datetime
    time_t time_now;
    struct tm *info_time;
    char day_report[20], time_report[20];
    
    // Repetição
    int whales_count = 0;
    char stop;
    
    do {
        printf("\nWhale %i", whales_count);
        
        time(&time_now);
        info_time = localtime(&time_now);
        snprintf(day_report, sizeof(day_report), "Day: %02d/%02d/%04d", 
            info_time->tm_mday, 
            info_time->tm_mon + 1,      // Month go of 0 to 11
            info_time->tm_year + 1900); // Counting years starts in 1900"
            
        snprintf(time_report, sizeof(day_report), "Time: %02d:%02d:%02d",
            info_time->tm_hour, 
            info_time->tm_min, 
            info_time->tm_sec);
        
        printf("\nWhat specie are?\n1. Blue\n2. Humpback\n3. Sperm\nSpecie code: ");
        scanf("%i", &code_specie);
        switch(code_specie) {
            case 1:
                strcpy(whales[whales_count].specie, "Blue");
                break;
            case 2:
                strcpy(whales[whales_count].specie, "Humpback");
                break;
            case 3:
                strcpy(whales[whales_count].specie, "Sperm");
                break;
            default:
                strcpy(whales[whales_count].specie, "Other");
                break;
        }
        
        sprintf(whales[whales_count].id, "%02d%02d/%i%i", 
            info_time->tm_mday, 
            info_time->tm_mon + 1, 
            code_specie, 
            whales_count);
        
        printf("\nWhere have you saw?: ");
        scanf("%s", local);
        
        printf("\nWhat the whale was doing? Example: breathing, eating: ");
        scanf("%s", activity);
        
        
        if (whales_count == 0 && access(name_archive, F_OK) != 0) {
            pointer = fopen(name_archive, "a");
            
            if (pointer == NULL) {
                fprintf(pointer, "Error: Null");
            }
            else {
                fprintf(pointer, "%s\nNumber of whales sighted: %i",
                    day_report,
                    whales_count + 1);
                fprintf(pointer, "\n\n%s \nCode: %s\nSpecie: %s\nLocal: %s\nActivity: %s\n\n",
                    time_report,
                    whales[whales_count].id, 
                    whales[whales_count].specie, 
                    local, 
                    activity);
            }
            
            fclose(pointer);
        }
        
        
        else if (whales_count > 0) {
            pointer = fopen(name_archive, "a");
            
            if (pointer == NULL) {
                fprintf(pointer, "Error: Null");
            }
            else {
                fprintf(pointer, "\n\n%s \nCode: %s\nSpecie: %s\nLocal: %s\nActivity: %s\n\n",
                    time_report,
                    whales[whales_count].id, 
                    whales[whales_count].specie, 
                    local, 
                    activity);
            }
            
            fclose(pointer);
        }
        
        
        else if (whales_count == 0 && access(name_archive, F_OK) == 0) {
            pointer = fopen(name_archive, "a");
            
            if (pointer == NULL) {
                fprintf(pointer, "Error: Null");
            }
            else {
                fprintf(pointer, "%s\nNumber of whales sighted: %i",
                    day_report,
                    whales_count + 1);
                fprintf(pointer, "\n\n%s \nCode: %s\nSpecie: %s\nLocal: %s\nActivity: %s\n\n",
                    time_report,
                    whales[whales_count].id, 
                    whales[whales_count].specie, 
                    local, 
                    activity);
            }
            
            fclose(pointer);
        }
        else {
            printf("Error.");
        }
        
        whales_count++;
        
        printf("\nStop system? (y/n): ");
        scanf(" %c", &stop);
        stop = tolower(stop);
        
    } while (stop != 'y');
    
    //fclose(pointer);
}
