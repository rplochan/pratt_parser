#pragma once
#include <vector>
#include <utility>
#include "token.h"
#include "ast.h"

class parser{
  // to navigate the token stream
  size_t pos =0;
  
  // to view to current token
  const token &peek();

 // to advance to the next token.
 const token &advance();
 
 std::pair<int,int> infix_exp(token_type);
 
 const std::vector<token>& t;
 
public:
   
 // Parse an expression using Pratt parsing
 parser(const std::vector<token>& tokens);
 
  // min_bp = minimum binding power
  expr_ptr parse_expression(int min_bp = 0);  
};
