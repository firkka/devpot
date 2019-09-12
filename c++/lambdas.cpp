#include <string>
#include <vector>

class AddressBook
{
    public:
    // using a template allows us to ignore the differences between functors, function pointers and lambda
    
    template<typename Func>
    std::vector<std::string> findMatchingAddresses (Func func)
    { 
        std::vector<std::string> results;
        for ( auto itr = _addresses.begin(), end = _addresses.end(); itr != end; ++itr )
        {
            // call the function passed into findMatchingAddresses and see if it matches
            if ( func( *itr ) )
            {
                results.push_back( *itr );
            }
        }
        return results;
    }

    private:
    std::vector<std::string> _addresses;
};

/*

If the function returns true, when given a particular address, the address will be returned.
Not quite convenient enough to create functions.
You had to go define it somewhere else, just to be able to pass it in for one simple use.
That's where lambdas come in.

*/
