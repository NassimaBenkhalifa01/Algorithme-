#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

Node* createEmptyList() {
    return NULL;
}

int isEmpty(Node *head) {
    return head == NULL;
}

Node* insertAtBeginning(Node *head, Product newProd) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = newProd;
    
    if (isEmpty(head)) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    
    return head;
}

Node* insertAtEnd(Node *head, Product newProd) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->Prod = newProd;
    
    if (isEmpty(head)) {
        newNode->next = newNode;
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    return head;
}

void displayProducts(Node *head) {
    if (isEmpty(head)) {
        printf("The list is empty.\n");
        return;
    }
    
    Node *current = head;
    
    printf("Products in the circular list:\n");
    printf("==============================\n");
    
    do {
        printf("ID: %d, Name: %s, Price: %d\n", 
               current->Prod.ID, 
               current->Prod.Name, 
               current->Prod.Price);
        current = current->next;
    } while (current != head);
    
    printf("==============================\n");
    printf("End of list.\n");
}

int main() {
    printf("=== Circular Singly Linked List Demo ===\n\n");
    
    Node *head = createEmptyList();
    printf("1. Created empty list.\n");
    
    if (isEmpty(head)) {
        printf("2. The list is empty.\n");
    }
    
    Product p1 = {101, "Laptop", 1500};
    Product p2 = {102, "Mouse", 25};
    Product p3 = {103, "Keyboard", 75};
    Product p4 = {104, "Monitor", 300};
    
    printf("\n3. Inserting products...\n");
    
    head = insertAtBeginning(head, p1);
    printf("   Inserted Laptop at beginning\n");
    
    head = insertAtEnd(head, p2);
    printf("   Inserted Mouse at end\n");
    
    head = insertAtBeginning(head, p3);
    printf("   Inserted Keyboard at beginning\n");
    
    head = insertAtEnd(head, p4);
    printf("   Inserted Monitor at end\n");
    
    printf("\n4. Displaying all products:\n");
    displayProducts(head);
    
    printf("\n5. Testing with new empty list:\n");
    Node *newList = createEmptyList();
    displayProducts(newList);
    
    Product p5 = {105, "Headphones", 50};
    newList = insertAtBeginning(newList, p5);
    printf("After inserting one product in empty list:\n");
    displayProducts(newList);
    
    printf("\n=== Program Finished ===\n");
    
    return 0;
}