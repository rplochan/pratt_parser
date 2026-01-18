#pragma once
#include<string>
#include<memory>
#include"token.h"

class expression {
    public:
    virtual ~expression() = default;
};

using expr_ptr = std::unique_ptr<expression>;

class num_expr : public expression {
    public:
    double value;

    num_expr(double value){
        this->value = value;
    }
};

class var_expr : public expression {
    public:
    std::string name;

    var_expr(const std::string &name){
        this->name = name;
    }
};

class binary_expr : public expression {
    public:
    token_type op;
    expr_ptr left;
    expr_ptr right;
     
    binary_expr(token_type op, expr_ptr left, expr_ptr right){
        this->op = op;
        this->left = std::move(left);
        this->right = std::move(right);
    }
};

