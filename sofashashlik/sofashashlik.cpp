﻿#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;



struct DateTime {
    double year;
    int month;
    int day;
    int hour;
    int minute;
};

struct Sheep
{
    int weight = 40;
    int weightWool = 400;
    

    void print() {

        setlocale(LC_ALL, "Russian");
        cout << "w: " << weight << "   ww: " << weightWool << " " << endl;
    }
};

void addSheep(Sheep*& sheeps, int& size, Sheep sheep) {
    Sheep* temp = new Sheep[size + 1];
    for (int i = 0; i < size; i++) {
        temp[i] = sheeps[i];
    }
    temp[size] = sheep;
    delete[] sheeps;
    sheeps = temp;
    size++;
}

void deliteSheep(Sheep*& sheeps, int& size, int index) {
    Sheep* temp = new Sheep[size - 1];
    if (index <= size) {
        for (int i = 0; i < index; i++) {
            temp[i] = sheeps[i];
        }
        for (int i = index + 1; i < size; i++) {
            temp[i - 1] = sheeps[i];
        }
        delete[] sheeps;
        sheeps = temp;
        size--;
    }
    else {
        cout << "u are bad human" << endl;
    }
}




Sheep createSheep() {
    Sheep sheep;
    sheep.weight = rand() % 100 + 20;
    sheep.weightWool = rand() % 100 + 200;
    return sheep;
}

void file(Sheep* arrSheeps,int size){
        FILE* file;
        if ((file = fopen("D:\\sheepfile.txt", "w")) == NULL) {

        }
        else {
            for (int i = 0; i < size; i++) {
                fprintf(file, "%d", arrSheeps[i].weight);
                fprintf(file, "%s", "\n");
                fprintf(file, "%d", arrSheeps[i].weightWool);
                fprintf(file, "%s", "\n");
                
            }
        }
        fclose(file);
    }

    void plan(Sheep* arrSheeps) {
    
    }



int main()
{
    cout << "Welcome to Sofa's shashlikhouse!" << endl << endl;
    int size = 10;
    Sheep* arrSheeps = new Sheep[size];
    int meat = 0;
    for (int iq = 0; iq <= 30; iq++) {
        setlocale(LC_ALL, "Russian");
        srand(time(0));

        cout << "Good morning!" << endl << endl;

        cout << "My herd: " << endl << endl;
        for (int i = 0; i < size; i++) {
            arrSheeps[i].print();
            cout << endl;
        }
        cout << endl;


        
        int index;
        cout << "Choose which sheep will you kill?" << endl;
        cin >> index;
        int meat = arrSheeps[index].weight;
        deliteSheep(arrSheeps, size, index);


        for (int i = 0; i < size; i++) {
            arrSheeps[i].weight += 1;
            arrSheeps[i].weightWool += 100;

        }
        cout << endl << endl;

        if (meat < 30) {
            cout << "Not enough meat, kill sheep(" << endl;
            deliteSheep(arrSheeps, size, index);
            for (int i = 0; i < size; i++) {
                arrSheeps[i].print();
                cout << endl;
            }
            cout << endl << endl;
        }
        else {
            cout << "Enough meat)" << endl;
        }
        cout << endl << endl;
        cout << "End of the day!" << endl << endl;
        meat -= 30;
        cout << meat << " kg left" << endl << endl;
        if (iq % 5 == 0) {
            Sheep NewSheep = createSheep();
            addSheep(arrSheeps, size, NewSheep);
            for (int i = 0; i < size; i++) {
                arrSheeps[i].print();
                cout << endl;
            }
            cout << endl << endl;
        }
        file(arrSheeps, size);
    }


}
