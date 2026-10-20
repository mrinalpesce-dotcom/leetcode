
#include <bits/stdc++.h>
using namespace std;

// Node of a doubly linked list
class node {
public:
    int key;
    int data;
    node* next;
    node* prev;

    node(int k, int d) {
        key = k;
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, node*> m;

    node* head;
    node* tail;
    int capacity;

    // Constructor
    LRUCache(int cap) {
        capacity = cap;

        // Dummy nodes to simplify insertion and deletion
        head = new node(-1, -1);
        tail = new node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    // Remove a node from its current position
    void deleteNode(node* temp) {
        node* before = temp->prev;
        node* after = temp->next;

        before->next = after;
        after->prev = before;
    }

    // Insert a node immediately after head
    // This makes it the most recently used node
    void insertAfterHead(node* temp) {
        temp->next = head->next;
        temp->prev = head;

        head->next->prev = temp;
        head->next = temp;
    }

    // Return the value associated with a key
    int get(int key) {
        // If key is not present, return -1
        if (m.find(key) == m.end()) {
            return -1;
        }

        // Get the address of the node from the map
        node* temp = m[key];

        // Move the accessed node to the front
        deleteNode(temp);
        insertAfterHead(temp);

        // Return the stored value
        return temp->data;
    }

    // Insert a new key-value pair or update an existing key
    void put(int key, int value) {
        // If key already exists
        if (m.find(key) != m.end()) {
            node* temp = m[key];

            // Update its value
            temp->data = value;

            // Mark it as most recently used
            deleteNode(temp);
            insertAfterHead(temp);

            return;
        }

        // If capacity is zero, nothing can be stored
        if (capacity == 0) {
            return;
        }

        // If cache is full, remove the least recently used node
        if (m.size() == capacity) {
            node* lru = tail->prev;

            // Remove its key from the map
            m.erase(lru->key);

            // Remove the node from the linked list
            deleteNode(lru);

            // Free the node's memory
            delete lru;
        }

        // Create a new node
        node* temp = new node(key, value);

        // Store the node's address in the map
        m[key] = temp;

        // Insert the new node at the front
        insertAfterHead(temp);
    }
};

