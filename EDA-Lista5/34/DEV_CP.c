#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

long long segtree[4 * MAXN];  
long long arr[MAXN];          

// Function to build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

// Function to update the segment tree
void update(int node, int start, int end, int idx, long long val) {
    if (start == end) {
        arr[idx] = val;
        segtree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

// Function to query the segment tree
long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return 0;
    }
    if (l <= start && end <= r) {
        return segtree[node];
    }
    int mid = (start + end) / 2;
    long long p1 = query(2 * node, start, mid, l, r);
    long long p2 = query(2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
    }

    build(1, 1, N);

    for (int i = 0; i < M; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int K;
            long long X;
            scanf("%d %lld", &K, &X);
            update(1, 1, N, K, X);
        } else if (type == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            printf("%lld\n", query(1, 1, N, A, B));
        }
    }

    return 0;
}
