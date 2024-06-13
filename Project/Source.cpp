#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const int REDCI = 20;
const int STUPCI = 40;

void ispisiMrezu(vector<vector<char>>& mreza) {
    for (int i = 0; i < REDCI; ++i) {
        for (int j = 0; j < STUPCI; ++j) {
            cout << mreza[i][j];
        }
        cout << endl;
    }
}

void ocistiEkran() {
    cout << "\033[2J\033[1;1H"; // ANSI escape kod za ?iš?enje ekrana
}

void pomakniDoB(int pocetniRedak, int pocetniStupac, int krajnjiRedak, int krajnjiStupac) {
    vector<vector<char>> mreza(REDCI, vector<char>(STUPCI, '.'));
    mreza[pocetniRedak][pocetniStupac] = 'A';
    mreza[krajnjiRedak][krajnjiStupac] = 'B';

    int trenutniRedak = pocetniRedak;
    int trenutniStupac = pocetniStupac;

    while (trenutniRedak != krajnjiRedak || trenutniStupac != krajnjiStupac) {
        ocistiEkran();
        mreza[trenutniRedak][trenutniStupac] = '*';
        ispisiMrezu(mreza);

        this_thread::sleep_for(chrono::milliseconds(100));

        // Pomicanje prema cilju
        if (trenutniRedak < krajnjiRedak) {
            trenutniRedak++;
        }
        else if (trenutniRedak > krajnjiRedak) {
            trenutniRedak--;
        }
        else if (trenutniStupac < krajnjiStupac) {
            trenutniStupac++;
        }
        else if (trenutniStupac > krajnjiStupac) {
            trenutniStupac--;
        }
    }

    ocistiEkran();
    mreza[trenutniRedak][trenutniStupac] = '*';
    ispisiMrezu(mreza);
}

int main() {
    int pocetniRedak, pocetniStupac, krajnjiRedak, krajnjiStupac;

    cout << "Unesite redak i stupac po?etne to?ke A (1-20 za redak, 1-40 za stupac): ";
    cin >> pocetniRedak >> pocetniStupac;
    cout << "Unesite redak i stupac krajnje to?ke B (1-20 za redak, 1-40 za stupac): ";
    cin >> krajnjiRedak >> krajnjiStupac;

    // Prilagodba za indeksiranje od 0
    pocetniRedak--;
    pocetniStupac--;
    krajnjiRedak--;
    krajnjiStupac--;

    pomakniDoB(pocetniRedak, pocetniStupac, krajnjiRedak, krajnjiStupac);

    return 0;
}
