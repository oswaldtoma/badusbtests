#ifndef SIMPLETESTLIB_H_
#define SIMPLETESTLIB_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <unordered_map>

/*
	To use this library, you should call SETUP_TESTS() in main() (in your test project).
	Create test functions i.e. void TemperatureTest() with CHECK macros inside.
	Add addresses of every created function, to TestManager object you've created earlier, using ADD_TEST_CASE(function name) macro, 
	then call RUN_ALL_TESTS().
	THAT'S ALL!

	Name of the function used in ADD_TEST_CASE macro, will be displayed during testing. If you want to customize the name displayed during runtime, use addTestCase method from TestManager class, directly.

	MOCK MACROS:
	void Function() { //definition of a function used in the algorithm
		RETURN_MOCKED_VALUE(Function);
	}

	MOCK_FUNCTION(Function, 42); //SETTING THE VALUE TO BE RETURNED BY Function()

	update() //SHOULD USE Function() AND GET 42 SOMEWHERE IN THE ALGORITHM
*/

//GENERAL MACROS
#define SETUP_TESTS() TestManager tests
#define ADD_TEST_CASE(func) tests.addTestCase(#func, func)
#define RUN_ALL_TESTS() tests.runAllTests()
//

//CHECK MACROS
#define CHECK_EQ(expected, actual) UNSAFE::checkEqual(expected, actual, __LINE__)
#define CHECK(expression) UNSAFE::checkTrue(expression, __LINE__)
//

//MOCK MACROS
#define MOCK_FUNCTION(func, value) UNSAFE::mockFunction(func, value)
#define RETURN_MOCKED_VALUE(func) UNSAFE::findFuncAndGetVal(func)
//

class TestCase {
public:
	TestCase(const std::string& name, std::function<void()> testFunction)
		: testName(name), testFunc(testFunction) {}

	void run() {
		std::cout << "Running test: " << testName << "... ";
		testFunc();
	}

private:
	std::string testName;
	std::function<void()> testFunc;
};

class TestManager {
public: 
	void addTestCase(const std::string& name, std::function<void()> testFunction) {
		testCases.emplace_back(name, testFunction);
	}

	void runAllTests() {
		std::cout << "Running all tests: " << std::endl;
		for (auto& testCase : testCases) {
			testCase.run();
			std::cout << "[OK]" << std::endl;
		}
	}

private:
	std::vector<TestCase> testCases;
};

//NOT SAFE, IGNORE IT
namespace UNSAFE {
	// WARNING! USE MACROS! USING FUNCTIONS DIRECTLY IS NOT RECOMMENDED
	template <class T>
	inline void checkEqual(T expected, T actual, uint64_t line) {
		// This function should not be used directly.
		// Use CHECK_EQ() instead.
		if (expected != actual && strcmp((char*)expected, (char*)actual)) {
			std::cout << "[ERROR at line: " << line << "] " << "Expected: " << expected << " Actual: " << actual << std::endl;
			exit(1);
		}
	}

	// WARNING! USE MACROS! USING FUNCTIONS DIRECTLY IS NOT RECOMMENDED
	template<>
	inline void checkEqual(char* expected, char* actual, uint64_t line) {
		// This function should not be used directly.
		// Use CHECK_EQ() instead.
		if (strcmp(expected, actual)) {
			std::cout << "[ERROR at line: " << line << "] " << "Expected: " << expected << " Actual: " << actual << std::endl;
			exit(1);
		}
	}

	// WARNING! USE MACROS! USING FUNCTIONS DIRECTLY IS NOT RECOMMENDED
	template <class V>
	inline void checkTrue(V expression, uint64_t line) {
		// This function should not be used directly.
		// Use CHECK() instead.
		if (!(expression)) {
			std::cout << "[ERROR at line: " << __LINE__ << "] " << std::endl;
			exit(1);
		}
	}
	// WARNING END

	std::unordered_map<void*, long long int> mockFuncsAndValues; //std::function zamiast void*?

	// WARNING! USE MACROS! USING FUNCTIONS DIRECTLY IS NOT RECOMMENDED
	template <class X>
	void mockFunction(void* func, X value) {
		std::pair<void*, X> info = { func, value };
		mockFuncsAndValues.insert(info);
	}

	// WARNING! USE MACROS! USING FUNCTIONS DIRECTLY IS NOT RECOMMENDED
	long long int findFuncAndGetVal(void* func) {
		auto search = mockFuncsAndValues.find(func);
		if (search != mockFuncsAndValues.end()) {
			return search->second;
		}

		return 0;
	}
	// WARNING END
}

#endif /* SIMPLETESTLIB_H_ */
