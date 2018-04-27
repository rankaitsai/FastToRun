#ifndef TCOLLECTION_H
#define TCOLLECTION_H

#include <string>
using std::string;

template <class TBase>

class TCollection {
protected:
  std::vector<TBase> _items;

public:
  void add(TBase item) {
    _items.push_back(item);
  }

  void del(TBase item) {
    int index = findObjectIndex(item);

    if(index >= 0) {
      _items.erase(_items.begin() + index);
    }
  }

  void call(string cname) {

  }

  bool isExist(TBase item) {
    for(int i = 0; i < count(); i++) {
      if(_items[i] == item) {
        return true;
      }
    }
    return false;
  }

  int findObjectIndex(TBase item) {
    for(int i = 0; i < count(); i++) {
      if(_items[i] == item) {
        return i;
      }
    }
    return -1;
  }

  int count() {
    return _items.size();
  }

  string printAll() {
    string result = "";

    for(int i = 0; i < count(); i++) {
      result += _items[i]->getCommandName() + ",";
    }

    return result;
  }
};

#endif
