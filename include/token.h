#pragma once
#include <string>

enum class TokenType {
    identifier,
    number,
    plus, //  +
    minus, //  -
    asterisk, //  *
    slash, //  /
    assign, //  =
    left_paren, //  (
    right_paren, //  )

    EndOfFile
}; 

struct Token {
    TokenType type; // type_of_token
    std::string lexeme; // substring
    double number = 0; // only for number tokens
};

