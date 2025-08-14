#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <memory>
#include <typeinfo>
#include <exception>
#include <fstream>
#include <regex>

/**
 * In order to add new test case use slicer-test code snippet whose definition
 * is added in the snippets.code-snippets file of the root of this project.
 */

// basic io

namespace test_01 {
  void basicIO() {
    std::cout << "basic io - enter an integer: ";
    int x;
    std::cin >> x;
    std::cout << "you entered: " << x << std::endl;
  }
  void fileIO() {
    std::string line;
    std::ofstream outFile("out.txt");
    if (outFile.is_open()) {
      outFile << "writing to a file.\n";
      outFile.close();
    }
    std::ifstream inFile("out.txt");
    if (inFile.is_open()) {
      std::getline(inFile, line);
      inFile.close();
    }
  }
  void entry() {
    basicIO();
    fileIO();
  }
}

// basic data types and operators
namespace test_02 {
  void dataTypesAndOperators() {
    int a = 5;
    double b = 3.14;
    char c = 'a';
    bool d = true;
    int newVariableAdded = 7;
    std::cout << "int: " << a << std::endl;
    std::cout << "double: " << b << std::endl;
    std::cout << "new variable added: " << newVariableAdded << std::endl;
    std::cout << "char: " << c << std::endl;
    std::cout << "bool: " << d << std::endl;
  }
  void entry() {
    dataTypesAndOperators();
  }
}

// control flow statements
namespace test_03 {
  void simpleControlFlow() {
    int x = 10;
    if (x > 5) {
      std::cout << "x is greater than 5" << std::endl;
    } else {
      std::cout << "x is 5 or less" << std::endl;
    }
    for (int i = 0; i < 5; ++i) {
      std::cout << "i = " << i << std::endl;
    }
    int y = 0;
    while (y < 5) {
      std::cout << "y = " << y << std::endl;
      ++y;
    }
  }
  char switchCase(float score) {
    int range = score / 10;
    switch (range) {
      case 10:
      case 9:
          return 'A';
      case 8:
          return 'B';
      case 7:
          return 'C';
      case 6:
          return 'D';
      case 5:
          return 'E';
      case 4:
          return 'F';
      case 3:
      case 2:
      case 1:
      case 0:
          return 'U';
      default:
          return '?';
    }
  }
  char consequentIfs(int score) {
    if (score >= 90 && score <= 100) {
        return 'A';
    } else if (score >= 80 && score < 90) {
        return 'B';
    } else if (score >= 75 && score < 80) {
        return 'C';
    } else if (score >= 70 && score < 75) {
        return 'D';
    } else if (score >= 65 && score < 70) {
        return 'E';
    } else if (score >= 60 && score < 65) {
        return 'F';
    } else if (score >= 55 && score < 60) {
        return 'G';
    } else if (score >= 50 && score < 55) {
        return 'H';
    } else if (score >= 40 && score < 50) {
        return 'I';
    } else if (score >= 30 && score < 40) {
        return 'J';
    } else if (score < 30) {
        return 'U'; // Ungraded or Fail
    } else {
        return '?';
    }
}
void entry() {
  switchCase(99);
  consequentIfs(33);
  simpleControlFlow();
  }
}

// function overloading
namespace test_04 {
  void print_char(char i) {
    std::cout << "char: " << i << std::endl;
  }
  void print_int(int i) {
    std::cout << "int: " << i << std::endl;
  }
  void print_double(double i) {
    std::cout << "double: " << i << std::endl;
  }
  void entry() {
    print_int(1);
    print_double(1.1);
    print_char('a');
  }
}

// classes and objects
namespace test_05 {
  namespace BaseNamespace {
    void greet() {
      std::cout << "hello from BaseNamespace" << std::endl;
    }
  }
  class SimpleClass {
  public:
    SimpleClass(int value) : value(value) {}
    void display() const {
      std::cout << "value is: " << value << std::endl;
    }
  private:
    int value;
  };
  class ConstructorDestructor {
  public:
    ConstructorDestructor() {
      std::cout << "constructor called" << std::endl;
    }
    ~ConstructorDestructor() {
      std::cout << "destructor called" << std::endl;
    }
  };
  class Base {
  public:
    void show() {
      std::cout << "base class" << std::endl;
    }
  };
  class Derived : public Base {
  public:
    void show() {
      std::cout << "derived class" << std::endl;
    }
  };
  class StaticExample {
  public:
    static int count;
    StaticExample() { ++count; }
    static void displayCount() {
      ++count;
      std::cout << "static count: " << count << std::endl;
    }
  };
  class OperatorOverloading {
  public:
    OperatorOverloading(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    OperatorOverloading operator+(const OperatorOverloading &other) const {
      return OperatorOverloading(real + other.real, imag + other.imag);
    }
    friend std::ostream &operator<<(std::ostream &os, const OperatorOverloading &c) {
      os << c.real << " + " << c.imag << "i";
      return os;
    }
  private:
    double real, imag;
  };
  class FriendFunction {
  public:
    FriendFunction(int v) : value(v) {}
    friend void showValue(const FriendFunction &ff);
  private:
    int value;
  };
  class BaseWithVirtualDestructor {
  public:
    virtual ~BaseWithVirtualDestructor() {
      std::cout << "BaseWithVirtualDestructor destructor called" << std::endl;
    }
  };
  class MultipleInheritanceA {
  public:
    void showA() { std::cout << "class MultipleInheritanceA" << std::endl; }
  };
  class MultipleInheritanceB {
  public:
    void showB() { std::cout << "class MultipleInheritanceB" << std::endl; }
  };
  class MultipleInheritanceC : public MultipleInheritanceA, public MultipleInheritanceB {
  public:
    void showC() { std::cout << "class MultipleInheritanceC" << std::endl; }
  };
  void showValue(const FriendFunction &ff) {
    std::cout << "FriendFunction value is: " << ff.value << std::endl;
  }
  void testSimpleClass() {
    SimpleClass sc(10);
    sc.display();
  }
  void testConstructorDestructor() {
    ConstructorDestructor cd;
  }
  void testInheritance() {
    Derived d;
    d.show();
  }
  void testPolymorphism() {
    Base *b = new Derived();
    b->show();
    delete b;
  }
  int StaticExample::count = 0;
  void testStaticExample() {
    StaticExample s1, s2;
    StaticExample::displayCount();
  }
  void testBaseNamespace() {
    BaseNamespace::greet();
  }
  void testOperatorOverloading() {
    OperatorOverloading oo1(3.0, 4.0);
    OperatorOverloading oo2(1.0, 2.0);
    OperatorOverloading oo3 = oo1 + oo2;
    std::cout << "oo3 value: " << oo3 << std::endl;
  }
  void testFriendFunction() {
    FriendFunction ff(3);
    showValue(ff);
  }
  void testBaseWithVirtualDestructor() {
    BaseWithVirtualDestructor *b = new BaseWithVirtualDestructor();
    delete b;
  }
  void testMultipleInheritance() {
    MultipleInheritanceC mi;
    mi.showA();
    mi.showB();
    mi.showC();
  }
  void entry() {
    testSimpleClass();
    testConstructorDestructor();
    testInheritance();
    testPolymorphism();
    testStaticExample();
    testBaseNamespace();
    testOperatorOverloading();
    testFriendFunction();
    testBaseWithVirtualDestructor();
    testMultipleInheritance();
  }
}

// templates
namespace test_06 {
  template <typename T>
  void printTemplate(T value) {
    std::cout << "template value" << value << std::endl;
  }
  void entry() {
    printTemplate(1);
    printTemplate('1');
    printTemplate(1.1);
  }
}

// stl containers
namespace test_07 {
  void stlContainers() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int num : vec) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  void entry() {
    stlContainers();
  }
}

// lambda expressions
namespace test_08 {
  void lambdaExpressions() {
    auto lambda = [](int x) { return x * x; };
    std::cout << "lambda of 7: " << lambda(7) << std::endl;
  }
  void autoLambda() {
    auto lambda = []() { std::cout << "auto lambda" << std::endl; };
    lambda();
  }
  void entry() {
    lambdaExpressions();
    autoLambda();
  }
}

// smart pointers
namespace test_09 {
  void smartPointers() {
    std::unique_ptr<int> p1 = std::make_unique<int>(10);
    std::cout << "unique pointer value: " << *p1 << std::endl;
    std::shared_ptr<int> p2 = std::make_shared<int>(11);
    std::cout << "shared pointer value: " << *p2 << std::endl;
  }
  void entry() {
    smartPointers();
  }
}

// exception handling
namespace test_10 {
  void exceptionHandling() {
    try {
      throw std::runtime_error("an error occured");
    } catch (const std::exception &e) {
      std::cout << "caught exception: " << e.what() << std::endl;
    }
  }
  class CustomException : public std::exception {
  public:
    const char *what() const noexcept override {
      return "custom exception";
    }
  };
  void testCustomException() {
    try {
      throw CustomException();
    } catch (const CustomException &ce) {
      std::cout << "custom exception caught: " << ce.what() << std::endl;
    }
  }
  void entry() {
    exceptionHandling();
    testCustomException();
  }
}

// typeid
namespace test_11 {
  void typeId() {
    int a = 10;
    std::cout << "a is of type " << typeid(a).name() << std::endl;
  }
  void entry() {
    typeId();
  }
}

// type traits
namespace test_12 {
  void typeTraits() {
    std::cout << "is int an integral type" << std::boolalpha << std::is_integral<int>::value << std::endl;
  }
  void entry() {
    typeTraits();
  }
}

// move semantics
namespace test_13 {
  void moveSemantics() {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = std::move(vec1);
    std::cout << "vec2 contents after move: ";
    for (int num : vec2) {
      std::cout << num << " ";
    }
    std::cout << std::endl;
  }
  void entry() {
    moveSemantics();
  }
}

// constexpr function and values
namespace test_14 {
  constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
  }
  void constexprValue() {
    constexpr int value = 7;
    std::cout << "constexpr value: " << value << std::endl;
  }
  void entry() {
    factorial(7);
    constexprValue();
  }
}

// regex
namespace test_15 {
  void customRegex() {
    std::regex pattern("([a-z]+)(0-9)+");
    std::string text = "armslicer123 rules456";
    std::smatch matches;
    if (std::regex_search(text, matches, pattern)) {
      std::cout << "match found: " << matches[0] << std::endl;
      std::cout << "first group: " << matches[1] << std::endl;
      std::cout << "second group: " << matches[2] << std::endl;
    }
  }
  void entry() {
    customRegex();
  }
}

// structured bindings
namespace test_16 {
  void structuredBindings() {
    std::pair<int, std::string> p(1, "structuredBindingsExample");
    auto [num, str] = p;
    std::cout << "structured bindings: " << num << ", " << str << std::endl;
  }
  void entry() {
    structuredBindings();
  }
}

// no returning functions
namespace test_17 {
  void infiniteLoop() {
    int sum = 0;
    while (true) {
      sum++;
    }
  }

  void infiniteLoops() {
    int sum = 0;
    while (true) {
      sum++;
    }
    int product = 1;
    while (true) {
      product *= sum;
    }
  }

  [[noreturn]] 
  void terminateProgram() {
    std::cout << "Terminating program." << std::endl;
    std::exit(1);
  }

  [[noreturn]] 
  void abortProgram() { // for loop before abort
    std::cout << "Aborting the program." << std::endl;
    std::abort();
  }

  [[noreturn]]
  void throwException() {
    throw std::runtime_error("Throwing an exception.");
  }

  void do_nothing() {
  }

  void entry() {
    infiniteLoop();
    terminateProgram();
    abortProgram();
    throwException();
  }
}

__attribute_used__ int testGlobalStatic() {
  return 1 + 1;
}

int main() {
  testGlobalStatic();
  test_01::entry();
  test_01::entry();
  test_02::entry();
  test_03::entry();
  test_04::entry();
  test_05::entry();
  test_06::entry();
  test_07::entry();
  test_08::entry();
  test_09::entry();
  test_10::entry();
  test_11::entry();
  test_12::entry();
  test_13::entry();
  test_14::entry();
  test_15::entry();
  test_16::entry();
  test_17::entry();
  return 0;
}