#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TransistorListNode.h"

// Global variable to keep track of the current position
int currentPosition = 0;

// Function to add a new transistor to the end of the list
void AddTransistorToList(TransistorListNode** head, TransistorListNode* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        TransistorListNode* current = *head;
        while (current->nextNodePtr != NULL) {
            current = current->nextNodePtr;
        }
        current->nextNodePtr = newNode;
    }
    currentPosition++;
}

// Function to remove a transistor by its unique model
void RemoveTransistorFromList(TransistorListNode** head, const char* model) {
    TransistorListNode* current = *head;
    TransistorListNode* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->model, model) == 0) {
            if (prev == NULL) {
                *head = current->nextNodePtr;
            } else {
                prev->nextNodePtr = current->nextNodePtr;
            }
            free(current);
            currentPosition--;
            return;
        }

        prev = current;
        current = current->nextNodePtr;
    }
}

// Function to change the position of a transistor
void ChangeTransistorPosition(TransistorListNode** head, int currentPos, int newPos) {
    if (currentPos < 1) currentPos = 1;
    if (newPos < 1) newPos = 1;
    if (newPos > currentPosition) newPos = currentPosition;

    if (currentPos == newPos) {
        return; // No change needed
    }

    TransistorListNode* current = *head;
    TransistorListNode* prev = NULL;

    int currentPosition = 0;

    while (current != NULL) {
        currentPosition++;
        if (currentPosition == currentPos) {
            // Remove the node from its current position
            if (prev == NULL) {
                *head = current->nextNodePtr;
            } else {
                prev->nextNodePtr = current->nextNodePtr;
            }

            // Add the node at the new position
            if (newPos == 1) {
                current->nextNodePtr = *head;
                *head = current;
            } else {
                TransistorListNode* newNode = *head;
                for (int i = 1; i < newPos - 1; i++) {
                    newNode = newNode->nextNodePtr;
                }
                current->nextNodePtr = newNode->nextNodePtr;
                newNode->nextNodePtr = current;
            }

            return;
        }

        prev = current;
        current = current->nextNodePtr;
    }
}

// Function to free the memory of the entire linked list
void FreeTransistorList(TransistorListNode** head) {
    while (*head != NULL) {
        TransistorListNode* current = *head;
        *head = (*head)->nextNodePtr;
        free(current);
    }
    currentPosition = 0;
}

// Function to print a menu
void PrintMenu(const char* title) {
    printf("%s MENU\n", title);
    printf("a - Add transistor\n");
    printf("r - Remove transistor\n");
    printf("c - Change position of transistor\n");
    printf("o - Output full transistor list\n");
    printf("q - Quit\n");
}

// Function to execute the menu options
TransistorListNode* ExecuteMenu(char choice, const char* title, TransistorListNode* head) {
    switch (choice) {
        case 'a': {
            printf("ADD TRANSISTOR\n");
            char model[50];
            double maxVoltage, maxCurrent;

            printf("Enter transistor's unique model: ");
            scanf("%s", model);
            printf("Enter maximum rated voltage (V): ");
            scanf("%lf", &maxVoltage);
            printf("Enter maximum rated current (mA): ");
            scanf("%lf", &maxCurrent);

            TransistorListNode* newNode = (TransistorListNode*)malloc(sizeof(TransistorListNode));
            CreateTransistorListNode(newNode, model, maxVoltage, maxCurrent, NULL);

            AddTransistorToList(&head, newNode);

            printf("Transistor added.\n");
            break;
        }
        case 'r': {
            printf("REMOVE TRANSISTOR\n");
            char model[50];

            printf("Enter transistor's unique model: ");
            scanf("%s", model);

            RemoveTransistorFromList(&head, model);

            printf("%s removed.\n", model);
            break;
        }
        case 'c': {
            printf("CHANGE POSITION OF TRANSISTOR\n");
            int currentPos, newPos;

            printf("Enter transistor's current position: ");
            scanf("%d", &currentPos);
            printf("Enter new position for transistor: ");
            scanf("%d", &newPos);

            ChangeTransistorPosition(&head, currentPos, newPos);

            printf("Transistor moved to position %d.\n", newPos);
            break;
        }
        case 'o': {
            printf("%s MENU\n", title);

            if (head == NULL) {
                printf("Transistor list is empty\n");
            } else {
                int position = 1;
                TransistorListNode* current = head;
                while (current != NULL) {
                    printf("%d.\n", position);
                    PrintTransistorListNode(current);
                    current = GetNextTransistorListNode(current);
                    position++;
                }
            }
            break;
        }
        case 'q':
            // Quit option
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }

    return head;
}

int main() {
    char title[100];
    TransistorListNode* head = NULL;

    printf("Enter the transistor list's title: ");
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    char choice;
    do {
        PrintMenu(title);
        printf("Choose an option: ");
        scanf(" %c", &choice);
        getchar(); // Consume the newline character

        head = ExecuteMenu(choice, title, head);
    } while (choice != 'q');

    FreeTransistorList(&head);

    return 0;
}
