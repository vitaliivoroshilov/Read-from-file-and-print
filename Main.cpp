#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char name[250];
    string s;
    cout << "Enter the name of the file: "; //Ввести путь к файлу
    cin.getline(name, 250);
    FILE* f;
    fopen_s(&f, name, "r");

    fseek(f, 0, SEEK_END); //Сместим указатель f к концу файла
    int size = ftell(f); //Получаем размер файла
    fseek(f, 0, SEEK_SET);

    char buf(size);

    while (!feof(f))
    {
        fread(&buf, sizeof buf, 1, f); //считываем посимвольно из файла
        if (isalpha(buf)) cout << " " << buf;
        else cout << " \n Unknown parameter " << buf << "\n";
    }
    fclose(f);

    system("pause");
    return 0;
}