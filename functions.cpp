void CourseSubject::addSubject(string name, int hours)
{
    course *newsubject = new course;
    newsubject->subject = name;
    newsubject->hours = hours;
    newsubject->next = first;
    first = newsubject;
}

string CourseSubject::returnName()
{
    if (first->hours > 0)
    {
        first->hours = (first->hours) - 1;
        return (first->subject);
    }
    else if (first->next != NULL)
    {
        first = first->next;
        first->hours = (first->hours) - 1;

        return (first->subject);
    }
    else
    {
        change();
        return "!";
    }
}

void CourseSubject::change()
{
    lastReached = false;
}

bool CourseSubject::checkchange()
{
    return lastReached;
}

void CourseSubject::display()
{
    course *current = first;
    while (current != NULL)
    {
        cout << "Credit Hours: " << current->hours << "\t"
             << "Subject: " << current->subject << endl;

        current = current->next;
    }
}

void ClassName::addClass(string name, int section)
{
    // creating new item for list
    newClass = new subjectName;
    newClass->departmentName = name;
    newClass->sections = section;
}

void ClassName::addSubject(string name, int hours)
{
    // adding course to current department
    newClass->course.addSubject(name, hours);
}

void ClassName::nextClass()
{
    // pointing first to this current list item
    newClass->next = first;
    first = newClass;
}

void ClassName::setRestore()
{
    restorePtr = first;
}

void ClassName::setValues()
{
    subjectName *current = first;
    while (current != NULL)
    {
        current = current->next;
        values++;
    }
}

int ClassName::getValues()
{
    return values;
}

void ClassName::display()
{
    subjectName *current = first;
    while (current != NULL)
    {
        cout << endl
             << "DEPARTMENT: " << current->departmentName << endl
             << "Section: " << current->sections << endl;
        cout << "Current Courses are:\n";
        current->course.display();
        current = current->next;
    }
    cout << "Total number of rooms: " << totalRooms << endl;
}
/*  function for included classes  */

void InputFileStream::addDepartment()
{
    ofstream fout(storageFile, ios::app);
    string department;
    int section;

    fout << storageStartDepartment;
    cout << "\nEnter name for the Department: ";
    cin >> department;
    cout << "Enter Section(integer from 1 to 9): ";
    cin >> section;
    fout << department << storageNumberCharacter
         << section << storageEndDepartment;
    fout.close();
}

void InputFileStream::addCourse()
{
    ofstream fout(storageFile, ios::app);
    if (!fout)
        cout << "No such file found";
    cout << "\nDo you want to add course to this department(y for yes): ";
    char opinion;
    cin >> opinion;
    int hours;
    while (opinion == 'y' || opinion == 'Y')
    {
        cout << "\nEnter course subject name: ";
        string subject;
        cin >> subject;
        cout << "Enter Credit Hoours for current subject(integer From 1 to 9): ";
        cin >> hours;
        fout << subject << storageNumberCharacter << hours;
        cout << "\nDo you want to add antoher subject(y for yes): ";
        cin >> opinion;
        if (opinion == 'y' || opinion == 'Y')
        {
            fout << storageEndSubjectCharacter;
        }
    }
    fout << storageEndCourseCharacter;
    fout.close();
}

// buffer function

void clearBuffer(char *buffer)
{
    for (int b = 0; b < 25; b++)
    {
        buffer[b] = '\0';
    }
}

void readInputFromStorage(ClassName &Faculity)
{
    // Reading from file
    ifstream fin("./data.txt");

    // ClassName Faculity;
    int number;
    char data = '\0';
    char buffer[25] = {'\0'};

    fin >> data;

    while (data != storageEndFileCharacter)
    {
        int i;
        if (data == storageStartDepartment)
        {
            fin >> data;
            for (i = 0; data != storageEndDepartment; i++)
            {
                buffer[i] = data;
                fin >> data;

                if (data == '%')
                {
                    fin >> data;
                    number = data - 48;

                    // skipping that number character
                    fin >> data;
                }
            }
            Faculity.addClass(buffer, number);

            // checking for number
            fin >> data;

            // making buffer ready for next input
            clearBuffer(buffer);
        }

        // now adding subjects for current department
        while (data != storageEndCourseCharacter && data != storageEndFileCharacter && data != storageStartDepartment)
        {
            for (i = 0; data != storageEndSubjectCharacter && data != storageEndCourseCharacter; i++)
            {
                buffer[i] = data;
                fin >> data;
                // optimize required
                if (data == '%')
                {
                    fin >> data;
                    number = data - 48;

                    // skipping that number character
                    fin >> data;
                }
            }
            Faculity.addSubject(buffer, number);

            // making buffer ready for next input
            clearBuffer(buffer);

            fin >> data;
        }
        Faculity.nextClass();
    }
    fin >> totalRooms;
    fin.close();
}

void generateBlockClass(ClassName &Facuilty, string (*rooms)[5][8], int (*sections)[5][8])
{
    //      && complete < values
    //  && complete < values
    //
    int complete = 0, values = Facuilty.getValues(), even = 0;

    for (int i = 0; i < totalRooms && complete <= values; i++)
    {
        for (int j = 0; j < 5 && complete <= values; j++)
        {
            for (int k = 0; k < 8 && complete <= values; k++)
            {
            a:
                string department = Facuilty.first->departmentName,
                       subject = Facuilty.first->course.returnName(),
                       full = department + " " + subject;
                while (!(Facuilty.first->course.checkchange()) && complete <= values)
                {
                    if (Facuilty.first->next == NULL)
                    {
                        Facuilty.first = Facuilty.restorePtr;
                    }
                    Facuilty.first = Facuilty.first->next;
                    complete++;
                    if (subject == "!")
                    {
                        goto a;
                    }
                }

                if (even % 2 == 0)
                {
                    if (Facuilty.first->next == NULL)
                    {
                        Facuilty.first = Facuilty.restorePtr;
                    }
                    Facuilty.first = Facuilty.first->next;
                }

                rooms[i][j][k] = full;
                sections[i][j][k] = Facuilty.first->sections;
                totalIncludes++, even++;
            }
        }
    }
}

string day(int i)
{
    switch (i)
    {
    case 1:
    {
        return "Monday";
    }
    break;
    case 2:
    {
        return "Tuesday";
    }
    break;
    case 3:
    {
        return "wednesday";
    }
    break;
    case 4:
    {
        return "Thrusday";
    }
    break;
    case 5:
    {
        return "Friday";
    }
    break;
    }
    return "Hello";
}