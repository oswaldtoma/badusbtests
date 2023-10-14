#include <cstddef>
#include <cstdint>

class ScriptLang
{
    struct KeyValueDict
    {
        char key[4];
        uint16_t value;
    };

public:
    static void getLineBytesArray(const char* scriptLine, char* outArray);
    static uint16_t getKeyNumValue(const char* keyString);

private:
    static constexpr uint8_t DICTIONARY_ELEMENTS_NUMBER = 19;

    static uint16_t getSpecialKeyNumValue(const char* keyString);
    static bool hasSpaces(const char* string);
    static bool isString(const char* string);

    static KeyValueDict m_dictionary[DICTIONARY_ELEMENTS_NUMBER];
};