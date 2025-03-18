#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define TASK_LENGTH 100

char tasks[MAX_TASKS][TASK_LENGTH]; // Array to store tasks
int taskCount = 0;                   // Current number of tasks

// Function to add a task
void addTask(char* task) {
    if (taskCount < MAX_TASKS) {
        strncpy(tasks[taskCount], task, TASK_LENGTH);
//        tasks[taskCount][TASK_LENGTH - 1] = '\0'; // Ensure null termination
        taskCount++;
        printf("Task added: %s\n", task);
    } else {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

// Function to display all tasks
void displayTasks() {
    if (taskCount == 0) {
        printf("No tasks in the list.\n");
        return;
    }
	int i;
    printf("To-Do List:\n");
    for ( i = 0; i < taskCount; i++) {
        printf("%d: %s\n", i + 1, tasks[i]);
    }
}

// Function to remove a task by index
void removeTask(int index) {
    if (index < 1 || index > taskCount) {
        printf("Invalid task number.\n");
        return;
    }
    int i;
    for (i = index - 1; i < taskCount - 1; i++) {
        strncpy(tasks[i], tasks[i + 1], TASK_LENGTH);
    }
    taskCount--;
    printf("Task removed.\n");
}

int main() {
    int choice;
    char task[TASK_LENGTH];
    
	printf("To-do List \n");
	printf("========== \n");
	
    while (1) {
        printf("\n1. Add Task\n2. Display Tasks\n3. Remove Task\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                printf("Enter the task: ");
                scanf(" %[^\n]", task); 
                addTask(task);
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                printf("Enter the task number to remove: ");
                int taskNumber;
                scanf("%d", &taskNumber);
                removeTask(taskNumber);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

