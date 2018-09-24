#include "RuleBase.hpp"

BaseRule::BaseRule() {
}

BaseRule::~BaseRule() {
}

int BaseRule::applyRule(int state, int neighbors) {
    int newState = state;
    if (state == 0) {
        if (neighbors == 3) {
            newState = 1;
        }
    } else {
        if (neighbors < 2 || neighbors > 3) {
            newState = 0;
        }
    }
    return newState;
}