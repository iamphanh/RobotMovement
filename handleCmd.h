#pragma once

#include "CommandLine.h"

class handleCmd {
public:
    static CommandLine* createCommand(const string& commandStr);
};
