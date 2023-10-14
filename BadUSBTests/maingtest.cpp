//#include "simpletestlib.h"
#include "googletest/include/gtest/gtest.h"
#include "../BadUSB/ScriptLang.h"
#include "../BadUSB/ScriptManager.h"
#include "KeyboardFake.h"
#include <iostream>
#include <chrono>

TEST(TestProject, TestSingleChar)
{
	char buffer = '\0';
	ScriptLang::getLineBytesArray("a", &buffer);
	EXPECT_EQ('a', buffer);

	buffer = '\0';
	ScriptLang::getLineBytesArray("b", &buffer);
	EXPECT_EQ('b', buffer);
}

TEST(TestProject, TestKeyCombination)
{
	char buffer[30] = { '\0' };
	ScriptLang::getLineBytesArray("OS r d", buffer);

	EXPECT_EQ((uint8_t)0x83, (uint8_t)buffer[0]); //OS
	EXPECT_EQ('r', buffer[1]);
	EXPECT_EQ('d', buffer[2]);
}

TEST(TestProject, TestWordWithQuotationMarks)
{
	char buffer[20] = { '\0' };
	ScriptLang::getLineBytesArray("\"Samochod123\"", buffer);

	EXPECT_EQ((char*)"\"Samochod123\"", buffer);
}

TEST(TestProject, TestWordWithQuotationMarksAndSomethingAfter)
{
	char buffer[20] = { '\0' };
	ScriptLang::getLineBytesArray("\"Samochod123\" r", buffer); //should abandon and return empty array

	EXPECT_EQ((char*)"", buffer);
}

TEST(TestProject, TestWordWithQuotationMarksAndSpaces)
{
	char buffer[30] = { '\0' };
	ScriptLang::getLineBytesArray("\"Samochod123 Ala ma kota\"", buffer); //should return bytes including spaces 

	EXPECT_EQ((char*)"\"Samochod123 Ala ma kota\"", buffer);
}

TEST(TestProject, TestWordWithSpecialKeyPhraseInside)
{
	char buffer[30] = { '\0' };
	ScriptLang::getLineBytesArray("\"Samochod123 OS\"", buffer); //should return bytes including spaces, NO SPECIAL KEY

	EXPECT_EQ((char*)"\"Samochod123 OS\"", buffer);
}

TEST(TestProject, TestComment)
{
	char buffer[30] = { '\0' };
	ScriptLang::getLineBytesArray("COM komentarz 123", buffer);

	EXPECT_EQ((char*)"", buffer);
}

//SCRIPT MANAGER
TEST(TestProject, ScriptManagerRowCounter)
{
	const char* string = "OS R";
	uint16_t result = ScriptManager::getRowCount((uint8_t*)string, 4);

	EXPECT_EQ(1, (int)result);

	//with new line after first, no new line after second
	string = "OS R\n LALT TAB";
	EXPECT_EQ(2, (int)ScriptManager::getRowCount((uint8_t*)string, 14));

	string = "OS r\n\"notepad\"\nENT";
	EXPECT_EQ(3, (int)ScriptManager::getRowCount((uint8_t*)string, 18));
}
TEST(TestProject, ScriptManagerTest1)
{
	ScriptManager::Row rows[20] = { {0}, 0 };

	const char* string = "OS R";
	ScriptManager::getRows((uint8_t*)string, 4, rows, 20);

	EXPECT_EQ((const char*)rows[0].rowArray, "OS R");

	string = "OS R\n\"Samochod123\"";
	ScriptManager::getRows((uint8_t*)string, 18, rows, 20);
	EXPECT_EQ((const char*)rows[0].rowArray, "OS R");
	EXPECT_EQ((const char*)rows[1].rowArray, "\"Samochod123\"");

	string = "OS R\r\n\"Samochod123\"";
	ScriptManager::getRows((uint8_t*)string, 19, rows, 20);
	EXPECT_EQ((const char*)rows[0].rowArray, "OS R");
	EXPECT_EQ((const char*)rows[1].rowArray, "\"Samochod123\"");

	string = "\"notepad\"";
	ScriptManager::getRows((uint8_t*)string, 9, rows, 20);
	EXPECT_EQ(9, (int)rows[0].rowLength);
}

TEST(TestProject, ScriptManagerWithKeyboard)
{
	KeyboardFake keyboard;
	ScriptManager::init(&keyboard);

	const char* string = "OS R";
	ScriptManager::executeScript((uint8_t*)string, 19);

	EXPECT_EQ((uint8_t)0x83, keyboard.getPressedKey(0));
}

TEST(TestProject, ScriptManagerTest2)
{
	KeyboardFake keyboard;
	ScriptManager::init(&keyboard);

	const char* string = "\"notepad\"";
	ScriptManager::executeScript((uint8_t*)string, 9);

	EXPECT_EQ((uint8_t)'n', keyboard.getPressedKey(0));
	EXPECT_EQ((uint8_t)'o', keyboard.getPressedKey(1));
	EXPECT_EQ((uint8_t)'t', keyboard.getPressedKey(2));
	EXPECT_EQ((uint8_t)'e', keyboard.getPressedKey(3));
	EXPECT_EQ((uint8_t)'p', keyboard.getPressedKey(4));
	EXPECT_EQ((uint8_t)'a', keyboard.getPressedKey(5));
	EXPECT_EQ((uint8_t)'d', keyboard.getPressedKey(6));
	EXPECT_EQ((uint8_t)'\0', keyboard.getPressedKey(7)); //not pressed
}

TEST(TestProject, ScriptManagerTest3)
{
	KeyboardFake keyboard;
	ScriptManager::init(&keyboard);

	const char* string = "OS r\n\"notepad\"\nENT";
	ScriptManager::executeScript((uint8_t*)string, 18);

	EXPECT_EQ((uint8_t)0x83, keyboard.getPressedKey(0));
	EXPECT_EQ((uint8_t)'r', keyboard.getPressedKey(1));
	EXPECT_EQ((uint8_t)'n', keyboard.getPressedKey(2));
	EXPECT_EQ((uint8_t)'o', keyboard.getPressedKey(3));
	EXPECT_EQ((uint8_t)'t', keyboard.getPressedKey(4));
	EXPECT_EQ((uint8_t)'e', keyboard.getPressedKey(5));
	EXPECT_EQ((uint8_t)'p', keyboard.getPressedKey(6));
	EXPECT_EQ((uint8_t)'a', keyboard.getPressedKey(7));
	EXPECT_EQ((uint8_t)'d', keyboard.getPressedKey(8));
	EXPECT_EQ((uint8_t)0xB0, keyboard.getPressedKey(9));

	keyboard.clearPressedIndex();
}

TEST(TestProject, ScriptManagerTest4LongText)
{
	KeyboardFake keyboard;
	ScriptManager::init(&keyboard);

	const char* lorem = "\"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s.\"";
	ScriptManager::executeScript((uint8_t*)lorem, 155);

	EXPECT_EQ((uint8_t)'L', keyboard.getPressedKey(0));
	EXPECT_EQ((uint8_t)'.', keyboard.getPressedKey(151));
}

TEST(TestProject, ScriptManagerKeysOneAfterAnother)
{
	KeyboardFake keyboard;
	ScriptManager::init(&keyboard);

	const char* string = "a\nENT\nb\nENT\nc\nENT\nd\nENT\ne\nENT\nf\nENT\ng\nENT\nh\nENT\ni\nENT\nj\nENT\nk\nENT\nl\nENT\nm\nENT\nn\nENT\no\nENT\n";
	ScriptManager::executeScript((uint8_t*)string, 91);

	EXPECT_EQ((uint8_t)'o', keyboard.getPressedKey(28));
	EXPECT_EQ((uint8_t)176, keyboard.getPressedKey(29));
}

// int main() {
// 	SETUP_TESTS();

// 	ADD_TEST_CASE(TestSingleChar);
// 	ADD_TEST_CASE(TestKeyCombination);
// 	ADD_TEST_CASE(TestWordWithQuotationMarks);
// 	ADD_TEST_CASE(TestWordWithQuotationMarksAndSomethingAfter);
// 	ADD_TEST_CASE(TestWordWithQuotationMarksAndSpaces);
// 	ADD_TEST_CASE(TestWordWithSpecialKeyPhraseInside);
// 	ADD_TEST_CASE(TestComment);
// 	ADD_TEST_CASE(ScriptManagerTest1);
// 	ADD_TEST_CASE(ScriptManagerWithKeyboard);
// 	ADD_TEST_CASE(ScriptManagerTest2);
// 	ADD_TEST_CASE(ScriptManagerTest3);
// 	ADD_TEST_CASE(ScriptManagerTest4LongText);
// 	ADD_TEST_CASE(ScriptManagerKeysOneAfterAnother);

// 	auto start = std::chrono::high_resolution_clock::now();

// 	RUN_ALL_TESTS();

// 	auto end = std::chrono::high_resolution_clock::now();

// 	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
// }