/*
 Derived from Processing preprocessor code by Jakub Valtar and Florian Jenett.
 Copyright (c) 2021 Gagik Amaryan 
*/
parser grammar ProcessingParser;

import JavaParser;

options { tokenVocab=ProcessingLexer; }

// main entry point, select sketch type
sketch
    :   staticMode
    |   activeMode
    ;

// static mode, will run once (no function definitions)
staticMode
	:	importDeclaration* blockStatement* importDeclaration* blockStatement* EOF
	;

// active mode, has function definitions
activeMode
	:	importDeclaration* classBodyDeclaration* importDeclaration* classBodyDeclaration* EOF
	;

variableDeclaratorId
    :   warnTypeAsVariableName
    |   Identifier ('[' ']')*
    ;

// bug #93
// https://github.com/processing/processing/issues/93
// prevent from types being used as variable names
warnTypeAsVariableName
    :   primitiveType ('[' ']')* { 
            notifyErrorListeners("Type names are not allowed as variable names: "+$primitiveType.text); 
        }
    ;

// add support for converter functions int(), float(), ..
// Only the line with "functionWithPrimitiveTypeName" was added
// at a location before any "type" is being matched
expression
    :   primary
    |   expression '.' Identifier
    |   expression '.' 'this'
    |   expression '.' 'new' nonWildcardTypeArguments? innerCreator
    |   expression '.' 'super' superSuffix
    |   expression '.' explicitGenericInvocation
    |   expression '[' expression ']'
    |   apiFunction
    |   expression '(' expressionList? ')'
    |   'new' creator
    |   functionWithPrimitiveTypeName
    |   '(' typeType ')' expression
    |   expression ('++' | '--')
    |   ('+'|'-'|'++'|'--') expression
    |   ('~'|'!') expression
    |   expression ('*'|'/'|'%') expression
    |   expression ('+'|'-') expression
    |   expression ('<' '<' | '>' '>' '>' | '>' '>') expression
    |   expression ('<=' | '>=' | '>' | '<') expression
    |   expression 'instanceof' typeType
    |   expression ('==' | '!=') expression
    |   expression '&' expression
    |   expression '^' expression
    |   expression '|' expression
    |   expression '&&' expression
    |   expression '||' expression
    |   expression '?' expression ':' expression
    |   warnTypeAsVariableName
    |   <assoc=right> expression
        (   '='
        |   '+='
        |   '-='
        |   '*='
        |   '/='
        |   '&='
        |   '|='
        |   '^='
        |   '>>='
        |   '>>>='
        |   '<<='
        |   '%='
        )
        expression
    ;

// catch special API function calls that we are interessted in
apiFunction
    :   apiDraw
    |   apiColor
    ;
apiDraw
    : circleFunction
    | drawFourDecimal
    ;

apiColor
    :  colorFunction '(' colorLiteral ')'
    ;

colorFunction: (FILL | BACKGROUND | STROKE);


circleFunction : CIRCLE '(' position ',' position ',' position ')';
drawFourDecimal : drawFourDecimalShape '(' position ',' position ',' position ',' position ')';

// draw functions which take 4 decimal arguments
drawFourDecimalShape: RECT
                    | ELLIPSE
                    | LINE;  
position: DECIMAL_LITERAL
          | FRAMECOUNT;

drawShape
    : CIRCLE
    | RECT
    | ELLIPSE
;

apiSize
    : 'size' '(' expression ',' expression ( ',' expression )? ')'
    ;

// these are primitive type names plus "()"
// "color" is a special Processing primitive (== int)
functionWithPrimitiveTypeName
	:	(	'boolean'
		|	'byte'
		|	'char'
		|	'float'
		|	'int'
        |   COLOR
		) '(' expressionList ')'
	;

// adding support for "color" primitive
primitiveType:	javaPrimitiveType
	;

// original Java.g4 primitiveType
javaPrimitiveType
    :   'boolean'
    |   'char'
    |   'byte'
    |   'short'
    |   'int'
    |   'long'
    |   'float'
    |   'double'
    ;

// added HexColorLiteral
literal
    :   colorLiteral
    |	integerLiteral
    |	floatLiteral
    |   CHAR_LITERAL
    |   STRING_LITERAL
    |   BOOL_LITERAL
    |   'null'
    ;

colorLiteral
    :   hexColorLiteral
    |   singleColorLiteral
    |   rgbColorLiteral
    ;

hexColorLiteral : '#' hexColorValue;

hexColorValue: HEX_COLOR_VALUE;

singleColorLiteral
    :   integerLiteral
    ;

rgbColorLiteral
    :   integerLiteral ',' integerLiteral ',' integerLiteral
    ;

// As parser rule so this produces a separate listener
// for us to alter its value.
// hexColorLiteral
// 	:   HEX_COLOR_LITERAL	
// 	;

