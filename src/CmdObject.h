#ifndef CMDOBJECT_H
#define CMDOBJECT_H

#include <iostream>
#include <string>

using std::string;

class CmdObject {
public:
  CmdObject(string cname, string wcname, string remark):_cname(cname), _wcname(wcname), _remark(remark) {

  }

  string getCommandName() const {
    return _cname;
  }

  string getWindowsCommandName() const {
    return _wcname;
  }

  string getRemark() const {
    return _remark;
  }

private:

  string _cname;
  string _wcname;
  string _remark;
};

#endif
