#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>

using namespace std;

int tail1[20], tail2[40], a = 3, ii;
bool work = true;
vector<char> snake = { '@' };

#include "Objects.h"

#include "Interface.h"

int main()

{

    Interface click;
    Objects walls;
    Objects snake;

    cout << "UP - w" << endl << "Down - s" << endl << "Left - a" << endl << "Right - d" << endl << "Quit - q" << endl;

    cout << "To play 1 but to procrastinate 0" << endl << "Your decide: ";

    cin >> work;

        do {
    
            click.manage();

        } while (work);

    system("cls");

    cout << endl << endl << "****************Game over***************\n";

    click.result();

    return 0;
}