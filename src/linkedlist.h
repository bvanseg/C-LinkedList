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

LinkedList * create_linkedList(int elementSize);

bool add_linkedList(LinkedList * list, void * value);
bool addAt_linkedList(LinkedList * list, void * value, int index);
void addAll_linkedList(LinkedList * list, int size, ...);

bool remove_linkedList(LinkedList * list, int index);
bool removeLast_linkedList(LinkedList * list);

void * get_linkedList(LinkedList * list, int index);

void clear_linkedList(LinkedList * list);

int size_linkedList(LinkedList * list);
bool isEmpty_linkedList(LinkedList * list);

void destroy_linkedList(LinkedList * list);

#endif // LINKEDLIST_H_INCLUDED
