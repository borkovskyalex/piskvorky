#include <iostream>
using namespace std;

struct hrac {
    char z;
};

void vykresli(char (&p)[3][3]) {
    cout << p[0][0] << "|" << p[0][1] << "|" << p[0][2] << "\n";
    cout << "-+-+-\n";
    cout << p[1][0] << "|" << p[1][1] << "|" << p[1][2] << "\n";
    cout << "-+-+-\n";
    cout << p[2][0] << "|" << p[2][1] << "|" << p[2][2] << "\n";
}

void tah(char (&p)[3][3], hrac h) {
    int x,y;
    znova:
    cout << "Zadej x a y pro " << h.z << ": ";
    if(!(cin >> x >> y)) {
        cout << "chybny vstup\n";
        cin.clear();
        char blbost[100];
        cin >> blbost;
        goto znova;
    }
    if(x<0) goto chyba;
    if(x>2) goto chyba;
    if(y<0) goto chyba;
    if(y>2) goto chyba;
    if(p[x][y]=='X') goto chyba;
    if(p[x][y]=='O') goto chyba;
    p[x][y] = h.z;
    return;
chyba:
    cout << "chybny vstup\n";
    goto znova;
}

int vyhra(char (&p)[3][3]) {
    if(p[0][0]=='X' && p[0][1]=='X' && p[0][2]=='X') return 1;
    if(p[1][0]=='X' && p[1][1]=='X' && p[1][2]=='X') return 1;
    if(p[2][0]=='X' && p[2][1]=='X' && p[2][2]=='X') return 1;
    if(p[0][0]=='X' && p[1][0]=='X' && p[2][0]=='X') return 1;
    if(p[0][1]=='X' && p[1][1]=='X' && p[2][1]=='X') return 1;
    if(p[0][2]=='X' && p[1][2]=='X' && p[2][2]=='X') return 1;
    if(p[0][0]=='X' && p[1][1]=='X' && p[2][2]=='X') return 1;
    if(p[0][2]=='X' && p[1][1]=='X' && p[2][0]=='X') return 1;

    if(p[0][0]=='O' && p[0][1]=='O' && p[0][2]=='O') return 2;
    if(p[1][0]=='O' && p[1][1]=='O' && p[1][2]=='O') return 2;
    if(p[2][0]=='O' && p[2][1]=='O' && p[2][2]=='O') return 2;
    if(p[0][0]=='O' && p[1][0]=='O' && p[2][0]=='O') return 2;
    if(p[0][1]=='O' && p[1][1]=='O' && p[2][1]=='O') return 2;
    if(p[0][2]=='O' && p[1][2]=='O' && p[2][2]=='O') return 2;
    if(p[0][0]=='O' && p[1][1]=='O' && p[2][2]=='O') return 2;
    if(p[0][2]=='O' && p[1][1]=='O' && p[2][0]=='O') return 2;

    int r=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(p[i][j]==' ') r++;
        }
    }
    if(r==0) return 3;
    return 0;
}

int main() {
    char p[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    hrac h1; h1.z = 'X';
    hrac h2; h2.z = 'O';
    int k = 1;
    while(1) {
        vykresli(p);
        if(k==1) {
            tah(p, h1);
            k = 2;
        } else {
            tah(p, h2);
            k = 1;
        }
        int v = vyhra(p);
        if(v==1) {
            vykresli(p);
            cout << "X vyhral\n";
            return 0;
        }
        if(v==2) {
            vykresli(p);
            cout << "O vyhral\n";
            return 0;
        }
        if(v==3) {
            vykresli(p);
            cout << "remiza\n";
            return 0;
        }
    }
}
