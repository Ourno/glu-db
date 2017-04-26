#include <string.h>
#include <vector>
#include <ctime>

#ifndef lesson_INCLUDED
#define lesson_INCLUDED

using namespace std;
 
// База данных загрузки аудиторий. Поля: дата и время начала, дата и время конца, аудитория, преподаватель
 
typedef struct lesson {
    tm start_date;
    tm start_time;
    tm endin_date;
    tm endin_time;
    
    string teacher;
    string auditory;
    
} lesson;

void launch_create_lesson_dialog();

void print_lesson(lesson* lesson);

void print_lessons();

void save_file();

void load_file();

void free_memory();

#endif