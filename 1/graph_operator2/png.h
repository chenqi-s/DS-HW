#ifndef PNG_H
#define PNG_H

#include <cmath>
#include <iostream>
#include <QString>
#include "lodepng.h"

class png
{
public:
	png(int _w, int _h);
	void point(int x, int y, int color=1);
	void circle(int a, int b, int r, int color=1);
	void line(int x1, int y1, int x2, int y2, int r, int color=1);
    void save(QString filename);
private:
	int w, h;
	lodepng::State state;
	std::vector<unsigned char> image;
};

#endif
