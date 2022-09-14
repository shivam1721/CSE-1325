#include "transcript.h"

Transcript::Transcript(Section& section, Student& student, Grade grade); 
  : _section{section}, _student{student}, _grade{grade} { }

Transcript::Transcript(std::istream& ist) : _section{ist}, _student{ist} {
    _grade = load_grade(ist);
}

void Transcript::save(std::ostream& ost) {
    _section.save(ost);
    _student.save(ost);
    ost << _grade << '\n' << '\n';
}

void Transcript::assign_grade(Grade grade){

}

std::ostream& operator<<(std::ostream& ost, const Transcript& transcript) {
    ost << transcript._section << transcript._student << " earned a " << transcript._grade;
    return ost;
}
