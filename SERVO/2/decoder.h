#ifndef DECODER_H
#define DECODER_H
#include <cstring> 

          
#define MAX_KEYWORD_STRING_LTH 10 // mksymalna dlugosc komendy 

enum TokenType {
   KEYWORD,
   NUMBER,
   STRING
};

enum KeywordCode {
   ID,
   CALLIB,
   GOTO,
   STEP
};

struct Keyword {
   enum KeywordCode eCode;
   char cString[MAX_KEYWORD_STRING_LTH + 1];
};

union TokenValue {
   enum KeywordCode eKeywordCode; // jezeli KEYWORD unsigned 
   unsigned int uiNumber;  // jezeli NUMBER 
   char * pcString;        // jezeli STRING 
};

struct Token {
   enum TokenType eType;    // KEYWORD, NUMBER, STRING 
   union TokenValue uValue; // enum, unsigned int, char* 
};

class Decoder{
	public:
	Decoder(unsigned char ucMaxTokenInput, unsigned char ucMaxKeywordInput, struct Keyword * pKeywordDictionary);
	void DecodeMsg(char * String);
	struct Token *pasTokens;
	struct Keyword *pasKeywords;
	unsigned char ucTokenNr;
	private:

	unsigned char ucKeywordNr;
	unsigned char ucMaxTokenNumber;
	char ucFindTokensInString(char * String);
	enum Result eSringToKeyword(char cStr[], enum KeywordCode * peKeyword);
	void DecodeTokens();
	
};



	#endif
