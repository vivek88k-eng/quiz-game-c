#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// player info structure
struct Player {
    char name[50];                 // 🧑player's name
    int score;                     // 📜player's score
};

// Structure to store Quiz Question📜
struct QuizQuestion {
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correctOption;
};

// Function declarations
void startQuiz();
void saveScore(char name[], int score);
void displayHighScores();

int main() {
    int choice;
    while (1) {
        printf("Welcome to Quiz Game!\n");
        printf("Start Quiz\n");
        printf("View High Scores\n");
        printf("Exit\n");
        printf("Enter Your Choice:");
        scanf("%d", &choice);

        if (choice == 1) {
            startQuiz();
        } else if (choice == 2) {
            displayHighScores();
        } else if (choice == 3) {
            printf("😎 Thank you for playing! Exiting....\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void startQuiz() {
    struct QuizQuestion questions[5] = {
        {
            "❓ Which of the following is a valid keyword in C?",
            "A) function",
            "B) void",
            "C) define",
            "D) include",
            'B'
        },
        {
            "🧠 Which header file is used for input/output in C?",
            "A) conio.h",
            "B) iostream",
            "C) stdio.h",
            "D) string.h",
            'C'
        },
        {
            "📘 What is the size of int in most 32-bit systems?",
            "A) 2 bytes",
            "B) 4 bytes",
            "C) 8 bytes",
            "D) Depends on compiler",
            'B'
        },
        {
            "💻 What is the correct way to declare a string in C?",
            "A) string name;",
            "B) char name[20];",
            "C) char name;",
            "D) str name;",
            'B'
        },
        {
            "🔁 Which loop is guaranteed to run at least once?",
            "A) for loop",
            "B) while loop",
            "C) do-while loop",
            "D) infinite loop",
            'C'
        }
    };

    char playerName[50];
    int score = 0;
    char answer;

    printf("Enter your name: ");
    scanf("%s", playerName);
    printf("\nWelcome, %s! Let's start the quiz\n\n", playerName);

    for (int i = 0; i < 5; i++) {
        printf("Q%d: %s\n", i + 1, questions[i].question);
        printf("%s\n", questions[i].optionA);
        printf("%s\n", questions[i].optionB);
        printf("%s\n", questions[i].optionC);
        printf("%s\n", questions[i].optionD);

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &answer);

        if (answer >= 'a' && answer <= 'z') {
            answer = answer - 32;
        }

        if (answer == questions[i].correctOption) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! Correct answer was: %c\n\n", questions[i].correctOption);
        }
    }

    printf("Quiz Completed, %s!\n", playerName);
    printf("Your final score is : %d out of 5\n", score);

    saveScore(playerName, score);
}

void saveScore(char name[], int score) {
    FILE *fp = fopen("scores.txt", "a");
    if (fp == NULL) {
        printf("Error opening file to save score!\n");
        return;
    }
    fprintf(fp, "%s %d\n", name, score);
    fclose(fp);
    printf("Your score has been saved successfully!\n");
}

void displayHighScores() {
    FILE *fp = fopen("scores.txt", "r");
    char name[50];
    int score;
    int count = 0;

    if (fp == NULL) {
        printf("❌ No high score data found!\n");
        return;
    }

    printf("\n🏆 High Scores Leaderboard 🏆\n");
    printf("==============================\n");

    while (fscanf(fp, "%s %d", name, &score) != EOF) {
        printf(" %s\t→ Score: %d\n", name, score);
        count++;
    }

    if (count == 0) {
        printf("😅 No scores saved yet!\n");
    }

    fclose(fp);
    printf("==============================\n\n");
}
