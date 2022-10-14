/*
 * MIT License
 *
 * Copyright (c) 2020 Boston Vanseghi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdarg.h>
#include "linkedlist.h"

LinkedList* create_linkedList(int elementSize) {
    LinkedList* list = malloc(sizeof(LinkedList));

    if (list != NULL) {
        list->size = 0;
        list->elementSize = elementSize;

        list->head = malloc(sizeof(LL_Node));

        // Setup the head of the list.
        if (list->head != NULL) {
            list->head->data = malloc(elementSize);
            list->head->NEXT = NULL;
        }
    }

    return list;
}

bool add_linkedList(LinkedList* list, void* value) {
    if (list == NULL)
        return false;

    LL_Node* current = list->head;

    int i = 0;
    while (current->NEXT != NULL)
        current = current->NEXT;

    if (list->size == 0)
        memcpy(list->head->data, value, list->elementSize);
    else
        memcpy(current->data, value, list->elementSize);

    LL_Node* newNode = malloc(sizeof(LL_Node));

    if (newNode != NULL) {
        newNode->NEXT = NULL;
        newNode->data = malloc(list->elementSize);
    }

    current->NEXT = newNode;

    list->size++;

    return true;
}

bool addAt_linkedList(LinkedList* list, void* value, int index) {
    if (list == NULL)
        return false;

    LL_Node* prev = NULL;
    LL_Node* current = list->head;

    for (int i = 0; i < index; i++) {
        if (i == index - 1)
            prev = current;
        current = current->NEXT;
    }

    LL_Node* newNode = malloc(sizeof(LL_Node));

    if (newNode != NULL) {
        newNode->data = malloc(list->elementSize);

        if (index == 0) {
            newNode->NEXT = list->head;
            list->head = newNode;
            memmove(list->head->data, value, list->elementSize);
        }
        else {
            newNode->NEXT = current;
            if(prev != NULL)
                prev->NEXT = newNode;
            memmove(newNode->data, value, list->elementSize);
        }

        list->size++;

        return true;
    }
    return false;
}

void addAll_linkedList(LinkedList* list, int size, ...) {
    va_list params;
    va_start(params, size);
    void* arg = va_arg(params, void*);
    int i = 0;
    while (i < size) {
        add_linkedList(list, arg);
        arg = va_arg(params, void*);
        i++;
    }
    va_end(params);
}

bool remove_linkedList(LinkedList* list, int index) {

    LL_Node* prev = NULL;
    LL_Node* current = list->head;

    for (int i = 0; i < index; i++) {
        if (i == index - 1)
            prev = current;
        current = current->NEXT;
    }

    if (index == 0 && list->size >= 1) {
        list->head = current->NEXT;
    }
    else {
        if(prev != NULL)
            prev->NEXT = prev->NEXT->NEXT;
    }

    free(current->data);
    free(current);

    list->size--;

    return true;
}

bool removeLast_linkedList(LinkedList* list) {
    return remove_linkedList(list, list->size - 1);
}

void* get_linkedList(LinkedList* list, int index) {
    if (index == list->size)
        return NULL; // TODO: Throw error.

    LL_Node* current = list->head;

    for (int i = 0; i < index; i++) {
        current = current->NEXT;
    }

    return current->data;
}

void clear_linkedList(LinkedList* list) {

    LL_Node* current = list->head;
    LL_Node* next;

    while (current != NULL) {
        next = current->NEXT;
        free(current->data);
        free(current);
        current = next;
    }

    list->size = 0;

    LL_Node* newHead = malloc(sizeof(LL_Node));

    if (newHead != NULL) {
        newHead->data = malloc(sizeof(list->elementSize));
        newHead->NEXT = NULL;
    }
    list->head = newHead;
}

int size_linkedList(LinkedList* list) {
    return list->size;
}

bool isEmpty_linkedList(LinkedList* list) {
    return list->size == 0;
}

void destroy_linkedList(LinkedList* list) {
    clear_linkedList(list);
    free(list->head);
    free(list);
    list = NULL;
}
