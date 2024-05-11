/*
NAME :- AYUSH ARYA
BRANCH :- ECE
SECTION :- A
ENROLLMENT NUMBER :- 23DOECBTEC0000101
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int coeff;
    int expo;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL;
}

int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int coeff, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = stack->top;
    stack->top = newNode;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Underflow!\n");
        return;
    }
    Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
}

void show(Stack* stack) {
    Node* temp = stack->top;
    while (temp != NULL) {
        printf("%dx^%d + ", temp->coeff, temp->expo);
        temp = temp->next;
    }
    printf("\n");
}

void addPolynomials(Stack* p1, Stack* p2, Stack* p3) {
    while (!isEmpty(p1) && !isEmpty(p2)) {
        Node* temp1 = p1->top;
        Node* temp2 = p2->top;
        if (temp1->expo == temp2->expo) {
            push(p3, temp1->coeff + temp2->coeff, temp1->expo);
            pop(p1);
            pop(p2);
        } else if (temp1->expo > temp2->expo) {
            push(p3, temp1->coeff, temp1->expo);
            pop(p1);
        } else {
            push(p3, temp2->coeff, temp2->expo);
            pop(p2);
        }
    }
    while (!isEmpty(p1)) {
        push(p3, p1->top->coeff, p1->top->expo);
        pop(p1);
    }
    while (!isEmpty(p2)) {
        push(p3, p2->top->coeff, p2->top->expo);
        pop(p2);
    }
}

int main() {
    Stack p1, p2, p3;
    initStack(&p1);
    initStack(&p2);
    initStack(&p3);

    printf("Enter polynomial 1:\n");
    int n1;
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        int coeff, expo;
        scanf("%d %d", &coeff, &expo);
        push(&p1, coeff, expo);
    }

    printf("Enter polynomial 2:\n");
    int n2;
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        int coeff, expo;
        scanf("%d %d", &coeff, &expo);
        push(&p2, coeff, expo);
    }

    addPolynomials(&p1, &p2, &p3);

    printf("Resultant polynomial:\n");
    show(&p3);

    return 0;
}