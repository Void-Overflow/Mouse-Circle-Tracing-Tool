#include "CursorHandler.h"

static const double PI = 3.1415926535;

CursorHandler::CursorHandler(int windowLength, int windowHeight, int radius, std::pair<int, int> centerCoords) {
	_wHeight = windowHeight;
	_wLength = windowLength;
	_radius = radius;
	_centerCoords = centerCoords;
}

void CursorHandler::drawCircle() {

	double i, angle, x1, y1;
	coords.clear();

	for (i = 0; i < 360; i += 1)
	{
		angle = i;
		x1 = _radius * cos(angle * PI / 180);
		y1 = _radius * sin(angle * PI / 180);
		coords.push_back(std::make_pair(_wLength + x1, _wHeight + y1));
		SetCursorPos(_wLength + x1, _wHeight + y1);
		Sleep(1);
	}
	_finalCoords.first = _wLength + x1;
	_finalCoords.second = _wHeight + y1;
}

void CursorHandler::holdClick()
{
	SetCursorPos(_wLength + _radius * cos(0 * PI / 180), _wHeight + _radius * sin(0 * PI / 180));
	::ZeroMemory(&_input, sizeof(_input));
	_input.type = INPUT_MOUSE;
	_input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_ABSOLUTE;
	_input.mi.dx = _wLength + _radius * cos(0 * PI / 180);
	_input.mi.dy = _wHeight + _radius * sin(0 * PI / 180);
	::SendInput(1, &_input, sizeof(_input));
}

void CursorHandler::releaseClick()
{
	::ZeroMemory(&_input, sizeof(_input));
	_input.type = INPUT_MOUSE;
	_input.mi.dwFlags = MOUSEEVENTF_LEFTUP | MOUSEEVENTF_ABSOLUTE;
	_input.mi.dx = _finalCoords.first;
	_input.mi.dy = _finalCoords.second;
	::SendInput(1, &_input, sizeof(_input));
}
