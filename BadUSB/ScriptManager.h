#include "IKeyboard.h"

class ScriptManager
{
public:
    typedef struct
    {
        uint8_t rowArray[512];
        uint16_t rowLength;
    } Row;

    static void init(IKeyboard* keyboard);
    static void executeScript(uint8_t* rawBytes, uint16_t size);

    //tests
    static uint16_t getRowCount(uint8_t* buffer, uint16_t buffSize);
    static void getRows(uint8_t* rawBytesArr, uint16_t rawBytesArrSize, Row* rowArray, uint16_t rowArrSize);

private:
    static IKeyboard* m_keyboard;
};