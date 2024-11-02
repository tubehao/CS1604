#include <iostream>
#include <Random.h>
#include <chrono>
#include <thread>
using namespace std;

class Animal {
public:
      virtual int move() = 0;
      virtual void display() = 0;
};

class Tortoise : public Animal {
public:
    int move()
    {
        int probability = randomInteger(1, 10);

        if (probability < 5) return 3;
        else if (probability < 7) return -6;
        else return 1;
    }

    void display()
    {
        cout << "T";
    }
};

class Hare : public Animal {
public:
    int move()
    {
        int probability = randomInteger(1, 10);

        if (probability < 2) return 0;
        else if (probability < 4) return -9;
        else if (probability < 5) return 14;
        else if (probability < 8) return 3;
        else return -2;
    }

    void display()
    {
        cout << "H";
    }
};

int displayStatus(Animal **players, int* distance, int num)
{
    for (int i = 0; i < num; ++i) {
        players[i]->display();
        cout << '\t';
    }
    cout << endl;

    for (int i = 0; i < num; ++i)
        cout << distance[i] << '\t';
    cout << endl;
}

int play(Animal **players, int num, int LENGTH)
{
    int  *distance,  winner,  length = 0;
    distance = new int[num];
    for (int i = 0; i < num; ++i)
        distance[i] = 0;

    do {
        for (int i = 0; i < num; ++i) {
            distance[i] +=  players[i]->move();
            if (distance[i] > length) {
                length = distance[i];
                winner = i;
            }
        }
        displayStatus(players, distance, num);

        // Wait;
        this_thread::sleep_for(chrono::milliseconds(500));
    } while (length < LENGTH);

    delete[] distance;
    return winner;
}

int main()
{
    const int LENGTH = 20;
    int  num, winner;
    Animal **players;

    cout << "Number of players ? ";
    cin >> num;

    players = new Animal*[num];
    for (int i = 0; i < num; ++i)
        if (randomBool())
            players[i] = new Tortoise;
        else
            players[i] = new Hare ;

    winner = play(players, num, LENGTH);

    cout << "The winner is player : " << winner << endl;

    for (int i = 0; i < num; i++)
        delete players[i];

    delete[] players;

    return 0;
}
