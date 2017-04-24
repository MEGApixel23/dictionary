#include <map>;
using namespace std;

class Dictionary 
{
	public:
		AnsiString translate(AnsiString x, AnsiString source) {
			map <AnsiString, AnsiString> dict;
			AnsiString lowerCase = x.LowerCase();

			if (source == "ua") {
				dict = ua_en;
			} else if (source == "en") {
				dict = en_ua;
			}
			
			if (dict.count(lowerCase) > 0) {
 				return dict[lowerCase];
			}
			
			return "None";
		}

		Dictionary();

	private:
		map <AnsiString, AnsiString> en_ua;
		map <AnsiString, AnsiString> ua_en;
};


Dictionary::Dictionary()
{
	int delimiter_position;

	AnsiString english;
	AnsiString translation;
	AnsiString delimiter = ":";
	AnsiString dictionary_path = "dictionary.txt";

	TStringList *list = new TStringList;
   	list->LoadFromFile(dictionary_path);

   	for (int i = 0; i < list->Count; ++i)
   	{
   		delimiter_position = list->Strings[i].Pos(delimiter);

   		english = list->Strings[i].SubString(
	   		0, delimiter_position - 1
		).LowerCase();
		translation = list->Strings[i].SubString(
	   		delimiter_position + 1, list->Strings[i].Length()
		).LowerCase();

		en_ua.insert( pair<AnsiString, AnsiString>(english, translation) );
		ua_en.insert( pair<AnsiString, AnsiString>(translation, english) );
   	}
}