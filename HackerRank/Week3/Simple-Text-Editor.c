#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000000

typedef struct Stack {
    char* states[MAX_LEN];
    int top;
} Stack;

void push(Stack* stack, const char* str) {
    stack->states[++(stack->top)] = strdup(str);
}

char* pop(Stack* stack) {
    if (stack->top < 0) return "";
    return stack->states[(stack->top)--];
}

int main() {
    int Q;
    scanf("%d", &Q);

    char S[MAX_LEN] = "";
    Stack history;
    history.top = -1;

    for (int i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            char W[MAX_LEN];
            scanf("%s", W);
            push(&history, S);
            strcat(S, W);
        } else if (type == 2) {
            int k;
            scanf("%d", &k);
            push(&history, S);
            S[strlen(S) - k] = '\0';
        } else if (type == 3) {
            int k;
            scanf("%d", &k);
            printf("%c\n", S[k - 1]);
        } else if (type == 4) {
            strcpy(S, pop(&history));
        }
    }

    return 0;
}
