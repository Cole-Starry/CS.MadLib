#include <iostream>
#include <conio.h>
#include <string>
#include <array>

using namespace std;

struct Entry {
	string type;
	string input;
};

void printMadLib(array<Entry, 10> entries);
int findEntry(string input, array<Entry, 10> entries);
array<Entry, 10> GetEntries(array<Entry, 10> entries);
array<Entry, 10> entryCheck(array<Entry, 10> entries);
array<Entry, 10> inputEntrie(int i, array<Entry, 10> entries);
void printentries(array<Entry, 10> entries);

int main()
{
	array<Entry, 10> entries = {{
		{"place", ""},
		{"adjective", ""},
		{"noun", ""},
		{"famous person", ""},
		{"verb", ""},
		{"animal", ""},
		{"color", ""},
		{"food", ""},
		{"adverb", ""},
		{"object", ""}
	}};

	entries = GetEntries(entries);
	entries = entryCheck(entries);
	printMadLib(entries);
	(void)_getch();
	return 0;
}

array<Entry, 10> GetEntries(array<Entry, 10> entries) {
	for (int i = 0; i < entries.size(); ++i)
	{
		entries = inputEntrie(i, entries);
	}
	return entries;
}

void printentries(array<Entry, 10> entries)
{
	for (int i = 0; i < static_cast<int>(entries.size()); ++i)
	{
		cout << i + 1 << ". " << entries[i].type << ": " << entries[i].input << "\n";
	}
}

array<Entry, 10> entryCheck(array<Entry, 10> entries)
{
	while (true)
	{
		printentries(entries);
		cout << "If you would like to change any of these please input the number of the entry or the type.\nIf you are satisfed with your answers please type 'Y'.\n";
		string input;
		cin >> input;

		if (input == "yes" || input == "y" || input == "Yes" || input == "Y" || input == "YES")
		{
			return entries;
		}
		else
		{
			int entry = findEntry(input, entries);
			if (entry == -1)
			{
				cout << "Entry not found.\n";
			}
			else
			{
				entries = inputEntrie(entry, entries);
			}
		}
	}
}

int findEntry(string input, array<Entry, 10> entries)
{
	for (int i = 0; i < static_cast<int>(entries.size()); ++i)
	{
		if (to_string(i + 1) == input || entries[i].type == input)
		{
			return i;
		}
	}
	return -1;
}

array<Entry, 10> inputEntrie(int i, array<Entry, 10> entries)
{
	cout << i + 1 << ". Please input a " << entries[i].type << ". \n";
	string input;
	cin >> input;
	entries[i].input = input;
	return entries;
}

void printMadLib(array<Entry, 10> entries)
{
	cout << "Once upon a time in " << entries[0].input << ", there was a " << entries[1].input << " " << entries[2].input << ".\n";
	cout << "One day, they met " << entries[3].input << ", who loved to " << entries[4].input << " with their pet " << entries[5].input << ".\n";
	cout << "They wore a " << entries[6].input << " scarf and shared some " << entries[7].input << ".\n";
	cout << "Then, " << entries[8].input << ", they carried a " << entries[9].input << " on their next adventure.\n";
	cout << "And they all lived happily ever after!\n";
}