#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    int characters = 0, lines = 0, words = 0;

    bool isWord = false;

    ifstream inputFile("Global.txt");

    if (!inputFile.is_open())
    {

        cout << "Error al Abrir el archivo!" << endl;
        return 1;
    }

    char ch;

    while (inputFile.get(ch))
    {

        cout << ch;

        if (ch == '\n')
        {
            lines++;
        }

        if (!isspace(ch))
        {
            characters++;
            if (!isWord)
            {
                isWord = true;
                words++;
            }
        }
        else
        {
            isWord = false;
        }
    }

    cout << endl;
    cout << "Num Palabras:" << words << endl;
    cout << "Num Caracteres:" << characters << endl;

    if (lines > 0)
    {
        cout << "Num Lineas:" << lines + 1 << endl;
    }

    else if (words > 0 && lines <= 0)
    {
        lines = 1;
        cout << "Num Lineas:" << lines << endl;
    }

    inputFile.close();

    return 0;
}