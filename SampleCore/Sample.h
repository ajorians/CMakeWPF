#pragma once

#include "ISample.h"

namespace SampleCore
{
   class Sample : public ISample
   {
   public:
      Sample();

      int GetValue() const override;
      void IncrementValue() override;

   private:
      int _currentValue;
   };
}