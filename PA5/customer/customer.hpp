int globalTime = 0;

class Data
{
    public: // Member functions
    
    private:
    int customerNumber = 1000; // Unique identifier; starts at 1; after 24 hours should be reset to 1
    int serviceTime; // Random time; varies between express and normal lanes; units in minutes
    int totalTime; // totalTime = serviceTime + sum of serviceTimes of customers in line
    // before this customer; units in minutes
}; // This memory needs to be allocated on the heap!