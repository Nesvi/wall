#include "BufferManager.h"
#include <iostream> 

std::vector<Buffer*> BufferManager::Buffers;
Gsv::View* BufferManager::sourceView;

void BufferManager::init( Gsv::View& view){

  sourceView = &view;
  
  //Buffers.push_back(Buffer("test.lua","/home/nesvi/Escritorio/"));
  //setBuffer(0);
}

void BufferManager::setBuffer(const int& id){
  sourceView->set_buffer( Buffers[id]->getSourceBuffer() );
}

void BufferManager::setBuffer(Buffer& buf){
  sourceView->set_buffer( buf.getSourceBuffer() );
}

Buffer* BufferManager::newBuffer(){
  
  Buffers.push_back( new Buffer() );
  return Buffers[Buffers.size() - 1];

}

Buffer* BufferManager::newBuffer(const std::string& a, const std::string& b){
  
  Buffers.push_back( new Buffer(a,b) );
  return Buffers[Buffers.size() - 1];

}
