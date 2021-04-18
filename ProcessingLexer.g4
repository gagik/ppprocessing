/*
 Derived from Processing preprocessor code by Jakub Valtar and Florian Jenett.
 Copyright (c) 2021 Gagik Amaryan 
*/
lexer grammar ProcessingLexer;

import JavaLexer;

// // add color literal notations for
// // #ff5522
// HEX_COLOR_LITERAL
// 	:	'#' HEX_COLOR_VALUE
// 	;
HEX_COLOR_VALUE: HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT;
HEX_START: '#';
CIRCLE: 'circle';
ELLIPSE: 'ellipse';
RECT: 'rect';
LINE: 'line';
// catch floating point numbers in a parser rule
DECIMAL_LITERAL:    ('0' | [1-9] (Digits? | '_'+ Digits)) [lL]?;

SIZE: 'size';

SUBTRACT: '-';
ADD: '+';
SIN: 'sin';
COS: 'cos';
// special variables
FRAMECOUNT: 'frameCount';

// color-related
COLOR: 'color';
FILL: 'fill';
BACKGROUND: 'background';
STROKE: 'stroke';

HEX_DIGIT: [0-9a-fA-F];

// copy from Java.g4 where is is just a fragment
HEX_FLOAT_LITERAL:  '0' [xX] (HexDigits '.'? | HexDigits? '.' HexDigits) [pP] [+-]? Digits [fFdD]?;