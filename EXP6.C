#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define BUFFER_SIZE 5
#define NUM_ITEMS 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;
int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;

void wait(int *s) {
    while (*s <= 0);
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void producer() {
    int item;
    if (full == BUFFER_SIZE) {
        printf("Buffer is full, producer is waiting...\n");
    } else {
        item = rand() % 100;
        wait(&empty);
        wait(&mutex);
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;
        signal(&mutex);
        signal(&full);
    }
}

void consumer() {
    int item;
    if (empty == BUFFER_SIZE) {
        printf("Buffer is empty, consumer is waiting...\n");
    } else {
        wait(&full);
        wait(&mutex);
        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;
        signal(&mutex);
        signal(&empty);
    }
}

void display_menu() {
    printf("\nProducer-Consumer Problem\n");
    printf("1. Produce Item\n");
    printf("2. Consume Item\n");
    printf("3. Exit\n");
}

void main() {
    int choice;
    clrscr();

    while (1) {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);  
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        delay(1000);  
    }
}

