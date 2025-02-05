
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heap.h"


heap_t *heap_create(int capacity) {
    heap_t *heap = malloc(sizeof(heap_t));
    heap->data = malloc(sizeof(heap_node_t) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    return heap;
}

void heap_free(heap_t *heap) {
    free(heap->data);
    free(heap);
}

unsigned int heap_size(heap_t *heap) { return heap->size; }

unsigned int heap_parent(unsigned int index) {
    return (index - 1) / 2;
}

unsigned int heap_left_child(unsigned int index) {
    return 2 * index + 1;
}

unsigned int heap_right_child(unsigned int index) {
    // FILL ME OUT
}

unsigned int heap_level(unsigned int index) {
    return (int)(log2(index + 1));
}

void heap_print(heap_t *heap) {
    for (int ix = 0; ix < heap_size(heap); ix++) {
        printf("%3d - %3d : " HEAP_KEY_FORMAT " (val %lld)\n", heap_level(ix), ix,
               heap->data[ix].key, heap->data[ix].value);
    }
    printf("\n");
}

void heap_swap(heap_t *heap, int index1, int index2) {
    heap_node_t temp = heap->data[index1];
    heap->data[index1] = heap->data[index2];
    heap->data[index2] = temp;
}

void heap_bubble_up(heap_t *heap, int index) {
    // FILL ME IN
}

void heap_bubble_down(heap_t *heap, int index) {
    int min_index = index;
    int left = heap_left_child(index);
    int right = heap_right_child(index);

    if (left < heap_size(heap) && heap->data[left].key < heap->data[min_index].key) {
        min_index = left;
    }

    if (right < heap_size(heap) && heap->data[right].key < heap->data[min_index].key) {
        min_index = right;
    }

    if (min_index != index) {
        heap_swap(heap, index, min_index);
        heap_bubble_down(heap, min_index);
    }
}

void heap_insert(heap_t *heap, heap_key_t key, heap_value_t data) {
    if (heap_size(heap) == heap->capacity) {
        return;
    }

    heap->data[heap_size(heap)].key = key;
    heap->data[heap_size(heap)].value = data;
    heap->size++;

    heap_bubble_up(heap, heap_size(heap) - 1);
}


heap_value_t heap_remove_min(heap_t *heap) {
    if (heap_size(heap) == 0) {
        return (heap_value_t) KEY_NOT_PRESENT;
    }

    heap_value_t min = heap->data[0].value;

    heap->size--;

    // move last element to the root
    heap->data[0] = heap->data[heap_size(heap)];

    // then bubble it down to its correct position
    heap_bubble_down(heap, 0);

    return min;
}

unsigned int heap_find_key_index(heap_t *heap, heap_key_t aKey) {
    for (unsigned int ix = 0; ix < heap_size(heap); ix++) {
        if (heap->data[ix].key == aKey) {
            return ix;
        }
    }
    return KEY_NOT_PRESENT;
}

heap_value_t heap_find_key(heap_t *heap, heap_key_t aKey) {
    int index = heap_find_key_index(heap, aKey);
    if (index == KEY_NOT_PRESENT) {
        return (heap_value_t)KEY_NOT_PRESENT;
    }
    return heap->data[index].value;
}

void heap_update_key(heap_t *heap, heap_key_t old_key, heap_key_t new_key) {
    // FILL ME IN

}
void heap_update_value(heap_t *heap, heap_key_t key, heap_value_t new_data) {
    // FILL ME IN
}
