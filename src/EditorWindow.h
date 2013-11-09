#ifndef _EditorWindow
#define _EditorWindow

#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm.h>
#include <gtksourceviewmm.h>

class EditorWindow : public Gtk::Window
{

public:
  EditorWindow();
  virtual ~EditorWindow();
  virtual bool on_key_press_event(GdkEventKey* event);

protected:
  //Member widgets:
  Gtk::ScrolledWindow scrollWindow;
  Gsv::View sourceView;
  Gtk::VBox mainVBox;
  
  Gtk::Entry console;

};

#endif // GTKMM_EXAMPLE_HELLOWORLD_H
