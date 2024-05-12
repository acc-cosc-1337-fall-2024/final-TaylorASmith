//DIE_H
#ifndef DIE_H
#define DIE_H

class Die {
    public:
        Die();
        int roll();
    
    private:
        static const int sides = 6;
};

#endif
