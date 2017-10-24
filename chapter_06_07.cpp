#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	int vowel = 0;
	int consonant = 0;
	int other = 0;
	char word[20];

	cout << "Enter words (q to quit):\n";
	while (cin >> word)
	{
		if (isalpha(word[0]))
		{
			if (word[0] == 'q'&&strlen(word) == 1)
				break;
			else if (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')
				++vowel;
			else
				++consonant;
		}
		else
			++other;
	}
	cout << vowel << " words beginning with vowels\n";
	cout << consonant << " words beginning with consonants\n";
	cout << other << " others\n";

	return 0;
}