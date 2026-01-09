#pragma once
#include"token.h"
#include"lexer.h"
#include<string>
#include<cctype>
#include<stdexcept>

token lexer::get_next_token(){
    //skip white_space

    while(pos < input.length() && isspace(input[pos])){
        pos++;
    }

    //end_of_file

    if(pos >= input.length()){
        return {token_type::EndOfFile, ""};
    }

    //single_character_tokens
    char current_char = input[pos];
    switch(current_char){
        case '+':  
            pos++;
            return {token_type::plus, "+"};

        case '-':
            pos++;
            return {token_type::minus, "-"};
        
        case '*':
            pos++;
            return {token_type::asterisk, "*"};
        
        case '/':
            pos++;
            return {token_type::slash, "/"};
        
        case '=':
            pos++;
            return {token_type::assign, "="};

        case '(':
            pos++;
            return {token_type::left_paren, "("};

        case ')':
            pos++;
            return {token_type::right_paren, ")"};

        default:
            throw std::runtime_error(std::string("Unexpected character: ") + current_char);

    }

    
    

             
}



std::vector<token> lexer::tokenize(){}