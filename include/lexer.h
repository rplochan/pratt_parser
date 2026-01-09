#pragma once
#include"token.h"
#include <string>
#include <vector>

class lexer {
    public:
        lexer(const std::string& input_string){
            pos = 0;
            input = input_string;
        }
        std::vector<token> tokenize();

    private:
        std::string input;
        size_t pos;
        token get_next_token();
};
