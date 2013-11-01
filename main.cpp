#include "EditorWindow.h"
#include <gtkmm/application.h>
#include "BufferLuaQB.h"
#include "Lua.h"
int main (int argc, char *argv[])
{
  Gsv::init();
  
  Lua::init();
  BufferLuaQB::load(Lua::getL());

  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

  EditorWindow editor;

  Lua::Main();

  for(int i = 1; i < argc; i++){
    std::string openCommand("open(\"");
    openCommand += argv[i];
    openCommand += "\")";
    //std::cout << "Ejecutando:"  << openCommand << std::endl;
    luaL_dostring(Lua::L, openCommand.c_str());
  }
    
  //Shows the window and returns when it is closed.
  return app->run(editor);
}
