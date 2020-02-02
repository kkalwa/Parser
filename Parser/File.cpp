#include "File.h"
#include "FileBaseException.h"

/* Standardowy konstruktor obiektu. Pomys³ jest taki ¿eby przesy³aæ do niego sterowanie ze wszystkich innych konstruktorów*/
Kamil::File::File(const char* filePath)
{
	openFile(filePath);
}

/* Konstruktor tworzy obiekt na podstawie pliku std::string. Przekazuje sterowanie do standardowego konstruktora bazuj¹cego na C_stringu*/
Kamil::File::File(const std::string& filePath): File(filePath.c_str())
{
}

/* Destruktor. Nie przewidujê dziedziczenia z tej klasy, wiêc zostawi³em to tak jak jest. */
Kamil::File::~File()
{
	if (s_read.is_open()) // Jesli plik zostal otwarty to nalezy go zamknac. Nie wiem czy tak jest dobrze.
	{
		s_read.close();
	}
}

void Kamil::File::setPath(const char* filePath)
{
	openFile(filePath);
}

void Kamil::File::setPath(const std::string& filePath)
{
	openFile(filePath.c_str());
}

const std::string& Kamil::File::getPath()
{
	return s_filePath;
}

void Kamil::File::getOneLine(std::string& output)
{
	if (s_read.good())
	{
		std::getline(s_read, output);
	}
	else
	{
		throw FileBaseException(FileBaseException::READ_FILE_FAILURE);
	}
}

bool Kamil::File::eof()
{
	return s_read.eof();
}

/* Funkcja w³aœciwa, która otwieraæ powinna plik. Inne publiczne funkcje powinny tylko przygotowaæ nazwê pliku do otworzenia
Jeœli nie uda siê otworzyæ pliku to rzucany jest wyj¹tek typu FileBaseException. W przeciwnym razie ustawiona zostaje zmienna
s_filePath i aktywowany zostaje strumien s_read*/
void Kamil::File::openFile(const char* filePath)
{
	if (s_read.is_open())
	{
		s_read.close();
	}
	s_read.open(filePath);

	if (!s_read)
	{
		throw FileBaseException(FileBaseException::OPEN_FILE_FAILURE);
	}
	
	s_filePath = filePath;
}
