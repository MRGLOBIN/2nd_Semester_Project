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