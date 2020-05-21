#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <fstream>

class Objects {

public:

    int high = 20, length = 40;
    int first, tail;

    void horizontal_wall() {
        for (int i = 0; i < length; i++)
        {
            cout << "#";
        }
    }

    void snakee() {

        static int x_, y_, eat_x = x_, eat_y = y_;

        int i = 0, j = 0;

        horizontal_wall();

        cout << endl;

        srand(time(0));

        for (; j < high; j++)
        {
            cout << "#";
            for (i = 0; i < length - 2; i++)
            {
                if (i == x_ && j == y_) {
                    cout << snake[0];
                }
                else if (i == eat_x && j == eat_y)
                    cout << "^";
                else
                {
                    bool k = true;
                    for (int p = 0; p < snake.size() - 1; p++)
                    {
                        if (i == tail1[p] && j == tail2[p] && snake.size() > 1 && k == true)
                        {
                            cout << snake[p + 1];

                            k = false;
                        }
                    }
                    if (k)
                        cout << " ";
                }

            }
            if (j == high - 1) {

                //game will close when head will take place a body
                for (int i = 0; i < snake.size() - 1; i++)
                {
                    if (x_ == tail1[i] && y_ == tail2[i]) {
                        work = false;
                        break;
                    }

                }

                for (int k = 0; k < snake.size(); k++)
                {
                    tail1[snake.size() - k] = tail1[snake.size() - k - 1];
                    tail2[snake.size() - k] = tail2[snake.size() - k - 1];
                }

                tail1[0] = x_;
                tail2[0] = y_;
            }

            cout << "#";


            cout << endl;
        }

        if (x_ == eat_x && y_ == eat_y)
        {
            eat_x = rand() % (length - 2);
            eat_y = rand() % (high - 1);

            if (first == 1) {
                snake.push_back('#');
            }

            first = 1;

        }

        horizontal_wall();

        if (a == 0) {//up
            y_--;
        }
        else if (a == 1) {//down
            y_++;
        }
        else if (a == 2) {//left
            x_--;
        }
        else if (a == 3) {//right
            x_++;

        }

        if ((x_ == length - 2) || (x_ == -1) || (y_ == high) || (y_ == -1)) {
            work = false;
        }

    }
};
