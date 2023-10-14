class Standard
  {
  }
template <typename TYPE> class DataSource : public Standard
  {TYPE theValue;
   DataSource(TYPE value)
     {set(value);        
     }
   DataSource set(TYPE value)
     {theValue = value;
     }
   DataSource &get()
     {return theValue;
     }
  };
int main()
  {DataSource<int> element(5);
   cout << element.get() << endl;     
  }