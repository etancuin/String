#include "string.hpp"

namespace String
{
  string::string()
  {
    buffer = new char[0];
    len = 0;
  }
  string::string(const char s[])
  {
    len = strlen(s);
    if(len > 0)
    {
      buffer = new char[len];
      for (int i = 0; i < len; i++)
         buffer[i] = s[i];
    }  
    else
      buffer = nullptr;
  }

  string::string(const string& other)
  {
    len = other.len;
    if(len > 0)
    {
      buffer = new char[len];
      for (int i = 0; i < len; i++)
         buffer[i] = other.buffer[i];
    }  
    else
      buffer = nullptr;
  }
  string& string::operator=(const string& other)
  {
    if(this != &other)
    {
      delete[] buffer;
      len = other.len;
      if(len > 0)
      {
        buffer = new char[len];
        for (int i = 0; i < len; i++)
          buffer[i] = other[i];
      }  
      else
        buffer = nullptr;
    }
    return *this;
  }
  string::~string()
  {
    delete[] buffer;
  }

  int string::length() const
  {
    return len;
  }
  int string::size() const
  {
    return len;
  }

  char& string::operator[](int i)
  {
    return buffer[i];
  }
  const char& string::operator[](int i) const
  {
    return buffer[i];
  }

  string string::operator+(const string& other) const
  {
    string result;
    result.len = len + other.len;
    result.buffer = new char[result.len];
    for (int i = 0; i < len; i++)
      result.buffer[i] = buffer[i];
    for (int i = 0; i < other.len; i++)
      result.buffer[i + len] = other.buffer[i];
    return result;
  }
  string string::operator+(const char& ch) const
  {
    string result;
    result.len = len + 1;
    result.buffer = new char[result.len];
    for (int i = 0; i < len; i++)
      result.buffer[i] = buffer[i];
    result.buffer[len] = ch;
    return result;
  }

  bool string::operator==(const string& other) const
  {
    if (len != other.len)
      return false;
    for (int i = 0; i < len; i++)
    {
      if (buffer[i] != other.buffer[i]) 
        return false;
    }
    return true;
  }
  int string::find(const char* s, int pos) const
  {
    string temp(s);
    for(int i = pos; i < this->size(); i++)
    {
      for(int j = 0, k = i; j < temp.size() && k < this->size() && buffer[k] == temp.buffer[j]; ++k, ++j)
      {
        if(j == temp.size() - 1)
          return i;
      }
    }
    return -1;
  }

  string string::substr(int start, int length) const
  {
     string result;
     if (length > 0)
     {
        result.len = length;
        result.buffer = new char[length];
        for (int i = 0; i < length; i++)
           result.buffer[i] = buffer[start + i];
     }
     return result;
  }
  void string::print(std::ostream& out) const
  {
     for (int i = 0; i < len; i++)
     {
        out << buffer[i];
     }
  }
  
  std::ostream& operator<<(std::ostream& out, const string& str)
  {
     str.print(out);
     return out;
  }
  std::istream& operator>>(std::istream& in, string& str)
  {
    char c;
    while(in.get(c) && !isspace(c))
    {
      str = str + c;
    }
    return in;
  }
   bool operator!=(const string& s, const string& t)
  {
     return !(s == t);
  }
  bool operator>(const string& lhs, const string& rhs)
  {
    for(int i = 0; i < lhs.size() && i < rhs.size(); i++)
    {
      if(lhs[i] > rhs[i])
        return true;
      else if(lhs[i] < rhs[i])
        return false;
    }
    if(lhs.size() > rhs.size())
      return true;
    else
      return false;
  }
  bool operator<(const string& lhs, const string& rhs)
  {
    return (!(lhs == rhs) && !(rhs > lhs));
  }
}