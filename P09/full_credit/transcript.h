#ifndef __TRANSCRIPT_
#define __TRANSCRIPT_

#include "student.h"  
#include "section.h"
#include "grade.h"

class Transcript {
  public:
    Transcript(Section& section, Student& student, Grade grade); 
    Transcript(std::istream& ist);
    void save(std::ostream& ost);
    void assign_grade(Grade grade);
    friend std::ostream& operator<<(std::ostream& ost, const Transcript& transcript);
  private:
    Section& _section;
    Student& _student;
    Grade _grade;

};

#endif
