#include "ScriptManager.h"
#include "ScriptLang.h"
#include "Helper.h"
#include "string.h"
#include "stdlib.h"

IKeyboard* ScriptManager::m_keyboard = nullptr;

void ScriptManager::init(IKeyboard* keyboard)
{
    m_keyboard = keyboard;
}

void ScriptManager::executeScript(uint8_t* rawBytes, uint16_t size)
{
    uint16_t rowCount = getRowCount(rawBytes, size);

    static Row rows[50] = { { 0 }, 0 };
    for (uint8_t i = 0; i < 50; i++)
    {
        Helper::fillArrayWithValue(rows[i].rowArray, 512, 0);
        rows[i].rowLength = 0;
    }

    getRows(rawBytes, size, rows, 50);

    uint16_t nextDelay = 100;

    for (uint16_t row = 0; row < rowCount; row++)
    {
        static char buffer[512];
        Helper::fillArrayWithValue((uint8_t*)buffer, 512, 0);

        if (strstr((const char*)rows[row].rowArray, "WT "))
        {
            nextDelay = atoi((const char*)rows[row].rowArray[3]);
            continue;
        }

        ScriptLang::getLineBytesArray((const char*)rows[row].rowArray, buffer);
        uint16_t bytesCount = Helper::getStringLength((uint8_t*)buffer, 512);

        if (buffer[0] == '"' && buffer[bytesCount - 1] == '"') //string
        {
            buffer[bytesCount - 1] = '\0';
            m_keyboard->write((const uint8_t*)(buffer + 1), rows[row].rowLength - 2); //ignore quotation marks
            continue;
        }

        for (uint16_t c = 0; c < bytesCount; c++)
        {
            m_keyboard->press(buffer[c], nextDelay);
            nextDelay = 100;
        }

        m_keyboard->releaseAll();
    }
}

uint16_t ScriptManager::getRowCount(uint8_t* buffer, uint16_t buffSize)
{
    uint16_t rowCount = 1;

    if (Helper::isEmpty(buffer, buffSize))
    {
        return 0;
    }

    for (uint16_t i = 0; i < buffSize; i++)
    {
        bool windowsLineBreak = buffer[i] == '\r' && buffer[i + 1] == '\n';
        bool unixLineBreak = buffer[i] == '\n';

        bool endOfFile = i + 1 == buffSize;
        bool endOfLine = windowsLineBreak || unixLineBreak || endOfFile;

        if (endOfLine)
        {
            if (windowsLineBreak)
            {
                i++;
            }

            if (!endOfFile)
            {
                rowCount++;
            }
        }          
    }

    return rowCount;
}

void ScriptManager::getRows(uint8_t* rawBytesArr, uint16_t rawBytesArrSize, Row* rowArray, uint16_t rowArrSize)
{
    uint16_t nextEmptyRow = 0;

    static char buffer[512];
    Helper::fillArrayWithValue((uint8_t*)buffer, 512, 0);

    uint16_t bufferIndex = 0;

    for (uint16_t i = 0; i <= rawBytesArrSize; i++)
    {
        bool windowsLineBreak = rawBytesArr[i] == '\r' && rawBytesArr[i + 1] == '\n';
        bool unixLineBreak = rawBytesArr[i] == '\n';

        bool endOfFile = i == rawBytesArrSize;
        bool endOfLine = windowsLineBreak || unixLineBreak || endOfFile;

        if (endOfLine)
        {          
            Helper::copyArray(rowArray[nextEmptyRow].rowArray, (uint8_t*)buffer, bufferIndex);
            rowArray[nextEmptyRow].rowLength = bufferIndex;

            Helper::fillArrayWithValue((uint8_t*)buffer, 512, 0);
            bufferIndex = 0;
            nextEmptyRow++;

            if (windowsLineBreak)
            {
                i++; //skip \r
            }

            continue; //begin processing next row
        }

        buffer[bufferIndex] = rawBytesArr[i];
        bufferIndex++;
    }
}