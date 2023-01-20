#include <iostream> 
#include <fstream> // чтение запись файла
#include <string>  // работа со строками 

using namespace std;

int main()
{
    system("chcp 1251>nul"); //кириллизация
    system("color 1f"); //фон
    string str, otv; //вопрос-ответ
    int z = 1; //кол-во вопрос
    bool interval = false;
    ifstream f;
    f.open("test.txt");       //ifstream f("test.txt");   // окрываем файл для чтения
    ofstream out;             // поток для записи
    out.open("myanswer.txt"); // окрываем файл для записи
    if (f)                    // if (f.is_open())  проверка файла, что он открыт
    {
        while (getline(f, str)) // читаем данные построчно из файла
        {
            if (!interval) {
                cout << "\n\n\t\t\t\tТест\n";
                cout << "\t\t\tЗадание №" << z << "\n\n";
            }
            cout << "\t" << str << "\n";
            if (interval) {
                cout << "\n\t\t\tВведите ответ>";
                cin >> otv;
                z++;
                system("cls");
                out << otv << "\n";  // запись в файл ответов         
            }
            interval = !interval;
        }
    }
    else return 36;
    f.close(); out.close();       // закрываем файлы
    int p = 0, n = 0; //кол-во правильных-нет ответов
    ifstream f1("answer.txt");     // окрываем файл для чтения
    ifstream f2("myanswer.txt");   // окрываем файл для чтения
    cout << "\n\n";
    while (getline(f1, str) && getline(f2, otv)) // читаем данные построчно из файла
    {
        if (str == otv) { cout << "\t\t\t" << otv << " - верно\n"; p++; }
        else { cout << "\t\t\t" << otv << " - ошибка\n"; n++; }
    }
    f1.close(); f2.close();
    cout << "\n\n\t\t\tКоличество правильных ответов>>" << p << "\n";
    cout << "\t\t\tКоличество ошибок>>" << n << "\n";
    cout << "\n\n\t\t\t";

    system("pause");
}