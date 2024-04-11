#include <iostream>
#include <Game.h>

using namespace std;

int main()
{
    Game game = Game();
    auto pos = game.marbles();
    int count = 1;
    for(auto &p : pos) {
        cout << p.toString() << " " << count << endl;
        count++;
        if(count == 15 ) {
            cout << "14 billes" << endl;
        }
    }
    cout << endl << "compteur : " << count-1 << endl;
    return 0;
}
