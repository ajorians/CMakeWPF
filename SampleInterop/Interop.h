#pragma once

namespace SampleCore
{
   class ISample;
}

namespace SampleInterop
{
   public ref class Interop
   {
   public:
      Interop();
      ~Interop();

      int GetValue() /*const*/;
      void IncrementValue();

      event System::EventHandler^ OnValueChanged;

   private:
      SampleCore::ISample* _sample;
   };
}