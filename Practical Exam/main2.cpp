#include <iostream>

using namespace std;

char temperatureSign[6] = {'K', 'k', 'C', 'c', 'F', 'f'};

/* class used is named tempConversion and it contains the 
class members that calculates each conversion */
class tempConversion
{
    private:
        double temperature;
        
    public:
        tempConversion(double temp): temperature(temp) {}
        
        double celtofar()
        {
            return (temperature * 1.8 + 32);
        }
        
        double celtokel()
        {
            return (temperature + 273.15);
        }
        
        double fartocel()
        {
            return (temperature - 32) * 0.55555555555;
        }
        
        double fartokel()
        {
            return (((temperature - 32) * 0.555555555) + 273.15);
        }
        
        double keltocel()
        {
            return (temperature - 273.15);
        }
        
        double keltofar()
        {
            return (temperature - 273.15) * 1.8 + 32;
        }
};


int main()
{
    double temperature;
    char firstUnit;
    char secondUnit;
    
    while (true)
        {
        cout << "Select starting temperature unit (C, F, K): ";
        cin >> firstUnit;
        
        cout << "Enter Temperature: ";
        cin >> temperature;
        
        cout << "Select new temperature unit (C, F, K): ";
        cin >> secondUnit;
        
        tempConversion calculator(temperature);
        if (firstUnit == 'C' || firstUnit == 'c')
        {
            if (secondUnit == 'C' || secondUnit == 'c')
            {
                cout << "Same Unit Selected, Try Again." << endl;
            }
            else if (secondUnit == 'F' || secondUnit == 'f')
            {
                double celtofar = calculator.celtofar();
                cout << "Celsius to Farenheit = " << celtofar << "F" << endl;
                
                if (celtofar < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (celtofar > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (celtofar > 20 || celtofar < 40)
                {
                    cout << "Normal" << endl;
                }
            }
            
            else if (secondUnit == 'K' || secondUnit == 'k')
            {
                double celtokel = calculator.celtokel();
                cout << "Celsius to Kelvin = " << celtokel << "K"  << endl;
                
                if (celtokel < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (celtokel > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (celtokel > 20 || celtokel < 40)
                {
                    cout << "Normal" << endl;
                }
              
            }
            else
            {
                cout << "Invalid Key, Try again." << endl;
            }
        }
        
        if (firstUnit == 'F' || firstUnit == 'f')
        {
            if (secondUnit == 'F' || secondUnit == 'f')
            {
                cout << "Same Unit Selected, Try Again." << endl;;
            }
            
            else if (secondUnit == 'C' || secondUnit == 'c')
            {
                double fartocel = calculator.fartocel();
                cout << "Farenheit to Celsius = " << fartocel << "C"  << endl;
                
                if (fartocel < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (fartocel > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (fartocel > 20 || fartocel < 40)
                {
                    cout << "Normal" << endl;
                }
                
                
            }
            
            else if (secondUnit == 'K' || secondUnit == 'k')
            {
                double fartokel = calculator.fartokel();
                cout << "Farenheit to Kelvin = " << fartokel << "K"  << endl;
                
                if (fartokel < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (fartokel > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (fartokel > 20 || fartokel < 40)
                {
                    cout << "Normal" << endl;
                }
            
            }
            else
            {
                cout << "Invalid Key, Try again." << endl;
            }
        }
        
        if (firstUnit == 'K' || firstUnit == 'k')
        {
            if (secondUnit == 'K' || secondUnit == 'k')
            {
                cout << "Same Unit Selected, Try Again." << endl;
            }
            
            else if (secondUnit == 'C' || secondUnit == 'c')
            {
                double keltocel = calculator.keltocel();
                cout << "Kelvin to Celsius = " << keltocel << "C" << endl;
                
                if (keltocel < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (keltocel > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (keltocel > 20 || keltocel < 40)
                {
                    cout << "Normal" << endl;
                }
                
                
            }
            
            else if (secondUnit == 'F' || secondUnit == 'f')
            {
                double keltofar = calculator.keltofar();
                cout << "Kelvin to Farenheit = " << keltofar << "K"  << endl;
                
                if (keltofar < 20)
                {
                    cout << "Cold" << endl;
                }
                
                else if (keltofar > 40)
                {
                    cout <<"Hot" << endl;
                }
                
                else if (keltofar > 20 || keltofar < 40)
                {
                    cout << "Normal" << endl;
                }
                
              
            }
            else
            {
                cout << "Invalid Key, Try again." << endl;
            }
        }
    }
    return 0;
}