#pragma once
#include <iostream>
#include <string>
#include "File.h"

namespace Kamil
{
	class Interpreter
	{
	public:
		Interpreter(const std::string& filePath);
		Interpreter(const char* filePath);
		Interpreter() = default;
		virtual ~Interpreter();
		virtual void start() = 0;
	protected:
		void trim(std::string& word);
		Kamil::File* s_filePtr = nullptr;
	};
}

