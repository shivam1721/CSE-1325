#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> 

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(400, 200);
    set_title("The smart school");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     file
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);
    
    //     insert
    // Create a insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
    
    //     relate
    // Create a relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);


    //         new school
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_NewSchool", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);

    //         quit
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //         new student
    // Append New to the insert menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_NewStudent", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new);
    
    //         new parent
    // Append New to the insert menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_NewParent", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new);
    
    //         new student and parent
    // Append New to the relate menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("Student_to_Parent", true));
    menuitem_new->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_new);


    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
     vbox->add(*toolbar);

    // MW disp
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    
    vbox->show_all();

    
    on_new_school_click();
}

Mainwin::~Mainwin() { }

void Mainwin::on_new_school_click() {
    
}


void Mainwin::on_new_student_click() {
    std::string name = get_string("Name?");
    std::string email = get_string("Email?");
    int grade = get_int("Grade?");
    Parent->add_student(*(new Student s{name, email, grade}));
    _students.push_back(s);
    show_data();
    
}

void Mainwin::on_new_parent_click() {
    std::string name = get_string("Name?");
    std::string email = get_string("Email?");
    Student->add_parent(*(new Parent p{name, email}));
    _parents.push_back(p);
    show_data();
    
}

void Mainwin::on_new_student_parent_click() {
 }

void show_data(){
    int i;
    std::string stu,prt;
    for(i = 0; i < _students.size(); i++)
    {
       stu+= _students.full_info() + "\n";
    }
    for(i = 0; i < _parents.size(); i++)
    {
       prt+= _parents.full_info() + "\n";
    }
    std::string info_disp = "Student  " + s + "Parent  " + p;
    display->set_text(info_disp);
 
}    


void Mainwin::on_quit_click() {
    close();
}

