#include "RuleOverpopulation.hpp"

OverPopulationRule::OverPopulationRule() {
}

OverPopulationRule::~OverPopulationRule() {
}

int OverPopulationRule::applyRule(int state, int neighbors) {
    int newState = state;
    if (state == 0) {
        if (neighbors >= 2) {
            newState = 1;
        }
    } else {
        if (neighbors < 1 || neighbors > 6) {
            newState = 0;
        }
    }
    return newState;
}