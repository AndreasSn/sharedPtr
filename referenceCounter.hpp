

class referenceCounter
{
private:
    int count = 0;
public:
    int getCount(){
        return count;
    }
    void incCount(){
        ++count; // increment the reference counter
    }
    int decCount(){
        return --count; // decrement the reference counter
    }
};


