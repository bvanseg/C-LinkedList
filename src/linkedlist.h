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
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <stdbool.h>

typedef struct node {
    void * data;
    struct node * NEXT;
} LL_Node;

typedef struct linkedList {
    LL_Node * head;
    int size;
    int elementSize;
} LinkedList;

LinkedList * linked_list_create(int elementSize);

bool linked_list_add(LinkedList * list, void * value);
bool linked_list_insert(LinkedList * list, void * value, int index);
void linked_list_add_all(LinkedList * list, int size, ...);

bool linked_list_remove(LinkedList * list, int index);
bool linked_list_remove_last(LinkedList * list);

void * linked_list_get(LinkedList * list, int index);

void linked_list_clear(LinkedList * list);

int linked_list_size(LinkedList * list);
bool linked_list_is_empty(LinkedList * list);

void linked_list_destroy(LinkedList * list);

#endif // LINKEDLIST_H_INCLUDED
