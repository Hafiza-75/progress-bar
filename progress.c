#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>  //for windows
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>   //for linux
    #define  SLEEP(ms) usleep((ms) * 100)
#endif

#define BAR_LENGTH 50 // Defining the length of bar

void displayProgressBar(int percentage) {
    int numBars = (percentage * BAR_LENGTH) / 100;
    printf("\r["); //Carriage return to overwrite the prevvious lines
    
    // filled portion
    for ( int i = 0; i < numBars; i++ ) {
        printf("#");
    }

    // empty portion
    for ( int i = numBars; i < BAR_LENGTH; i++ ) {
        printf("-");
    }
    
    printf("] %d%%", percentage);
    fflush(stdout); // Ensures output is displayed immediately
}


void runProcess(const char *processName) {
    printf("\n%s\n" , processName);
    for ( int i = 0; i <= 100; i++){
        displayProgressBar(i);
        SLEEP(50);     // Sleep for 50 miliseconds
    }

    printf("\n%s Complete!", processName);
}


int main() {

    runProcess("Initializing...");
    runProcess("Loading  Assets...");
    runProcess("Processing Data...");
    runProcess("Finalizing Setup...");
    runProcess("Completing Installation...");

    printf("\nAll Processes are completed successfully!\n");
    printf("\t\t %c %c %c\n", 2,2,2); // ☺ (ASCII value 2)

    return 0;
}
