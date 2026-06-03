
#include "strings.h"
#include "decoder.h"
#include <cstring> 
#include <cstdlib>
#define NULL 0






Decoder::Decoder(unsigned char ucMaxTokenInput, unsigned char ucMaxKeywordInput, struct Keyword * pKeywordDictionary) : ucMaxTokenNumber(ucMaxTokenInput) {
    
    ucKeywordNr = ucMaxKeywordInput;
    pasTokens = new Token[ucMaxTokenNumber];
    pasKeywords = pKeywordDictionary; 
}
char Decoder::ucFindTokensInString(char * String){
	unsigned char ucTokenCounter=0;
	char *pcToken = std::strtok(String," ");
	while (pcToken != NULL && ucTokenCounter < ucMaxTokenNumber ){
		pasTokens[ucTokenCounter].uValue.pcString =  pcToken;
		ucTokenCounter++;
		pcToken = std::strtok(NULL, " ");
	}
	return ucTokenCounter;
	
}


enum Result Decoder::eSringToKeyword(char cStr[], enum KeywordCode * peKeyword) {
   unsigned char ucKeywordCtr;
   for (ucKeywordCtr = 0; ucKeywordCtr <ucKeywordNr; ucKeywordCtr++) {
		 if (std::strcmp(cStr, pasKeywords[ucKeywordCtr].cString)==0){
         * peKeyword = pasKeywords[ucKeywordCtr].eCode;
         return OK;
      }
   }
   return ERROR;
}

void Decoder::DecodeTokens() {
   unsigned char ucTokenCtr;
   struct Token * psToken;

   for (ucTokenCtr = 0; ucTokenCtr < ucTokenNr; ucTokenCtr++) {
      psToken = & pasTokens[ucTokenCtr];
      if (OK == eSringToKeyword(psToken -> uValue.pcString, &psToken -> uValue.eKeywordCode)) {
         psToken -> eType = KEYWORD;
      }
			else {
			unsigned long ulHexNumber = std::strtoul(psToken -> uValue.pcString,NULL,16);
			if (ulHexNumber != 0){
				psToken -> uValue.uiNumber =  ulHexNumber;
				psToken -> eType = NUMBER;
			}
		}
   }
}

void Decoder::DecodeMsg(char * String) {
   ucTokenNr = ucFindTokensInString(String);
   ReplaceCharacterInString(String, ' ', NULL);
   DecodeTokens();
}


