#include <stdio.h> // prinf, scanf, snprintf, fprintf, FILE, fopen, fclose
#include <ctype.h> // tolower
#include <string.h> // strcpy
#include <time.h> // time, localtime, time_t, tm

#define MAX 10

struct WHALE
{
    char id[10];
    char specie[50];
};

int main()
{
    // Information about the sighting
    struct WHALE whales[MAX];
    int code_specie;
    char local[50];
    char activity[50];
    //..Datetime
    char day_report[20], time_report[20];
    time_t time_now;
    struct tm *info_time;
    
    // File
    FILE *pointer;
    
    // Loop
    int whales_count = 0;
    char stop;
    

    pointer = fopen("whales.txt", "a");

    do {
        printf("\nWhale %i", whales_count);
        
        // Saving the datetime
        time(&time_now); // time: Returns the current calendar time as a time_t value
        info_time = localtime(&time_now); // localtime: Converts a time_t value to local time and returns a pointer to a struct tm

        // 	snprintf: writes a formatted string into a char array (memory-safe)
        snprintf(day_report, sizeof(day_report), "Day: %02d/%02d/%04d", 
            info_time->tm_mday, 
            info_time->tm_mon + 1,      // Month go of 0 to 11
            info_time->tm_year + 1900); // Counting years starts in 1900"
            
        snprintf(time_report, sizeof(time_report), "\nTime: %02d:%02d:%02d",
            info_time->tm_hour, 
            info_time->tm_min, 
            info_time->tm_sec);
        
        // Information about the whale
        printf("\nWhat specie are?\n1. Blue\n2. Humpback\n3. Sperm\nSpecie code: ");
        scanf("%i", &code_specie);
        switch(code_specie) {
            case 1:
                strcpy(whales[whales_count].specie, "Blue"); // strcpy: copies the characters of a string into the memory of another string
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
        
        snprintf(whales[whales_count].id, sizeof(whales[whales_count].id), "%02d%02d/%i%i", 
            info_time->tm_mday, 
            info_time->tm_mon + 1, 
            code_specie, 
            whales_count);
        
        printf("\nWhere have you saw?: ");
        scanf("%s", local);
        
        printf("\nWhat the whale was doing? Example: breathing, eating: ");
        scanf("%s", activity);
        
        // Registering the whale sighting in the file
        if (whales_count == 0) {            
            if (pointer == NULL) {
                fprintf(pointer, "Error: Null");
            }
            else {
                fprintf(pointer, "%s\n", day_report);
            }
        }

        if (whales_count > 0) {
            if (pointer == NULL) {
                fprintf(pointer, "Error: Null");
            }
            else {
                fprintf(pointer, "\n");
            }
        }
        
        
        if (pointer == NULL) {
            fprintf(pointer, "Error: Null");
        }
        else {
            fprintf(pointer, "%s\nCode: %s\nSpecie: %s\nLocal: %s\nActivity: %s",
                time_report,
                whales[whales_count].id, 
                whales[whales_count].specie, 
                &local, 
                &activity);
        }
        
        whales_count++;
        
        // Asking the user if they want to stop the program
        printf("\nStop system? (y/n): ");
        scanf(" %c", &stop);
        stop = tolower(stop);
        
    } while (stop != 'y');

    // Printing the number of whales sighted and closing the file
    pointer == NULL ? fprintf(pointer, "Error: Null") : fprintf(pointer, "\nNumber of whales sighted: %i\n\n", whales_count);
    
    fclose(pointer);
}
