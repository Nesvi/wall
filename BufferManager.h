#ifndef _BufferManager
#define _BufferManager

#include "Buffer.h"

#include <gtkmm.h>
#include <gtksourceviewmm.h>

class BufferManager{

 protected:
  static Gsv::View* sourceView;
  static std::vector<Buffer*> Buffers;

 public:
  static void init(Gsv::View&);
  static void setBuffer(const int&);
  static void setBuffer(Buffer*);
  
  static Buffer* newBuffer();
  static Buffer* newBuffer(const std::string&, const std::string&);
};

#endif
