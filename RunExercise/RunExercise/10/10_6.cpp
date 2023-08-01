#include "10_6.h"

int main10_6()
{
	const char *lineA, *lineB;

	lineA = "Banana"; lineB = "Aurora"; // result: 1 (lineA > lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	lineA = "Aurora"; lineB = "Banana"; // result: -1 (lineA < lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	lineA = "Banana"; lineB = "Banana"; // result: 0 (lineA == lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	lineA = "Forge"; lineB = "Fox";		// result: -1 (lineA < lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	lineA = "Fox"; lineB = "Forge";		// result: 1 (lineA > lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	// Unicode uppercase letter codes are larger than uppercase letter codes

	lineA = "fox"; lineB = "Zoom";		// result: 1 (lineA > lineB)
	cout << lineA << "//" << lineB << ":\n " << compstr(lineA, lineB) <<"\n";

	return 0;
}


// The function compares two specified strings and 
// returns the result of the comparison:
//  0 is stringA = stringB
// -1 is stringA < stringB
//  1 is stringA > stringB
//
// When sorting names in ascending order (that is, alphabetically), names
// are sorted as follows (the name above (closer to the beginning of the alphabet) is considered smaller):
// 1. Aurora
// 2. Banana
// 3. Forge
// 5. Zoom
// 6. fox (with a capital letter)
int compstr(const char *stringA, const char *stringB)
{
	// Until the end of any of the lines is reached, we compare them 
	// character by character

	while (*stringA && *stringB)
	{
		if (*stringA > *stringB)
			return 1;
		else if (*stringA < *stringB)
			return -1;
		*stringA++; *stringB++;
	}

	// If the program has reached here, then the end of either one of the lines
	// has been reached,
	// or the end of both lines at the same time, while the short line
	// completely, coincides with the beginning of the long one

	if (!*stringA && !*stringB) {
		return 0;
	}
	else if (!*stringA)
	{
		return -1;
	}
	else
		return 1;
}
