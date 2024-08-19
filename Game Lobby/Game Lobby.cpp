#include <iostream>
#include <vector>

using namespace std;

class Player {

    string name;
    Player* next=NULL;

public:

    Player(string name)
    {
        this->name = name;
    }

    void set_next(Player* pl) {
        next = pl;
    }

    void print_name() {
        cout << name << endl;
    }

    Player* get_next() {
        return next;
    }

};

class Lobby {
    int count = 0;
    Player* first = NULL;
    Player* last = NULL;
public:

    Lobby()
    {
        cout << "Lobby Bobby is created." << endl;
    }

    Lobby(Player& pl)
    {
        first = &pl;
        cout << "Lobby Bobby is created." << endl;
        ++count;
    }

    void create_player() {
        cout << "Please enter the name of new player: ";
        string g;
        cin >> g;
        Player* pl = new Player(g);
        ++count;
        if (count == 1) {
            first = pl;
        }
        else if(count==2) {
            last = pl;
            first->set_next(pl);
        }
        else {
            last->set_next(pl);
            last = pl;
        }
    }

    void remove_player() {
        if (count > 0) {
            Player* pl = first;
            first = first->get_next();
            delete pl;
            --count;
        }
        else {
            cout << "Nobody in lobby..."<<endl;
        }
    }

    void clear() {
        Player* pl = first;
        while (count > 0) {
            first = first->get_next();
            delete pl;
            pl = first;
            --count;
        }
        last = NULL;
        first = NULL;
    }

    void print_lobby() {
        Player* pl = first;
        cout << count << " players in the lobby:" << endl;
        for (int i = 0;i < count;++i) {
            pl->print_name();
            pl = pl->get_next();
        }
    }

    ~Lobby() {
        clear();
    }

};


int main()
{
    Lobby lb;
    int choice;
    do {

        cout << "\tWhat do you want:" << endl;
        cout << "\t0-quit" << endl;
        cout << "\t1-Add player" << endl;
        cout << "\t2-Remove player" << endl;
        cout << "\t3-Show lobby" << endl;
        cout << "\t4-Clear lobby" << endl;
        cout << "\tchoice: ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "Bye-bye!" << endl;
            break;
        case 1:
            lb.create_player();
            break;
        case 2:
            lb.remove_player();
            break;
        case 3:
            lb.print_lobby();
            break;
        case 4:
            lb.clear();
            break;
        }

    } while (choice != 0);
}
