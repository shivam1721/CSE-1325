#include "subject.h"

Subject::load_subject(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    _subject = subject_opt_string(s);
}

std::string to_string(Subject subject) {
    if(subject == Subject::READING) return "reading";
    else if(subject == Subject::WRITING) return "writing";
    else if(subject == Subject::MATH) return "math";
    else if(subject == Subject::SCIENCE) return "science";
    else if(subject == Subject::HISTORY) return "history";
    else if(subject == Subject::SPORTS) return "sports";
    else if(subject == Subject::MUSIC) return "music";
    else throw std::out_of_range("Invalid subject");
}

Subject subject_opt_string(Std::string s) {
    if(s == "reading") return Subject::READING;
    else if(s == "writing") return Subject::WRITING;
    else if(s == "math") Subject::MATH;
    else if(s == "science") return Subject::SCIENCE;
    else if(s == "history") Subject::HISTORY;
    else if(s == "sports") return Subject::SPORTS;
    else if(s == "music") Subject::MUSIC;
    else throw std::out_of_range("Invalid subject");
}

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
    ost << to_string(subject);
    return ost;
}


