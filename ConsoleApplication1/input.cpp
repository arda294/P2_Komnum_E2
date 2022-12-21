#include "window.h"
#include "input.h"


Data myInput::parseInput(HWND textBox, HWND startX, HWND endX, HWND result) {
	char string[400];
	char* token;
	char* next_token;
	char separators[] = ",";
	double y, a, b;
	Data data;
	
	GetWindowTextA(textBox, string, 400);
	std::cout << string << "\n";
	// Ambil token
	token = strtok_s(string, separators, &next_token);
	// Convert token menjadi double
	y = std::stod(token);
	data.push_back(y);
	// Ulang sampe habis
	while (true) {
		token = strtok_s(NULL, separators, &next_token);
		if (token == NULL) break;
		y = std::stod(token);
		data.push_back(y);
	}
	for (double y : data) {
		std::cout << y << "\n";
	}
	// Ambil batasan bawah
	GetWindowTextA(startX, string, 400);
	a = std::stod(string);
	// Ambil batasan atas
	GetWindowTextA(endX, string, 400);
	b = std::stod(string);
	sprintf_s(string, "Result : %lf", Romberg::calc(data, a, b));
	// Tampilkan hasil
	SetWindowTextA(result, string);

	return data;
}