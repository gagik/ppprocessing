/*
 Derived from Processing preprocessor code by Jakub Valtar and Florian Jenett.
 Copyright (c) 2021 Gagik Amaryan 
*/
lexer grammar ProcessingLexer;

import JavaLexer;

// add color literal notations for
// #ff5522
HEX_COLOR_LITERAL
	:	'#' HexDigit HexDigit HexDigit HexDigit HexDigit HexDigit
	;

CIRCLE: 'circle';
ELLIPSE: 'ellipse';
RECT: 'rect';
// catch floating point numbers in a parser rule
DECIMAL_LITERAL:    ('0' | [1-9] (Digits? | '_'+ Digits)) [lL]?;

SIZE_FUNCTION: 'size';
COLOR_FUNCTION: 'color';
FILL_FUNCTION: 'fill';

// copy from Java.g4 where is is just a fragment
HEX_FLOAT_LITERAL:  '0' [xX] (HexDigits '.'? | HexDigits? '.' HexDigits) [pP] [+-]? Digits [fFdD]?;