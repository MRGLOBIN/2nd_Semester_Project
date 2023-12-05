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

struct subjectName
{
    string departmentName;
    int sections;
    CourseSubject course;
    subjectName *next;
};

class ClassNameData
{
protected:
    int values;
    subjectName *first,
        *newClass,
        *restorePtr;
};

class ClassName : public ClassNameData
{

public:
    ClassName()
    {
        first = NULL;
        values = 0;
    }
    void addClass(string, int);
    void addSubject(string, int);
    void nextClass();
    void setRestore();
    void setValues();
    int getValues();
    void display();
    friend void generateBlockClass(ClassName &, string (*)[5][8], int (*)[5][8]);
};

/* classes for file stream handlers */

class InputFileStream
{
private:
    char opinion;

public:
    // constructors
    InputFileStream()
    {
        opinion = '\n';
    }

    // functions headers
    void addDepartment();
    void addCourse();
};