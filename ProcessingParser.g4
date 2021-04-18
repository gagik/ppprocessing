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

blockStatement
    : localVariableDefinition
    | localVariableDeclaration ';'
    | statement
    | localTypeDeclaration
    ;

// simplified variable definition for the purpose
// of float declarations only for now
localVariableDefinition
    : typeType IDENTIFIER '=' expression ';'
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

expression
    :   FRAMECOUNT  
    // |   additionOperation 
    |   primary
    |   expression (ADD|SUBTRACT|MUL|DIV) expression
    |   expression '.' Identifier
    |   expression '.' 'this'
    |   expression '.' 'new' nonWildcardTypeArguments? innerCreator
    |   expression '.' 'super' superSuffix
    |   expression '.' explicitGenericInvocation
    |   expression '[' expression ']'
    |   mathFunction
    |   apiFunction
    |   expression '(' expressionList? ')'
    |   'new' creator
    |   functionWithPrimitiveTypeName
    |   '(' typeType ')' expression
    |   expression ('++' | '--')
    |   ('+'|SUBTRACT|'++'|'--') expression
    |   ('~'|'!') expression
    |   expression ('*'|'/'|'%') expression
    |   expression (ADD|SUBTRACT) expression
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

// additionOperation:
//     expression (ADD | SUBTRACT) expression;

mathFunction
    :   mathSinCos
    |   ABS_FUNC '(' expression ')'
;

mathSinCos: (SIN | COS) '(' expression ')';
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


circleFunction : CIRCLE '(' expression ',' expression  ',' expression ')';
drawFourDecimal : drawFourDecimalShape '(' expression  ',' expression ',' expression ',' expression ')';

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

