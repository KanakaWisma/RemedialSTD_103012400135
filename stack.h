#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <string>
using namespace std;

const int N_STACK = 2025;
typedef string infotype;

struct Stack{
    infotype info[N_STACK];
    int top;
};

void create_stack(Stack &S);
bool is_empty(Stack S);
bool is_full(Stack S);
void push(Stack &S, infotype x);
void pop(Stack &S, infotype &x);
void manageAction(Stack &S_Aksi, Stack &S_Redo, infotype aksi);
int totalDamage(Stack &S_Aksi);

#endif // STACK_H_INCLUDED
