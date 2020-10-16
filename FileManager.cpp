#include<iostream>
#pragma warning (disable: 4996)
#include<cstdio>


using namespace std;

/*
       Задание: Файловый менеджер
           Реализуйте следующие функции:
               1. Создание файла в указанной директории
               2. Удаление файла
               3. Смена названия/перемещение файла (вводим старое название и новое название)
               4. Чтение содержимого файла
               5. Определение размера файла (вводим путь до файла, получаем размер в байтах)
               6. Запись данных в файл (в конец)
   */

enum {
    EXIT,
    CREATE_FILE,
    DELETE_FILE,
    NAME_CHANGE,
    FILE_TRANSFER,
    READ_FILE,
    SIZEofFile,
    WritingData
};

int main()
{

    char text[50];
    char location[50];
    char newLocation[50];
    int result;
    int action;

    do
    {
        cout << R"(

0 -  Exit
1 -  Create file
2 -  Delete file
3 -  Change name
4 -  Transfer file
5 -  Read file
6 -  Size of file
7 -  Writing data to a file

)";
        cin >> action;

        if (action == EXIT)
        {
            cout << "You exited the program\n";
            break;
        }
        else if (action == CREATE_FILE)
        {
            cout << "Please enter file location\n";
            cin >> location;

            FILE* f = fopen(location, "w");

            if (f) {
                cout << "Enter text for the file\n";
                cin >> text;
                fputs(text, f);
                fclose(f);
            }
            else {
                perror("Error message");
            }
        }
        else if (action == DELETE_FILE)
        {
            cout << "Please enter file location for delete\n";
            cin >> location;

            result = remove(location);
            if (result != 0) {
                perror("Cannot remove file");
            }
            else {
                cout << "You deleted file\n";
            }
        }
        else if (action == NAME_CHANGE)
        {
            cout << "Please enter file location for change name\n";
            cin >> location;
            cout << "Please enter file new name\n";
            cin >> newLocation;

            result = rename(location, newLocation);

            if (result != 0) {
                perror("Cannot rename file");
            }
            else {
                cout << "You renamed file\n";
            }
        }
        else if (action == FILE_TRANSFER)
        {
            cout << "Change location\n\nPlease enter file location\n";
            cin >> location;
            cout << "Please enter file new location\n";
            cin >> newLocation;


            result = rename(location, newLocation);
            if (result != 0) {
                perror("Cannot rename file");
            }
            else
            {
                cout << "You renamed file location\n";
            }
        }
        else if (action == READ_FILE)
        {
            cout << "Read file\n\nPlease enter file location\n";
            cin >> location;

            FILE* f = fopen(location, "r");
            if (!f) {
                perror("Error message");
            }
            else {
                char data[100];
                cout << "Data in text\n";
                while (fgets(data, 100, f))
                {
                    cout << data;
                }
                fclose(f);
            }
        }
        else if (action == SIZEofFile)
        {
            cout << "Size of file \n\nPlease enter file location\n";
            cin >> location;
            FILE* f = fopen(location, "r");
            if (!f) {
                perror("Errors :");
            }
            else
            {
                fseek(f, 0, SEEK_END);
                cout << "filesize is: " << ftell(f) << '\n';
                fclose(f);
            }

        }
        else if (action == WritingData)
        {
            cout << "Writing of file \n\nPlease enter file location\n";
            cin >> location;
            cout << "Enter text for the file\n";
            cin >> text;
            FILE* f = fopen(location, "a");
            if (!f) {
                perror("Cannot rename file");
            }
            else
            {
                fputs("\n", f);
                fputs(text, f);
                fclose(f);
            }
        }
        else {
            cout << "Wrong choice, try again\n";
        }


    } while (true);

}





