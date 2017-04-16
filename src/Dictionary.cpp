#include <map>;
using namespace std;

class Dictionary 
{
	public:
		AnsiString translate(AnsiString x) {
			if (words_map.count(x) > 0) {
 				return words_map[x];
			}
			
			return "None";
		}
		Dictionary();

	private:
		map <AnsiString,AnsiString> words_map;
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
		);
		translation = list->Strings[i].SubString(
	   		delimiter_position + 1, 1000
		);

		words_map.insert ( pair<AnsiString,AnsiString>(english,translation) );
   	}
}