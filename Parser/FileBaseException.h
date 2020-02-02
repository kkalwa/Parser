#pragma once
#include <exception>

namespace Kamil
{
	class FileBaseException :
		public std::exception
	{

	public:
		FileBaseException(const char* message);
		static constexpr char OPEN_FILE_FAILURE[] = "Couldn't open file";
		static constexpr char READ_FILE_FAILURE[] = "Couldn't read from file";
	};
}
