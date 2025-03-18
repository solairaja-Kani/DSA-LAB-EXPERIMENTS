#include <stdio.h>
#include <stdlib.h>

// Define a node structure for polynomial
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node** tail = &result;

    while (poly1 && poly2) {
        if (poly1->exp > poly2->exp) {
            *tail = createNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            *tail = createNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            *tail = createNode(poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);
    }

    // If there are remaining terms in poly1 or poly2
    while (poly1) {
        *tail = createNode(poly1->coeff, poly1->exp);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while (poly2) {
        *tail = createNode(poly2->coeff, poly2->exp);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }

    return result;
}

// Function to display the polynomial
void displayPolynomial(struct Node* poly) {
    while (poly) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly)
            printf(" + ");
    }
    printf("\n");
}

// Main function
int main() {
    // First polynomial: 3x^3 + 5x^2 + 6
    struct Node* poly1 = createNode(3, 3);
    poly1->next = createNode(5, 2);
    poly1->next->next = createNode(6, 0);

    // Second polynomial: 4x^3 + 2x^1 + 5
    struct Node* poly2 = createNode(4, 3);
    poly2->next = createNode(2, 1);
    poly2->next->next = createNode(5, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);

    return 0;
}
