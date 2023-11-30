#ifndef OBSERVER_H
#define OBSERVER_H

#include <vector>

namespace s21 {

class Observer {
public:
  virtual void Update(int state_id) = 0;
};

class Observable {
public:
  virtual ~Observable();
  void Notify(int state_id);
  void AddObserver(Observer *obs);
  void RemoveObserver(Observer *obs);

private:
  std::vector<Observer *> obs_;
};
};     // namespace s21
#endif // OBSERVER_H
