%{
  #define YYSTYPE int
  #include <math.h>
  int yylex (void);
  void yyerror (char const *);
%}

/* Bison declarations.  */
%token key_word
%token unsigned_numeric_literal
%token national_character_string_literal
%token bit_string_literal
%token hex_string_literal
%token large_object_length_token
%token multiplier
%token character_string_literal
%token date_string
%token time_string
%token timestamp_string
%token interval_string
%token delimited_identifier
%token Unicode_delimited_identifier
%token SQL_special_character
%token not_equals_operator
%token greater_than_or_equals_operator
%token less_than_or_equals_operator
%token concatenation_operator
%token right_arrow
%token left_bracket_trigraph
%token right_bracket_trigraph
%token double_colon
%token double_period

%%
nondelimiter_token:
    key_word
    |unsigned_numeric_literal
    |national_character_string_literal
    |bit_string_literal
    |hex_string_literal
    |large_object_length_token
    |multiplier;

delimiter_token: 
    character_string_literal
    |date_string
    |time_string
    |timestamp_string
    |interval_string
    |delimited_identifier
    |Unicode_delimited_identifier
    |SQL_special_character
    |not_equals_operator
    |greater_than_or_equals_operator
    |less_than_or_equals_operator
    |concatenation_operator
    |right_arrow
    |left_bracket_trigraph
    |right_bracket_trigraph
    |double_colon
    |double_period;
%%