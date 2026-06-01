#include <iostream>
using namespace std;

struct hrac {
    char z;
};

void vykresli(char (&p)[3][3]) {
    cout << p[0][2] << "|" << p[1][2] << "|" << p[2][2] << "\n";
    cout << "-+-+-\n";
    cout << p[0][1] << "|" << p[1][1] << "|" << p[2][1] << "\n";
    cout << "-+-+-\n";
    cout << p[0][0] << "|" << p[1][0] << "|" << p[2][0] << "\n";
}

void tah(char (&p)[3][3], hrac h) {
    int x,y;
    znova:
    cout << "Zadej pro " << h.z << "\n";
    cout << "x: ";
    if(!(cin >> x)) {
        cout << "chybny vstup\n";
        cin.clear();
        char blbost[100];
        cin >> blbost;
        goto znova;
    }
    cout << "y: ";
    if(!(cin >> y)) {
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
    hrac h1; h1.z = 'X';
    hrac h2; h2.z = 'O';
zacatek:
    char p[3][3];
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            p[i][j] = ' ';
        }
    }
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
        if(v!=0) {
            vykresli(p);
            if(v==1) cout << "X vyhral\n";
            if(v==2) cout << "O vyhral\n";
            if(v==3) cout << "remiza\n";
            
            cout << "rematch?(a/n)\n";
            char a;
            cin >> a;
            if(a=='a') goto zacatek;
            return 0;
        }
    }
}
