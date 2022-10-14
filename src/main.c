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
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

int main() {
    LinkedList* list = linked_list_create(sizeof(int));

    int a = 0, b = 1, c = 2, d = 3;

    printf("Is list empty: %d\n", linked_list_is_empty(list));

    linked_list_add(list, &a);
    printf("Value at list[0]: %d\n", *(int*)linked_list_get(list, 0));
    printf("Size of list: %d\n", linked_list_size(list));

    linked_list_add(list, &b);
    printf("Value at list[1]: %d\n", *(int*)linked_list_get(list, 1));
    printf("Size of list: %d\n", linked_list_size(list));

    linked_list_add(list, &c);
    printf("Value at list[2]: %d\n", *(int*)linked_list_get(list, 2));
    printf("Size of list: %d\n", linked_list_size(list));

    linked_list_add(list, &d);
    printf("Value at list[3]: %d\n", *(int*)linked_list_get(list, 3));
    printf("Size of list: %d\n", linked_list_size(list));

    printf("Is list empty: %d\n", linked_list_is_empty(list));

    printf("Clearing list...\n");
    linked_list_clear(list);

    printf("Is list empty: %d\n", linked_list_is_empty(list));

    linked_list_destroy(list);
    return 0;
}
