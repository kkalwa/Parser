#pragma once
#include "Interpreter.h"
#include <string>

namespace Kamil {
	class SimpleInterpreter :
		public Interpreter
	{
	public:
		SimpleInterpreter(const char* filePath);
		SimpleInterpreter(const std::string& filePath);

		virtual void start();

	
	};
}
