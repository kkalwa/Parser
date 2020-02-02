#include "Interpreter.h"

Kamil::Interpreter::Interpreter(const std::string& filePath): Interpreter(filePath.c_str())
{

}

Kamil::Interpreter::Interpreter(const char* filePath): s_filePtr(new File(filePath))
{
	
}

Kamil::Interpreter::~Interpreter()
{
	delete s_filePtr;
}

void Kamil::Interpreter::trim(std::string& word)
{
	size_t position{ word.find(" ") };
	if (position == std::string::npos) // Jesli na wstepie wyjdzie npos to oznacza to ze dany string nie ma spacji. Wtedy mozna bez problemu wyjsc
		return;

	while ( word.find_first_of(" ") == 0 ) // Petla wykonuje sie tak dlugo jak na poczatku stringa sa spacje.
	{
		word = word.substr(1, word.length()); // Jesli spacja jest na pierwszym miejscu to odcina siê j¹
	}
	if (word.empty()) // Jeœli s³owo zawiera³o tylko same spacje to te zostan¹ usuniête i obiekt bêdzie pusty
		return;
	while (word.find_last_of(" ") == word.length() - 1) // Pêtla wykonuje siê tak d³ugo jak na koñcu s¹ spacje
	{
		word = word.substr(0, word.length() - 1); // Jesli spacja jest na ostatnim miejscu to wycina sie j¹
	}
}