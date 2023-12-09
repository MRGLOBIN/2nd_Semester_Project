int main()
{
    ClassName Faculity;

    cout << "\t\t Hello World\n"
         << "\t\t Welcome TO Time Table Program"
         << "\n\n"
         << "Please selsect yout option: \n"
         << "Press 1 to generate time table\n"
         << "Press 2 to add items to DataBase\n"
         << "Press 3 to display items from DataBase DataBase\n";

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        readInputFromStorage(Faculity);
        Faculity.setRestore();
        Faculity.setValues();
        // 8 are the block hours and 5 are total days in week
        string rooms[totalRooms][5][8];
        int sections[totalRooms][5][8];
        generateBlockClass(Faculity, rooms, sections);

        int complete = 0;

        cout << "************************************************************" << endl;
        cout << "\t\t START OF TIME TABLE" << endl;
        cout << "************************************************************" << endl;
        for (int i = 0; i < totalRooms && complete <= totalIncludes - 2; i++)
        {
            cout << "************************************************************" << endl;
            cout << "\t\t Room Number: " << i + 1 << endl
                 << "************************************************************" << endl;
            for (int j = 0; j < 5 && complete <= totalIncludes - 2; j++)
            {
                cout << "************************************************************" << endl;
                cout << "\t\t Day of Week: " << day(j + 1) << endl
                     << "************************************************************" << endl;
                for (int k = 0; k < 8 && complete <= totalIncludes - 2; k++)
                {
                    cout << "Department & Subject:\t";
                    cout << rooms[i][j][k] << endl;
                    cout << "Section: " << sections[i][j][k] << "\tSlot: " << k + 1 << endl;
                    complete++;
                }
            }
        }
        cout << "************************************************************" << endl;
        cout << "\t\t END OF TIME TABLE" << endl;
        cout << "************************************************************" << endl;
    }
    break;

    case 2:
    {
        cout << "************************************************************" << endl;
        cout << "\t\t START OF INPUT" << endl;
        cout << "************************************************************" << endl;
        cout << "\nDo you want to enter Department(y for yes): \n";
        InputFileStream q;
        char y;
        cin >> y;

        if (y == 'y' || y == 'Y')
        {
            ofstream fout(storageFile);
            fout.close();
        }

        while (y == 'y' || y == 'Y')
        {
            q.addDepartment();
            q.addCourse();
            cout << "\nDo you want to add another department(y for Yes): \n";
            cin >> y;
        }
        ofstream fout(storageFile, ios::app);
        fout << storageEndFileCharacter;
        cout << "Enter number of Rooms: ";
        cin >> totalRooms;
        fout << totalRooms;
        fout.close();
        cout << "************************************************************" << endl;
        cout << "\t\t START OF INPUT" << endl;
        cout << "************************************************************" << endl;
    }

    break;

    case 3:
    {
        readInputFromStorage(Faculity);
        cout << "************************************************************" << endl;
        cout << "\t\t START OF DISPLAY" << endl;
        cout << "************************************************************" << endl;
        Faculity.display();
        cout << "************************************************************" << endl;
        cout << "\t\t END OF DISPLAY" << endl;
        cout << "************************************************************" << endl;
    }

    break;

    default:
    {
        cout << "\nInvalid Option";
    }
    break;
    }

    // experiment

    return 0;
}
