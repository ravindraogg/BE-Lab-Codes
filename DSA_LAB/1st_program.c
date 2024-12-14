#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_DAYS_IN_WEEK 7

typedef struct {
    char* acDayName;
    int iDate;
    char* acActivity;
} DAYTYPE;

void Free_cal(DAYTYPE*);
void Disp_cal(DAYTYPE*);
void Read_cal(DAYTYPE*);
DAYTYPE* createcal();

int main() {
    DAYTYPE* weekly_calendar = createcal();
    Read_cal(weekly_calendar);
    Disp_cal(weekly_calendar);
    Free_cal(weekly_calendar);
    return 0;
}

DAYTYPE* createcal() {
    DAYTYPE* calendar = (DAYTYPE*)malloc(NUM_DAYS_IN_WEEK * sizeof(DAYTYPE));
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        calendar[i].acDayName = NULL;
        calendar[i].iDate = 0;
        calendar[i].acActivity = NULL;
    }
    return calendar;
}

void Read_cal(DAYTYPE* calendar) {
    char choice;
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Do you want to enter details for day %d [Y/N]: ", i + 1);
        scanf(" %c", &choice);
        getchar();
        if (tolower(choice) == 'n') continue;

        printf("Day Name: ");
        char nameBuffer[50];
        scanf("%s", nameBuffer);
        calendar[i].acDayName = strdup(nameBuffer);

        printf("Date: ");
        scanf("%d", &calendar[i].iDate);

        printf("Activity: ");
        char activityBuffer[100];
        getchar();
        scanf("%[^\n]", activityBuffer);
        calendar[i].acActivity = strdup(activityBuffer);

        printf("\n");
    }
}

void Disp_cal(DAYTYPE* calendar) {
    printf("\nWeek's Activity Details\n");
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        printf("Day %d:\n", i + 1);
        if (calendar[i].iDate == 0) {
            printf("No activity\n");
            continue;
        }
        printf("Day name: %s\n", calendar[i].acDayName);
        printf("Date: %d\n", calendar[i].iDate);
        printf("Activity: %s\n", calendar[i].acActivity);
    }
}

void Free_cal(DAYTYPE* calendar) {
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        free(calendar[i].acDayName);
        free(calendar[i].acActivity);
    }
    free(calendar);
}
