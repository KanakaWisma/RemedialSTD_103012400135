#include "stack.h"

void create_stack(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool is_full(Stack S) {
    return S.top == N_STACK - 1;
}

void push(Stack &S, infotype X) {
    if (!is_full(S)) {
        S.top++;
        S.info[S.top] = X;
    }
}

void pop(Stack &S, infotype &X) {
    if (!isEmpty(S)) {
        X = S.info[S.top];
        S.top--;
    }
}

void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi) {
    infotype P;

    if (aksi == "UNDO") {
        if (!isEmpty(S_Aksi)) {
            pop(S_Aksi, P);
            push(S_Redo, P);
        }
    }
    else if (aksi == "REDO") {
        if (!isEmpty(S_Redo)) {
            pop(S_Redo, P);
            push(S_Aksi, P);
        }
    }
    else {
        push(S_Aksi, aksi);
        while (!isEmpty(S_Redo)) {
            pop(S_Redo, P);
        }
    }
}

int totalDamage(Stack &S_Aksi) {
    Stack S_Temp;
    infotype P;
    int total = 0;

    create_stack(S_Temp);

    while (!isEmpty(S_Aksi)) {
        pop(S_Aksi, P);

        if (P == "ATTACK") {
            total += 30;
        }
        else if (P == "DEFENSE") {
            total += 5;
        }

        push(S_Temp, P);
    }

    while (!isEmpty(S_Temp)) {
        pop(S_Temp, P);
        push(S_Aksi, P);
    }

    return total;
}

