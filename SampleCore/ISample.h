#pragma once

namespace SampleCore
{
   class ISample
   {
   public:
      virtual int GetValue() const = 0;
      virtual void IncrementValue() = 0;
   };
}