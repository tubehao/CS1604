#include <iostream>
#include <sstream>
#include <cassert>
#include <thread>
#include <chrono>
#include <Random.h>
#include <Stack.h>
using namespace std;

//
// Unit
//
class Unit {
public:
    Unit(int r, int c) : row(r), col(c) {}

    int getRow() const { return row; }
    int getCol() const { return col; }
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }

private:
    int row, col;
};

//
// Output of unit:
//
ostream& operator<<(ostream& os, const Unit& u)
{
    return os << "Unit at (" << u.getRow() << ", " << u.getCol() << ")";
}

//
// Command
//
class Command
{
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};

//
// Move Command
//
class MoveCommand : public Command {
public:
    MoveCommand(Unit *u, int r, int c)
        : unit(u), row(r), col(c),
        rowBefore(u->getRow()), colBefore(u->getCol())
    {}

    virtual void execute() override {
        unit->setRow(row);
        unit->setCol(col);
    }

    virtual void undo() override {
        unit->setRow(rowBefore);
        unit->setCol(colBefore);
    }

private:
    Unit *unit;
    int row, col;
    int rowBefore, colBefore;
};

//
// Input Handler
//
Command* handleInput(Unit *u, int i)
{
    if (i <= 0 || i > 9)
        return nullptr;

    switch (i) {
    case 1:
        return new MoveCommand(u, u->getRow() - 1, u->getCol() - 1);
    case 2:
        return new MoveCommand(u, u->getRow() - 1, u->getCol());
    case 3:
        return new MoveCommand(u, u->getRow() - 1, u->getCol() + 1);
    case 4:
        return new MoveCommand(u, u->getRow(), u->getCol() - 1);
    case 5:
        return new MoveCommand(u, u->getRow(), u->getCol());
    case 6:
        return new MoveCommand(u, u->getRow(), u->getCol() + 1);
    case 7:
        return new MoveCommand(u, u->getRow() + 1, u->getCol() - 1);
    case 8:
        return new MoveCommand(u, u->getRow() + 1, u->getCol());
    case 9:
        return new MoveCommand(u, u->getRow() + 1, u->getCol() + 1);
    }

    assert(false);
}

//
// Undo commands
//
void undoCommands(Stack<Command*> &cmds, int n)
{
    while (!cmds.isEmpty() && n > 0) {
        Command *cmd = cmds.pop();
        cmd->undo();
        delete cmd;
    }
}

//
// Query the input of Player A
//
Command *queryInputA(Unit& u, Stack<Command*> &cmds)
{
    cout << "(Player A) Enter input:";

    string line;
    if (!getline(cin, line))
        return nullptr;

    stringstream ss(line);
    int i;
    ss >> i;

    if (i == 0) {
        int n;
        ss >> n;
        if (n > 0)
            undoCommands(cmds, n);
        return nullptr;
    }


    /*int i = randomInteger(1, 9);

    cout << i << endl;*/

    Command* cmd = handleInput(&u, i);
    cmds.push(cmd);
    return cmd;
}

//
// Query the input of Player B
//
Command *queryInputB(Unit& u, Stack<Command*> &cmds)
{
    cout << "(Player B) Enter input:";

    /* string line;
    if (!getline(cin, line))
        return nullptr;

    stringstream ss(line);
    int i;
    ss >> i;
    */

    int i = randomInteger(1, 9);

    cout << i << endl;

    Command* cmd = handleInput(&u, i);
    cmds.push(cmd);
    return cmd;
}

//
// Game loop
//
void play()
{
    Unit ua(10, 10);
    Unit ub(20, 20);
    int turn = 0;

    //
    // side = true when player A is active
    // side = false when player B is active
    //
    bool side = true;

    Stack<Command*> cmds;

    while (true) {
        Command *cmd;

        if (side)
            cmd = queryInputA(ua, cmds);
        else
            cmd = queryInputB(ub, cmds);

        if (cmd != nullptr)
            cmd->execute();

        cout << "Turn " << turn << ": " << ua << " and " << ub << endl;
        side = !side;

        //this_thread::sleep_for(chrono::milliseconds(500));
    }

    // Clean up commands
    while (!cmds.isEmpty())
        delete cmds.pop();
}

//
// Main
//
int main()
{
    play();
    return 0;
}
