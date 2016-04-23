
#ifndef _D_WHEEL

#define WHITESPACECHAR "\t\v\n\r\f "
#define PUNCTCHAR "!?.:;,"
#define HEXCHAR "0123456789ABCDEFabcdef"
#define CHARACTERS "abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPKRSTUVWXYZ"
#define VOGALS "aeiouAEIOU"


#define IsUpper(c) ((c) >= 'A' && (c) <= 'Z')
#define ToUpper(c) (IsLower((c)) ? (c) - 32 : c)
#define IsLower(c) ((c) >= 'a' && (c) <= 'z')
#define ToLower(c) (IsUpper((c)) ? (c) + 32 : c)
#define IsDigit(c) ((c) >= '0' && (c) <= '9') 
#define IsAlpha(c) (IsUpper((c)) || IsLower((c)))
#define IsAlNum(c) (IsAlpha((c)) || IsDigit((c)))
#define IsAscii(c) ((c) >= 0 && (c) <= 127)
#define IsCntrl(c) ((c) >= 0 && (c) <= 32)
#define IsSpace(c) (StrChr(WHITESPACECHAR, (c)) == NULL ? 0 : 1)
#define IsPrint(c) ((c) >= 32 && (c) <= 255) /* Some of 127 to 255 could be non printable.. */
#define ISGraph(c) ((c) >= 33 && (c) <= 254)
#define IsPunct(c) (StrChr(PUNCTCHAR, (c)) == NULL ? 0 : 1) /* Different from Standard, only punctuation here */
#define IsxDigit(c) ((StrChr(HEXCHAR, (c)) == NULL ? 0 : 1)
#define IsBlack(c) ((StrChr("\t ", (c)) == NULL ? 0 : 1)
#define IsVogal(c) ((StrChr(VOGALS, ((c)) == NULL ? 0 : 1)

int StrLenV1 (char *s);
int StrLen (char *s);
char *StrChr (char *s, char c);
char *StrrChr (char *s, char c);
char *StrUpr (char *s);
char *StrLwr (char *s);
int StrCmp (char *s1, char *s2);
int StrcaseCmp (char *s1, char *s2);
int StrnCmp (char *s1, char *s2, int n);
int StrnCmp2 (char *s1, char *s2, int n);
int StrncaseCmp (char *s1, char *s2, int n);
char *StrCpy (char *dest, char *src);
char *StrnCpy (char *dest, char *src, int n);
char *StrCat (char *dest, char *src);
char *StrnCat (char *dest, char *src, int n);
char *StrDup (char *s);
char *StrnDup (char *s, int n);
int StrSpn (char *s1, char *s2);
int StrcSpn (char *s1, char *s2);
char *StrPbrk (char *s1, char *s2);
char *StrStr (char *s1, char *s2);
char *StrRev (char *s);
char *StrSet (char *s, char c);
char *StrnSet (char *s, char c, int n);
int Atoi (char *s);
long Atol (char *s);
long long Atoll (char *s);
float Atof (char *s);
char *StrFry (char *s);
char *StrRep (char *s, char c, int *how);
char *StrTok (char *s, char *delim);

#define _DWHEEL_H
#endif
