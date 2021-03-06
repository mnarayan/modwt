/*
  FILE: Exception.hpp
  AUTHOR: Shane Neph & Scott Kuehn
  CREATE DATE: Fri Aug 10 15:01:39 PDT 2007
*/

//
//    The Maximal Overlap Discrete Wavelet Transform (MODWT)
//    Copyright (C) 2007-2013 Shane Neph and Scott Kuehn
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License along
//    with this program; if not, write to the Free Software Foundation, Inc.,
//    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//

#ifndef EXCEPTIONTEMPLATE_H
#define EXCEPTIONTEMPLATE_H

#include <exception>
#include <string>

namespace Ext
{

  template <typename ExceptionType, int ErrorID>
  struct Exception 
    : public ExceptionType 
  {
    enum { Value = ErrorID };
    explicit Exception(const std::string& msg) : msg_(msg) { /* */ }
    Exception(const std::string& msg1, const std::string& msg2) : msg_(msg1 + "\n" + msg2) { /* */ }
    virtual ~Exception() throw() { /* */ }
    virtual const char* what() const throw() { return msg_.c_str(); }
  protected:
    Exception() { } // Hack.  look to use traits
    std::string msg_;
  };

  // Set of common application errors
  enum MajorErrors
    {
      FileErrorNum,
      UserErrorNum,
      DataErrorNum,
      ProgramErrorNum
    };
  enum FileErrorNums
    {
      InvalidFileErrorNum,
      MissingFileErrorNum
    };
  enum UserErrorNums 
    { 
      InvalidOperationErrorNum
    };
  enum DataErrorNums { };
  enum ProgramErrorNums
    {
      ParameterErrorNum,
      LogicErrorNum,
      ArgumentErrorNum
    };
  
  typedef Exception<std::exception, FileErrorNum> FileError;
  typedef Exception<FileError, InvalidFileErrorNum> InvalidFile;
  typedef Exception<FileError, MissingFileErrorNum> MissingFile;

  typedef Exception<std::exception, UserErrorNum> UserError;
  typedef Exception<UserError, InvalidOperationErrorNum> InvalidOperationError;

  typedef Exception<std::exception, DataErrorNum> DataError;

  typedef Exception<std::exception, ProgramErrorNum> ProgramError;
  typedef Exception<ProgramError, ParameterErrorNum> ParameterError;
  typedef Exception<ProgramError, LogicErrorNum> LogicError;
  typedef Exception<ProgramError, ArgumentErrorNum> ArgumentError;

}

#endif // EXCEPTIONTEMPLATE_H

