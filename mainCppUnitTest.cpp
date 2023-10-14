#include "CppUnitTest.h"
#include "../BadUSB/ScriptLang.h"
#include "../BadUSB/ScriptManager.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "KeyboardFake.h"
#include <chrono>
#include <iostream>

namespace BadUSBTests
{
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	TEST_CLASS(ScriptLangTests)
	{
	public:
		TEST_METHOD(TestSingleChar)
		{
			start = std::chrono::high_resolution_clock::now();

			char buffer = '\0';
			ScriptLang::getLineBytesArray("a", &buffer);
			Assert::AreEqual('a', buffer);

			buffer = '\0';
			ScriptLang::getLineBytesArray("b", &buffer);
			Assert::AreEqual('b', buffer);
		}

		TEST_METHOD(TestKeyCombination)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("OS r d", buffer);

			Assert::AreEqual((uint8_t)0x83, (uint8_t)buffer[0]); //OS
			Assert::AreEqual('r', buffer[1]);
			Assert::AreEqual('d', buffer[2]);
		}

		TEST_METHOD(TestWordWithQuotationMarks)
		{
			char buffer[20] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123\"", buffer);

			Assert::AreEqual("\"Samochod123\"", buffer);
		}

		TEST_METHOD(TestWordWithQuotationMarksAndSomethingAfter)
		{
			char buffer[20] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123\" r", buffer); //should abandon and return empty array

			Assert::AreEqual("", buffer);
		}

		TEST_METHOD(TestWordWithQuotationMarksAndSpaces)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123 Ala ma kota\"", buffer); //should return bytes including spaces 

			Assert::AreEqual("\"Samochod123 Ala ma kota\"", buffer);
		}

		TEST_METHOD(TestWordWithSpecialKeyPhraseInside)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("\"Samochod123 OS\"", buffer); //should return bytes including spaces, NO SPECIAL KEY

			Assert::AreEqual("\"Samochod123 OS\"", buffer);
		}

		TEST_METHOD(TestComment)
		{
			char buffer[30] = { '\0' };
			ScriptLang::getLineBytesArray("COM komentarz 123", buffer);

			Assert::AreEqual("", buffer);
		}
	};

	TEST_CLASS(ScriptManagerTests)
	{
	public:
		TEST_METHOD(ScriptManagerRowCounterTest)
		{
			const char* string = "OS R";
			uint16_t result = ScriptManager::getRowCount((uint8_t*)string, 4);

			Assert::AreEqual(1, (int)result);

			//with new line after first, no new line after second
			string = "OS R\n LALT TAB";
			Assert::AreEqual(2, (int)ScriptManager::getRowCount((uint8_t*)string, 14));

			string = "OS r\n\"notepad\"\nENT";
			Assert::AreEqual(3, (int)ScriptManager::getRowCount((uint8_t*)string, 18));
		}
		TEST_METHOD(ScriptManagerTest1)
		{
			ScriptManager::Row rows[20] = { {0}, 0 };

			const char* string = "OS R";
			ScriptManager::getRows((uint8_t*)string, 4, rows, 20);

			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");

			string = "OS R\n\"Samochod123\"";
			ScriptManager::getRows((uint8_t*)string, 18, rows, 20);
			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");
			Assert::AreEqual((const char*)rows[1].rowArray, "\"Samochod123\"");

			string = "OS R\r\n\"Samochod123\"";
			ScriptManager::getRows((uint8_t*)string, 19, rows, 20);
			Assert::AreEqual((const char*)rows[0].rowArray, "OS R");
			Assert::AreEqual((const char*)rows[1].rowArray, "\"Samochod123\"");

			string = "\"notepad\"";
			ScriptManager::getRows((uint8_t*)string, 9, rows, 20);
			Assert::AreEqual(9, (int)rows[0].rowLength);
		}

		TEST_METHOD(ScriptManagerWithKeyboard)
		{
			KeyboardFake keyboard;
			ScriptManager::init(&keyboard);

			//const char* string = "OS R\r\n\"Samochod123\"";
			//ScriptManager::executeScript((uint8_t*)string, 19);

			//Assert::AreEqual((uint8_t)0x83, keyboard.getPressedKey(0)); presses are replaced by write func

			const char* string = "OS R";
			ScriptManager::executeScript((uint8_t*)string, 19);

			Assert::AreEqual((uint8_t)0x83, keyboard.getPressedKey(0));
		}

		TEST_METHOD(ScriptManagerTest2)
		{
			KeyboardFake keyboard;
			ScriptManager::init(&keyboard);

			const char* string = "\"notepad\"";
			ScriptManager::executeScript((uint8_t*)string, 9);

			Assert::AreEqual((uint8_t)'n', keyboard.getPressedKey(0));
			Assert::AreEqual((uint8_t)'o', keyboard.getPressedKey(1));
			Assert::AreEqual((uint8_t)'t', keyboard.getPressedKey(2));
			Assert::AreEqual((uint8_t)'e', keyboard.getPressedKey(3));
			Assert::AreEqual((uint8_t)'p', keyboard.getPressedKey(4));
			Assert::AreEqual((uint8_t)'a', keyboard.getPressedKey(5));
			Assert::AreEqual((uint8_t)'d', keyboard.getPressedKey(6));
			Assert::AreEqual((uint8_t)'\0', keyboard.getPressedKey(7)); //not pressed
		}

		TEST_METHOD(ScriptManagerTest3)
		{
			KeyboardFake keyboard;
			ScriptManager::init(&keyboard);

			const char* string = "OS r\n\"notepad\"\nENT";
			ScriptManager::executeScript((uint8_t*)string, 18);

			Assert::AreEqual((uint8_t)0x83, keyboard.getPressedKey(0)); 
			Assert::AreEqual((uint8_t)'r', keyboard.getPressedKey(1));
			Assert::AreEqual((uint8_t)'n', keyboard.getPressedKey(2));
			Assert::AreEqual((uint8_t)'o', keyboard.getPressedKey(3));
			Assert::AreEqual((uint8_t)'t', keyboard.getPressedKey(4));
			Assert::AreEqual((uint8_t)'e', keyboard.getPressedKey(5));
			Assert::AreEqual((uint8_t)'p', keyboard.getPressedKey(6));
			Assert::AreEqual((uint8_t)'a', keyboard.getPressedKey(7));
			Assert::AreEqual((uint8_t)'d', keyboard.getPressedKey(8));
			Assert::AreEqual((uint8_t)0xB0, keyboard.getPressedKey(9)); 

			keyboard.clearPressedIndex();
		}

		TEST_METHOD(ScriptManagerTest4LongText)
		{
			KeyboardFake keyboard;
			ScriptManager::init(&keyboard);

			const char* lorem = "\"Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s.\"";
			ScriptManager::executeScript((uint8_t*)lorem, 155);

			Assert::AreEqual((uint8_t)'L', keyboard.getPressedKey(0));
			Assert::AreEqual((uint8_t)'.', keyboard.getPressedKey(151));
		}

		TEST_METHOD(ScriptManagerKeysOneAfterAnother)
		{
			KeyboardFake keyboard;
			ScriptManager::init(&keyboard);

			const char* string = "a\nENT\nb\nENT\nc\nENT\nd\nENT\ne\nENT\nf\nENT\ng\nENT\nh\nENT\ni\nENT\nj\nENT\nk\nENT\nl\nENT\nm\nENT\nn\nENT\no\nENT\n";
			ScriptManager::executeScript((uint8_t*)string, 91);

			Assert::AreEqual((uint8_t)'o', keyboard.getPressedKey(28));
			Assert::AreEqual((uint8_t)176, keyboard.getPressedKey(29));

			end = std::chrono::high_resolution_clock::now();

			std::cout << "Runtime: " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
		}
	};
}
