#include <stdlib.h>
#include <stdbool.h>

#define MAXV 1000000

typedef struct {
    int *arr;
    int size;
    int cap;
} Vec;

void pushBack(Vec *v, int x) {
    if (v->size == v->cap) {
        v->cap = v->cap ? v->cap * 2 : 2;
        v->arr = realloc(v->arr, v->cap * sizeof(int));
    }

    v->arr[v->size++] = x;
}

bool isPrime(int x) {
    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }

    return true;
}

int minJumps(int* nums, int numsSize) {

    if (numsSize == 1)
        return 0;

    Vec *mp = calloc(MAXV + 1, sizeof(Vec));

    // build prime -> indices map
    for (int i = 0; i < numsSize; i++) {

        int x = nums[i];
        int temp = x;

        for (int p = 2; p * p <= temp; p++) {

            if (x % p == 0) {

                pushBack(&mp[p], i);

                while (x % p == 0)
                    x /= p;
            }
        }

        if (x > 1)
            pushBack(&mp[x], i);
    }

    // BFS
    int *q = malloc(numsSize * sizeof(int));

    int front = 0;
    int back = 0;

    bool *vis = calloc(numsSize, sizeof(bool));
    bool *usedPrime = calloc(MAXV + 1, sizeof(bool));

    q[back++] = 0;
    vis[0] = true;

    int steps = 0;

    while (front < back) {

        int sz = back - front;

        while (sz--) {

            int i = q[front++];

            if (i == numsSize - 1)
                return steps;

            // left
            if (i - 1 >= 0 && !vis[i - 1]) {
                vis[i - 1] = true;
                q[back++] = i - 1;
            }

            // right
            if (i + 1 < numsSize && !vis[i + 1]) {
                vis[i + 1] = true;
                q[back++] = i + 1;
            }

            // teleport
            int p = nums[i];

            if (isPrime(p) && !usedPrime[p]) {

                usedPrime[p] = true;

                for (int k = 0; k < mp[p].size; k++) {

                    int nxt = mp[p].arr[k];

                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q[back++] = nxt;
                    }
                }
            }
        }

        steps++;
    }

    return -1;
}