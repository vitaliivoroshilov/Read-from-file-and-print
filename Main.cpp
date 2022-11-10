#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    char name[250];
    string s;
    cout << "Enter the name of the file: "; //File path
    cin.getline(name, 250);
    FILE* f;
    fopen_s(&f, name, "r");

    fseek(f, 0, SEEK_END); //Move the pointer to the end of file
    int size = ftell(f); //Get size of file
    fseek(f, 0, SEEK_SET);

    char buf(size);

    while (!feof(f))
    {
        fread(&buf, sizeof buf, 1, f); //Read from a file
        if (isalpha(buf)) cout << " " << buf;
        else cout << " \n Unknown parameter " << buf << "\n";
    }
    fclose(f);

    system("pause");
    return 0;
}
