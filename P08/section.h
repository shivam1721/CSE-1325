#ifndef __SECTION_H
#define __SECTION_H

#include "course.h"
#include "semester.h"


class Section {
  public:
    Section(Course course, Semester semester, int year);
    Section(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Section& section);
    std::string to_string() const;
  
  private:
    int _year;
    Course _course;
    Semester _semester;
};

#endif
