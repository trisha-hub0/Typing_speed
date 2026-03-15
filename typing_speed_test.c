#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main() {
    char target[] = "The quick brown fox jumps over the lazy dog.";
    char input[200];
    time_t start, end;
    double time_taken;
    int word_count = 0;

    printf("***** Typing Speed Test *****\n");
    printf("Type the following sentence exactly as it appears:\n\n");
    printf("\"%s\"\n", target);

    printf("\nPress Enter when you are ready to start...");
    getchar();

    time(&start);

    printf("\nStart typing:\n");
    fgets(input, sizeof(input), stdin);

    time(&end);

    // Remove newline character added by fgets
    input[strcspn(input, "\n")] = '\0';

    time_taken = difftime(end, start);

    // Word counting logic (robust)
    int in_word = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i]) && !in_word) {
            word_count++;
            in_word = 1;
        } else if (isspace(input[i])) {
            in_word = 0;
        }
    }

    printf("\nTime taken: %.2f seconds\n", time_taken);
    printf("Words typed: %d\n", word_count);

    if (time_taken > 0) {
        double wpm = (word_count / time_taken) * 60.0;
        printf("Typing Speed: %.2f words per minute (WPM)\n", wpm);
    } else {
        printf("Typing Speed: Too fast to calculate\n");
    }

    if (strcmp(target, input) == 0) {
        printf("Accuracy: 100%% (Perfect match!)\n");
    } else {
        printf("Accuracy: Less than 100%%\n");
    }

    return 0;
}
