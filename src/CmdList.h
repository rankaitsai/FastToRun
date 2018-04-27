// CmdList.h

#ifndef CMDLIST_H
#define CMDLIST_H

#include "./CmdObject.h"
#include "./TCollection.h"

class CmdList : public TCollection<CmdObject *> {
public:
  CmdList() {}

private:
};


#endif
