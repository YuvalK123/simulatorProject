//
// Created by israela on 26/12/2019.
//

#include "Command.h"
class Sleep : public Command {
public:
    int execute() override;
};

int Sleep::execute() {
    return 0;
}
