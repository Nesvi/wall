#include "Buffer.h"
#include <iostream>
#include <string>

Gsv::View* Buffer::myView = 0;
 
Buffer::Buffer(const std::string& filename, const std::string& filepath){
  //std::cout << "Creando un buffer con ruta" << std::endl;
  name = filename;
  path = filepath;
  
  //deduceLanguage();TODO
  
  std::string fileLocation(path);
  fileLocation += name;
  std::ifstream inputFS;
  inputFS.open(fileLocation.c_str());
  
  std::string content( (std::istreambuf_iterator<char>(inputFS) ),
                       (std::istreambuf_iterator<char>()    ) );
  
  sourceBuffer = Gsv::Buffer::create();
  sourceBuffer->set_text( Glib::ustring(content) );
  
  inputFS.close();
  voidPath = false;
  setLanguage("lua");
}

Buffer::Buffer(){
  //std::cout << "Creando un buffer sin ruta" << std::endl;
  sourceBuffer = Gsv::Buffer::create();
  sourceBuffer->set_text( Glib::ustring("") );
  voidPath = true;
  setLanguage("lua");

}

Glib::RefPtr<Gsv::Buffer>& Buffer::getSourceBuffer(){
  return sourceBuffer;
}

void Buffer::setLanguage(const std::string& langu){
  lang = langu;
  sourceBuffer->set_language(Gsv::LanguageManager::get_default()->get_language(lang));

}

void Buffer::sayHello(){

  std::cout << "Buffer:Hello I'm " << lua_id << std::endl;
}

void Buffer::setText(const std::string& myText){

  sourceBuffer->set_text( Glib::ustring(myText) );

}

std::string Buffer::getText(){
  std::cout << "Estoy siendo llamado" << std::endl;
  std::string out(sourceBuffer->get_text()); 
  return out ;
}

void Buffer::insertInCursor(const std::string& beg){
  aux = beg;
  sourceBuffer->insert_at_cursor(beg);
}


void Buffer::save(){

  if( voidPath ){
    std::cout << "WALL->Error saving: Define a path for this buffer" << std::endl;
    return;
  }
  std::cout << "WALL->Saving..." << std::endl;
  std::string fileLocation(path);
  fileLocation += name;
  std::ofstream outputFS;
  outputFS.open(fileLocation.c_str());
  outputFS << sourceBuffer->get_text();
  outputFS.close();
  
}

void Buffer::moveCursor( const int& line,const int& offset){
  
  //Gtk::TextIter a = sourceBuffer->begin();//get_iter_at_line(line);
  sourceBuffer->place_cursor(sourceBuffer->get_iter_at_line_offset(line,offset));
  
}

int Buffer::getCursorLine(){

  return sourceBuffer->get_insert()->get_iter().get_line();

}

void Buffer::setSourceView(Gsv::View* in){
  myView = in;
}

void Buffer::setBuffer(){
  myView->set_buffer(getSourceBuffer());
}
