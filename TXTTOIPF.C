/*

    txttoipf - a program to convert ascii files to ipf files.

    Program by Dennis Frost

    Email:
          dfrost@wvuvphs1.hsc.wvu.edu
          dlfrost@miavx1.acs.muohio.edu

*/
#include <stdio.h>

void main(int argc, char *argv[])
{
FILE *inputfile, *outputfile;
char c;

if (argc != 3)
    {
    printf("txttoipf textfile ipffile\n\n");
    printf("Program by Dennis Frost\n\n");
    printf("Email:\n");
    printf("      dfrost@wvuvphs1.hsc.wvu.edu\n");
    printf("      dlfrost@miavx1.acs.muohio.edu\n");
    exit(-1);
    }

if (( inputfile = fopen(argv[1], "r")) == NULL)
    {
    printf("Cannot open file %s\n",argv[1]);
    exit(-2);
    }

if (( outputfile = fopen(argv[2], "w")) == NULL)
    {
    printf("Cannot open file %s\n",argv[2]);
    exit(-3);
    }


while( ! feof( inputfile) )
    { 
    c = fgetc(inputfile);
    switch( c )
        {
        case '&':
            fputs("&amp.",outputfile);
            break;
        case ':':
            fputs("&colon.",outputfile);
            break;
        case '^':
            fputs("&caret.",outputfile);
            break;
        case ',':
            fputs("&comma.",outputfile);
            break;
        case ''':
            fputs("&apos.",outputfile);
            break;
        case '*':
            fputs("&asterisk.",outputfile);
            break;
        case '\\':
            fputs("&bslash.",outputfile);
            break;
        case '"':
            fputs("&cdq.",outputfile);
            break;
        case '-':
            fputs("&dash.",outputfile);
            break;
        case '$':
            fputs("&dollar.",outputfile);
            break;
        case '.':
            fputs("&per.",outputfile);
            break;
        case '=':
            fputs("&eq.",outputfile);
            break;
        case '!':
            fputs("&xclm.",outputfile);
            break;
        case '>':
            fputs("&gtsym.",outputfile);
            break;
        case '<':
            fputs("&ltsym.",outputfile);
            break;
        case '{':
            fputs("&lbrace.",outputfile);
            break;
        case '[':
            fputs("&lbracket.",outputfile);
            break;
        case '(':
            fputs("&lpar.",outputfile);
            break;
        case '#':
            fputs("&numsign.",outputfile);
            break;
        case '`':
            fputs("&osq.",outputfile);
            break;
        case '%':
            fputs("&percent.",outputfile);
            break;
        case '+':
            fputs("&plus.",outputfile);
            break;
        case '}':
            fputs("&rbrace.",outputfile);
            break;
        case ']':
            fputs("&rbracket.",outputfile);
            break;
        case ')':
            fputs("&rpar.",outputfile);
            break;
        case ';':
            fputs("&semi.",outputfile);
            break;
        case '/':
            fputs("&slash.",outputfile);
            break;
        case '@':
            fputs("&atsign.",outputfile);
            break;
        case '|':
            fputs("&splitvbar.",outputfile);
            break;
        case '~':
            fputs("&tilde.",outputfile);
            break;
        case '_':
            fputs("&us.",outputfile);
            break;
        default:
            fputc(c,outputfile);
            break;
         }     /* End Switch */
    } /* End While */

fclose(inputfile);
fclose(outputfile);
exit(0);
}

