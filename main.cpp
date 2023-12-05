#include <iostream>
#include <fstream>

using namespace std;

const string storageFile = "./data.txt";
const char storageEndSubjectCharacter = ':',
           storageStartDepartment = '=',
           storageEndDepartment = '-',
           storageEndCourseCharacter = '+',
           storageEndFileCharacter = '?',
           storageNumberCharacter = '%';
int totalRooms, totalIncludes = 0;

#include "./includeClasses.cpp"
#include "./functions.cpp"
#include "./logics.cpp"
