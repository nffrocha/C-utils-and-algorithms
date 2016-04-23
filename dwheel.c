/* by Nelson Rocha */

#include <stdlib.h>
#include "dwheel.h"

/* StrLen V1 - Unused */
int StrLenV1 (char *s) {
	int i = 0;
	while (*s++)
		i++;
	return i;
}

/* StrLen V2 - Used */
int StrLen (char *s) {
 char *t = s;
 for ( ; *t ; t++);
 return t - s;
}

char *StrChr (char *s, char c) {
 for ( ; *s ; s++)
  if (*s == c)
   return s;
  return NULL;
}

char *StrrChr (char *s, char c) {
 int flg = 0;
 
 for ( ; *s ; s++)
  if (*s == c) /* Prevent to repeat the loop again back if c does not exist on s */
   flg = 1;
 
 while (*--s && flg)
  if (*s == c)
   return s;
 
 return NULL;
}

char *StrUpr (char *s) {
 char *t = s;
 
 for ( ; *s ; s++)
   *s = ToUpper(*s);
 
 *s = '\0';
 return t;
}

char *StrLwr (char *s) {
 char *t = s;
 
 for ( ; *s; s++)
  *s = ToLower(*s);
 
 *s = '\0';
 return t;
}

int StrCmp (char *s1, char *s2) {
 for ( ; *s1 || *s2; s1++, s2++)
  if (*s1 != *s2)
    return *s1 - *s2;
  
 return 0;
}

int StrcaseCmp (char *s1, char *s2) {
 char c1, c2;
 
 for ( ; *s1 || *s2; s1++, s2++) {
  c1 = ToLower(*s1);
  c2 = ToLower(*s2);
  
  if (c1 != c2)
    return c1 - c2;
  }
 
 return 0;
}

int StrnCmp (char *s1, char *s2, int n) {
 int i;
 
 for (i = 0; (i < n) && (*s1 || *s2); i++, s1++, s2++)
  if (*s1 != *s2)
   return *s1 - *s2;
 
 return 0;
}
/* Just for demonstrarion porpuses, the first in my tests is fastest than this */
int StrnCmp2 (char *s1, char *s2, int n) {
 char *t = s1;
 
 for ( ; (s1-t < n) && (*s1 || *s2); s1++, s2++)
  if (*s1 != *s2)
   return *s1 - *s2;
 
 return 0;
}

int StrncaseCmp (char *s1, char *s2, int n) {
 int i;
 char c1, c2;
 
 for (i = 0; (i < n) && (*s1 || *s2); i++, s1++, s2++) {
  c1 = ToLower(*s1);
  c2 = ToLower(*s2);
  
  if (c1 != c2)
   return c1 - c2;
 }
 
 return 0;
}

char *StrCpy (char *dest, char *src) {
 char *t = dest;
 
 while ((*dest++ = *src++));
 
 *dest = '\0';
 return t;
}

char *StrnCpy (char *dest, char *src, int n) {
 char *t = dest;
 int i;
 
 for (i = 0; i < n && (*dest = *src); i++, dest++, src++);
 
 *dest = '\0';
 return t;
}

char *StrCat (char *dest, char *src) {
 char *t = dest;
 
 while (*++dest);
 
 while ((*dest++ = *src++));
 
 *dest = '\0';
 return t;
}

char *StrnCat (char *dest, char *src, int n) {
 char *t = dest;
 int i;
 
 while (*++dest);
 
 for (i = 0; i < n && (*dest = *src); i++, dest++, src++);
 
 *dest = '\0';
 return t;
}

char *StrDup (char *s) {
 char *t, size;
 
 size = StrLen(s) + 1;
 t = malloc(size);
 
 if (t)
  StrCpy(t,s);
 
 return t;
}

char *StrnDup (char *s, int n) {
 char *t;
 
 t = malloc(n+1);
 
 if (t)
  StrnCpy(t, s, n);
 
 return t;
}   

int StrSpn (char *s1, char *s2) {
 char *t = s2;
 for ( ; *s2 && (*s1 == *s2); s1++, s2++);
 return s2 - t;
}

int StrcSpn (char *s1, char *s2) {
 char *t1 = s1, *t2 = s2;
 
 for ( ; *s1 ; s1++, s2 = t2)
  for ( ; *s2 ; s2++)
   if (*s1 == *s2)
    return s1 - t1;
 
 return s1 - t1;
}

char *StrPbrk (char *s1, char *s2) {
 char *t = s2;
 
 for ( ; *s1 ; s1++)
  for (s2 = t; *s2 ; s2++)
   if (*s1 == *s2)
    return s1;
 
 return NULL;
}

char *StrStr (char *s1, char *s2) {
 char *t1, *t2 = s2;
 
 for ( ; *s1 ; s1++) {
  if (*s1 == *s2) {
   t1 = s1; /* just to store later the position of s1 after the comparision with s2 */
   
   for ( ; *s1 && (*s1 == *s2); s1++, s2++);
   
   if ((s1-t1) == (s2-t2)) /* if len of (sub)string s1 is equal to len of subtring s2 then it should return */
    return t1; /* s1 from the start offset, t1 points to last s1 position before the comparision */
   
   s2 = t2; /* point s2 at the beginning of string */
   s1 = t1; /* point s1 at the last position before the comparision */
  }
 }
 return NULL;
}
/* Reverse s, example: CoolMaster will be retsaMlooC 
   Note: s will be changed */
char *StrRev (char *s) {
 char *t = StrDup(s), *end = s;
 
 t += StrLen(t);
 
 while ((*s++ = *--t));
 
 *s = '\0';
 return end;
}

/* Change all characters of s to c and return a pointer to s */
char *StrSet (char *s, char c) {
 char *t = s;
 
 for ( ; *s ; s++)
  *s = c;
 
 *s = '\0';
 return t;
}

/* Change the first n characters of s to c and return a pointer to s */ 
char *StrnSet (char *s, char c, int n) {
 char *t = s;
 
 for ( ; *s && (s-t < n) ; s++)
  *s = c;
 
 return t;
}

/* Return the integer of s */
int Atoi (char *s) {
 int res = 0, minus = 0;
 
 if (*s == '-') {
  minus = 1;
  s++;
 } 
 
 for ( ; *s && IsDigit(*s); s++)
    res = res * 10 + *s - '0';
 
 if (minus)
  res = -res;
 
 return res;
}

/* Return the long of s */
long Atol (char *s) {
 long res = 0;
 int minus = 0;
 
 if (*s == '-') {
  minus = 1;
  s++;
 } 
 
 for ( ; *s && IsDigit(*s); s++)
    res = res * 10 + *s - '0';
 
 if (minus)
  res = -res;
 
 return res;
}
/* Return the long long of s */
long long Atoll (char *s) {
 long long res = 0;
 int minus = 0;
 
 if (*s == '-') {
  minus = 1;
  s++;
 } 
 
 for ( ; *s && IsDigit(*s); s++)
    res = res * 10 + *s - '0';
 
 if (minus)
  res = -res;
 
 return res;
}

/* Return the float of s */
float Atof (char *s) {
 float rvalue = 0, lvalue = 0, res = 0;
 int i, div, minus = 0, exp = 0, expminus = 0;
 
 if (*s == '-') {
  minus = 1;
  s++;
 }

 for ( ; *s && IsDigit(*s); s++)
  rvalue = rvalue * 10 + *s - '0';
 
 if (*s == '.') {
  for (div = 0, s++; *s && IsDigit(*s); s++, div++)
   lvalue = lvalue * 10 + *s - '0';
 
  for (i = 0; i < div; i++)
   lvalue = lvalue / 10;
 }
 
 if (minus) {
   lvalue = -lvalue;
   rvalue = -rvalue;
 }
 res = rvalue + lvalue;
 
 if (*s == 'e' || *s == 'E') {
  s++;
  
  if (*s == '-') {
   expminus = 1;
   s++;
  }
  
  for ( ; *s && IsDigit(*s); s++)
   exp = exp * 10 + *s - '0';

  for (i = 0; i < exp; i++) {
   if (expminus)
     res = res / 10;
   else
     res = res * 10;
  }
 }
 
 return res;
}

/* Swap characters on s, randomic generator must be initialize before function call */
char *StrFry (char *s) {
 char *t = s, *l;
 int len = StrLen(s), rd, *cont, i;
 
 l = StrDup(s);
 cont = (int *) malloc(len);
 
 for (i = 0; i < len; i++)
  cont[i] = 0;
 
 for (i = 0; i < len; i++) {
  do {
   rd = rand()%len;
  } while (cont[rd]);
 
  s[rd] = *l;
  cont[rd] = 1;
  l++;
 }
 
 free(l);
 free(cont);
 
 return t;
}

/* Sequence of c characters will be be transformed in just one, s will not be changed, third argument will contain
 the number of characters that have been skipped */
char *StrRep (char *s, char c, int *how) {
 char *t, *l;
 char prev;
 int i = 0;
 
 l = malloc(StrLen(s)+1); /* will have more bytes than neccessary */
 prev = '\0';

 for (t = l; *s ; s++) {
  
  if (*s != prev || prev != c) {
   *l = *s;
   l++;
  }
  else
   i++;
 
 prev = *s;
 }
 
 *l = '\0';
  *how = i;
 return t;  
} 

/* If certain delim is found more than 1, 2, 3 or more times in a row some bugs could happen , need to fix it later */
char *StrTok (char *s, char *delim) {
 static char *t;
 char *tok, *retchr, *tmp, *delims;
 int ret = 0, len = 0, le = 0;
 
 if (s)
  t = s;
 
 tmp = t;
 delims = delim;
 
 for ( ; *delim ; delim++) {
  tmp = StrRep(tmp, *delim, &le);
  len +=le;
 }
 
 if (*tmp == *delims) {
   tmp++;
   len++;
 }
 retchr = StrStr(tmp, delims);

 if (retchr)
  ret = retchr - tmp;
 
 if (!ret)
  ret = StrLen(tmp);
  
 if (!retchr && !ret)
  return NULL;
  
 tok = malloc(ret);
 StrnCpy(tok, tmp, ret);
 t = t + ret + len;
 
 return tok;
}
