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
