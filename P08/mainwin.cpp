#include "mainwin.h"
#include "entrydialog.h"
#include <iostream> // for std::cerr logging
#include <fstream>
#include <sstream>

// using P07 suggested solution

Mainwin::Mainwin() {

    // /////////////////
    // G U I   S E T U P
    // /////////////////

    set_default_size(640, 480);
    set_title("SMART");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // Menu
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    // File
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    // New School
    // Append New to the File menu
    Gtk::MenuItem *menuitem_new = Gtk::manage(new Gtk::MenuItem("_New School", true));
    menuitem_new->signal_activate().connect([this] {this->on_new_school_click();});
    filemenu->append(*menuitem_new);
    
    // Save school
    // Append Save... to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    
    
    // Save_as school
    // Append Save As... to the File menu
    Gtk::MenuItem *menuitem_save_as = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_save_as->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_save_as);
    
    // Open school
    // Append Open... to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);

    // Quit
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);

    // Insert
    // Create an Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);

    // New Student
    // Append New Student to the Insert menu
    Gtk::MenuItem *menuitem_new_student = Gtk::manage(new Gtk::MenuItem("New _Student", true));
    menuitem_new_student->signal_activate().connect([this] {this->on_new_student_click();});
    insertmenu->append(*menuitem_new_student);

    // New Parent
    // Append New Parent to the Insert menu
    Gtk::MenuItem *menuitem_new_parent = Gtk::manage(new Gtk::MenuItem("New _Parent", true));
    menuitem_new_parent->signal_activate().connect([this] {this->on_new_parent_click();});
    insertmenu->append(*menuitem_new_parent);
    
    // New Course
    // Append New Course to the Insert menu
    Gtk::MenuItem *menuitem_new_course = Gtk::manage(new Gtk::MenuItem("New _Course", true));
    menuitem_new_course->signal_activate().connect([this] {this->on_new_course_click();});
    insertmenu->append(*menuitem_new_course);
    
    // New Section
    // Append New Section to the Insert menu
    Gtk::MenuItem *menuitem_new_section = Gtk::manage(new Gtk::MenuItem("New _Section", true));
    menuitem_new_section->signal_activate().connect([this] {this->on_new_section_click();});
    insertmenu->append(*menuitem_new_section);
    

    //         T E S T   D A T A
    // Append Test Data to the Insert menu
    Gtk::MenuItem *menuitem_test_data = Gtk::manage(new Gtk::MenuItem("_Test Data", true));
    menuitem_test_data->signal_activate().connect([this] {this->on_easter_egg();});
    insertmenu->append(*menuitem_test_data);

    // Relate
    // Create a Relate menu and add to the menu bar
    Gtk::MenuItem *menuitem_relate = Gtk::manage(new Gtk::MenuItem("_Relate", true));
    menubar->append(*menuitem_relate);
    Gtk::Menu *relatemenu = Gtk::manage(new Gtk::Menu());
    menuitem_relate->set_submenu(*relatemenu);

    // Student To Parent
    // Append Student to Parent to the Insert menu
    Gtk::MenuItem *menuitem_student_parent = Gtk::manage(new Gtk::MenuItem("_Student to Parent", true));
    menuitem_student_parent->signal_activate().connect([this] {this->on_student_parent_click();});
    relatemenu->append(*menuitem_student_parent);
    
    // View
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
    
    // Course
    // append course to view menu
    Gtk::MenuItem *menuitem_course = Gtk::manage(new Gtk::MenuItem("_Course", true));
    //menuitem_view->signal_activate().connect([this] {this->on_about_click();});
    viewmenu->append(*menuitem_course);
    
    // Section
    // append section to view menu
    Gtk::MenuItem *menuitem_section = Gtk::manage(new Gtk::MenuItem("_Section", true));
    //menuitem_view->signal_activate().connect([this] {this->on_about_click();});
    viewmenu->append(*menuitem_section);
       
    // Help
    // Create a help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);
    
    // About
    // append about to help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);

    // ///////////// //////////////////////////////////////////////////////////
    // T O O L B A R
    // Add a toolbar to the vertical box below the menu
    Gtk::Toolbar *toolbar = Gtk::manage(new Gtk::Toolbar);
    vbox->pack_start(*toolbar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*toolbar);

    // New School
    // Add a new school icon
    Gtk::ToolButton *new_school_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::NEW));
    new_school_button->set_tooltip_markup("New School");
    new_school_button->signal_clicked().connect([this] {this->on_new_school_click();});
    toolbar->append(*new_school_button);
    
    // Open School
    // Add a open school icon
    Gtk::ToolButton *on_open_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::OPEN));
    on_open_button->set_tooltip_markup("Open School");
    on_open_button->signal_clicked().connect([this] {this->on_open_click();});
    toolbar->append(*on_open_button);
    
    // Save School
    // Add a save school icon
    Gtk::ToolButton *on_save_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE));
    on_save_button->set_tooltip_markup("Save School");
    on_save_button->signal_clicked().connect([this] {this->on_save_click();});
    toolbar->append(*on_save_button);
    
    // Save as School
    // Add a save_as school icon
    Gtk::ToolButton *on_save_as_button = Gtk::manage(new Gtk::ToolButton(Gtk::Stock::SAVE_AS));
    on_save_as_button->set_tooltip_markup("Save School As");
    on_save_as_button->signal_clicked().connect([this] {this->on_save_as_click();});
    toolbar->append(*on_save_as_button);

    //add custom student icon
    Gtk::Image* button1_image = Gtk::manage(new Gtk::Image{"button1_st.png"});
    button1 = Gtk::manage(new Gtk::ToolButton(*button1_image));
    button1->set_tooltip_markup("Create New Student");
    button1->signal_clicked().connect([this] {this->on_new_student_click();});
    toolbar->append(*button1);
    
    //add custom parent icon
    Gtk::Image* button2_image = Gtk::manage(new Gtk::Image{"button2_pt.png"});
    button2 = Gtk::manage(new Gtk::ToolButton(*button2_image));
    button2->set_tooltip_markup("Create New Parent");
    button2->signal_clicked().connect([this] {this->on_new_parent_click();});
    toolbar->append(*button2);


    //add custom relate student and parent icon
    Gtk::Image* button3_image = Gtk::manage(new Gtk::Image{"button3_rl.png"});
    button3 = Gtk::manage(new Gtk::ToolButton(*button3_image));
    button3->set_tooltip_markup("Relate Student to Parent");
    button3->signal_clicked().connect([this] {this->on_student_parent_click();});
    toolbar->append(*button3);
    
    //add custom course icon
    Gtk::Image* button5_image = Gtk::manage(new Gtk::Image{"button5_c.png"});
    button5 = Gtk::manage(new Gtk::ToolButton(*button5_image));
    button5->set_tooltip_markup("New Course");
    button5->signal_clicked().connect([this] {this->on_new_course_click();});
    toolbar->append(*button5);
    
    //add custom section icon
    Gtk::Image* button6_image = Gtk::manage(new Gtk::Image{"button6_sec.png"});
    button6 = Gtk::manage(new Gtk::ToolButton(*button6_image));
    button6->set_tooltip_markup("New Section");
    button6->signal_clicked().connect([this] {this->on_new_section_click();});
    toolbar->append(*button6);
    
    //add custom quit icon
    Gtk::Image* button4_image = Gtk::manage(new Gtk::Image{"button4_q.png"});
    button4 = Gtk::manage(new Gtk::ToolButton(*button4_image));
    button4->set_tooltip_markup("Quit");
    button4->signal_clicked().connect([this] {this->on_quit_click();});
    toolbar->append(*button4);
    
 
    // /////////////////////////// ////////////////////////////////////////////
    // D I S P L A Y
    // Provide a text entry box to show the data
    display = Gtk::manage(new Gtk::Label());
    display->set_hexpand(true);
    display->set_vexpand(true);
    vbox->add(*display);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);

    // Make the box and everything in it visible
    vbox->show_all();

    // Start a new game
    on_new_school_click();
}

Mainwin::~Mainwin() { 
    for(Student* s : students) delete s;
    for(Parent* p : parents) delete p;
}

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_new_school_click() {
    for(Student* s : students) delete s;
    for(Parent* p : parents) delete p;
    students.clear();
    parents.clear();
    _filename = DEFAULT_FILENAME;
    show_data();
}

//
// Save a school to the filesystem
//
void Mainwin::on_save_as_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("SMART files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(_filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Save", Gtk::RESPONSE_OK);

    int result = dialog.run();
    if(result == Gtk::RESPONSE_OK) {
        _filename = dialog.get_filename();
        on_save_click();
    }
}


//
// Save a school to the file specified in _filename
//
void Mainwin::on_save_click() {
    try {
        std::ofstream ofs{_filename};
        
        // Save "magic cookie" to identify file
        ofs << COOKIE << '\n';  
        ofs << FILE_VERSION << '\n';      // File format version number
        
        // Save composite data
        ofs << students.size() << '\n';
        for(Student* student : students) student->save(ofs);
        ofs << parents.size() << '\n';
        for(Parent* parent : parents) parent->save(ofs);
        
        // Save aggregate data
        for(Student* student : students) student->save_aggregates(ofs);
        for(Parent* parent : parents) parent->save_aggregates(ofs);
        
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        error("Unable to save school", e);
    }
}
//
// Open a school from the filesystem
//
void Mainwin::on_open_click() {
    Gtk::FileChooserDialog dialog("Please choose a file",
          Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_smart = Gtk::FileFilter::create();
    filter_smart->set_name("smart files");
    filter_smart->add_pattern(FILE_PATTERN);
    dialog.add_filter(filter_smart);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(_filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    int result = dialog.run();

    if (result == Gtk::RESPONSE_OK) {
        try {
            // Try to open the selected file - if it fails, preserve current data
            std::ifstream ifs{dialog.get_filename()};
            
            // Success! Clear data and remember filename
            on_new_school_click();
            show_data();
            _filename = dialog.get_filename();
            
            // Check the magic cookie
            std::string cookie;
            std::getline(ifs, cookie);
            if(cookie != COOKIE) throw std::runtime_error{"Not a " + TITLE + " file"};
            std::string version;
            std::getline(ifs, version);
            if(version != FILE_VERSION) throw std::runtime_error{"Unsupported file version"};
            
            // Load the composite students
            int size;
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) students.push_back(new Student{ifs});
            
            // Load the composite parents
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) parents.push_back(new Parent{ifs});
            
            // Load the composite courses
            int size;
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) courses.push_back(new Course{ifs});
            
            // Load the composite sections
            ifs >> size; ifs.ignore(32767, '\n');
            while(size--) sections.push_back(new Section{ifs});
            
            // Aggregate the student relationships
            std::ostringstream oss;
            std::map<std::string, Parent*> parent_aggregates;
            for(Parent* p : parents) {
                oss.str("");
                oss << *p;
                parent_aggregates[oss.str()] = p;
            }
            for(Student* s : students) s->load_aggregates(ifs, parent_aggregates);
            
            // Aggregate the parent relationships
            std::map<std::string, Student*> student_aggregates;
            for(Student* s : students) {
                oss.str("");
                oss << *s;
                student_aggregates[oss.str()] = s;
            }
            for(Parent* p : parents) p->load_aggregates(ifs, student_aggregates);
            
            // If an error occurred warn user, otherwise show the loaded data
            if(!ifs) throw std::runtime_error{"File contents bad"};
            show_data();
        } catch (std::exception& e) {
            error("Unable to open school", e);
        }
    }
}

void Mainwin::on_new_student_click() {     // Create a new student
    try {
        EntryDialog name{*this, "Student name?"};
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;  // Other response codes are at 
        //    https://developer.gnome.org/gtkmm/stable/classGtk_1_1ResponseType__Wrapper.html
        
        EntryDialog email{*this, "Student email?"};
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;

        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        students.push_back(new Student{name.get_text(), email.get_text(), grade});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data();
}
void Mainwin::on_new_parent_click() {      // Create a new parent
    try {
        EntryDialog name{*this, "Parent name?"}; 
        if(name.run() == Gtk::RESPONSE_OK) name.hide();
        else return;
        
        EntryDialog email{*this, "Parent email?"}; 
        if(email.run() == Gtk::RESPONSE_OK) email.hide();
        else return;
        
        parents.push_back(new Parent{name.get_text(), email.get_text()});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data();
}
void Mainwin::on_student_parent_click() {  // Relate student and parent
    try {
        int student = select_student(); if (student < 0) return;
        int parent = select_parent(); if (parent < 0) return;
        students.at(student)->add_parent(*parents.at(parent));
        parents.at(parent)->add_student(*students.at(student));
    } catch(std::exception& e) {
        error("Unable to relate", e);
    }
    show_data();
}

void Mainwin::on_new_course_click() {      // Create a new course
    try {
        EntryDialog subject{*this, "Subject ?"}; 
        if(subject.run() == Gtk::RESPONSE_OK) subject.hide();
        else return;
        
        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        courses.push_back(new Course{subject.get_text(), grade});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data();
}

void Mainwin::on_new_section_click() {      // Create a new section
    try {
        EntryDialog subject{*this, "Subject ?"}; 
        if(subject.run() == Gtk::RESPONSE_OK) subject.hide();
        else return;
        
        int grade = select("Student grade?", 12, 1);
        if(grade < 1) return;
        
        EntryDialog semester{*this, "Semester ?"}; 
        if(semester.run() == Gtk::RESPONSE_OK) semester.hide();
        else return;
        
        int year = select("Student year?", 2021);
        if(year == 2021 ) return;
        
        sections.push_back(new Section{subject.get_text(), grade, subject.get_text(), year});
    } catch(std::exception& e) {
        error("Invalid input", e);
    }
    show_data();
}

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); 
    dialog.set_program_name("Smart");
    auto logo = Gdk::Pixbuf::create_from_file("smartimage.png");
    dialog.set_logo(logo);
    dialog.set_version("Version 1.3.0+");
    dialog.set_copyright("Copyright 2019-2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Shivam Patel"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by Shivam Patel, created for personal use only ", 
        "George Rice"};
    dialog.set_artists(artists);
    dialog.run();
}

// /////////////////
// U T I L I T I E S
// /////////////////

void Mainwin::show_data() {
    std::string s;
    s += "    Students\n\n";
    for(int i=0; i<students.size(); ++i) 
        s += students.at(i)->full_info() + '\n';
    s += "\n    Parents\n\n";
    for(int i=0; i<parents.size(); ++i) 
        s += parents.at(i)->full_info() + '\n';
    for(int i=0; i<courses.size(); ++i) 
        s += courses.at(i)->to_string() + '\n';
    for(int i=0; i<sections.size(); ++i) 
        s += sections.at(i)->to_string() + '\n';



    display->set_markup(s);
}

// Returns index of selected student, or -1 for Cancel / Close
int Mainwin::select_student() {
    std::string prompt = "Select Student\n\n";
    for(int i=0; i<students.size(); ++i)
        prompt += std::to_string(i) + ") " + students[i]->to_string() +'\n';
    return select(prompt, students.size()-1);
}

// Returns index of selected parent, or -1 for Cancel / Close
int Mainwin::select_parent() {
    std::string prompt = "Select Parent\n\n";
    for(int i=0; i<parents.size(); ++i)
        prompt += std::to_string(i) + ") " + parents[i]->to_string() +'\n';
    return select(prompt, parents.size()-1);
}

// Returns index of selected course, or -1 for Cancel / Close
int Mainwin::select_course() {
    std::string prompt = "Select Course\n\n";
    for(int i=0; i<courses.size(); ++i)
        prompt += std::to_string(i) + ") " + courses[i]->to_string() +'\n';
    return select(prompt, courses.size()-1);
}

// Returns index of selected section, or -1 for Cancel / Close
int Mainwin::select_section() {
    std::string prompt = "Select Section\n\n";
    for(int i=0; i<sections.size(); ++i)
        prompt += std::to_string(i) + ") " + sections[i]->to_string() +'\n';
    return select(prompt, sections.size()-1);
}

// Returns int between [min, max], or min-1 for Cancel / Close
int Mainwin::select(std::string prompt, int max, int min) {
    int selection = min-1;
    while(true) {
        try {
            EntryDialog dialog{*this, prompt}; 
            int response = dialog.run();
            if(response == Gtk::RESPONSE_OK) {
                selection = std::stoi(dialog.get_text());
                if (min <= selection && selection <= max) break;
                throw std::out_of_range{"Invalid selection"};
            } else {
                selection = -1; // Likely Cancel or X
                break;
            }
        } catch(std::exception& e) {
            error("Invalid selection", e);
        }
    }
    return selection;
}

void Mainwin::on_easter_egg() {
    const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
    const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
    const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };
    try {
        for(int i=0; i<grades.size(); ++i)
            students.push_back(new Student{names[i], emails[i], grades[i]});
        for(int i=grades.size(); i<names.size(); ++i)
           parents.push_back(new Parent{names[i], emails[i]});
        students[0]->add_parent(*parents[0]); parents[0]->add_student(*students[0]);
        students[0]->add_parent(*parents[1]); parents[1]->add_student(*students[0]);
        students[1]->add_parent(*parents[0]); parents[0]->add_student(*students[1]);
        students[1]->add_parent(*parents[1]); parents[1]->add_student(*students[1]);
        students[2]->add_parent(*parents[2]); parents[2]->add_student(*students[2]);
        students[2]->add_parent(*parents[1]); parents[1]->add_student(*students[2]);
        students[3]->add_parent(*parents[1]); parents[1]->add_student(*students[3]);
        students[3]->add_parent(*parents[2]); parents[2]->add_student(*students[3]);
        students[3]->add_parent(*parents[3]); parents[3]->add_student(*students[3]);
        show_data();
    } catch(std::exception& e) {
        error("Easter Egg failed", e);
    }
}

void Mainwin::error(std::string msg, std::exception& e) {
    Gtk::MessageDialog{*this, msg + '\n' + e.what(), false, Gtk::MESSAGE_WARNING}.run();
}
