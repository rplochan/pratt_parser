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

     char current_char = input[pos];

     //numeric literal with decimal support

    if(isdigit(current_char)){
        std::string number_lexeme;
        int dot_count =0;
        while(pos < input.length() && (isdigit(input[pos])|| input[pos] == '.')){

            if(input[pos] == '.'){
                if(dot_count == 1){
                    throw std::runtime_error("Invalid number format: multiple decimal points");
                }
                dot_count++;
            }
            
            number_lexeme += input[pos++];
        }

        return {token_type::number, number_lexeme, std::stod(number_lexeme)};
    }


    //identifier (variable names)

    if(isalpha(current_char) || current_char == '_'){
        std::string identifier_lexeme;
        while(pos < input.length() && ((isalnum(input[pos]) || input[pos] == '_'))){
            identifier_lexeme += input[pos++];
        }
        return {token_type::identifier, identifier_lexeme};
    }


    //single_character_tokens

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

    }

    throw std::runtime_error(std::string("Unexpected character: ") + current_char);
}



std::vector<token> lexer::tokenize(){
    std::vector<token> tokens;
    while(true){
        token t = get_next_token();
        tokens.push_back(t);
        if(t.type == token_type::EndOfFile){
            break;
        }
    }

    return tokens;
}