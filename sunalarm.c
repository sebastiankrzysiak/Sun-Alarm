#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int turnOffLights();
int setSunAlarm(int hours, int minutes, char am_pm);
int simulateSunrise();

int main() {
    int hours, minutes;
    char am_pm;

    printf("Enter the time for the alarm (HH MM AM/PM): ");
    scanf("%d %d %c", &hours, &minutes, &am_pm);

    printf("Good Night\n");

    turnOffLights();
    setSunAlarm(hours, minutes, am_pm);

    printf("Good Morning\n");

    return 0;
}

int turnOffLights() {

    FILE *file = fopen("turnoff.py", "r");

    if (file == NULL) {
        fprintf(stderr, "Could not open file");
        return 1;
    }

    system("python3 turnoff.py");

    fclose(file);

    return 0;
}

int setSunAlarm(int hours, int minutes, char am_pm) {

    // Convert 12-hour format to 24-hour format
    if (am_pm == 'P' && hours != 12) {
        hours += 12;
    } else if (am_pm == 'A' && hours == 12) {
        hours = 0;
    }
    
    time_t currentTime;
    struct tm *timeinfo;
    int alarmSeconds, currentSeconds;

    time(&currentTime);
    timeinfo = localtime(&currentTime);
    currentSeconds = timeinfo->tm_hour * 3600 + timeinfo->tm_min * 60 + timeinfo->tm_sec;

    // Calculate the alarm time in seconds
    alarmSeconds = hours * 3600 + minutes * 60;

    // Adjust alarm time if it is already past
    if (alarmSeconds <= currentSeconds) {
        alarmSeconds += 24 * 3600;
    }

    // Calculate the time to start the sunrise simulation (20 minutes before the alarm)
    int twentyMinutesBefore = alarmSeconds - 20 * 60;

    if (twentyMinutesBefore < 0) {
        twentyMinutesBefore += 24 * 3600;
    }

    // Calculate the wait time until the sunrise simulation
    int waitSeconds = twentyMinutesBefore - currentSeconds;

    printf("%d\n", waitSeconds);
    
    sleep(waitSeconds);

    simulateSunrise();

    return 0;
}

int simulateSunrise() {

    FILE *file = fopen("sunrise.py", "r");

    if (file == NULL) {
        fprintf(stderr, "Could not open file");
        return 1;
    }

    system("python3 sunrise.py");

    fclose(file);

    return 0;   
}