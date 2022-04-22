 /* 
    --------------------- PROJETO DE COMPILADORES ----------------------------

    Goncalo Vasconcelos Correia 2019216331
    Vicente Freire Tiago 2018281994

 */

 /*includes e declaracao de variaveis*/
%{
#include "y.tab.h"
#include <ctype.h>

#include "functions.h"


extern node* myprogram;
int errorBrace2=0;
int errorBrace=0;
extern int flag;
int line=1;
int column=1;
extern int printTree;
int auxEscp=0;
int aux = 0;
int auxStr=0;
int auxEnd=0;
int auxOpenBrace=0;

int errLine;
int errColumn;

void increaseColumn();
void increaseLine();
void printToken(char *token, int flag);

char strings[200]="";

%}
%X COMMENT STRLIT_ST SEMICOLON_ST

digit                                  [0-9]
octaldigit                             [0-7]
hexadigit                              [0-9a-fA-F]
decimallit                             0|[1-9]{digit}*
octallit                               0{octaldigit}+
hexalit                                0[xX]{hexadigit}+
exponent                               [eE]("+"|"-")?{digit}+ 
letter                                 [a-zA-Z_]
escape                                 \\n|\\f|\\r|\\\\|\\\"|\\t
invalidEscape                          \\[^nfr\\tr\n\"]?

id                                     {letter}({letter}|{digit})*
intlit                                 {decimallit}|{octallit}|{hexalit}
reallit                                {digit}+"."{digit}*{exponent}?|{digit}+{exponent}|"."{digit}+{exponent}? 
strlit                                 ([^\n\r\\\"]|{escape})*	

package                                package
func                                   func
semicolon                              ";"
comma                                  ","
blankid                                "_"
assign                                 "="
star                                   "*"
div                                    "/"
minus                                  "-"
plus                                   "+"
eq                                     "=="
ge                                     ">="
gt                                     ">"
lbrace                                 "{"
rbrace                                 "}"
le                                     "<="
lpar                                   "("
rpar                                   ")"
lsq                                    "["
lt                                     "<"
mod                                    "%"
ne                                     "!="
not                                    "!"
and                                    "&&"
or                                     "||"
rsq                                    "]"
return                                 return
else                                   else
for                                    for
if                                     if
var                                    var
int                                    int
float32                                float32
bool                                   bool
string                                 string
print                                  fmt"."Println
parseint                               strconv"."Atoi
cmdargs                                os"."Args

reserved                               break|case|chan|const|continue|default|defer|else|fallthrough|for|func|go|goto|if|import|interface|map|package|range|return|select|struct|switch|type|var|"++"|"--"
tokenseparator                         " "|\t|\b
singlelinecomment                      "//"        
initcomment                            "/*"
endcomment                             "*/"   
endLine                                "\n"|"\r\n"    

%%

{intlit}                               {errorBrace2=0;if (flag == 1) {fprintf(yyout,"INTLIT(%s)\n",yytext);} increaseColumn(); BEGIN SEMICOLON_ST; if (flag ==2){ yylval.str=(char*)strdup(yytext); return INTLIT;}}
{reallit}                              {errorBrace2=0;if (flag == 1) {fprintf(yyout, "REALLIT(%s)\n", yytext);} increaseColumn(); BEGIN SEMICOLON_ST; if (flag ==2){yylval.str=(char*)strdup(yytext); return REALLIT;}}
{func}                                 {errorBrace2=0;printToken("FUNC", flag); if (flag ==2){return FUNC;}}
{package}                              {errorBrace2=0;printToken("PACKAGE", flag); if (flag ==2){return PACKAGE;}}
{semicolon}                            {errorBrace2=0;printToken("SEMICOLON", flag); if (flag ==2){return SEMICOLON;}}
{comma}                                {errorBrace2=0;printToken("COMMA", flag); if (flag ==2){return COMMA;}}
{blankid}                              {errorBrace2=0;printToken("BLANKID", flag); if (flag ==2){return BLANKID;}}
{assign}                               {errorBrace2=0;printToken("ASSIGN", flag); if (flag ==2){return ASSIGN;}}
{star}                                 {errorBrace2=0;printToken("STAR", flag); if (flag ==2){return STAR;}}
{div}                                  {errorBrace2=0;printToken("DIV", flag); if (flag ==2){return DIV;}}
{minus}                                {errorBrace2=0;printToken("MINUS", flag); if (flag ==2){return MINUS;}}
{plus}                                 {errorBrace2=0;printToken("PLUS", flag); if (flag ==2){return PLUS;}}
{eq}                                   {errorBrace2=0;printToken("EQ", flag); if (flag ==2){return EQ;}}
{ge}                                   {errorBrace2=0;printToken("GE", flag); if (flag ==2){return GE;}}
{gt}                                   {errorBrace2=0;printToken("GT", flag); if (flag ==2){return GT;}}
{lbrace}                               {errorBrace2=0;printToken("LBRACE", flag); auxOpenBrace+=1;if (flag ==2){return LBRACE;}}
{rbrace}                               {errorBrace2=0;printToken("RBRACE", flag); auxOpenBrace-=1;BEGIN SEMICOLON_ST; errorBrace=0; if (flag ==2){return RBRACE;}}
{le}                                   {errorBrace2=0;printToken("LE", flag); if (flag ==2){return LE;}}
{rpar}                                 {printToken("RPAR", flag); BEGIN SEMICOLON_ST;errorBrace=1; if (flag ==2){return RPAR;}}
{lpar}                                 {printToken("LPAR", flag);errorBrace2=0;if (flag ==2){return LPAR;}}
{lsq}                                  {errorBrace2=0;printToken("LSQ", flag);if (flag ==2){return LSQ;}}
{lt}                                   {errorBrace2=0;printToken("LT", flag);if (flag ==2){return LT;}}
{mod}                                  {errorBrace2=0;printToken("MOD", flag); if (flag ==2){return MOD;}}
{ne}                                   {errorBrace2=0;printToken("NE", flag); if (flag ==2){return NE;}}
{not}                                  {errorBrace2=0;printToken("NOT", flag);if (flag ==2){return NOT;}}
{and}                                  {errorBrace2=0;printToken("AND", flag); if (flag ==2){return AND;}}
{or}                                   {errorBrace2=0;printToken("OR", flag); if (flag ==2){return OR;}}
{rsq}                                  {errorBrace2=0;printToken("RSQ", flag); if (flag ==2){BEGIN SEMICOLON_ST; return RSQ;}}
{return}                               {errorBrace2=0;printToken("RETURN", flag); if (flag ==2){BEGIN SEMICOLON_ST; return RETURN;}}
{else}                                 {errorBrace2=0;printToken("ELSE", flag);if (flag ==2){return ELSE;}}
{for}                                  {errorBrace2=0;printToken("FOR", flag); if (flag ==2){return FOR;}}
{if}                                   {errorBrace2=0;printToken("IF", flag); if (flag ==2){return IF;}}
{var}                                  {errorBrace2=0;printToken("VAR", flag); if (flag ==2){return VAR;}}
{int}                                  {errorBrace2=0;printToken("INT", flag);if (flag ==2){return INT;}}
{float32}                              {errorBrace2=0;printToken("FLOAT32", flag);if (flag ==2){return FLOAT32;}}
{bool}                                 {errorBrace2=0;printToken("BOOL", flag); if (flag ==2){return BOOL;}}
{string}                               {errorBrace2=0;printToken("STRING", flag);if (flag ==2){return STRING;}}
{print}                                {errorBrace2=0;printToken("PRINT", flag); if (flag ==2){return PRINT;}}
{parseint}                             {errorBrace2=0;printToken("PARSEINT", flag); if (flag ==2){return PARSEINT;}}
{cmdargs}                              {errorBrace2=0;printToken("CMDARGS", flag); if (flag ==2){return CMDARGS;}}
{reserved}                             {if (flag == 1) {fprintf(yyout,"RESERVED(%s)\n",yytext);} increaseColumn(); if (flag ==2){ yylval.str=yytext; return RESERVED;}}
{id}                                   {if (flag == 1) {fprintf(yyout, "ID(%s)\n", yytext);} increaseColumn(); BEGIN SEMICOLON_ST; if (flag ==2){ yylval.id=createID(yytext,line,column-yyleng);return ID;}}
{tokenseparator}                       {increaseColumn();}
{singlelinecomment}.*                  {;}

{endLine}                              {increaseLine();}

{initcomment}                          {increaseColumn(); errColumn=column-2; errLine=line ;BEGIN COMMENT; }

0{digit}+                              {if (atoi(&yytext[0]) > 7) { printTree=1;fprintf(yyout, "Line %d, column %d: invalid octal constant (%s)\n", line, column, yytext);} increaseColumn();}

<COMMENT><<EOF>>	                   { printTree=1;fprintf(yyout,"Line %d, column %d: unterminated comment\n", errLine, errColumn); BEGIN 0;return 0;}
<COMMENT>.                             {increaseColumn();}
<COMMENT>\n                            {increaseLine();}
<COMMENT>{endcomment}                  {if(aux == 0) {increaseColumn(); BEGIN 0;} if(aux  == 1) {increaseColumn(); BEGIN SEMICOLON_ST; aux = 0;}} 

\"                                        {BEGIN STRLIT_ST; errorBrace2=1;errColumn=column; errLine=line; increaseColumn(); auxEscp=0; memset(strings, 0, sizeof(strings));}
<STRLIT_ST>{endLine}                      { errorBrace2=0;printTree=1;fprintf(yyout,"Line %d, column %d: unterminated string literal\n",errLine,errColumn);memset(strings,0,sizeof(strings));increaseLine();BEGIN 0;}
<STRLIT_ST>{invalidEscape}                { errorBrace2=0; printTree=1;fprintf(yyout,"Line %d, column %d: invalid escape sequence (%s)\n",line,column,yytext),increaseColumn();auxEscp=1;}
<STRLIT_ST><<EOF>>                        { errorBrace2=0;errorBrace2=1;printTree=1;fprintf(yyout,"Line %d, column %d: unterminated string literal\n",errLine,errColumn);memset(strings,0,sizeof(strings));BEGIN 0;}
<STRLIT_ST>{strlit}                       {if (flag==1 || flag==2) {memset(strings,0,sizeof(strings));strcat(strings,yytext);} auxStr=1;increaseColumn();}
<STRLIT_ST>\"                             {   
                                            

                                                if(auxStr==0 && auxEscp==0){
                                                    if(flag==1){fprintf(yyout, "STRLIT(\"\")\n");}
                                                     char auxStr[100]="";
                                                    
                                                    BEGIN SEMICOLON_ST;
                                                    if (flag ==2){
                                                        strcat(auxStr,"\"");
                                                        strcat(auxStr,strings);
                                                        strcat(auxStr,"\"");

                                                        
                                                        yytext = (char*)strdup(auxStr);

                                                        
                                                        
                                                        yylval.str=(char*)strdup(auxStr);
                                                        yylval.str=(char*)strdup(strings); 
                                                        increaseColumn();
                                                        return STRLIT;
                                                    }
                                                    memset(strings,0,sizeof(strings));
                                                    }
                                                else if(auxEscp==0 && auxStr==1){
                                                    if(flag==1){fprintf(yyout,"STRLIT(\"%s\")\n",strings);}
                                                    char auxStr[100]="";
                                                    BEGIN SEMICOLON_ST;

                                                    if (flag ==2){

                                                       

                                                        strcat(auxStr,"\"");
                                                        strcat(auxStr,strings);
                                                        strcat(auxStr,"\"");

                                                        
                                                        yytext = (char*)strdup(auxStr);

                                                        
                                                        
                                                        yylval.str=(char*)strdup(auxStr);
                                                        increaseColumn();
                                                       
                                                        return STRLIT;
                                                    }
                                                    memset(strings,0,sizeof(strings));
                                                    memset(auxStr,0,sizeof(auxStr));
                                                   
                                                }
                                                else if(auxEscp==1 && auxStr==1){
                                                    memset(strings,0,sizeof(strings));
                                                    auxStr=0;
                                                    auxEscp=0;
                                                    BEGIN 0;
                                                }
                                                memset(strings,0,sizeof(strings));
                                                BEGIN SEMICOLON_ST;
                                                increaseColumn();
                                                auxStr=0;
                                                auxEscp=0;
                                                
                                                
                                    }
                                                

<SEMICOLON_ST>{endLine}                   {if(errorBrace==1){errorBrace2=1;errorBrace=0;}errLine=line; errColumn=column;if (flag == 1) {fprintf(yyout, "SEMICOLON\n");} increaseLine(); BEGIN 0; if (flag ==2){return SEMICOLON;}}
<SEMICOLON_ST>{semicolon}                 {if (flag == 1) {fprintf(yyout, "SEMICOLON\n");} increaseColumn(); BEGIN 0; if (flag ==2){return SEMICOLON;}}
<SEMICOLON_ST>{tokenseparator}+           {increaseColumn();}
<SEMICOLON_ST>{singlelinecomment}.*       {if (flag == 1) {fprintf(yyout, "SEMICOLON\n");} increaseColumn(); BEGIN 0; if (flag ==2){return SEMICOLON;}}
<SEMICOLON_ST>{initcomment}               {aux = 1; increaseColumn(); BEGIN COMMENT;}
<SEMICOLON_ST><<EOF>>                     {if (flag == 1) {fprintf(yyout, "SEMICOLON\n");}  BEGIN 0; if (flag ==2){return SEMICOLON;}}
<SEMICOLON_ST>""/.                        {BEGIN 0;}

<<EOF>>                                   {if(auxOpenBrace!=0){increaseLine();} increaseColumn();return 0;}


.                                         {fprintf(yyout, "Line %d, column %d: illegal character (%s)\n", line, column, yytext); increaseColumn();}

%%

void increaseLine()
{
    column=1;
    line++;
    //fprintf(yyout,"line: %d\n",line);
}

void increaseColumn()
{
    column += yyleng;
    //fprintf(yyout,"chhar-> %s column: %d\n",yytext,column);
}

void printToken(char *token, int flag)
{
    if(flag == 1){
        fprintf(yyout, "%s\n", token);
    }
    increaseColumn();
}



int yywrap()
{
    return 1;
}
