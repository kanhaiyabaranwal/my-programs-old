#include <iostream>
#include <string>

struct State
{
    State (std::string topermute_, int place_, int nextchar_, State* next_ = 0)
        : topermute (topermute_)
        , place (place_)
        , nextchar (nextchar_)
        , next (next_) { }
    std::string topermute;
    int place;
    int nextchar;
    State* next;
};
std::string swtch (std::string topermute, int x, int y)
{
    std::string newstring = topermute;
    newstring[x] = newstring[y];
    newstring[y] = topermute[x]; //avoids temp variable

    return newstring;
}
void permute (std::string topermute, int place = 0)
{
    // Linked list stack.
    State* top = new State (topermute, place, place);

    while (top != 0)
    {
        State* pop = top;
        top = pop->next;

        if (pop->place == pop->topermute.length () - 1)
        {
            std::cout << pop->topermute << std::endl;
        }

        for (int i = pop->place; i < pop->topermute.length (); ++i)
        {
            top = new State (swtch (pop->topermute, pop->place, i), pop->place + 1, i, top);
        }

        delete pop;
    }
}

int main (int argc, char* argv[])
{
    if (argc!=2)    
    {
        std::cout<<"Proper input is 'permute string'";
        return 1;
    }
    else
    {
        permute (argv[1]);
    }

    return 0;
}

