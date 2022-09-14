#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <climits>
#include <gtkmm.h>
#include "student.h"
#include "parent.h"

// using P06 suggested solution

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
        void on_new_school_click();
        void on_save_click();
        void on_save_as_click();   
        void on_open_click();   
        void on_new_student_click();     
        void on_new_parent_click();      
        void on_easter_egg();            
        void on_student_parent_click();  
        void on_about_click();
        void on_quit_click();            
    
    private:
        void show_data();                
        int select_student();
        int select_parent();
        int select(std::string prompt, int max = INT_MAX, int min = 0);
        
        std::vector<Student> students;
        std::vector<Parent> parents;

        Gtk::Label *display;            
        Gtk::Label *msg; 
        std::string filename;
        Gtk::ToolButton *button1;                
        Gtk::ToolButton *button2;                
        Gtk::ToolButton *button3;
        Gtk::ToolButton *button4;             
};
#endif 
