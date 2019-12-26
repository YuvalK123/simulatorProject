//
// Created by israela on 26/12/2019.
//

#include "Command.h"
class Print : public Command {
public:
    int execute() override;
};

int Print::execute() {
    return 0;
}
