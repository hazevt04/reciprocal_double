// C++ File for main

#include "reciprocal_double.hpp"


void usage( const char* prog_name ) {
   std::cout << "Usage: " << std::string{prog_name} << " <double value>\n";
}


int main( int argc, char** argv ) {
   try {
      double value = 0.0;
      double recip_value = 0.0;

      if ( argc > 1 ) {
         char* pEnd;
         value = strtod( argv[1], &pEnd );
      } else {
         std::cout << "ERROR: " << argc << " arguments provided when 2 expected\n";
         usage(argv[0]);
         return EXIT_FAILURE;
      }

      std::cout << "Value was " << value << "\n"; 

      recip_value = reciprocal(value);
      std::cout << "Reciprocal is " << recip_value << "\n"; 

      double numerator = 2.0;
      double denominator = 5.0;
      double recip_denominator = reciprocal(denominator);
      std::cout << numerator << " / " << denominator << " = " << numerator/denominator <<"\n"; 
      std::cout << numerator << " * " << recip_denominator << " = " << numerator * recip_denominator <<"\n"; 
      return EXIT_SUCCESS;

   } catch ( std::exception& ex ) {
      std::cout << "ERROR: " << ex.what() << "\n";
      return EXIT_FAILURE;
   }
}

