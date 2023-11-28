#include "observer.h"
#include "algorithm"

using namespace s21;

Observable::~Observable() {}

void Observable::Notify(int state_id) {
  for (auto observer : obs_) {
    observer->Update(state_id);
  }
}

void Observable::AddObserver(Observer *obs) { obs_.push_back(obs); }

void Observable::RemoveObserver(Observer *obs) {
  auto it = std::find(obs_.begin(), obs_.end(), obs);
  if (it != obs_.end()) {
    std::iter_swap(it, obs_.end() - 1);
    obs_.pop_back();
  }
}
