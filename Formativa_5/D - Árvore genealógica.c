#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 300
#define NAME_LEN 50

int parent[MAX];
int rank[MAX];
char names[MAX][NAME_LEN];
int nameCount = 0;

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

int getNameIndex(char* name) {
    for (int i = 0; i < nameCount; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    strcpy(names[nameCount], name);
    return nameCount++;
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    // Process relations
    for (int i = 0; i < N; i++) {
        char name1[NAME_LEN], relation[NAME_LEN], name2[NAME_LEN];
        scanf("%s %s %s", name1, relation, name2);
        
        int index1 = getNameIndex(name1);
        int index2 = getNameIndex(name2);
        
        unite(index1, index2);
    }
    
    for (int i = 0; i < nameCount; i++) {
        getNameIndex(names[i]);
    }
    
    int familyCount = 0;
    bool isRepresentative[MAX] = {false};
    
    for (int i = 0; i < nameCount; i++) {
        int root = find(i);
        if (!isRepresentative[root]) {
            isRepresentative[root] = true;
            familyCount++;
        }
    }
    
    printf("%d\n", familyCount);
    
    return 0;
}
