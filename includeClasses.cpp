struct course
{
    string subject;
    int hours;
    course *next;
};

class CourseData
{
protected:
    bool lastReached;
    course *first;
};

class CourseSubject : public CourseData
{

public:
    CourseSubject()
    {
        lastReached = true,
        first = NULL;
    }

    void addSubject(string, int);
    string returnName();
    void change();
    bool checkchange();
    void display();
};
