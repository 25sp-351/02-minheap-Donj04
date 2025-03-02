
#ifndef HEAP_H
#define HEAP_H

// a min heap
#define KEY_NOT_PRESENT -1

typedef int heap_key_t;
#define HEAP_KEY_FORMAT "%d"

typedef unsigned long long heap_value_t;

typedef struct {
    heap_key_t key;
    heap_value_t value;
} heap_node_t;

typedef struct {
    heap_node_t *data;
    int size;
    int capacity;
} heap_t;

heap_t *heap_create(int capacity);

void heap_free(heap_t *heap);

unsigned int heap_size(heap_t *heap);

// adds a new element even if key exists already
void heap_insert(heap_t *heap, heap_key_t key, heap_value_t data);

heap_value_t heap_find_key(heap_t *heap, heap_key_t aKey);
void heap_update_key(heap_t *heap, heap_key_t old_key, heap_key_t new_key);
void heap_update_value(heap_t *heap, heap_key_t key, heap_value_t new_data);

heap_value_t heap_remove_min(heap_t *heap);

void heap_print(heap_t *heap);

#endif
