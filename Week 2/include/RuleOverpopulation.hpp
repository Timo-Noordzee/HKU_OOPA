#pragma once
#include "Rule.hpp"

class OverPopulationRule : public Rule {
   public:
    OverPopulationRule();
    ~OverPopulationRule();

    int applyRule(int state, int neighbors) override;
};