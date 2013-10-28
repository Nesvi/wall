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

  Glib::ustring aux;

 public:
  int lua_id;
  Buffer(const std::string&,const std::string&);
  Buffer();
  void setLanguage(const std::string&);
  /*TODO
  void deduceLanguage();
  void loadFile();
  */
  Glib::RefPtr<Gsv::Buffer>& getSourceBuffer();
  void sayHello();
  void setText(const std::string&);
  std::string getText();
  void insertInCursor(const std::string&);
  void moveCursor(const int&, const int&);
  void save();
  int getCursorLine();
};

#endif
