#ifndef __SEMESTER_H
#define __SEMESTER_H

enum class Semester {
  FALL,
  SPRING,
  SUMMER,
};

std::ostream& operator<<(std::ostream& ost, const Semester& semester);
void load_semester(std::istream ist);
std::string to_string(Semester semester);
Semester semester_opt_string(std::string s);

#endif
