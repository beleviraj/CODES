#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// Node structure for chaining
struct Node {
    int key;
    int value;
    struct Node* next;
};

// Hash table structure
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// Function to create a new node
struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->key = key;
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to initialize the hash table
void initializeHashTable(struct HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        ht->table[i] = NULL;
    }
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Function to insert a key-value pair into the hash table
void insert(struct HashTable* ht, int key, int value) {
    int index = hashFunction(key);

    // Create a new node with the key-value pair
    struct Node* newNode = createNode(key, value);
    if (newNode == NULL) {
        printf("Memory allocation failed. Unable to insert.\n");
        return;
    }

    // Insert the node into the hash table using chaining
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        struct Node* current = ht->table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    printf("Inserted key: %d, value: %d at index: %d\n", key, value, index);
}

// Function to search for a key in the hash table
int search(struct HashTable* ht, int key) {
    int index = hashFunction(key);

    // Search for the key in the linked list at the calculated index
    struct Node* current = ht->table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // Key not found
    return -1;
}

// Main function
int main() {
    struct HashTable myHashTable;
    initializeHashTable(&myHashTable);

    // Insert key-value pairs
    insert(&myHashTable, 1, 10);
    insert(&myHashTable, 11, 20);
    insert(&myHashTable, 21, 30);

    // Search for keys
    printf("Value for key 1: %d\n", search(&myHashTable, 1));
    printf("Value for key 11: %d\n", search(&myHashTable, 11));
    printf("Value for key 21: %d\n", search(&myHashTable, 21));
    printf("Value for key 5: %d\n", search(&myHashTable, 5));

    return 0;
}
