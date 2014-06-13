#include <fl/Headers.h>

int main(int argc, char** argv){
using namespace fl;

Engine* engine = new Engine;
engine->setName("");

InputVariable* inputVariable = new InputVariable;
inputVariable->setEnabled(true);
inputVariable->setName("X");
inputVariable->setRange(-10.000, 10.000);
inputVariable->addTerm(new Bell("small", -10.000, 5.000, 3.000));
inputVariable->addTerm(new Bell("medium", 0.000, 5.000, 3.000));
inputVariable->addTerm(new Bell("large", 10.000, 5.000, 3.000));
engine->addInputVariable(inputVariable);

OutputVariable* outputVariable1 = new OutputVariable;
outputVariable1->setEnabled(true);
outputVariable1->setName("A");
outputVariable1->setRange(0.000, 1.000);
outputVariable1->fuzzyOutput()->setAccumulation(new AlgebraicSum);
outputVariable1->setDefuzzifier(new WeightedAverage);
outputVariable1->setDefaultValue(fl::nan);
outputVariable1->setLockPreviousOutputValue(false);
outputVariable1->setLockOutputValueInRange(false);
outputVariable1->addTerm(new Ramp("a1", 0.000, 0.250));
outputVariable1->addTerm(new Ramp("a2", 0.600, 0.400));
outputVariable1->addTerm(new Ramp("a3", 0.700, 1.000));
engine->addOutputVariable(outputVariable1);

OutputVariable* outputVariable2 = new OutputVariable;
outputVariable2->setEnabled(true);
outputVariable2->setName("B");
outputVariable2->setRange(0.000, 1.000);
outputVariable2->fuzzyOutput()->setAccumulation(new AlgebraicSum);
outputVariable2->setDefuzzifier(new WeightedAverage);
outputVariable2->setDefaultValue(fl::nan);
outputVariable2->setLockPreviousOutputValue(false);
outputVariable2->setLockOutputValueInRange(false);
outputVariable2->addTerm(new Sigmoid("b1", 0.130, 30.000));
outputVariable2->addTerm(new Sigmoid("b2", 0.500, -30.000));
outputVariable2->addTerm(new Sigmoid("b3", 0.830, 30.000));
engine->addOutputVariable(outputVariable2);

OutputVariable* outputVariable3 = new OutputVariable;
outputVariable3->setEnabled(true);
outputVariable3->setName("C");
outputVariable3->setRange(0.000, 1.000);
outputVariable3->fuzzyOutput()->setAccumulation(new AlgebraicSum);
outputVariable3->setDefuzzifier(new WeightedAverage);
outputVariable3->setDefaultValue(fl::nan);
outputVariable3->setLockPreviousOutputValue(false);
outputVariable3->setLockOutputValueInRange(false);
outputVariable3->addTerm(new SShape("c1", 0.000, 0.250));
outputVariable3->addTerm(new ZShape("c2", 0.300, 0.600));
outputVariable3->addTerm(new SShape("c3", 0.700, 1.000));
engine->addOutputVariable(outputVariable3);

RuleBlock* ruleBlock = new RuleBlock;
ruleBlock->setEnabled(true);
ruleBlock->setName("");
ruleBlock->setConjunction(NULL);
ruleBlock->setDisjunction(NULL);
ruleBlock->setActivation(new AlgebraicProduct);
ruleBlock->addRule(fl::Rule::parse("if X is small then A is a1 and B is b1 and C is c1", engine));
ruleBlock->addRule(fl::Rule::parse("if X is medium then A is a2 and B is b2 and C is c2", engine));
ruleBlock->addRule(fl::Rule::parse("if X is large then A is a3 and B is b3 and C is c3", engine));
engine->addRuleBlock(ruleBlock);


}
