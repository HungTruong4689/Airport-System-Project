#pragma once
#include "Utility.h"
#include "Plane_P5.h"

typedef Plane_P5 Queue_entry;
const int maxqueue = 10; //  small value for testing

class Queue_P5 {
public:
	Queue_P5();
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry& item);
	Error_code retrieve(Queue_entry& item) const;

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};
class Extended_queue_P5 : public Queue_P5 {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry& item);
};
