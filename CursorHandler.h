#ifndef CURSORHANDLER_H
#define CURSORHANDLER_H

#ifdef _WIN32
#include <Windows.h>
#define NOT_ON_WINDOWS false
#else
#define NOT_ON_WINDOWS true

#endif

#include <vector>

class CursorHandler
{
private:
	int _wLength = 1920, _wHeight = 1080;
	int _radius;

	std::pair<int, int> _centerCoords;
	std::pair<int, int> _finalCoords;

	INPUT _input = { 0 };
public:
	std::vector<std::pair<int, int>> coords;
	CursorHandler(int windowLength, int windowHeight, int radius, std::pair<int, int> centerCoords);

	void drawCircle();
	void holdClick();
	void releaseClick();
};

#endif 
