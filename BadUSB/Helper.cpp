#include "Helper.h"

void Helper::copyArray(uint8_t* destination, uint8_t* source, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		destination[i] = source[i];
	}
}

void Helper::fillArrayWithValue(uint8_t* destination, uint16_t size, uint16_t value)
{
	for (uint16_t i = 0; i < size; i++)
	{
		destination[i] = value;
	}
}

uint16_t Helper::getStringLength(uint8_t* array, uint16_t arrSize)
{
	for (uint16_t i = 0; i < arrSize; i++)
	{
		if (array[i] == '\0')
		{
			return i; //length without null char
		}
	}

	return 0;
}

bool Helper::isEmpty(uint8_t* array, uint16_t arrSize)
{
	bool empty = true;

	for (uint8_t i = 0; i < arrSize; i++)
	{
		if (array[i] != '\0')
		{
			empty = false;
			break;
		}
	}

	return empty;
}
