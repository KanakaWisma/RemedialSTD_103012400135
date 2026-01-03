#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack S_Aksi, S_Redo;
    int total;

    create_stack(S_Aksi);
    create_stack(S_Redo);

    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "DEFENSE");
    manageAction(S_Aksi, S_Redo, "ATTACK");
    manageAction(S_Aksi, S_Redo, "UNDO");
    manageAction(S_Aksi, S_Redo, "UNDO");
    manageAction(S_Aksi, S_Redo, "REDO");
    manageAction(S_Aksi, S_Redo, "DEFENSE");

    total = totalDamage(S_Aksi);

    cout << "Total Damage = " << total << endl;

    return 0;
}



