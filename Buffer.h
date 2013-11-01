#ifndef _Buffer
#define _Buffer

#include <gtkmm.h>
#include <gtksourceviewmm.h>
#include <fstream>
#include <string>

class Buffer{

 private:
  std::string slurp(std::ifstream& in);

 protected:
  Glib::RefPtr<Gsv::Buffer> sourceBuffer;
  std::string name;
  std::string path;
  std::string lang;
  bool voidPath;
  static Gsv::View* myView;
  Glib::ustring aux;

 public:
  int lua_id;
  Buffer(const std::string&,const std::string&);
  Buffer();
  void setLanguage(const std::string&);//BIND
  Glib::RefPtr<Gsv::Buffer>& getSourceBuffer();//BIND
  void sayHello();//BIND
  void setText(const std::string&);//BIND
  std::string getText();//BIND
  void insertInCursor(const std::string&);//BIND
  void moveCursor(const int&, const int&);//BIND
  void save();//BIND
  int getCursorLine();//BIND
  void setBuffer();//BIND
  static void setSourceView(Gsv::View*);
};

#endif
