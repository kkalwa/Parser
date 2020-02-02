#pragma once
#include <string>
#include <fstream>


namespace Kamil
{
	/*Klasa pliku. Uzytkownik otwiera plik za jej pomoca i dokoknuje odczytu i zapisu po jednej linijce za pomoca funkcji skladowych
	
	Nalezy stworzyc osobn¹ klasê wyj¹tków dla wszystkich problemów.*/
	class File
	{
	public:
		File() = delete;
		File(const char* filePath);          // Standardowy konstruktor do otwierania pliku na podstawie C-Stringa
		File(const std::string& filePath);   // Konstruktor do otwierania pliku na podstawie obiektu typu std::string
		File(const File&) = delete;          // Konstruktor kopiujacy jest kasowany, bo raczej nie kopiuje sie plikow
		File(File&&) = delete;
		void operator=(const File&) = delete; // Podobnie jak konstruktor kopiujacy
		void operator=(File&&) = delete;
		~File();

		void setPath(const char* filePath);        // Ustawianie nowej sciezki do pliku
		void setPath(const std::string& filePath); // Ustawienie nowej sciezki do pliku
		const std::string& getPath();              // Sprawdzenie aktualnej sciezki do pliku

		void getOneLine(std::string& output);      // Pobranie jednej linijki tekstu
		bool eof();                                // Sprawdzenie czy osiagnieto koniec pliku

	protected:
		void openFile(const char* filePath); // Bazowa funkcja do otwierania pliku.
		std::string s_filePath;
		std::ifstream s_read;
	};
}
