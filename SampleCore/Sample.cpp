#include "Sample.h"

using namespace SampleCore;

constexpr int StartingValue = 0;

Sample::Sample()
   : _currentValue( StartingValue )
{
}

int Sample::GetValue() const
{
   return _currentValue;
}

void Sample::IncrementValue()
{
   _currentValue++;
}
