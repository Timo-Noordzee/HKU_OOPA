#pragma once

class Rule {
   public:
    Rule();
    virtual ~Rule();

    virtual int applyRule(int state, int neighbors) = 0;
};