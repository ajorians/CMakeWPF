﻿using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Windows.Input;

namespace TestWpfApp
{
   public class MainWindowViewModel : INotifyPropertyChanged
   {
      private readonly SampleInterop.Interop _interop;
      public MainWindowViewModel()
      {
         _interop = new SampleInterop.Interop();

         _interop.OnValueChanged += ( s, e ) =>
         {
            NotifyPropertyChanged( nameof( CurrentValue ) );
         };

         _incrementCommand = new RelayCommand( () => _interop.IncrementValue() );
      }

      public int CurrentValue
      {
         get => _interop.GetValue();
      }

      private ICommand _incrementCommand;
      public ICommand IncrementCommand
      {
         get => _incrementCommand;
      }

      private void NotifyPropertyChanged( [CallerMemberName] string propertyName = "" )
      {
         PropertyChanged?.Invoke( this, new PropertyChangedEventArgs( propertyName ) );
      }

      public event PropertyChangedEventHandler PropertyChanged;
   }
}