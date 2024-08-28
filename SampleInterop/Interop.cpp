#include "Interop.h"

#include <SampleCore/Sample.h>

using namespace SampleInterop;

Interop::Interop()
{
   _sample = new SampleCore::Sample();
}

Interop::~Interop()
{
   delete _sample;
}

int Interop::GetValue() /*const*/
{
   return _sample->GetValue();
}

void Interop::IncrementValue()
{
   _sample->IncrementValue();

   OnValueChanged(this, gcnew System::EventArgs());
}
