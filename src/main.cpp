#include <iostream>
#include <vector>
#include "lexer.h"
#include "token.h"

std::string token_type_to_string(token_type t) {
    switch (t) {
        case token_type::number:      return "NUMBER";
        case token_type::identifier:  return "IDENTIFIER";
        case token_type::plus:        return "PLUS";
        case token_type::minus:       return "MINUS";
        case token_type::asterisk:    return "ASTERISK";
        case token_type::slash:       return "SLASH";
        case token_type::assign:      return "ASSIGN";
        case token_type::left_paren:  return "LPAREN";
        case token_type::right_paren: return "RPAREN";
        case token_type::EndOfFile:   return "EOF";
    }
    return "UNKNOWN";
}

int main() {
    std::string input;

    std::cout << "Enter input: ";
    std::getline(std::cin, input);

    lexer lex(input);
    std::vector<token> tokens = lex.tokenize();

    std::cout << "\nTokens:\n";
    for (const auto& t : tokens) {
        std::cout << token_type_to_string(t.type);

        if (!t.lexeme.empty()) {
            std::cout << " (" << t.lexeme << ")";
        }

        if (t.type == token_type::number) {
            std::cout << " value=" << t.number;
        }

        std::cout << "\n";
    }

    return 0;
}
