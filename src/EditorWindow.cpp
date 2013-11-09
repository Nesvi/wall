
#include "EditorWindow.h"
#include <iostream>
#include "Lua.h"
#include "Buffer.h"

EditorWindow::EditorWindow()
{
  // Sets the border width of the window.
  set_border_width(10);
  set_default_size(400, 400);
  set_title("WALL");

  sourceView.set_auto_indent(true);
  sourceView.set_show_line_numbers(true);
  
  Buffer::setSourceView(&sourceView);

  //mainVBox.set_homogeneous(false);
  mainVBox.pack_start(scrollWindow,true,true);
  mainVBox.pack_start(console,false,false);
  

  scrollWindow.add(sourceView);
  add(mainVBox);

  add_events(Gdk::KEY_PRESS_MASK);

  show_all_children();
  console.set_visible(false);
  
}

EditorWindow::~EditorWindow()
{
}

bool EditorWindow::on_key_press_event(GdkEventKey* event)
{
 
  if(event->keyval == GDK_KEY_Return && console.is_focus()) {
    luaL_dostring(Lua::L,console.get_buffer()->get_text().c_str());
    console.set_text("");
    console.set_visible(false);
  }
  else
  if ((event->state &(GDK_SHIFT_MASK | GDK_CONTROL_MASK | GDK_MOD1_MASK)) == GDK_MOD1_MASK)
    {
      //std::cout << "Tecla" << std::endl;// GDK_MOD1_MASK is normally the Alt key
      //Lua::loadScript("test1.lua");
      switch ( event->keyval){
      
      case GDK_KEY_0:
	std::cout << "Hello" << std::endl; 
	luaL_dostring(Lua::L, "WALL_Bindings.Alt0()");
	break;
      
      case GDK_KEY_1:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt1()");
	break;
	
      case GDK_KEY_2:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt2()");
	break;
       
      case GDK_KEY_3:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt3()");
	break;

      case GDK_KEY_4:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt4()");
	break;

      case GDK_KEY_5:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt5()");
	break;

      case GDK_KEY_6:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt6()");
	break;

      case GDK_KEY_7:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt7()");
	break;

      case GDK_KEY_8:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt8()");
	break;

      case GDK_KEY_9:
	luaL_dostring(Lua::L, "WALL_Bindings.Alt9()");
	break;

      case GDK_KEY_x:
	console.grab_focus();
	console.set_visible(true);
	break;
	/*
      case GDK_KEY_Return:
	std::cout << "Hey enter" << std::endl;
	break;*/
      }
      
      return true;
    }
  
  return Gtk::Window::on_key_press_event(event);
}

/*Referencia

m_button.signal_clicked().connect(sigc::mem_fun(*this, &EditorWindow::on_button_clicked));

std::cout << "Contenido" << sourceBuffer->get_text(sourceBuffer->begin(), sourceBuffer->end())<<std::endl;
 */

