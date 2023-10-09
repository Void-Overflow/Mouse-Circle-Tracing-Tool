#include <iostream>
#include <string>
#include "CursorHandler.h"

int main() {
	if (NOT_ON_WINDOWS)
		std::cout << "This application is only supported on Windows Devices.";
	else {
		while (true) {
			std::cout << "Radius Length: "; //200
			int radius;
			std::cin >> radius;

			std::pair<int, int> center;
			std::string* centerIn = new std::string();

			std::cout << "\n\nCenter coordinates(c = center):\nX: "; // C = (960, 553)
			std::cin >> *centerIn;

			if (*centerIn == "c" || *centerIn == "C")
				center.first = 960;
			else
				center.first = std::stoi(*centerIn);

			std::cout << "Y: ";
			std::cin >> center.second;

			if (*centerIn == "c" || *centerIn == "C")
				center.second = 553;
			else
				center.second = std::stoi(*centerIn);

			delete centerIn;

			HANDLE hConsolec = GetStdHandle(STD_OUTPUT_HANDLE);
			for (int i = 5; i > 0; i--) {
				system("cls");

				SetConsoleTextAttribute(hConsolec, 7);
				std::cout << "Drawing circle in ";
				SetConsoleTextAttribute(hConsolec, 4);
				std::cout << i;
				SetConsoleTextAttribute(hConsolec, 7);
				std::cout << " seconds\n";

				SetConsoleTextAttribute(hConsolec, 11);
				std::cout << "\tr = " + std::to_string(radius) << std::endl;
				std::cout << "\tcenter coordinates (" + std::to_string(center.first) + "," + std::to_string(center.second) + ")";
				Sleep(1000);
			}
			system("cls");
			SetConsoleTextAttribute(hConsolec, 7);
			std::cout << "Circle is drawing...\nHold esc whenever you would like to stop drawing the circle.\n";


			CursorHandler circle(center.first, center.second, radius, center);

			while (!GetAsyncKeyState(VK_ESCAPE)) {
				circle.holdClick();
				circle.drawCircle();
				circle.releaseClick();
			}
			
			std::cin.clear();
			std::cin.sync();

			std::string resp;
			std::cout << "\nDone drawing the circle. Would you Like to see the coordinates that were drawn? (Y/N) : ";
			std::cin.ignore();
			std::cin >> resp;
			SetConsoleTextAttribute(hConsolec, 8);
			if (resp == "Y" || resp == "y") {
				for(int i = 0; i < circle.coords.size(); i++)
					std::cout << "{" + std::to_string(circle.coords.at(i).first) + "," + std::to_string(circle.coords.at(i).second) + "} ";
			}
			SetConsoleTextAttribute(hConsolec, 7);

			std::cout << "\nWould you like to run this application again? (Y/N) : ";  
			std::cin >> resp;
			system("cls");
			if (resp != "Y" && resp != "y")
				break;
		}
	}
	return 0;
}