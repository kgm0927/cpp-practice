#include <iostream>
#include "Shape.h"
using namespace std;

class Rect : public Shape {
protected:
	virtual void draw();
};