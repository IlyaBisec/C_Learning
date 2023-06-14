#pragma once
#include "9_2.h"

int main9_2()
{
	Pstring longLine = "Learning to program has no more to do with designing interactive software than learning to touch type has to do with writing poetry\n";
	std::cout << "Long line: \n";
	longLine.display();
	
	Pstring shortLine = "hello world";
	std::cout << "Short line: \n";
	shortLine.display();

	return 0;
}

void String::display() const
{
	std::cout << p_line;
}

String::operator char* ()
{
	return p_line;
}

Pstring::Pstring(const char *line)
{
	// if the line is too long 
	if (strlen(line) > LENGTH - 1)
	{
		for (int i = 0; i < LENGTH; i++)
		{
			p_line[i] = line[i];
			p_line[i] = '\0';
		} 
	}
	else {
		String(line);
	}
}
