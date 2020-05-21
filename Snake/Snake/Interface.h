#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>

class Interface : Objects {
public:
    enum Move { UP = 119, Down = 115, Right = 97, Left = 100, Quit = 113 };

    Objects snake1;

    void manage() {
        system("cls");

        snake1.snakee();

        if (_kbhit())
        {
            switch (_getch()) {
            case UP:
                if (a != 1)
                    a = 0;
                break;
            case Down:
                if (a != 0)
                    a = 1;
                break;
            case Right:
                if (a != 3)
                    a = 2;
                break;
            case Left:
                if (a != 2)
                    a = 3;
                break;
            case Quit:
                work = false;
                break;
            }
            Sleep(5);
        }

        cout << "\nScore: " << (snake.size() - 1) * 10;

    }

    void result() {
        int record;
        ifstream read_record("records.txt", ios::in);

        read_record >> record;
        read_record.close(); // close file


        if ((snake.size() - 1) * 10 > record) {
            ofstream write_record("records.txt");

            write_record << ((snake.size() - 1) * 10);
            write_record.close();
        }

        read_record.open("records.txt");
        read_record >> record; //for one word
        //read_record.getline(record, 5);//for one line
        read_record.close(); // close file
        cout << endl << "Record is: " << record << endl << endl;

    }
};