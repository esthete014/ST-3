// Copyright 2024 Kochetov Nikolay
#include "TimedDoor.h"

DoorTimerAdapter::DoorTimerAdapter(TimedDoor& door) : door(door) {}

void DoorTimerAdapter::Timeout() {
  door.throwState();
}

TimedDoor::TimedDoor(int timeout) : iTimeout(timeout), isOpened(false) {
  adapter = new DoorTimerAdapter(*this);
  Timer timer;
  timer.tregister(timeout, adapter);
}

bool TimedDoor::isDoorOpened() {
  return isOpened;
}

void TimedDoor::unlock() {
  isOpened = true;
}

void TimedDoor::lock() {
  isOpened = false;
}

int TimedDoor::getTimeOut() const {
  return iTimeout;
}

void TimedDoor::throwState() {
  if (isOpened) {
    std::cout
    << "Door has been open for "
    << iTimeout << " seconds." << std::endl;
  } else {
    std::cout << "Door has been closed for "
    << iTimeout << " seconds." << std::endl;
  }
}
