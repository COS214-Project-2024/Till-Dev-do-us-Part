#include "Resources.h"
#include "Water.h"
#include "Energy.h"
#include "Materials.h"



int main() {
    // Create resources
    Water* water = new Water();
    Energy* energy = new Energy();
    Materials* steel = new Materials("Steel");
    Materials* wood = new Materials("Wood");
   


     // Test different scenarios
    cout << "--- Testing Water Resource ---" << endl;
     cout<<water->getState()<<endl;
    water->consume(18000); 
    water->consume(40000);  
    water->consume(40000);  
    
  
    cout << "\n--- Testing Energy Resource ---" << endl;
    energy->consume(100002); 
    energy->consume(800);  

   cout << "\n--- Testing Other Resources ---" << endl;
   cout<<"Steel's state: "<<steel->getState()<<endl;
   cout<<"Wood's state: "<<wood->getState()<<endl;

    // Cleanup
    delete water;
    delete energy;
    delete steel;
    delete wood;
   

    return 0;
}

