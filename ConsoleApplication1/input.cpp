#include "window.h"
#include "input.h"


Data myInput::parseInput(HWND textBox, HWND startX, HWND endX, HWND result) {
	char string[400];
	char* token;
	char* next_token;
	char separators[] = ",";
	double y, a, b;

	Data data;
	// Ambil data dari textbox
	GetWindowTextA(textBox, string, 400);
	std::cout << string << "\n";
	// Ambil token
	token = strtok_s(string, separators, &next_token);
	
	try {
		// Convert token menjadi double
		y = std::stod(token);
	}
	catch (std::invalid_argument const& err) {
		SetWindowTextA(textBox, "Not a number");
		return data;
	}
	
	data.push_back(y);
	// Ulang hingga tidak ada token baru
	while (true) {
		token = strtok_s(NULL, separators, &next_token);
		if (token == NULL) break;
		try {
			y = std::stod(token);
		}
		catch (std::invalid_argument const& err) {
			SetWindowTextA(textBox, "Not a number");
			return data;
		}
		data.push_back(y);
	}
	// Cek data
	for (double y : data) {
		std::cout << y << "\n";
	}
	// Ambil batasan bawah
	GetWindowTextA(startX, string, 400);
	a = std::stod(string);
	// Ambil batasan atas
	GetWindowTextA(endX, string, 400);
	b = std::stod(string);
	// Cek apakah jumlah input data adalah 2^n+1
	if (((data.size() - 1) & (data.size() - 2) != 0)) {
		std::cout << "pias: " << data.size() - 1;
		SetWindowTextA(textBox, "Please enter 2^n+1 data point");
		return data;
	}
	sprintf_s(string, "Result : %lf", Romberg::calc(data, a, b));
	// Tampilkan hasil
	SetWindowTextA(result, string);

	return data;
}