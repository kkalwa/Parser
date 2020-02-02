#include "SimpleInterpreter.h"

Kamil::SimpleInterpreter::SimpleInterpreter(const char* filePath): Interpreter(filePath)
{
}

Kamil::SimpleInterpreter::SimpleInterpreter(const std::string& filePath): SimpleInterpreter(filePath.c_str())
{
}

void Kamil::SimpleInterpreter::start()
{
	std::string line;
	std::size_t position{ 0 };
	std::string variableName;
	std::string variableValue;

	while (!s_filePtr->eof())
	{
		s_filePtr->getOneLine(line);
		if ((position = line.find("=")) != std::string::npos) // przypisanie do position pozycji znaku rownosci w stringu
		{
			// Sterowanie w tym ifie oznacza, ze znaleziono znak rownosci
			variableName = line.substr(0, position);
			variableValue = line.substr(position + 1, line.length()); // Roz³o¿enie linijki na nazwe zmiennej i jej wartosc
			
		}
	}


}


