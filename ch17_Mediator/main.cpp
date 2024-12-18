#include "ConcreteColleagueA.h"
#include "ConcreteColleagueB.h"
#include "ConcreteMediator.h"

int main(){
    ConcreteMediator mediator;
    ConcreteColleagueA colleagueA(&mediator);
    ConcreteColleagueB colleagueB(&mediator);
    mediator.addColleague(&colleagueA);
    mediator.addColleague(&colleagueB);

    colleagueA.SendMessage("A asked: \"What is up?\"");
    colleagueB.SendMessage("B answered: \"I am fine, 3Q!\"");
}