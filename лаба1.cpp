#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(1251);
    struct stud {
        char fam[20];
        int gr;
        int oc[3];
        double sr;
    };
    stud a[30] = {}; // инициализируем массив a нулями
    stud w = {}; // инициализируем структуру w нулями

    int n, size = sizeof(stud);
    FILE* f, * ft;
    char name[10] = ""; // инициализируем name пустой строкой
    char nametxt[10] = ""; // инициализируем nametxt пустой строкой

    while (true) {
        system("cls");
        puts(" Создать файл - 1");
        puts(" Открыть файл- 2");
        puts(" Добавить в файл -3");
        puts(" Выбрать из файла -4");
        puts("Записать в текстовый файл - 5");
        puts(" Выход - 0");
        switch (getch())
        {
        case'1':system("cls");
            cout << "Имя создоваевого фаила = "; cin >> name;
            f = fopen(name, "wb");
            fclose(f);

        case '3':system("cls");
            f = fopen(name, "ab");
            while (true) {
                cout << "Фамилия = "; cin >> w.fam;
                if (w.fam[0] == '.') break;
                cout << "Группа = "; cin >> w.gr;
                cout << "Физика ="; cin >> w.oc[0];
                cout << "Математика= "; cin >> w.oc[1];
                cout << "Информатика = "; cin >> w.oc[2];
                double s = 0;
                for (int k = 0; k < 3; k++) s += w.oc[k];
                w.sr = s / 3;
                fwrite(&w, size, 1, f);
            }
            fclose(f);
            break;
        case'2':system("cls");
            cout << "Имя открываемого файла ="; cin >> name;
            f = fopen(name, "rb");
            cout << " Список группы\n" << endl;
            cout << " Фамилия Группа Физика Математика Информатика Средний балл\n";
            while (fread(&w, size, 1, f))
                printf("%-8s %-8d %-8d %-12d %-12d %-15.2f\n",
                    w.fam, w.gr, w.oc[0], w.oc[1], w.oc[2], w.sr);
            fclose(f); system("pause");
            break;

        case '4':
            system("cls");
            f = fopen(name, "rb");
            cout << " Список учеников у которых оценка по информатике 9 или 10\n";
            cout << "Фамилия Группа Физика Математика Информатика Средний балл\n";
            while (fread(&w, size, 1, f)) {
                if (w.oc[2] == 9 || w.oc[2] == 10) {
                    printf("%-8s %-8d %-8d %-12d %-12d %-15.2f\n",
                        w.fam, w.gr, w.oc[0], w.oc[1], w.oc[2], w.sr);
                }
            }

            fclose(f);

            system("pause");
            break;
        case '5':
            system("cls");
            cout << " Имя текстового файла = "; cin >> nametxt;
            f = fopen(name, "rb");
            ft = fopen(nametxt, "wt");
            fprintf(ft, "                     Содержимое всего файла и результаты решения индивидуального задания\n");
            fprintf(ft, "Фамилия Группа Физика Математика Информатика Средний балл\n");
            while (fread(&w, size, 1, f))
                fprintf(ft, "%-8s %-8d %-8d %-12d %-12d %-15.2f\n",
                    w.fam, w.gr, w.oc[0], w.oc[1], w.oc[2], w.sr);

            // Добавляем результаты решения индивидуального задания в конец файла
            fprintf(ft, "\n\nРезультаты решения индивидуального задания:\n");
            fprintf(ft, " Список учеников у которых оценка по информатике 9 или 10\n");
            fprintf(ft, "Фамилия Группа Физика Математика Информатика Средний балл\n");
            fseek(f, 0, SEEK_SET); // перемещаем указатель в начало файла
            while (fread(&w, size, 1, f)) {
                if (w.oc[2] == 9 || w.oc[2] == 10) {
                    fprintf(ft, "%-8s %-8d %-8d %-12d %-12d %-15.2f\n",
                        w.fam, w.gr, w.oc[0], w.oc[1], w.oc[2], w.sr);
                }
            }
            fclose(f); fclose(ft);
            break;

        case'0':return 0;
        }
    }
}