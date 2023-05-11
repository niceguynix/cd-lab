#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void removeduplicate();
void final();
int Isiden(char ch);
int Isop(char ch);
int Isdel(char ch);
int Iskey(char * str);
void removeduplicate();

char op[8] = {
  '+',
  '-',
  '*',
  '/',
  '=',
  '<',
  '>',
  '%'
};

char del[8] = {
  '}',
  '{',
  ';',
  '(',
  ')',
  '[',
  ']',
  ','
};

char * key[] = {
  "int",
  "void",
  "main",
  "char",
  "float"
};
//char *operato[]={"+","-","/","*","<",">","=","%","<=",">=","++"};
int idi = 0, idj = 0, k, opi = 0, opj = 0, deli = 0, uqdi = 0, uqidi = 0, uqoperi = 0, kdi = 0, liti = 0, ci = 0;
int uqdeli[20], uqopi[20], uqideni[20], l = 0, j;
char uqdel[20], uqiden[20][20], uqop[20][20], keyword[20][20];
char iden[20][20], oper[20][20], delem[20], litral[20][20], lit[20], constant[20][20];

void lexanalysis(char * str) {
  int i = 0;
  while (str[i] != '\0') {
    if (Isiden(str[i])) //for identifiers
    {
      while (Isiden(str[i])) {
        iden[idi][idj++] = str[i++];
      }
      iden[idi][idj] = '\0';
      idi++;
      idj = 0;
    } else
    if (str[i] == '"') //for literals
    {
      lit[l++] = str[i];
      for (j = i + 1; str[j] != '"'; j++) {
        lit[l++] = str[j];
      }
      lit[l++] = str[j];
      lit[l] = '\0';
      strcpy(litral[liti++], lit);
      i = j + 1;
    } else
    if (Isop(str[i])) // for operators
    {
      while (Isop(str[i])) {
        oper[opi][opj++] = str[i++];
      }
      oper[opi][opj] = '\0';
      opi++;
      opj = 0;
    } else
    if (Isdel(str[i])) //for delemeters
    {
      while (Isdel(str[i])) {
        delem[deli++] = str[i++];
      }
    } else {
      i++;
    }
  }
  final();
}

int Isiden(char ch) {
  if (isalpha(ch) || ch == '_' || isdigit(ch) || ch == '.')
    return 1;
  else
    return 0;
}

int Isop(char ch) {
  int  i;
  for (i = 0; i < 8 ; i++) {
    if (ch == op[i])
      return 1;
  }
  return 0;
}

int Isdel(char ch) {
  int i;
  for (i = 0; i < 8 ; i++) {
    if (ch == del[i])
      return 1;
  }
  return 0;
}

int Iskey(char * str) {
  int i;
  for (i = 0; i < 5; i++) {
    if (!strcmp(key[i], str))
      return 1;
  }
  return 0;
}

void final() {
  int i = 0;
  idi = 0;
  for (i = 0; i < uqidi; i++) {
    if (Iskey(uqiden[i])) //identifying keywords
      strcpy(keyword[kdi++], uqiden[i]);
    else
    if (isdigit(uqiden[i][0])) //identifying constants
      strcpy(constant[ci++], uqiden[i]);
    else
      strcpy(iden[idi++], uqiden[i]);
  }
  // printing the outputs
  printf("\n\tDelemeter are : \n");
  for (i = 0; i < uqdi; i++)
    printf("\t%c\n", uqdel[i]);
  printf("\n\tOperators are : \n");
  for (i = 0; i < uqoperi; i++) {
    printf("\t");
    puts(uqop[i]);
  }
  printf("\n\tIdentifiers are : \n");
  for (i = 0; i < idi; i++) {
    printf("\t");
    puts(iden[i]);
  }
  printf("\n\tKeywords are : \n");
  for (i = 0; i < kdi; i++) {
    printf("\t");
    puts(keyword[i]);
  }
  printf("\n\tConstants are :\n");
  for (i = 0; i < ci; i++) {
    printf("\t");
    puts(constant[i]);
  }
  printf("\n\tLiterals are :\n");
  for (i = 0; i < liti; i++) {
    printf("\t");
    puts(litral[i]);
  }
}

void main() {
  char str[50];
  //clrscr();
  printf("\nEnter the string : ");
  scanf("%[^\n]c", str);
  lexanalysis(str);
  //getch();
}