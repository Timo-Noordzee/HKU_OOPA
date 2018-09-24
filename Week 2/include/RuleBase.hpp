#pragma once
#include "Rule.hpp"

class BaseRule : public Rule {
   public:
    BaseRule();
    virtual ~BaseRule();

    int applyRule(int state, int neighbors) override;
};