#ifndef __SUBJECT_H
#define __SUBJECT_H

enum class Subject{
  READING,
  WRITING,
  MATH,
  SCIENCE,
  HISTORY,
  SPORTS,
  MUSIC,
};

std::ostream& operator<<(std::ostream& ost, const Subject& subject);
void load_subject(std::istream ist);
std::string to_string(Subject subject);
Subject subject_opt_string(std::string s);

#endif
