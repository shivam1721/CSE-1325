#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "person.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();          
        void on_new_student_click();  
        void on_new_parent_click();   
        void on_student_parent_click();             
        void on_quit_click();              
    private:
        int get_int(std::string prompt);
        std::string get_string(std::string prompt);
        void show_data();                                                      
        Gtk::Label *display;  
        Student _students[];
        Parent _parents[];
                            
        
};
#endif 
