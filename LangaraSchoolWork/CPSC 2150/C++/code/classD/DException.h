/*
Author: Gladys Monagan
Do not post anywhere
*/

#ifndef DLIST_EXCEPTION_H
#define DLIST_EXCEPTION_H

#include <string>    // for std::string
#include <stdexcept> // for std::exception

class DException : public std::exception {  
   public:
      DException(const std::string& what_arg = "") {
         what_msg = what_arg;
      }
      const char* what() const noexcept {
         return what_msg.c_str();
      }
   private:
      std::string what_msg;
}; 
#endif
