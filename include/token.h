#pragma once
#include <string>

enum class token_type {
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

struct token {
    token_type type; // type_of_token
    std::string lexeme; // substring
    double number = 0.0; // only for number tokens
};

